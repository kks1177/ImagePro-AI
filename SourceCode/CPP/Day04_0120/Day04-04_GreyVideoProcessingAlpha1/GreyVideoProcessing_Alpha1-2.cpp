// GreyVideoProcessing_Alpha1-2.cpp

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
void equalImage();				// A.����

void brightControlImage();		// B..��� ����
void reverseImage();			// C.����
void grayScaleImage();			// D.���
void L_R_mirroring();			// E.�¿� �̷���
void T_B_mirroring();			// F.���� �̷���
void turn90Right();				// ��� �̹��� ���������� 90�� ȸ��
void turn90Left();				// ��� �̹��� �������� 90�� ȸ��

/*
 - ��� (���/��Ӱ�)
 - ����
 - ��� 
 - ���� �¿� �̷���

 - ���� ���� �̷���
 - ��� �̹��� 90�� ȸ��
 - // ��� �̹��� 180�� ȸ��
 - // ��հ����� ���ó��
 - // �߾Ӱ����� ���ó��

*/


// �޴� ����		// ���� �����ؾ� �ϹǷ� ��ܿ� ��ġ
void printMenu() {
	puts("\n ### �׷��� ����ó�� (Alpha 1) ###\n");
	puts(" 0.����  1.����  9.����\n");
	puts("   A.����  B.���/��Ӱ�  C.����  D.���  E.�¿�̷���  F.���Ϲ̷���\n\n");
}
// �޴� ����
void choiceMenu() {
	char inKey = 0;		// Ű����� �Է� �޴� ����
	
	printMenu();
	while (inKey != '9') {
		inKey = _getch();

		switch (inKey) {
		case '0':	
			system("cls");
			printMenu(); 
			openImage(); 
			break;
		case '9':	break;
		case 'A':
		case 'a':
			system("cls");
			printMenu();
			equalImage();
			break;
		case 'B':
		case 'b':
			system("cls");
			printMenu();
			brightControlImage();
			break;
		case 'C':
		case 'c':
			system("cls");
			printMenu();
			reverseImage();
			break;
		case 'D':
		case 'd':
			system("cls");
			printMenu();
			grayScaleImage();
			break;
		case 'E':
		case 'e':
			system("cls");
			printMenu();
			L_R_mirroring();
			break;
		case 'F':
		case 'f':
			system("cls");
			printMenu();
			T_B_mirroring();
			break;
		case 'G':
		case 'g':
			system("cls");
			printMenu();
			T_B_mirroring();
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

	// �ּ�(fullname) + ���ϸ�(tmpname) + _512.raw ���ؼ� --> filename����
	strcat(fullName, tmpName);		// strcat : ���ڿ��� �̾���
	strcat(fullName, "_512.raw");
	strcpy(filename, fullName);

	//// ���� ���� ////
	FILE* rfp = fopen(filename, "rb");		// rb: Read Binary

	// 512x512 �� �ݺ��ؼ� �аų�, �ѹ濡 512,512 �аų�
	fread(inImage, sizeof(unsigned char), ROW * COL, rfp);

	//// ���� �ݱ� ////
	fclose(rfp);

	printf(" ���� %s \n\n", tmpName);
	equalImage();
}


// ***** ���� ó�� �Լ� ���� ***** //
// ���� �̹���
void equalImage() {
	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			outImage[i][k] = inImage[i][k];
		}
	}
	printf("\t< ���� �̹��� ȭ�� > \n");
	printScreen();
}

// �̹��� ��� ����
void brightControlImage() {
	int value;
	printf("��� ���� �� --> ");
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
	if (value > 0) {
		printf("\t< ��� %d ���� ȭ�� > \n", value);
		printScreen();
	}
	else if (value < 0) {
		printf("\t< ��� %d ���� ȭ�� > \n", value);
		printScreen();
	}
	else {
		printf("�ٽ� �Է��ϼ���!\n");
	}

	printf("------------------------------------------------\n");
	equalImage();
}

// �̹��� ���� ó��
void reverseImage() {
	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			outImage[i][k] = 255 - inImage[i][k];
		}
	}
	printf("\n\t< ���� ���� ȭ�� > \n");
	printScreen();

	printf("------------------------------------------------\n");
	equalImage();
}

// �̹��� ��� ó��
void grayScaleImage() {
	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			int px = inImage[i][k];

			if (px >= 127) {
				px = 255;
			}
			else if (px < 127) {
				px = 0;
			}

			outImage[i][k] = px;
		}
	}
	printf("\n\t< ���� ��� ó�� ȭ�� > \n");
	printScreen();

	printf("------------------------------------------------\n");
	equalImage();
}

// �̹��� �¿� �̷���
void L_R_mirroring() { 
	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			outImage[i][k] = inImage[i][COL - 1 - k];	// (�ִ뿭 - 1) - �ݺ���
		}
	}
	printf("\t< ���� �¿� �̷��� ȭ�� > \n");
	printScreen();

	printf("------------------------------------------------\n");
	equalImage();
}

// �̹��� ���� �̷���
void T_B_mirroring() {
	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			outImage[i][k] = inImage[ROW - 1 - i][k];		// (�ִ��� - 1) - �ݺ���
		}
	}

	printf("\t< ���� ���� �̷��� ȭ�� > \n");
	printScreen();

	printf("------------------------------------------------\n");
	equalImage();
}

// ��� �̹��� ���������� 90�� ȸ��
void turn90Right() {

}

// ��� �̹��� �������� 90�� ȸ��
void turn90Left() {

}

// ��� �̹��� 180�� ȸ��



// ��հ����� ���ó��


// �߾Ӱ����� ���ó��

