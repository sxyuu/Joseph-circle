// Joseph circle.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "Child.h"
#include "Circle.h"
using namespace std;



int main()
{
	cout << "this is my first program.\n";
	cout << "������������";
	int Startside, Startnumber, Large;
	cin >> Startside;
	cout << "�����뿪ʼ��ţ�";
	cin >> Startnumber;
	cout << "������ѭ�����ȣ�";
	cin >> Large;

	Circle A;
	A.CCircle(Startside, Startnumber, Large);

	if (!A.Judgelarge())
	{
		cout << "����ѭ����������\n";
		system("pause");
		return -1;
	}
	if (!A.Judgeside())
	{
		cout << "������������\n";
		system("pause");
		return -1;
	}
	if (!A.Judgestatnumber())
	{
		cout << "���뿪ʼ�������\n";
		system("pause");
		return -1;
	}
	
	A.run();
	cout << "���ʣ��" << A.last;
	system("pause");


	return 0;
}

