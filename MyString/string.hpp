
#include<iostream>
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
class String
{
	private:
		char* ptr=nullptr;
		unsigned int size=0;
	public:
		unsigned int Size() { return size; }
		String() {
			ptr = new char[1];
			*ptr = '\0';//������ ������
			size = 0;
		}
		String(const char* _ptr)
		{
			size = str_len(_ptr);
			//std::cout << "size " << size << std::endl;
			delete[]ptr;
			ptr = new char[size+1];
			for (unsigned int i = 0; i < size;++i)
				*(ptr+i)=*(_ptr+i);	
			*(ptr + size) = '\0';
			//std::cout << "created with pointer\n";
		}
		String(const String& rhs)
		{
			if (this != &rhs)//��������� �� ��������� �� �� ���� ����
			{
				//std::cout << "copy constructor was called\n";
				size = rhs.size;
				delete[]ptr;
				ptr = new char[size+1];
				for (unsigned int i = 0; i < size; ++i)
				{
						*(ptr + i) = *(rhs.ptr + i);
				}
				*(ptr + size) = '\0';
			}
			
		}
		String &operator=(const String& rhs)
		{
			if (this != &rhs)//��������� �� ���������� �� ������� ���� ����
			{
				delete[]ptr;
				size = rhs.size;
					ptr = new char[size+1];
					for (unsigned int i = 0; i < size; ++i)
					{
						*(ptr+i)=*(rhs.ptr+i);
					}
					*(ptr + size) = '\0';
			}
			return *this;
		}

		friend String  operator+(const String& left, const String& right)
		{
			//std::cout << "sum was called\n";
			unsigned int sumSize = left.size + right.size;
			char* sumPtr = new char[sumSize+1];
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
		friend bool operator<=(const String& lOperand,const String& rOperand)
		{
			//lOperator.Show();
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
					//std::cout << *(ptr + i) << std::endl;
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
			//if (lOperand.size == rOperand.size)
				return true;//���� �� ���� ��������� �� ��� ������� ���������  � ����� ������ ������ ������ ���������� true
			//else
				//return false;
		}
		friend bool operator<(const String& lOperand, const String& rOperand)
		{
			//lOperator.Show();
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
					//std::cout << *(ptr + i) << std::endl;
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
			return false;//l��� ������ ���������
		else
			return true;
		}
		friend bool operator>(const String& lOperator, const String& rOperand)
		{
			return !(lOperator <= rOperand);
		}
		friend std::ostream& operator<<(std::ostream& os, const String& const str)
		{
			char* pos_ptr = str.ptr;
			for (; *pos_ptr; ++pos_ptr)
				os << *pos_ptr;
			//delete pos_ptr
			return os;
		}
		~String()
		{
			//if (size != 0)
				delete[]ptr;//���������� ������
		}

};

