// String.cpp

using namespace std;
#include <string>
#include <stdio.h>

#define UI unsigned int

int main()
{
	// ������
	char ch1 = 'A';
	char ch2 = 127;
	unsigned char ch3 = 255;
	unsigned char ch4 = 0;

	short sh1 = -32768;
	unsigned short sh2 = 65535;

	int in1 = -2147483648;
	UI in2 = 4200000000;

	// ���� �� ���ڿ�
	char cc1 = 'A';
	string str1 = "AAA";

	printf("%s \n", str1.c_str());

	// �Ǽ���
	float fl1 = 0.1234567890;
	printf("%20.15f \n", fl1);
	double do1 = 0.1234567890;
	printf("%20.15f \n", do1);

	// ����������
	int a = 100;
	a = a + 1;
	printf("%d \n", a);		// 101
	a += 1;
	printf("%d \n", a);		// 102
	a++;		// == (a += 1;)
	printf("%d \n", a);		// 103
	++a;
	printf("%d \n", a);		// 104

	// if��
	a = 200;

	if (a == 100) {
		printf("100 �Դϴ�.");
	}
	else {
		printf("100 �ƴմϴ�.");
	}
}

