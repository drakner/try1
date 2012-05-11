#include "GameManager.h"
#include "SfmlWindow.h"
#include "GraphicsManager.h"

GameManager::GameManager(void)
{

}
GameManager::GameManager(SfmlWindow* window, GraphicsManager* gMgr)
{
	sfmlWindow = window;
	graphicsManager = gMgr;
}


GameManager::~GameManager(void)
{
}

void GameManager::play() 
{
	sf::Clock clock;
	while(sfmlWindow->isOpen()) {
		sfmlWindow->updateWindow(); // check user input, updates windows properties as needed.
			if(clock.getElapsedTime().asMilliseconds() > 16.67) {
				clock.restart();
				graphicsManager->Paint();
				sfmlWindow->display();
			}
		}
	sfmlWindow->close();
}