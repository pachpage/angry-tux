#include "GameManager.h"

GameManager::GameManager() {
}

GameManager::~GameManager() {
    delete _eventManager;
    EntityManager::Kill();
    MapManager::Kill();
    _app.Close();
}

void GameManager::init() {
    if (Config::Instance()->fullscreen) {
        _app.Create(sf::VideoMode(Config::Instance()->width, Config::Instance()->height, Config::Instance()->colors), "AngryTux", sf::Style::Fullscreen);
    } else {
        _app.Create(sf::VideoMode(Config::Instance()->width, Config::Instance()->height, Config::Instance()->colors), "AngryTux");
    }
    _app.SetFramerateLimit(Config::Instance()->fps);

    sf::View game_view(sf::FloatRect(0, 0, 800, 600));
    sf::View interface_view(sf::FloatRect(0, 0, 400, 300));
    _eventManager = new EventManager(&_app, game_view, interface_view);

    MapManager::Instance()->init();
}

void GameManager::newGame(const std::string world, int map_id) {
    _currentWorld = world;
    _currentMapId = map_id;
    createWorld();
    EntityManager::Instance()->init(&_app, _world);

    Map *currentMap = MapManager::Instance()->setMap(world, map_id);
    if (currentMap != NULL) {

        _eventManager->init();
        currentMap->load();

        //Game loop
        run();

    } else {
        Logger::Instance()->log("Map Id is unknown.");
    }

    MapManager::Instance()->stop();
    EntityManager::Instance()->stop();
    destroyWorld();

    if (_eventManager->isRestarting()) {
        restart();
    }
}

void GameManager::run() {

    while (_eventManager->isPlaying()) {

        _eventManager->manageEvent();

        _app.Clear(sf::Color::Black);

        if (!_eventManager->isPaused()) {
            _world->Step(1.0f / 30.0f, 6, 4);
        }

        EntityManager::Instance()->render();

        _app.Display();
    }
}

void GameManager::restart() {
    newGame(_currentWorld, _currentMapId);
}

void GameManager::createWorld() {
    b2Vec2 gravity(0.0f, -10.0f);
	_world = new b2World(gravity, true);
/*
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, 0.0f);
	b2Body* groundBody = _world->CreateBody(&groundBodyDef);
	b2PolygonShape groundBox;
	groundBox.SetAsBox(_app.GetWidth(), 0.0f);
	groundBody->CreateFixture(&groundBox, 0.0f);*/
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
