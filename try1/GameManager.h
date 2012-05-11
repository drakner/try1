#pragma once

class GraphicsManager;
class SfmlWindow;

class GameManager
{
public:
	GameManager();
	GameManager(SfmlWindow* window, GraphicsManager* gMgr);
	~GameManager(void);
	void play();
private:
	GraphicsManager* graphicsManager;
	SfmlWindow* sfmlWindow;
};

