// GreyVideoProcessing_Beta1-1.cpp

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <string>
using namespace std;	// C++ �߰� ���

// **** ������ (�߿�!) **** //
char filename[100];
const int ROW = 512, COL = 512;
unsigned char inImage[ROW][COL];		// input
unsigned char outImage[ROW][COL];		// output
HWND hwnd;		// ������ ȭ�� (�ܺ�, ������)		// �ϱ�x
HDC  hdc;		// �޵��� ȭ�� (����, ����)		// �ϱ�x

void printScreen();
void openImage();
void equalImage();				// A.����

void brightControlImage();		// B..��� ����
void reverseImage();			// C.����
void grayScaleImage();			// D.���
void L_R_mirroring();			// E.�¿� �̷���
void T_B_mirroring();			// F.���� �̷���
void turn90Right();				// G.��� �̹��� ���������� 90�� ȸ��
void turn90Left();				// H.��� �̹��� �������� 90�� ȸ��

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
	puts("\n");
	puts("\t\t\t=======================================================================");
	puts("\t\t\t                 ### �׷��� ����ó�� (Alpha 1) ###\n");
	puts("\t\t\t-----------------------------------------------------------------------");
	puts("\t\t\t 1.����  2.����  0.����  \n\n");
	puts("\t\t\t   A.����  B.���/��Ӱ�  C.����  D.���  E.�¿�̷���  F.���Ϲ̷���");
	puts("\t\t\t-----------------------------------------------------------------------\n");
}
// �޴� ����
void choiceMenu() {
	char inKey = 0;		// Ű����� �Է� �޴� ����

	printMenu();
	while (inKey != '0') {
		inKey = _getch();

		switch (inKey) {
		case '0':	break;
		case '1':
			system("cls");
			printMenu();
			openImage();
			break;
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
	hwnd = GetForegroundWindow();		// �߿����� ���� �ڵ�
	hdc = GetWindowDC(hwnd);			// �߿����� ���� �ڵ�

	choiceMenu();

	printf("�ȳ��� ������~");
}

// �̹����� ȭ�� ���
void printScreen() {
	//system("cls");
	int px = 0;

	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			px = outImage[i][k];
			SetPixel(hdc, k+50, i+300, RGB(px, px, px));		// hdc�� �������ִ� �Լ�		// i, k -> k+50, i+250
		}
	}
}

// ���� ����
void openImage() {
	char fullName[100] = "C:\\images\\Pet_RAW(squre)\\Pet_RAW(512x512)\\";		// ���� \\ �ٿ�����!
	char tmpName[100] = { 0 };

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

	equalImage();
	printf("------------------------------------------------\n");

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
}

// �̹��� ���� ó��
void reverseImage() {
	equalImage();
	printf("------------------------------------------------\n");

	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			outImage[i][k] = 255 - inImage[i][k];
		}
	}
	printf("\n\t< ���� ���� ȭ�� > \n");
	printScreen();
}

// �̹��� ��� ó��
void grayScaleImage() {
	equalImage();
	printf("------------------------------------------------\n");

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
}

// �̹��� �¿� �̷���
void L_R_mirroring() {
	equalImage();
	printf("------------------------------------------------\n");

	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			outImage[i][k] = inImage[i][COL - 1 - k];	// (�ִ뿭 - 1) - �ݺ���
		}
	}
	printf("\t< ���� �¿� �̷��� ȭ�� > \n");
	printScreen();
}

// �̹��� ���� �̷���
void T_B_mirroring() {
	equalImage();
	printf("------------------------------------------------\n");

	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			outImage[i][k] = inImage[ROW - 1 - i][k];		// (�ִ��� - 1) - �ݺ���
		}
	}

	printf("\t< ���� ���� �̷��� ȭ�� > \n");
	printScreen();
}

// ��� �̹��� ���������� 90�� ȸ��
void turn90Right() {
	equalImage();
	printf("------------------------------------------------\n");
}

// ��� �̹��� �������� 90�� ȸ��
void turn90Left() {
	equalImage();
	printf("------------------------------------------------\n");
}

// ��� �̹��� 180�� ȸ��


// ��հ����� ���ó��


// �߾Ӱ����� ���ó��

