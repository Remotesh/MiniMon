#pragma once

class Area 
{
public:
	Area();
	Area(int, int);
	~Area();

	virtual void generateArea();

	void setLayout(int**);

	void setupLayout();

	void freeLayout();

	int** getLayout();

	int getHeight();
	int getWidth();

protected:

	int height, width;
	int **layout;
};