// Quiz04-01.cpp
// ����1.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string>
using namespace std;

int plusNumber(int n1, int n2);
int subNumber(int n1, int n2);		// sub : subtract
int mulNumber(int n1, int n2);		// mul : multiply
float divNumber(int n1, int n2);	// div : divide
int remNumber(int n1, int n2);		// rem : remainder 

int main()
{
	int num1 = 100, num2 = 200;
	int result;
	float result2;

	// ���ϱ�
	result = plusNumber(num1, num2);
	printf("%d + %d = %d \n", num1, num2, result);

	// ����
	result = subNumber(num1, num2);
	printf("%d - %d = %d \n", num1, num2, result);

	// ���ϱ�
	result = mulNumber(num1, num2);
	printf("%d * %d = %d \n", num1, num2, result);

	// ������
	if (num2 != 0) {
		result2 = divNumber(num1, num2);
		printf("%d / %d = %.1f \n", num1, num2, result2);
	}
	else
		printf("�̷��� ���ô�.... \n");

	// ������
	result = remNumber(num1, num2);
	printf("%d %% %d = %d \n", num1, num2, result);
}


// �� ���ڸ� ���ϴ� �˰����� ����
int plusNumber(int n1, int n2) {
	int res;		// result -> res
	res = n1 + n2;

	return res;
}
// �� ���ڸ� ���� �˰����� ����
int subNumber(int n1, int n2) {
	int res;
	res = n1 - n2;

	return res;
}
// �� ���ڸ� ���ϴ� �˰����� ����
int mulNumber(int n1, int n2) {
	int res;
	res = n1 * n2;

	return res;
}
// �� ���ڸ� ������ �˰����� ����
float divNumber(int n1, int n2) {
	float res;
	res = (float)n1 / n2;

	return res;
}
// �� ������ ������ �˰����� ����
int remNumber(int n1, int n2) {
	int res;
	res = n1 % n2;

	return res;
}
