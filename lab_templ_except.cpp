//����������

//�������: 
//		������� �������,
//		������� �������,


// kostinann@mail.ru

#include "stdafx.h"
#include <vld.h>
#include <tchar.h>
#include <stdexcept>
#include "Swap.h"
#include "MyStack.h"
#include "MyStack2_List.h"
#include "MyQueue.h"

#define stop __asm nop

int _tmain(int argc, _TCHAR* argv[])
{


	////////////////////////////////////////////////////////////////////////////
	{//����. ������� �������.
		//�������� ������ ������� ������������ ������� ����
		//�������� - Swap(). ��������� ����������������� ����������
		//������� � ������� ������������ ���� ��������� ����.
		//��������� 1: ���������� ������� ���������� ��������� � .h-����.

		int iX = 1, iY = -1;
		Swap(iX, iY);

		double dX = 0.5, dY = -5.5;
		Swap(dX, dY);

		stop
			//��������� 2: ���������, ��� ����� �����������, ��� ����,
			//			����� ��������� ����� ������� � ��������� MyString
			//			�� ������ ���������, �� � ����������
			MyString str1("One"), str2("Two");
		Swap(str1, str2);
	}


	/////////////////////////////////////////////////////////////////////

	//����. ������� �������.
	{//������� 1.
		//�������� ������ ������ MyStack ��� �������� ��������� ������ ���� T.
		//���������: 1.�������� ����� ���-�� ������� - ������� � ������� ���������
		//			��� �������� ��������������� ������������� � ������ ���������
		//			�������� ������, 
		//			2.��� ������� ������������� ������� ����� ����� ���� �����������
		//			��������-��������� �������
		//			3.������������� ���������� �� ������ �������� "push" � "pop". ���
		//			����, ����� ������������� ���������� ���������� ���� �������� 
		//			������ ���� �� ������������ ���������� � ��������� ��������
		//			4. ������������� ���������� operator[] ����� �������, ����� ������������
		//			��� ������/�������� �������� ������ ��� ���������, ������� �� ����������


		//� ������� ������� MyStack �������� ���� �� 5 ��������� int - iStack �
		//���� �� 10 ��������� MyString - strStack � ������������������� � ���������
		//push() � pop(), operator[]

		MyStack<int,5> iStack(3,45);
		MyStack<MyString,10> strStack(2);

		iStack.push(9);
		iStack.push(345);
		try
		{
			iStack.push(111);
		}
		catch(std::out_of_range e)
		{
			cerr<<e.what()<<endl;
		}

		strStack.push(MyString("abc"));
		{
			MyString str1("Hello!");
			MyString* str2=new MyString("world");
			strStack.push(str1);
			strStack.push(*str2);
			delete str2;
		}
		strStack.push("qwert");
		MyString tmp=strStack[2];
		strStack[0]="start";

		stop

	}



	//������� 2. ���������� ������ ����� - MyStack2 ����� �������, ����� 
	//��� �������� ��������� ������������� ����������� ������.
	//���������� ����������� ����������� �������� ����� � ��� �������, � ������� �� ������� (push())
	//������������
	{
		MyStack2<MyString> s;
		{
			s.push("Hello ");
			s.push(MyString("world"));
			s.push("?");
			MyString str=s.top();
			s.pop();
			str=MyString("!!!");
			s.push(str);
		}
		cout<<s;
	}
	stop



		//������� 3. ���������� ������ ������� - MyQueue ����� �������, ����� 
		//��� �������� ��������� ������������� ������������ ������.
		//��� ������������� ������� ������� ������ ��������� �������, �� ����
		//����� �������� "�����", � "������" ������ ����� ��� ������� ��������� ��������
		//=> ������ ���� ����������� ��������� �����

	MyQueue<MyString> q;
	q.push("a");
	q.push("b");
	q.push("c");
	q.push("dog");
	q.push("cat");
	q.push("bird");
	q.push("Make");
	q.push("love");
	q.push("not");
	q.push("war");
	MyString tmp=q.pop();
	q.pop();
	q.pop();
	q.push("!");
	q.push("blah-blah-bla");
	q.push("Don't worry");
	q.push("be happy");
	q.push("qwert");
	cout<<endl<<q;
	stop

	MyQueue<MyString> q2=q;
	int i=3;
	do {q2.pop();i--;}
	while(i>0);
	cout<<endl<<q2;

	q=q2;
	q.push("Something");
	cout<<endl<<q;	

	return 0;
}

