// ����.cpp 


#include <string>
#include <stdio.h>
using namespace std;

int main()
{
	char str1[10] = "AAA";				// C Style
	printf("%s \n", str1);				// AAA

	string str2 = "BBB";				// C++ Style, cout ������� �ʱ� ���� -> printf("%s \n", ���ڿ�.c_str()) ���
	printf("%s \n", str2.c_str());		// BBB		// c_str() �Լ� : string�� C style�� ���ڿ��� �ٲ� �� ����ϴ� �Լ� (���� : const char*)

	
	//string str3 = "CCC";
	//printf("%s \n", str3);					// garbage value
}


#include <iostream>
#include <string.h>

