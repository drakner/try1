#include "GraphicsManager.h"
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <iostream>
GraphicsManager::GraphicsManager(void)
{

}


GraphicsManager::~GraphicsManager(void)
{
}
void GraphicsManager::setProjection(int width, int height) 
{
	double ratio = (width*1.0 / height*1.0); // width-height-ratio
	double widthInUnits = 10.0;
	double heightInUnits = widthInUnits/ratio;
	
	glMatrixMode(GL_PROJECTION);
	// width will always be 10 units, height calculated accordingly
	gluOrtho2D(-widthInUnits/2.0, widthInUnits/2.0, -(heightInUnits)/2, (heightInUnits)/2);
	std::cout << "UNIT-width: " << widthInUnits << " UNIT-height: " << heightInUnits << std::endl;
}

void GraphicsManager::Paint() 
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2d(-1.0, -1.0);
	glVertex2d(-1.0, 1.0);
	glVertex2d(1.0, 1.0);
	glVertex2d(1.0, -1.0);
	glEnd();
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2d(-0.5, -0.5);
	glVertex2d(-0.5, 0.5);
	glVertex2d(0.5, 0.5);
	glVertex2d(0.5, -0.5);
	glEnd();

}
