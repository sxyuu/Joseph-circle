#pragma once
#include <iostream>
#include "Child.h"
class Circle
{
private:
		void Bulid();//����Ȧ

public:
	int Startnunber, Large;//��ʼ��ţ�ѭ����С
	int b;
	int last;//���ʣ�µ���
	int Circleside;//Ȧ�Ĵ�С
	Child *Children;//��������
	int *list;
public:
	void CCircle(int Startside,int Startnumber,int large);//�Ա�� ѭ����С ��Ȧ��С���и�ֵ
	Circle();
	void run();//��ʼѭ����Ѱ�����ʣ�µ���
	~Circle();
};

