// Mission1_ImageProcessing.cpp
// 0119_�̼�	

// �̼�1. 20 ũ�� �迭 �غ�, �� �迭�� 1~99���� ���� ��, �迭 ���
/*	
* (�̼�1-1.) �迭���� ���� ū ���� �� ��ġ ���
* (�̼�1-2.) �迭���� ���� ���� ���� �� ��ġ ���
* (�̼�1-3.) �迭�� ��հ� ���
* (<��ȭ>�̼�1-4.) �迭�� �߾Ӱ� ���
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>		// rand
#include <stdlib.h>		// rand
using namespace std;

const int SIZE = 20;
int ary[SIZE];
int temp = 0;

void aryInit();		// �迭 �ʱ�ȭ
void arrayRand();	// �迭 ������
void printArray();	// �迭 ���

void findMaxValue();	// �迭 �� ���� ū ���� �ش� ��ġ ã��
void findMinValue();	// �迭 �� ���� ���� ���� �ش� ��ġ ã��
void aryAvr();			// �迭 ��հ�
void aryMid();			// �迭 �߾Ӱ�


int main()
{
	// �迭 �ʱ�ȭ
	aryInit();

	// �迭 ���� ��
	arrayRand();

	// �迭 ���
	printArray();
	printf("\n\n");

	// �迭 �� ���� ū ���� �ش� ��ġ ã��
	findMaxValue();
	// �迭 �� ���� ���� ���� �ش� ��ġ ã��
	findMinValue();
	
	// �迭 ��հ�
	aryAvr();

	// �迭 �߾Ӱ�
	aryMid();
}


// �迭 �ʱ�ȭ
void aryInit() {
	for (int i = 0; i < SIZE; i++) {
		ary[i] = 0;
	}
}

// �迭 ������
void arrayRand() {
	unsigned char data;
	srand((int)time(NULL));		// ���� �ʱ�ȭ
	for (int i = 0; i < SIZE; i++) {
		data = rand() % 100;		// ���Ͽ��� �� �� �б�
		ary[i] = data;
	}
}

// �迭 ���
void printArray() {
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", ary[i]);
	}
}

// �迭 �� ���� ū ���� �ش� ��ġ ã��
void findMaxValue() {
	int maxValue = ary[0];
	for (int i = 0; i < SIZE; i++) {
		if (ary[i] > maxValue) {
			maxValue = ary[i];
			temp = i;
		}
	}
	printf(" ����   ū �� : %d, ��ġ : %d\n", maxValue, temp);
}

// �迭 �� ���� ���� ���� �ش� ��ġ ã��
void findMinValue() {
	int minValue = ary[0];
	for (int i = 0; i < SIZE; i++) {
		if (ary[i] < minValue) {
			minValue = ary[i];
			temp = i;
		}
	}
	printf(" ���� ���� �� : %d, ��ġ : %d\n", minValue, temp);
}

// �迭 ��հ�
void aryAvr() {
	int hap = 0;
	int avr = 0;

	for (int i = 0; i < SIZE; i++) {
		hap += ary[i];
	}
	avr = hap / SIZE;
	printf("\n ��� �� : %d \n", avr);
}

// �迭 �߾Ӱ�
void aryMid() {
	int mid = 0;
	int temp = 0;
	int arySort1[SIZE] = {0, 0};

	//// �迭 ���� ////
	for (int i = 0; i < SIZE-1; i++) {
		for (int k = i+1; k < SIZE; k++) {
			if (ary[i] > ary[k]) {
				temp = ary[i];
				ary[i] = ary[k];
				ary[k] = temp;
			}
		}
	}
	printf("\n �߾Ӱ� : %d\n", ary[(SIZE - 1) / 2]);
}
