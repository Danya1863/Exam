#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Igra.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));
	Igra obj(Words());
	obj.menu();
}