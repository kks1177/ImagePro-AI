// BinaryFileProcessing.cpp
// 2������ ó��

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string>
using namespace std;	// C++ �߰� ���

char filename[100];
const int ROW = 512, COL = 512;
unsigned char inImage[ROW][COL];		// input
unsigned char outImage[ROW][COL];		// output

void printScreen();
void openImage();
void equalImage();
void addImage();

int main()
{
	//// ���� ���� ////
	openImage();

	//// ���� ó�� ////
	//addImage();


	printf("ó�� ��~");
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
	printScreen();
}


// ***** ���� ó�� �Լ� ���� ***** //
// 
void equalImage() {
	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			outImage[i][k] = inImage[i][k];
		}
	}
}

// �̹��� ��� ����
void addImage() {
	int value;
	printf("����� �� --> ");
	scanf("%d", &value);

	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			int px = inImage[i][k] + value;		// px : pixel,		unsigned int ���ϴ� ���� Ȯ��!!!
		
			if (px > 255)
				px = 255;
			else if (px < 0)
				px = 0;
			outImage[i][k] = px;
		}
	}
	printScreen();
}

