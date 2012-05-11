#pragma once
#include <SFML/Window.hpp>
class GraphicsManager;

class SfmlWindow
{
public:
	SfmlWindow(void);
	~SfmlWindow(void);
	void initialize(GraphicsManager* gMgr);
	void resize(int w, int h);
	void mousePressed(int button, int action);
	void mousePos(int x, int y);
	void execute();
	void catchInput();
	void updateWindow();
	void setGraphicsManager(GraphicsManager* gMgr);
	sf::Window window;
	bool isOpen();
	void display();
	void close();
private:
	bool windowIsOpen;
	unsigned int windowStyle;
	GraphicsManager* graphicsManager;
};

