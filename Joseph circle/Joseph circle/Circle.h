#pragma once
#include <iostream>
#include "Child.h"
class Circle
{
private:
		void Bulid();//建立圈

public:
	int Startnunber, Large;//开始编号，循环大小
	int last;//最后剩下的人
	int Circleside;//圈的大小
	Child *Children;//建立孩子
public:
	void CCircle(int Startside,int Startnumber,int large);//对编号 循环大小 和圈大小进行赋值
	Circle();
	void run();//开始循环，寻找最后剩下的人
	~Circle();
public:
	int Judgeside();
	int Judgestatnumber();
	int Judgelarge();
};

