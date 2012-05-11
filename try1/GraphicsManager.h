#pragma once
class GraphicsManager
{
public:
	GraphicsManager(void);
	~GraphicsManager(void);
	void setProjection(int width, int height);
	void Paint();
};

