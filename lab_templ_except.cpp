//����������

//�������: 
//		������� �������,
//		������� �������,


#include <tchar.h>
#include <stdexcept>
#include "templ_except.h"
#include "MyString.h"

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
		MyStack<MyString,10> strStack(5);

		iStack.push(9);
		iStack.push(345);

		stop

	}

	//������� 2. ���������� ������ ����� - MyStack2 ����� �������, ����� 
	//��� �������� ��������� ������������� ����������� ������.
	//���������� ����������� ����������� �������� ����� � ��� �������, � ������� �� ������� (push())
	//������������






	//������� 3. ���������� ������ ������� - MyQueue ����� �������, ����� 
	//��� �������� ��������� ������������� ������������ ������.
	//��� ������������� ������� ������� ������ ��������� �������, �� ����
	//����� �������� "�����", � "������" ������ ����� ��� ������� ��������� ��������
	//=> ������ ���� ����������� ��������� �����

	return 0;
}

