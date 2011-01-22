#include "Config.h"

Config::Config() {
}

Config::~Config() {
    RessourceManager::Kill();
    Logger::Kill();
}

void Config::init() {
    width = 800;
    height = 600;
    colors = 32;
    fullscreen = false;
    debug = true;
    fps = 60;
    image_path = "ressources/images/";
    maps_path = "ressources/maps";
    Logger::Instance()->init();
}
