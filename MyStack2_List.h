template <typename T>
class MyStack2
{
	class Node
	{
	public:
		T m_data;
		Node* pNext;
		Node(const T& data){m_data=data;};
	};
	Node* m_pHead;	
public:
	MyStack2(){m_pHead=nullptr;size=0;}
	~MyStack2();
	MyStack2(const MyStack2&);
	MyStack2& operator=(const MyStack2&);

	size_t size;
	void push(const T&);
	void pop(); //throw(std::out_of_range); // remove the last element
	T top() const; //throw(std::out_of_range); // just return the last element (do not remove it!)
private:
	void Print(ostream&,Node*) const;
	void Copy(Node*);
	friend ostream& operator<< <T> (ostream&,const MyStack2<T>&);
};

template <typename T>
MyStack2<T>::MyStack2(const MyStack2& s)
{
	size=0;
	*this=s;
}

template <typename T>
void MyStack2<T>::Copy(Node* node)
{
	if(node->pNext)
		Copy(node->pNext);
	push(node->m_data);
}

template <typename T>
MyStack2<T>& MyStack2<T>::operator=(const MyStack2& s)
{
	if(this!=&s)
	{
		Node* thisNode=m_pHead;
		Node* otherNode=s.m_pHead;
		if(size && s.size)
		{
			size_t comSize = size < s.size ? size : s.size;
			for(size_t i=0;i<comSize;i++)
			{
				thisNode->m_data=otherNode->m_data; // rewrite data in existing nodes
				thisNode=thisNode->pNext;
				otherNode=otherNode->pNext;
			}
		}

		Copy(otherNode);
		m_pHead=thisNode;

		size=s.size;
	}

	return *this;
}

template <typename T>
void MyStack2<T>::push(const T& data)
{
	Node* node=new Node(data);
	node->pNext=m_pHead;
	m_pHead=node;
	size++;
}

template <typename T>
T MyStack2<T>::top() const
{	
	if (!m_pHead)
		throw std::out_of_range("Error! MyStack2 is empty.");
	else
		return m_pHead->m_data;	
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
		size--;
	}
}

template<typename T>
ostream& operator<<(ostream& o, const MyStack2<T>& stack)
{
	if(stack.m_pHead)
	{
		stack.Print(o,stack.m_pHead);
		o<<stack.m_pHead->m_data;
	}
	return o;
}

template <typename T>
void MyStack2<T>::Print(ostream& o,Node* node) const
{
	node=node->pNext;
	if(node)
	{		
		Print(o,node);
		o<<node->m_data;
	}
}

template <typename T>
MyStack2<T>::~MyStack2()
{
	Node* tmp=m_pHead;
	for(size_t i=0;i<size;i++)
	{
		m_pHead=tmp->pNext;
		delete tmp;
		tmp=m_pHead;
	}
}

