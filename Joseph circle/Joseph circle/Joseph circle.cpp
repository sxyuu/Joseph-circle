// Joseph circle.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "Child.h"
#include "Circle.h"
using namespace std;



int main()
{
	cout << "this is my first program.\n";
	cout << "请输入人数：";
	int Startside, Startnumber, Large;
	cin >> Startside;
	cout << "请输入开始编号：";
	cin >> Startnumber;
	cout << "请输入循环长度：";
	cin >> Large;

	Circle A;
	A.CCircle(Startside, Startnumber, Large);

	if (!A.Judgelarge())
	{
		cout << "输入循环长度有误！\n";
		system("pause");
		return -1;
	}
	if (!A.Judgeside())
	{
		cout << "输入人数有误！\n";
		system("pause");
		return -1;
	}
	if (!A.Judgestatnumber())
	{
		cout << "输入开始编号有误！\n";
		system("pause");
		return -1;
	}
	
	A.run();
	cout << "最后剩下" << A.last;
	system("pause");


	return 0;
}

