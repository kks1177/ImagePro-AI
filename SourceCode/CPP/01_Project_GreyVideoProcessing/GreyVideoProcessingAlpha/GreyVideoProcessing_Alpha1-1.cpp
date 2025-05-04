// GreyVideoProcessing_Alpha1-1.cpp

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <conio.h>
using namespace std;	// C++ �߰� ���

char filename[100];
const int ROW = 512, COL = 512;
unsigned char inImage[ROW][COL];		// input
unsigned char outImage[ROW][COL];		// output

void printScreen();
void openImage();
void equalImage();				// ����

void brightControlImage();		// ��� ����
void reverseImage();			// ����
void grayScaleImage();			// ���

// �޴� ����		// ���� �����ؾ� �ϹǷ� ��ܿ� ��ġ
void printMenu() {
	puts("\n ## �׷��� ����ó�� (Alpha 1) ##\n");
	puts(" 0.����  1.����  9.����\n");
	puts(" A.����  B.���/��Ӱ�  C.����  ....\n");
}
// �޴� ����
void choiceMenu() {
	char inKey = 0;		// Ű����� �Է� �޴� ����

	while (inKey != '9') {
		printMenu();
		inKey = _getch();
		system("cls");

		switch (inKey) {
		case '0':	openImage(); 	break;
		case '9':	break;
		case 'A':
		case 'a':
			equalImage();
			break;
		case 'B':
		case 'b':
			brightControlImage();
			break;
		case 'C':
		case 'c':
			reverseImage();
			break;
		}
	}
}

int main()
{
	choiceMenu();

	printf("�ȳ��� ������~");
}

// �̹����� ȭ�� ���
void printScreen() {
	for (int i = 100; i < 110; i++) {
		for (int k = 100; k < 110; k++) {
			printf("%3d ", outImage[i][k]);
		}
		printf("\n");
	}
	printf("\n");
}

// ���� ����
void openImage() {
	char fullName[100] = "C:\\images\\Pet_RAW(squre)\\Pet_RAW(512x512)\\";		// ���� \\ �ٿ�����!
	char tmpName[100];

	printf(" ���ϸ� --> ");	// cat01, dog13
	scanf("%s", tmpName);
	strcat(fullName, tmpName);		// strcat : ���ڿ��� �̾���
	strcat(fullName, "_512.raw");
	strcpy(filename, fullName);

	//// ���� ���� ////
	FILE* rfp = fopen(filename, "rb");		// rb: Read Binary

	// 512x512 �� �ݺ��ؼ� �аų�, �ѹ濡 512,512 �аų�
	fread(inImage, sizeof(unsigned char), ROW * COL, rfp);

	//// ���� �ݱ� ////
	fclose(rfp);

	equalImage();
}


// ***** ���� ó�� �Լ� ���� ***** //
// 
void equalImage() {
	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			outImage[i][k] = inImage[i][k];
		}
	}
	printScreen();
}

// �̹��� ��� ����
void brightControlImage() {
	int value;
	printf("����� �� --> ");
	scanf("%d", &value);

	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			int px = inImage[i][k] + value;		// px : pixel

			if (px > 255)
				px = 255;
			else if (px < 0)
				px = 0;

			outImage[i][k] = px;
		}
	}
	printScreen();
}

// �̹��� ���� ó��
void reverseImage() {
	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			outImage[i][k] = 255 - inImage[i][k];
		}
	}
	printScreen();
}

// �̹��� ��� ó��


// �̹��� �¿� �̷���


// �̹��� ���� �̷���


// ��� �̹��� 90�� ȸ��


// ��� �̹��� 180�� ȸ��


// ��հ����� ���ó��


// �߾Ӱ����� ���ó��

