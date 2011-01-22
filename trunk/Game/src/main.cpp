#include <iostream>
#include "Utilities/Config.h"
#include "Game/GameManager.h"

int main(int argc, char** argv)
{
    Config::Instance()->init();
    GameManager::Instance()->init();
    GameManager::Instance()->newGame(1, "level1.xml");
    GameManager::Kill();
    Config::Kill();
	return 0;
}
