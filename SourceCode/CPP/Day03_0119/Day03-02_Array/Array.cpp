// Array.cpp

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string>
using namespace std;

int main()
{
	// for ���� �迭�� ���� ����
	const int SIZE = 5;		// const : ���ȭ��Ŵ
	int ary[5];
	int hap = 0;

	for (int i = 0; i < SIZE; i++) {			// i --> �迭�� ÷�� �뵵
		scanf("%d", &ary[i]);
		hap += ary[i];
	}
	printf("�հ� --> %d \n", hap);
}

