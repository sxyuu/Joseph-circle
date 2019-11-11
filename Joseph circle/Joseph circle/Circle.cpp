#include "stdafx.h"
#include "Circle.h"
#include "Child.h"
#include <iostream>


Circle::Circle()
{
	this->Circleside = 0;
	this->Large = 0;
	this->Startnunber = 0;
}
void Circle::CCircle(int Startside, int Startnumber, int large)
{
	this->Circleside = Startside;
	this->Startnunber = Startnumber;
	this->Large = large;
}


void Circle::Bulid()
{
	this->Children = new Child[this->Circleside];
	for (int i = 0; i < this->Circleside; i++)
	{
		this->Children[i].Childnumber = i + 1;
	}
	for (int i = 0; i < this->Circleside; i++)
	{
		if (i == 0)
		{
			Children[i].Lefthand =&Children[this->Circleside-1];
			Children[i].Righthand = &Children[i + 1];
		}
		if (i == this->Circleside-1)
		{
			Children[i].Righthand = &Children[0];
			Children[i].Lefthand = &Children[i - 1];
		}
		if (i != 0 && i != this->Circleside-1)
		{
			Children[i].Righthand = &Children[i + 1];
			Children[i].Lefthand = &Children[i - 1];
		}
	}
}

void Circle::run()
{
	Bulid();
	Child *New = &Children[0];
	if (this->Startnunber > 1)
	{

		for (int i = 0; i<this->Startnunber; i++)
		{
			New = New->Righthand;
		}

	}
	while (this->Circleside > 1)
	{
		for (int i = 0; i < this->Large-1; i++)
		{
			New = New->Righthand;
		}
		New->Lefthand->Righthand = New->Righthand;
		New->Righthand->Lefthand = New->Lefthand;
		New = New->Righthand;
		this->Circleside--;
	}
	this->last = New->Childnumber;
}

int Circle::Judgeside()
{
	if (this->Circleside >= 1)
		return 1;
	else return 0;
}

int Circle::Judgestatnumber()
{
	if (this->Startnunber > this->Circleside || this->Startnunber < 1)
		return 0;
	else return 1;
}

int Circle::Judgelarge()
{
	if (this->Large >= 1)
		return 1;
	else return 0;
}
Circle::~Circle()
{
}
