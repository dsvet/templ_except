template <typename T>
class MyQueue
{
	T* m_data;
	size_t m_cap;
	size_t m_n;
	size_t m_first, m_last;
public:
	MyQueue(size_t);
	~MyQueue();

	void push(const T&);
};

template <typename T>
MyQueue<T>::MyQueue(size_t cap=10)
{
	m_cap=cap;
	T=new T[cap];
	m_n=0;
	m_first=m_last=0;
}

template <typename T>
void MyQueue<T>::push(const T& data)
{
	if(m_n<m_cap)
	{
		//if(m_first<m_last && m_last<m_cap)
		//{
		//	m_data[m_last]=data;
		//	m_last=m_first+m_n;
		//	m_n++;
		//}
		//else if(m_last==m_cap)
		//{
		//	m_last=0;

		//}
	}
}