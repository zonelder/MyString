#include "string.h"
//��������������� �������
void ToLower(char& ch)//��������� ����������� ������������ ������ �� ����� ������� ����
{
	//�������� �������� �� ����������� ��� ����������,���� ��� ��������� ���������.����� ��� ������ ��� ���� ��� �� ������� ����-�� ������, � ������ ������� ��� �����
	if (ch >= 65 && ch <= 90)//������� ��� �����
		ch += (97 - 65);//��� �������� � �������� ���� ��� ������� � ������� �������� �� �� ����� ������� ��������(��� ������� A-65 �������,a-97)
	if (ch >= -64 && ch <= -33)//������� ������� ����� �� � �� �
		ch += (64 - 32);// (�-(-64),�-(-32))


}
size_t str_len(const char* str)
{
	if (str == NULL)
	{
		return 0;
	}
	const char* copy = str;
	for (; *copy; ++copy);//���� '\0'
	return copy - str;
}
//
String::String()
{
	ptr = new char[1];
	*ptr = '\0';//������ ������
	size = 0;
}
String::String(const char* _ptr)
{
	size = str_len(_ptr);
	delete[]ptr;
	ptr = new char[size + 1];
	for (unsigned int i = 0; i < size; ++i)
		*(ptr + i) = *(_ptr + i);
	*(ptr + size) = '\0';
}
String::String(const String& rhs)
{
	if (this != &rhs)//��������� �� ��������� �� �� ���� ����
	{
		//std::cout << "copy constructor was called\n";
		size = rhs.size;
		delete[]ptr;
		ptr = new char[size + 1];
		for (unsigned int i = 0; i < size; ++i)
		{
			*(ptr + i) = *(rhs.ptr + i);
		}
		*(ptr + size) = '\0';
	}
}

String::String(String&& rhs) noexcept {
	delete[]ptr;
	ptr = rhs.ptr;
	size = rhs.size;
	rhs.ptr = nullptr;
	rhs.size = 0;
}
String & String:: operator=(const String& rhs)
{
	if (this != &rhs)//��������� �� ��������� �� �� ���� ����
	{
		//std::cout << "copy constructor was called\n";
		size = rhs.size;
		delete[]ptr;
		ptr = new char[size + 1];
		for (unsigned int i = 0; i < size; ++i)
		{
			*(ptr + i) = *(rhs.ptr + i);
		}
		*(ptr + size) = '\0';
	}
	return *this;
}
String & String::operator=(String&& rhs) noexcept
{
	delete[]ptr;
	ptr = rhs.ptr;
	size = rhs.size;
	rhs.ptr = nullptr;
	rhs.size = 0;
	return*this;
}
String  operator+(const String& left, const String& right)
{
	unsigned int sumSize = left.size + right.size;
	char* sumPtr = new char[sumSize + 1];
	for (unsigned int i = 0; i < left.size; ++i)
	{
		*(sumPtr + i) = *(left.ptr + i);
	}
	char* ptrToEnd = sumPtr + left.size;
	for (unsigned int i = 0; i < right.size; ++i)
	{
		*(ptrToEnd + i) = *(right.ptr + i);
	}
	*(sumPtr + sumSize) = '\0';
	String sum(sumPtr);
	delete[]sumPtr;
	return sum;
}
bool operator<=(const String& lOperand, const String& rOperand) 
{
	for (unsigned int i = 0; i < lOperand.size; ++i)
	{
		if (i >= rOperand.size)
			return false;
		char firstCh = *(lOperand.ptr + i);
		char secondCh = *(rOperand.ptr + i);
		ToLower(firstCh);
		ToLower(secondCh);
		if (firstCh < secondCh)
		{
			return true;
		}
		if (firstCh == secondCh)
		{
			continue;
		}
		if (firstCh > secondCh)
		{
			return false;
		}
	}
	return true;//���� �� ���� ��������� �� ��� ������� ���������  � ����� ������ �� ������ ������.

}

bool operator<(const String& lOperand, const String& rOperand)
{
	for (unsigned int i = 0; i < lOperand.size; ++i)
	{
		if (i >= rOperand.size)
			return false;
		char firstCh = *(lOperand.ptr + i);
		char secondCh = *(rOperand.ptr + i);
		ToLower(firstCh);
		ToLower(secondCh);
		if (firstCh < secondCh)
		{
			return true;
		}
		if (firstCh == secondCh)
		{
			continue;
		}
		if (firstCh > secondCh)
		{
			return false;
		}
	}
	if (lOperand.size == rOperand.size)
		return false;//������ ��������� ���������
	else
		return true;//����� ������ ������ ������ �� ������ 
}

bool operator>(const String& lOperator, const String& rOperand)
{
	return !(lOperator <= rOperand);
}
std::ostream& operator<<(std::ostream& os, const String& const str)
{
	if (str.ptr != nullptr)
	{
		char* pos_ptr = str.ptr;
		for (; *pos_ptr; ++pos_ptr)
			os << *pos_ptr;
	}
	return os;
}


String::~String()
{
	delete[]ptr;
}