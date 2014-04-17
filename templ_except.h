#include <iostream>
using std::cerr;
using std::endl;

// ------- Task 1 ---------------------
template <typename T> 
void Swap(T& x, T& y)
{	
	T tmp=std::move(x);
	x=std::move(y);
	y=std::move(tmp);
}


// ------- Task 2 ---------------------
template <typename T, size_t MaxN>
class MyStack
{
	T m_data[MaxN];
	size_t m_size;
public:
	MyStack();
	MyStack(size_t N, T&& val=T());

	void push(T&& elem) throw(std::out_of_range);
	T& pop() throw(std::out_of_range);
};


template <typename T, size_t MaxN>
MyStack<T,MaxN>::MyStack()
{
	m_data=T();
	m_size=0;
}

template <typename T, size_t MaxN>
MyStack<T,MaxN>::MyStack(size_t N, T&& val)
{
	try
	{
		if(N>MaxN)
			throw std::out_of_range("Failed to create MyStack. Number of elements is more than capacity.");
		m_size=N;
		for(int i=0;i<N;i++)			
			m_data[i]=val;
		
	}
	catch(std::out_of_range e)
	{
		cerr<<e.what()<<endl;
	}
}

template <typename T, size_t MaxN>
void MyStack<T,MaxN>::push(T&& elem)
{
	try
	{
		if(m_size==MaxN)
			throw std::out_of_range("The element can not be pushed. MyStack is full.");
		m_data[m_size]=elem;
		m_size++;
	}
	catch(std::out_of_range e)
	{
		cerr<<e.what()<<endl;
	}
}

template <typename T, size_t MaxN>
T& MyStack<T,MaxN>::pop()
{
	try
	{
		if(m_size==0)
			throw std::out_of_range("Can't pop an element. MyStack is empty.");
		delete m_data[m_size-1];
		m_size--;
	}
	catch(std::out_of_range e)
	{
		cerr<<e.what()<<endl;
	}
}