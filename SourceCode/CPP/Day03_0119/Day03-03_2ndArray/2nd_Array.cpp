// 2nd_Array.cpp

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string>
using namespace std;

int main()
{
	const int ROW = 3, COL = 4;
	int ary2[ROW][COL];
	int initValue = 0;
	
	// �迭�� ���� ��� 0���� �ʱ�ȭ�϶�.
	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			ary2[i][k] = initValue;
		}
	}
}


