// Pointer01.cpp

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// �����迭, �����迭
int main()
{
	// ���ݺ��� ���� �Է��ϴ� ���ڵ��� �����ϰ�, �հ踦 ����.
	// �迭�� �غ��ؾ� ��.

	// ���1. �迭�� ����� ũ�� �غ�

	// ���2. �迭�� ũ�⸦ �Է¹ޱ�.
	/*
	int SIZE;
	printf("���� � �Է�? ");
	scanf("%d", &SIZE);
	
	int ary[SIZE] = { 0 };		// error.. �迭���� ������ ���� �� ����. �����..
	*/

	/*
	int a = 100;
	int b = 200;

	printf("%ld \n", &a);
	printf("%ld \n", &b);
	*/

	/*
	int aa[3] = { 10, 20, 30 };
	printf("%d, %x \n", aa[0], &aa[0]);		// �迭�� �̸�(aa)�� ������ �ƴ�, ������ ���
	printf("%d, %x \n", aa[1], &aa[1]);
	printf("%d, %x \n", aa[2], &aa[2]);

	printf("%x \n", aa);
	*/

	// �������� ���� ���� �� �ִ�.
	// ���� �տ� &�� ���̸�, ������ �ƴ϶� ������ �޸𸮻��� ������ �ǹ�
	// �� 1035 ���� �ּҰ�.. 
	// &a�� ������ �ƴ϶� ������ �����.
	// �迭�� aa[0]�� ������. &aa[0] ==> ��� (1039)
	// �迭�� �̸� aa�� ������ �����. (1039)


	/*
	char ch;		// ���� ��� ����
	char* p;		// �ּ� ��� ����

	ch = 'A';
	p = &ch;

	printf("%c, %x \n", ch, &ch);		// ch�� ��� ����, ch �ּҰ�
	printf("%x, %x \n", p, &p);			// ch�� �ּҰ�, p�� �ּҰ�

	printf("%c \n", *p);	// ch�� ��� ����
	*/

	
	// �� ���� �ٲٱ�.
	/*
	char ch1 = 'A', ch2 = 'Z';
	char* p;
	char* q;
	char tmp;

	p = &ch1;
	q = &ch2;
	tmp = *p;
	*p = *q;
	*q = tmp;

	printf("%c  %c", ch1, ch2);
	*/


	// �迭�� ������
	char s[8] = "Basic-C";
	char* p;

	p = s;

	printf("%c \n", *(p + 0));		// s[0] == *(p+0) == *p == p[0]
	printf("%c \n", *(p + 1));		// *(p+1) == *p+1
	*(p + 2) = '$';

	printf("%s \n", s);
	printf("%s \n", p);
}



