// Quiz03-02.cpp

#include <stdio.h>

// ���� 3-1.
/*
100��¥�� 1���� �迭�� �غ�
100���� 1���� ����
�հ� ���
*/
/*
int main()
{
	const int ARY_SIZE = 100;
	int ary[ARY_SIZE];
	int value = 100;
	int hap = 0;		// hap �� long Ÿ�� ����

	for (int i = 0; i < 100; i++) {		// **���� �������** for���� i�� �迭�� ÷��(ary[i]) �뵵�θ� ���
		ary[i] = value;
		value--;

		hap += ary[i];
	}
	printf("�հ� : %d \n", hap);
}
*/

// ���� 3-2.
/*
20��¥�� �迭 2�� �غ�
�� �迭���� 3�� ��� ����
�� �迭���� �� �迭�� ������ �Ųٷ� ����
�� �迭�� ���
*/

///*
int main()
{
	const int ARY_SIZE = 20;
	int ary1[ARY_SIZE], ary2[ARY_SIZE];
	int value = 3;

	for (int i = 0; i < ARY_SIZE; i++) {
		ary1[i] = value;
		value += 3;
		printf("%d ", ary1[i]);
	}
	printf("\n\n");
	for (int i = 0; i < ARY_SIZE; i++) {
		ary2[i] = ary1[(ARY_SIZE - 1) - i];
		printf("%d ", ary2[i]);
	}
	printf("\n");
}
//*/

