template <typename T, size_t MaxN>
class MyStack
{
	T m_data[MaxN];
	size_t m_size;
public:
	MyStack();
	MyStack(size_t N, T&& val=T());

	template <typename K>
	void push(K&& elem)
	{
		wrap_push(std::forward<T>(elem));
	}

	void wrap_push(T&&);

	T pop(); //throw(std::out_of_range);
	T& operator[](size_t ind); //throw(std::out_of_range);
};


template <typename T, size_t MaxN>
MyStack<T,MaxN>::MyStack()
{
	for(size_t i=0;i<MaxN;i++)
		m_data[i]=T();
	m_size=MaxN;
}

template <typename T, size_t MaxN>
MyStack<T,MaxN>::MyStack(size_t N, T&& val)
{
	if(N>MaxN)
		throw std::out_of_range("Failed to create MyStack. Number of elements is more than capacity.");
	m_size=N;
	for(size_t i=0;i<N;i++)			
		m_data[i]=val;

}

template <typename T, size_t MaxN>
void MyStack<T,MaxN>::wrap_push(T&& elem)
{
	if(m_size==MaxN)
		throw std::out_of_range("Can't insert an element. MyStack is full.");
	m_data[m_size]=elem;
	m_size++;
}

template <typename T, size_t MaxN>
T MyStack<T,MaxN>::pop()
{
	if(m_size==0)
		throw std::out_of_range("The element can not be taken. MyStack is empty.");
	return std::move(m_data[m_size--]);	
}

template <typename T, size_t MaxN>
T& MyStack<T,MaxN>::operator[](size_t ind)
{
	if(ind<m_size)
		return m_data[ind];
	else
		throw std::out_of_range("Wrong index!");
}

