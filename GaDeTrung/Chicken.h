#pragma once
#include <iostream>
#include "Point.h"

#define X0 1;
#define Y0 1;

using namespace std;
enum Direct
{
	STOP = 0,
	LEFT,
	RIGHT
};
class Chicken : Point
{
private:
	int x, y;
public:
	Chicken();
	~Chicken();
	void drawChicken();
};

