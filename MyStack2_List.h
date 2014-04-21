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
	MyStack2(){m_pHead=nullptr;}
	~MyStack2();

	void push(const T&);
	void pop() throw(std::out_of_range); // remove the last element
	T& top() throw(std::out_of_range); // just return the last element (do not remove it!)
};

template <typename T>
void MyStack2<T>::push(const T& data)
{
	Node* node=new Node(data);
	node->pNext=m_pHead;
	m_pHead=node;
}

template <typename T>
T& MyStack2<T>::top()
{	
	if (!m_pHead)
		throw std::out_of_range("Error! MyStack2 is empty.");
	else
		return *m_pHead;	
}

template <typename T>
void MyStack2<T>::pop()
{
	if (!m_pHead)
		throw std::out_of_range("Error! MyStack2 is empty.");
	else
	{
		Node* tmp=m_pHead->pNext;
		delete m_pHead;
		m_pHead=tmp;
	}
}




// Print - сделать рекурсивно