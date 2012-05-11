/**
 * SfmlWindow handles the window and mouse/ keyboard input.
 *
 */
#include <Windows.h>
#include <gl/GL.h>
#include <SFML/System.hpp>
#include "SfmlWindow.h"
#include <iostream>
#include "GraphicsManager.h"
SfmlWindow::SfmlWindow(void)
{
	windowIsOpen = true;
	graphicsManager = NULL;
}


SfmlWindow::~SfmlWindow(void)
{

}

/************************************************************************/
/* Initializing the window.                                              */
/************************************************************************/
void SfmlWindow::initialize(GraphicsManager* gMgr) 
{
	graphicsManager = gMgr;
	windowStyle = sf::Style::Close;
	window.create(sf::VideoMode(640, 320, 32), "Scene", windowStyle);
	graphicsManager->setProjection(window.getSize().x, window.getSize().y);
	glViewport(0, 0, 640, 320);
}
/** 
 * Catch keyboard input
 */
void SfmlWindow::catchInput() 
{
	sf::Event Event;
	while (window.pollEvent(Event))
	{
		
		// Some code for stopping application on close or when escape is pressed...
		if (Event.type == sf::Event::Resized) {
			graphicsManager->setProjection(window.getSize().x, window.getSize().y);
			glViewport(0, 0,window.getSize().x,window.getSize().y);
			
		}
		if (Event.type == sf::Event::Closed) {
			windowIsOpen = false;
		}
		if(Event.type == sf::Event::KeyPressed) {
			switch (Event.key.code) {
			case sf::Keyboard::Escape:
				std::cout << "esc pressed, isOpen = " << windowIsOpen << std::endl;
				windowIsOpen = false;
				break;
			case sf::Keyboard::Return:
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) ||sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)) {
// Change to windowed mode
					if(windowStyle == sf::Style::Fullscreen) { 
						window.setVisible(false); // instead of window.show() in sfml 1.6, correct?
						windowStyle = sf::Style::Close;
						window.create(sf::VideoMode(640, 320, 32), "Try1", windowStyle);
						graphicsManager->setProjection(window.getSize().x, window.getSize().y);
						glViewport(0, 0, window.getSize().x, window.getSize().y);
						window.setVisible(true);
					}
// Change to full screen mode
					else {		
						window.setVisible(false);
						windowStyle = sf::Style::Fullscreen;
						window.create(sf::VideoMode::getDesktopMode(), "Try1", windowStyle);
						
						glViewport(0, 0, window.getSize().x, window.getSize().y);
						window.setVisible(true);
					}
				}
				break;
			}
		}
	}
}

/************************************************************************/
/* Check user input, does changes to the window as needed.			   */
/************************************************************************/
void SfmlWindow::updateWindow() 
{
	catchInput();
}

bool SfmlWindow::isOpen() 
{
	return windowIsOpen;
}

void SfmlWindow::resize(int w, int h)
{

}

void SfmlWindow::mousePos(int x, int y) 
{
	
}

void SfmlWindow::setGraphicsManager(GraphicsManager* gMgr)
{
	graphicsManager = gMgr;
}

void SfmlWindow::display() 
{
	window.display();
}
void SfmlWindow::close() 
{
	window.close();
}