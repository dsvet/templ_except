//Исключения

//Шаблоны: 
//		шаблоны функций,
//		шаблоны классов,


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
	{//Тема. Шаблоны функций.
		//Создайте шаблон функции перестановки местами двух
		//значений - Swap(). Проверьте работоспособность созданного
		//шаблона с помощью приведенного ниже фрагмента кода.
		//Подсказка 1: объявление шаблона корректнее поместить в .h-файл.

		int iX = 1, iY = -1;
		Swap(iX, iY);

		double dX = 0.5, dY = -5.5;
		Swap(dX, dY);

		stop
			//Подсказка 2: подумайте, что нужно реализовать, для того,
			//			чтобы следующий вызов работал с объектами MyString
			//			не только корректно, но и эффективно
			MyString str1("One"), str2("Two");
		Swap(str1, str2);
	}


	/////////////////////////////////////////////////////////////////////

	//Тема. Шаблоны классов.
	{//Задание 1.
		//Создайте шаблон класса MyStack для хранения элементов любого типа T.
		//Подсказка: 1.элементы нужно где-то хранить - простым и удобным средством
		//			для хранения последовательно расположенных в памяти элементов
		//			является массив, 
		//			2.для задания максимального размера стека может быть использован
		//			параметр-константа шаблона
		//			3.обязательными операциями со стеком являются "push" и "pop". Для
		//			того, чтобы гарантировать корректное выполнение этих операций 
		//			хорошо было бы генерировать исключение в аварийной ситуации
		//			4. дополнительно реализуйте operator[] таким образом, чтобы пользователь
		//			мог читать/изменять значения только тех элементов, которые он формировал


		//С помощью шаблона MyStack создайте стек из 5 элементов int - iStack и
		//стек из 10 элементов MyString - strStack и поэкспериментируйте с функциями
		//push() и pop(), operator[]

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



	//Задание 2. Реализуйте шаблон стека - MyStack2 таким образом, чтобы 
	//для хранения элементов использовался ОДНОСВЯЗНЫЙ список.
	//Реализуйте возможность распечатать элементы стека в том порядке, в котором их заносил (push())
	//пользователь
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



		//Задание 3. Реализуйте шаблон очереди - MyQueue таким образом, чтобы 
		//для хранения элементов использовался динамический массив.
		//При использовании массива следует учесть специфику очереди, то есть
		//когда заполнен "хвост", в "голове" скорее всего уже имеются свободные элементы
		//=> должен быть организован кольцевой буфер

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

