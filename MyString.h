#pragma once
#include <string>


class MyString
{
	char* m_pStr;
public:
	MyString(const char* pStr=nullptr);
	MyString(const MyString&); // not using for swap (not efficient)
	MyString(MyString&&);
	~MyString(void);

	MyString& operator=(const MyString&); // not using for swap (not efficient)
	MyString& operator=(MyString&&);

	template<typename T>
	void friend Swap(MyString&, MyString&);
	
private:
	void Construct(const char*);
};

