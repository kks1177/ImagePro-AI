// for_while.cpp

#include <stdio.h>

int main()
{
	// 1���� 10���� ����ض�.
	/*
	 //Ctrl + k + c : ���ÿ��� �ּ�
	 //Ctrl + k + u : ���ÿ��� �ּ� ����
	for (int i = 1; i < 11; i++) {
		printf("%d\n", i);
	}
	*/

	/*
	printf("%d\n", 1);
	printf("%d\n", 2);
	printf("%d\n", 3);
	*/

	// 100���� 1������ �հ��?
	/*
	int hap = 0;
	for (int i = 100; i >= 1; i--) {
		hap += i;
	}
	printf("%d ", hap);
	*/

	// 1,1 --> 1,2 --> 1,3 --> 2,1 --> 2,2 --> 2,3, .... --> 4,3 ���
	for (int i = 1; i <= 4; i++) {
		for (int k = 1; k <= 3; k++) {
			printf("%d,%d \n", i, k);
		}
	}
}


