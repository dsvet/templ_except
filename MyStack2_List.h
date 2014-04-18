template <typename T>
class MyStack2
{
	class Node
	{
		T m_data;
		Node* pNext;
		Node(const T& data){m_data=data;};
	};
	Node* m_pHead;
public:
	MyStack2(){m_pHead=nullptr; m_pHead->pNext=nullptr;}
	~MyStack2();

	void push(const T&);
	T pop() throw(std::out_of_range);
};

template <typename T>
void MyStack2<T>::push(const T& data)
{
	Node* node=new Node(data);
	node->pNext=m_pHead;
	m_pHead=node;
}

template <typename T>
T MyStack2<T>::pop()
{
	try
	{
		if (!m_pHead)
			throw std::out_of_range("Can't insert an element. MyStack2 is empty.");
		else
		{
			T tmp=*m_pHead;
			m_pHead=m_pHead->pNext;
			return std::move(tmp);
		}
	}
	catch(std::out_of_range e)
	{
		cerr<<e.what()<<endl;
	}
}



//void pop(); убирает последний
//T& top(); возвращает последний
// Print - сделать рекурсивно