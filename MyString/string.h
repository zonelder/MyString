#pragma once
#include<iostream>
class String
{
	private:
		char* ptr=nullptr;
		unsigned int size=0;
	public:
		String();
		String(const char* _ptr);
		String(const String& rhs);
		String( String&& rhs)noexcept;
		~String();


		unsigned int Size() const;

		String& operator=(const String& rhs);
		String& operator=(String&& rhs)noexcept;
		friend String  operator+(const String& left, const String& right);

		friend bool operator<=(const String& lOperand, const String& rOperand);
		friend bool operator<(const String& lOperand, const String& rOperand);
		friend bool operator>(const String& lOperator, const String& rOperand);

		friend std::ostream& operator<<(std::ostream& os, const String& const str);


		

};
inline unsigned int String::Size() const { return size; }