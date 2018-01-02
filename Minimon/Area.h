#pragma once

class Area 
{
public:
	Area();
	Area(int, int);

	virtual void generateArea();

	void setLayout(int**);

	int** getLayout();

	int getHeight();
	int getWidth();

protected:

	int height, width;
	int **layout;
};