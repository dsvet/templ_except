template <typename T> 
void Swap(T& x, T& y)
{	
	T tmp=std::move(x);
	x=std::move(y);
	y=std::move(tmp);
}

template <> 
void Swap(MyString& x, MyString& y)
{
	char* tmp=x.m_pStr;
	x.m_pStr=y.m_pStr;
	y.m_pStr=tmp;
}
