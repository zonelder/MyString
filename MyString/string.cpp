#include "string.h"
//вспомогательные функции
void ToLower(char& ch)//сторонние бибилиотеки использвоать нельзя по этому написал свою
{
	//оставляю разность не вычисленной для читаемости,хотя это замедляет программу.Делаю так потому что этот код не пройдет куда-то дальше, а логику уловить так проще
	if (ch >= 65 && ch <= 90)//большие анг буквы
		ch += (97 - 65);//это смещение в таблиице аски при которой в таблице записана та же буква низкого регистра(для примера A-65 позиция,a-97)
	if (ch >= -64 && ch <= -33)//большие русские буквы от А до Я
		ch += (64 - 32);// (А-(-64),а-(-32))


}
size_t str_len(const char* str)
{
	if (str == NULL)
	{
		return 0;
	}
	const char* copy = str;
	for (; *copy; ++copy);//ищем '\0'
	return copy - str;
}
//
String::String()
{
	ptr = nullptr;
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
	if (this != &rhs)//проверяем не копируемм ли мы сами себя
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
	if (this != &rhs)//проверяем не копируемм ли мы сами себя
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
	String sumStr;
	sumStr.size = left.size + right.size;
	sumStr.ptr = new char[sumStr.size + 1];
	
	unsigned int i = 0;
	for (; i < left.size; ++i)
	{
		*(sumStr.ptr + i) = *(left.ptr + i);
	}
	for (unsigned int j = 0; j < right.size; ++j,++i)
	{
		*(sumStr.ptr + i) = *(right.ptr + j);
	}
	*(sumStr.ptr + sumStr.size) = '\0';
	return sumStr;
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
	return true;//если мы цикл закончили то все позиции совпадают  и левая строка не больше правой.

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
		return false;//строки полностью идентичны
	else
		return true;//левая строка меньше правой по длинне 
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