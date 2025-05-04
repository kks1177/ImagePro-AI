// Quiz04-03.cpp

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string>
using namespace std;	// C++ �߰� ���

// ���� ������ (�߿�!)
const char filename[100] = "C:\\images\\Etc_Raw(squre)\\flower512.raw";
const int ROW = 512, COL = 512;
unsigned char image[ROW][COL];

void printScreen();
void plusScreen();
void subScreen();
void GrayScaleScreen();

int main()
{
	//// ���� ���� ////
	FILE* rfp = fopen(filename, "rb");		// rb: Read Binary

	// 512x512 �� �ݺ��ؼ� �аų�, �ѹ濡 512,512 �аų�
	fread(image, sizeof(unsigned char), ROW * COL, rfp);

	//// ���� �ݱ� ////
	fclose(rfp);

	printf("\n\t < ���� ���� > \n");
	printScreen();
	printf("======================================");

	plusScreen();
	subScreen();
	GrayScaleScreen();

	printf("\nó�� ��~\n");
}

// �̹����� ȭ�� ���
void printScreen() {
	for (int i = 100; i < 110; i++) {
		for (int k = 100; k < 110; k++) {
			printf("%3d ", image[i][k]);
		}
		printf("\n");
	}
	printf("\n");
}

// ���� 50 ��� �ϱ�
void plusScreen() {
	int value = 50;
	for (int i = 100; i < 110; i++) {
		for (int k = 100; k < 110; k++) {
			int px = image[i][k] + value;
			if (px > 255) {
				image[i][k] = 255;
			}
			else {
				image[i][k] += value;
			}
		}
	}
}

// ���� 100 ��Ӱ� �ϱ�
void subScreen() {
	int value = 100;
	for (int i = 100; i < 110; i++) {
		for (int k = 100; k < 110; k++) {
			int px = image[i][k] - value;
			if (px > 255) {
				image[i][k] = 255;
			}
			else {
				image[i][k] -= value;
			}
		}
	}
}

// ���� ��� ó��
void GrayScaleScreen() {
	int value = 127;
	for (int i = 0; i < 110; i++) {
		for (int k = 0; k < 110; k++) {
			int px = image[i][k];
			if (px > value) {
				image[i][k] = 255;
			}
			else {
				image[i][k] = 0;
			}
		}
	}
}


