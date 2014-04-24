template <typename T>
class MyQueue
{
	T* m_data;
	size_t m_cap;
	size_t m_n;
	size_t m_first, m_last;
	const size_t add;

	MyQueue(const MyQueue&); // дописать!
	MyQueue& operator=(const MyQueue&); // дописать!
public:
	MyQueue(size_t cap=10);
	~MyQueue();

	void push(const T&);
	T pop();
private:
	void Print(ostream&) const;
	friend ostream& operator<< <T> (ostream&,const MyQueue<T>&);
};

template<typename T>
ostream& operator<< (ostream &o,const MyQueue<T> &q)
{
	q.Print(o);
	return o;
}

template<typename T>
void MyQueue<T>::Print(ostream &o) const
{
	for(size_t ind=m_first;ind<m_n;ind++)
		o<<m_data[ind % m_cap];
}

template <typename T>
MyQueue<T>::MyQueue(size_t cap):add(2)
{
	m_cap=cap;
	m_data=new T[cap];
	m_n=0;
	m_first=m_last=0;
}

template <typename T>
void MyQueue<T>::push(const T& data)
{
	if(m_first!=m_last || m_n==0) // so we have at least one free place in buffer to push new element
	{	
		m_n++;
		m_data[m_last]=data;
		m_last=(m_first+m_n) % m_cap;				
	}
	else // buffer is full
	{
		T* newData=new T[m_n+add];
		for(size_t i=0;i<m_n;i++)
			newData[i]=m_data[(m_first+i) % m_cap];
		delete[] m_data;
		m_data=newData;
		m_first=0;
		m_last=m_n-1;
		m_cap+=add;
	}
}

template <typename T>
T MyQueue<T>::pop()
{
	// check empty!!!!!!!
	m_n--;
	T tmp=m_data[m_first];
	m_first=(m_first+1) % m_cap;
	return tmp;
}

template <typename T>
MyQueue<T>::~MyQueue()
{
	delete[] m_data;
}