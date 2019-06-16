#include <iostream>
#include <Windows.h>
#pragma once

using namespace std;
class Point
{
public:
	Point();
	~Point();
	void xoaManHinh();
	void textColor(int color);
	void gotoXY(int x,int y);
	int whereX();
	int whereY();
};

