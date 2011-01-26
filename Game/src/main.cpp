#include <iostream>
#include "Utilities/Config.h"
#include "Game/GameManager.h"

int main(int argc, char** argv)
{
    Config::Instance()->init();
    GameManager::Instance()->init();
    GameManager::Instance()->newGame("world1", 1);
    GameManager::Kill();
    Config::Kill();
	return 0;
}
