#define _CRTDBG_MAP_ALLOC 
#include <stdlib.h>
#include <crtdbg.h>  
//��� �������� �� ������ ������
#include "string.h"


//� �������� ���������� ���� vector,���������� ����� ��������� ����� sort()
#include<vector>
#include <algorithm>
#include<iostream>

std::greater<String> reverse_lexographic_order;//����������� ��� ������� sort
std::less<String> lexographic_order;
int main()
{
	
	{//������ ���� ����� ��� ���������� ���� ���������� � �� ������������ ��� ����� ���������

	std::vector<String> v= { "124", "123"};
	v.at(1) = "2AV";
	v.push_back(String("ACDC") + String("abDC"));//�������� �� ����������������� ��������
	v.push_back(v.at(0));//��������� ����������� ����������� 
	v.push_back(String("3"));
	v.push_back(String("abc"));
	v.push_back(String("ABC"));
	v.push_back(String("0999999"));
	v.push_back(String("abc"));
	v.push_back(String());
	v.push_back(String("3251"));
	v.push_back(String(""));


	sort(v.begin(), v.end(), reverse_lexographic_order);//���������
	for (int i = 0; i < v.size(); ++i)
		{
		std::cout << v.at(i)<< "\n";
		}
	
	}
	_CrtDumpMemoryLeaks();//��������� �� ������
	return 0;
}