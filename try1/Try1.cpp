#include "try1.h"
#include <iostream>
#include "SfmlWindow.h"
#include "GraphicsManager.h"
#include "GameManager.h"

int main(int argc, char** argv) 
{
	// Initiate SFML
	SfmlWindow window;
	GraphicsManager graphicsManager;
	window.initialize(&graphicsManager);
	GameManager gameManager(&window, &graphicsManager);
	gameManager.play();
	return 0;
}

/* No meaning to create an object of this, done in main instead */
Try1::Try1(void)
{

}


Try1::~Try1(void)
{

}

void Try1::start()
{

}
