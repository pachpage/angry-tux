#include "GameManager.h"

GameManager::GameManager() {
}

GameManager::~GameManager() {
    EntityManager::Kill();
    MapManager::Kill();
    _app.Close();
}

void GameManager::init() {
    if (Config::Instance()->fullscreen) {
        _app.Create(sf::VideoMode(Config::Instance()->width, Config::Instance()->height, Config::Instance()->colors), "AngryTux", sf::Style::Fullscreen);
    } else {
        _app.Create(sf::VideoMode(Config::Instance()->width, Config::Instance()->height, Config::Instance()->colors), "AngryTux", sf::Style::Close);
    }
    _app.SetFramerateLimit(Config::Instance()->fps);

    MapManager::Instance()->init();
}

void GameManager::newGame(const std::string world, int map_id) {
    createWorld();
    EntityManager::Instance()->init(&_app, _world);

    Map *currentMap = MapManager::Instance()->setMap(world, map_id);
    if (currentMap != NULL) {
        _app.SetSize(currentMap->getMapSize().x, currentMap->getMapSize().y);
        currentMap->load();

        _playing = true;
        _paused = false;

        //Game loop
        run();

    } else {
        Logger::Instance()->log("Map Id is unknown.");
    }

    MapManager::Instance()->stop();
    EntityManager::Instance()->stop();
    destroyWorld();
}

void GameManager::run() {
    //TODO ajouter une classe Interface qui gère l'affichage d'info par dessus le jeu (bool paused, bool win, bool loose, ect) Gère les touches
    sf::View view(sf::FloatRect(0, 0, 800, 600));

    while (_playing) {
        sf::Event Event;
        while (_app.GetEvent(Event))  {
            if (Event.Type == sf::Event::Closed || (Event.Type == sf::Event::KeyPressed && Event.Key.Code == sf::Key::Escape)) {
                _playing = false;
            } else if (Event.Type == sf::Event::KeyPressed && Event.Key.Code == sf::Key::P) {
                _paused = !_paused;
            } else if (Event.Type == sf::Event::KeyPressed && Event.Key.Code == sf::Key::Equal) {
                view.Zoom(1.1f);
            } else if (Event.Type == sf::Event::KeyPressed && Event.Key.Code == sf::Key::Num6) {
                view.Zoom(0.9f);
            }
        }

        sf::Vector2f mousePosition = _app.ConvertCoords(_app.GetInput().GetMouseX(), _app.GetInput().GetMouseY());

        _app.Clear(sf::Color::Black);

        if (!_paused) {
            _world->Step(1.0f / 30.0f, 8, 4);
        }
        _app.SetView(view);
        EntityManager::Instance()->render();

        //_app.SetView(interface); affiche ce qu'il faut sur l'interface (menu, message, hud)

        _app.Display();
    }
}

void GameManager::createWorld() {
    b2Vec2 gravity(0.0f, -20.0f);
	_world = new b2World(gravity, true);

	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, 0.0f);
	b2Body* groundBody = _world->CreateBody(&groundBodyDef);
	b2PolygonShape groundBox;
	groundBox.SetAsBox(_app.GetWidth(), 0.0f);
	groundBody->CreateFixture(&groundBox, 0.0f);
}

void GameManager::destroyWorld() {
    b2Body* node = _world->GetBodyList();
    while (node) {
        b2Body* b = node;
        node = node->GetNext();
        _world->DestroyBody(b);
        node = _world->GetBodyList();
    }

    delete _world;
}
