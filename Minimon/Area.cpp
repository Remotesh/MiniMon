#include "Area.h"

Area::Area()
	:width(20),
	height(20)
{
	generateArea();
}

Area::Area(int w, int h)
	:width(w),
	height(h)
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

int** Area::getArea()
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