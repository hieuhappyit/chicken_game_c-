#include <windows.h>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include "Point.h"
#include "Chicken.h"
using namespace std;

#define SIZE 100
#define BLACK			0
#define DARK_BLUE		1
#define DARK_GREEN		2
#define DARK_CYAN		3
#define DARK_RED		4
#define DARK_PINK		5
#define DARK_YELLOW  	6
#define DARK_WHITE		7
#define GREY			8
#define BLUE			9
#define GREEN			10
#define CYAN			11
#define RED 			12
#define PINK			13
#define YELLOW  		14
#define WHITE			15

int Width = 45;
int	Height = 10;
int len = 4;
void readFile(char *file,char *data) {
	ifstream ifs;
	ifs.open(file);
	Point p;
	p.textColor(CYAN);
	while (!ifs.eof()) {

		ifs.getline(data, 100);
		cout <<"\t\t\t" << data<<endl;
	}
	ifs.close();
}
//void dynamicText(char text[]) {
//	//	display();
//	Point p;
//	while (1) {
//		p.gotoXY((Width / 2) - 4 - 3, Height / 2 - 1);
//		puts(text);
//		Sleep(250);
//		p.gotoXY((Width / 2) - 4 - 3, Height / 2 - 1);
//		for (int i = 0; i < strlen(text); i++) {
//			cout << " ";
//		}
//		Sleep(250);
//		if (_kbhit()) {
//			if (_getch() == 13)
//				break;
//		}
//	}
//}
void hidePointer() {
	HANDLE hOut;
	CONSOLE_CURSOR_INFO ConCurInf;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = FALSE;
	SetConsoleCursorInfo(hOut, &ConCurInf);
}
int Menu(int& choose, int option,Point &p) {
	int key = 0;
	int leng = len + 5;

	while (key != 13) {
		for (int i = 0; i < option * 2; i += 2) {
			p.gotoXY(Width - 4, Height + i);
			cout << ' ';
		}
		if ((key == 'w' || key == 'W' || key == 72) && choose > 1)
			choose--;
		else if ((key == 's' || key == 'S' || key == 80) && choose < option)
			choose++;

		for (int i = 0; i <= option * 2; i += 2) {
			if (choose == i / 2 + 1) {
				p.gotoXY(Width - 4, Height + i);
				putchar(175);
			}
		}
		key = _getch();
	}
	return choose;
}
int main() {
	hidePointer();
	char nameGame[SIZE] = "name.txt";
	char chicken[SIZE] = "chicken.txt";
	char data[SIZE];
	Point p;
	int choose = 1;
	cout << endl;
	cout << endl;
	while (choose != 0) {
		choose = 1;
		p.xoaManHinh();
		readFile(nameGame, data);
		p.textColor(DARK_YELLOW);
		p.gotoXY(Width, Height);
		puts("NEW GAME");
		p.gotoXY(Width, Height + 2 );
		puts("LEVEL");
		p.gotoXY(Width, Height + 4);
		puts("HIGH SCORE");
		p.gotoXY(Width, Height + 6);
		puts("EXIT");
		choose = Menu(choose, 4,p);
		switch (choose) {
			case 1:
				choose = 1;
				p.xoaManHinh();
			case 2:
				p.xoaManHinh();
		}
		if (choose == 4) {
			break;
		}
		p.xoaManHinh();
	}
	return 0;
}
