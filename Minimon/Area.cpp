#include "Area.h"

Area::Area()
	:width(20),
	height(20)
{
	setupLayout();
	generateArea();
}

Area::Area(int w, int h)
	:width(w),
	height(h)
{
	setupLayout();
}

Area::~Area()
{

}

void Area::generateArea()
{
	layout = new int*[width];
	for (int i = 0; i < width; i++)
	{
		layout[i] = new int[height];
	}

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			layout[i][j] = 0;
		}
	}
}

void Area::setLayout(int** newLayout)
{
	layout = newLayout;
}

void Area::setupLayout()
{
	layout = new int*[width];
	for (int i = 0; i < width; i++)
	{
		layout[i] = new int[height];
	}
}

void Area::freeLayout()
{
	if (width > 0 || height > 0)
	{
		for (int i = 0; i < width; i++)
		{
			delete[] layout[i];
		}
		delete[] layout;
	}
}

int** Area::getLayout()
{
	return layout;
}

int Area::getHeight()
{
	return height;
}

int Area::getWidth()
{
	return width;
}