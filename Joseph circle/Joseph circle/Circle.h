#pragma once
#include <iostream>
#include "Child.h"
class Circle
{
private:
		void Bulid();//����Ȧ

public:
	int Startnunber, Large;//��ʼ��ţ�ѭ����С
	int last;//���ʣ�µ���
	int Circleside;//Ȧ�Ĵ�С
	Child *Children;//��������
public:
	void CCircle(int Startside,int Startnumber,int large);//�Ա�� ѭ����С ��Ȧ��С���и�ֵ
	Circle();
	void run();//��ʼѭ����Ѱ�����ʣ�µ���
	~Circle();
public:
	int Judgeside();
	int Judgestatnumber();
	int Judgelarge();
};

