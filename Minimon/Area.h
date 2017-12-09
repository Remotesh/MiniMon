#pragma once
#include "ResourceIdentifier.h"

class Area 
{
public:
	Area();
	Area(int, int);

	virtual void generateArea();

	int** getArea();

	int getHeight();
	int getWidth();

protected:

	int height, width;
	int **layout;
};