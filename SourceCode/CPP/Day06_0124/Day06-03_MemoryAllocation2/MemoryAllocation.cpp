// MemoryAllocation.cpp

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int row = 5, col = 9;	// ������ ����
	// ���� int ary[row][col];

	int** p;
	//malloc(row * sizeof(int));		// �ɰ��� ����.. ������ ���ư����� char������ �� ��� ��罺ũ���� ��
	
	p = (int**)malloc(row * sizeof(int*));
	for (int i = 0; i < row; i++) {
		p[i] = (int*)malloc(col * sizeof(int));
	}

	// p[3][4] ����� Ȱ��..

	// �޸� ����
	for (int i = 0; i < row; i++) {
		free(*p[i]);
	}
	free(p);
}

