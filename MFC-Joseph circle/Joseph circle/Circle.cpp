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
	this->b = Startside;
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
	this->list = new int[this->Circleside+1];
	list[0] = Circleside;
	int a = 1;
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
		this->list[a] = New->Childnumber;
		New->Lefthand->Righthand = New->Righthand;
		New->Righthand->Lefthand = New->Lefthand;
		New = New->Righthand;
		
		this->Circleside--;
		a++;
	}
	this->last = New->Childnumber;
}

Circle::~Circle()
{
}
