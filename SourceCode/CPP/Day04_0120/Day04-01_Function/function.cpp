// function.cpp
// �Լ�

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string>
using namespace std;

int plusNumber(int n1, int n2);

int main()
{
	int num1 = 100, num2 = 200;
	int result;

	// �� ���ڸ� ���ϴ� �˰����� ����
	result = plusNumber(num1, num2);

	// ���
	printf("%d + %d = %d \n", num1, num2, result);
}


// �� ���ڸ� ���ϴ� �˰����� ����
int plusNumber(int n1, int n2) {
	int res;		// result -> res
	res = n1 + n2;

	return res;
}

