// Quiz03-01.cpp

#include <stdio.h>

// ���� 1-1. 1���� 100���� ���, ��... �� �� �Ѿ�� ��ĭ ����
/*
int main()
{
	for (int i = 1; i < 101; i++) {
		printf("%d ", i);
	}
}
*/


// ���� 1-2. 123���� 456���� ���. ��
/*
int main()
{
	for (int i = 123; i < 457; i++) {
		printf("%d ", i);
	}
}
*/


// ���� 1-3. 1���� 100���� Ȧ���� ���. ��
/*
int main()
{
	for (int i = 1; i < 101; i += 2) {
		printf("%d ", i);
	}
}
*/


// ���� 1-4. 12345���� 67890���� 839�� ����� ���. ��
/*
int main()
{
	for (int i = 12345; i < 67891; i++) {
		if (i % 839 == 0) {
			printf("%d ", i);
		}
	}
}
*/


// ���� 1-5. 2���� 1000������ �Ҽ��� ���. 
/*
int main()
{
	for (int i = 2; i < 1001; i++) {
		for (int k = 2; k < i; k++) {
			if (i % k == 0)
				break;
		}
		if (i == k) {
			printf("%d ", i);
		}
	}
}
*/


// ���� 2-1. ������ ����ϱ�
/*
int main()
{
	for (int i = 2; i <= 9; i++) {
		for (int k = 1; k <= 9; k++) {
			printf("%d x %d = %d \n", i, k, i * k);
		}
		printf("\n");
	}
}
*/


// ���� 2-2. ������ å��ħ ����ϱ�
int main()
{
	for (int i = 2; i <= 9; i++) {
		for (int k = 1; k <= 9; k++) {
			printf("%3d x %d = %2d \t", i, k, i * k);
		}
	}
}


// ���� 2-3. ������ å��ħ �Ųٷ� ����ϱ�
int main()
{
	for (int k = 1; k <= 9; k++) {
		for (int i = 2; i <= 9; i++) {

		}
	}
}





