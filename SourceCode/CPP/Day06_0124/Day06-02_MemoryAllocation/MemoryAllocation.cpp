// MemoryAllocation.cpp
// �޸� �Ҵ�

// Pointer01.cpp

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	// ���� �迭 --> ����ڰ� �Է��ϴ� ũ�⸸ŭ ...
	int SIZE;
	printf("�� �� : ");
	scanf("%d", &SIZE);

	int* p;
	p = (int*)malloc(SIZE * sizeof(int));		// malloc : MemoryAllocate(�޸� �Ҵ�)

	int value = 200;
	for (int i = 0; i < SIZE; i++) {
		p[i] = value++;
	}
	printf("%d \n", p[SIZE-1]);		// SIZE-1 : ������ ��ġ�� ��
	
	free(p);		// �޸� �Ҵ� ����(��ȯ) -> �ü������

	printf("���α׷� ��! \n");
}


