// Mission4_ImageProcessing.cpp

// �̼�4. 1000 ũ�� �迭 �غ�, 1~1000������ ���� �� �Ҽ� ����
// �迭���� �Ҽ��� �հ踦 ���� ���

# define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SIZE 1000

int main()
{
	int ary[SIZE] = { 0, };
	int cnt = 0;		// ������ ���������� Ȯ���ϱ� ���� ���� ����

	// �Ҽ��� �̹Ƿ� 1 ����
	for (int i = 2; i <= SIZE; i++) {
		for (int k = 2; k < i; k++) {
			// ������ ������[�ٸ� i�� k ���̿� ����� �������� �ǹ�
			if (i % k == 0) {
				cnt = 1;
				break;
			}
		}
		// ����� ������ �Ҽ�
		if (cnt == 0) {
			printf("%3d ", i);
			ary
		}
		cnt = 0;
	}

	for (int i = 0; i < )
	printf("\n\n 1~1000���� �Ҽ��� �հ� : %d \n", hap);

	return 0;
}


