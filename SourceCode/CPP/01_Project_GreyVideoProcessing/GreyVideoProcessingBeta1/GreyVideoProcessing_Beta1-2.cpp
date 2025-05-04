// GreyVideoProcessing_Beta1-2.cpp

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
char tmpName[100] = { 0 };		// ���ϸ� ���� ���� ����
const int ROW = 512, COL = 512;
unsigned char inImage[ROW][COL];		// input
unsigned char outImage[ROW][COL];		// output
HWND hwnd;		// ������ ȭ�� (�ܺ�, ������)		// �ϱ�x
HDC  hdc;		// �޵��� ȭ�� (����, ����)		// �ϱ�x

void openImage();
void printScreen(char res);
//void originImage();			// A.����
void equalImage();				// A.����

void brightControlImage();		// B.��� ����
void clearControlImage();		// C.���� ����
void reverseImage();			// D.����
void grayScaleImage();			// E.���
void L_R_mirroring();			// F.�¿� �̷���
void T_B_mirroring();			// G.���� �̷���
void turn90Right();				// H.��� �̹��� ���������� 90�� ȸ��
void turn90Left();				// I.��� �̹��� �������� 90�� ȸ��

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


// �޴� ����
void printMenu() {
	puts("\n");
	puts("\t\t\t=========================================================================");
	puts("\t\t\t                 ### �׷��� ����ó�� (Alpha 1) ###\n");
	puts("\t\t\t-------------------------------------------------------------------------");
	puts("\t\t\t [ ���� �޴� ���� ] \t 1.����  2.����  0.���� \n\n");
	puts("\t\t\t [ ����ó�� �޴� ���� ] \n");
	puts("\t\t\t    A.����  B.���  C.����  D.����  E.���  F.�¿�̷���  G.���Ϲ̷���");
	puts("\t\t\t=========================================================================\n");
}
// �޴� ����
void choiceMenu() {
	char inKey = 0;		// Ű����� �Է� �޴� ����

	printMenu();
	printf("\t\t\t �޴� ���� : ");

	while (inKey != '0') {
		inKey = _getch();

		switch (inKey) {
		case '0':	break;
		case '1':
			system("cls");
			printMenu();
			openImage();
			break;
		case 'A':	case 'a':
			system("cls");
			printMenu();
			equalImage();
			break;
		case 'B':	case 'b':
			system("cls");
			printMenu();
			brightControlImage();
			break;
		case 'C':	case 'c':
			system("cls");
			printMenu();
			clearControlImage();
			break;
		case 'D':	case 'd':
			system("cls");
			printMenu();
			reverseImage();
			break;
		case 'E':	case 'e':
			system("cls");
			printMenu();
			grayScaleImage();
			break;
		case 'F':	case 'f':
			system("cls");
			printMenu();
			L_R_mirroring();
			break;
		case 'G':	case 'g':
			system("cls");
			printMenu();
			T_B_mirroring();
			break;
		case 'H':	case 'h':
			system("cls");
			printMenu();
			T_B_mirroring();
			break;
		default:
			printf("�Է� ����! ���Է� �ٶ��ϴ�! \n");
			Sleep(1000);
			system("cls");
			printMenu();
			printf("\t\t\t �޴� ���� : ");
		}
	}
}

int main()
{
	hwnd = GetForegroundWindow();
	hdc = GetWindowDC(hwnd);

	choiceMenu();

	printf("\n%60s \n", "���α׷� ����!");
}


// ���� ����
void openImage() {
	char fullName[100] = "C:/images/Pet_RAW(squre)/Pet_RAW(512x512)/";

	printf("\t\t\t ���ϸ� --> ");	// cat01, dog13
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

	system("cls");
	printMenu();
	printf("\t\t\t������ ���ϸ� : %s %s", tmpName, "\n\n\n");
	equalImage();
}

// �̹����� ȭ�� ���
void printScreen(char res) {
	int px = 0;

	if (res == 0) {
		printf("\n");
		printf("%40s", " < ���� �̹��� ȭ�� > ");
		for (int i = 0; i < ROW; i++) {
			for (int k = 0; k < COL; k++) {
				px = outImage[i][k];
				SetPixel(hdc, k + 50, i + 400, RGB(px, px, px));		// hdc�� �������ִ� �Լ�		// i, k -> k+50, i+250
			}
		}
	}
	else {
		for (int i = 0; i < ROW; i++) {
			for (int k = 0; k < COL; k++) {
				px = outImage[i][k];
				SetPixel(hdc, k + 600, i + 400, RGB(px, px, px));
			}
		}
	}
}

// ���� �̹���
/*
void originImage() {
	system("cls");

	printf("���ϸ� : %s \n\n", imgname);
	printf("���� �̹���\n");
	equalImage(1);
}
*/


//// ******* ���� ó�� �Լ� ���� ******* ////


// ���� �̹���
void equalImage() {		// previousImage()
	system("cls");
	printMenu();
	printf("%40s %s %s", "������ ���ϸ� :", tmpName, "\t");

	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			outImage[i][k] = inImage[i][k];
		}
	}
//	printf("%40s", " < ���� �̹��� ȭ�� > ");
	printf("\n");
	printScreen(0);
}

// �̹��� ��� �� ����
void brightControlImage() {
	int value;

	system("cls");
	printMenu();
	printf("%40s %s", "������ ���ϸ� :", tmpName);

	printf("\t\t  ��� ���� �� --> ");
	scanf("%d", &value);
	printf("\n");

	equalImage();

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
		printf("%40s", " < ��� ");
		printf("%d ���� ȭ�� >", value);
		printScreen(1);
	}
	else if (value < 0) {
		printf("%40s", " < ��� ");
		printf("%d ���� ȭ�� >", value); 
		printScreen(1);
	}
	else {
		printf("�ٽ� �Է��ϼ���!\n");
	}
}

// �̹��� ���� ����
void clearControlImage() {
	char choice = 0;
	int value = 0;

	system("cls");
	printMenu();
	printf("%40s %s", "������ ���ϸ� :", tmpName);

	printf("\t\t[���� ����] 8.�����ϰ�  9.����ϰ� ");
	scanf("%c", &choice);

	if (choice == 8) {		// �����ϰ�
		printf("\t  ���� ���� �� --> ");
		scanf("%d", &value);
		printf("\n");

		equalImage();

		for (int i = 0; i < ROW; i++) {
			for (int k = 0; k < COL; k++) {
				int px = inImage[i][k] * value;		// px : pixel

				if (px > 255)
					px = 255;
				else if (px < 0)
					px = 0;
				else
					outImage[i][k] = px;
			}
		}
		if (value > 0) {
			printf("%40s", " < ���� ");
			printf("%d ���� ȭ�� >", value);
			printScreen(1);
		}
		else {
			printf("�ٽ� �Է��ϼ���!\n");
		}
	}
	else if (choice == 9) {		// ����ϰ�
		printf("\t  ���� ���� �� --> ");
		scanf("%d", &value);
		printf("\n");

		equalImage();

		for (int i = 0; i < ROW; i++) {
			for (int k = 0; k < COL; k++) {
				int px = inImage[i][k] / (float)value;		// px : pixel

				if (px > 255)
					px = 255;
				else if (px < 0)
					px = 0;
				else
					outImage[i][k] = px;
			}
		}
		if (value < 0) {
			printf("%40s", " < ���� ");
			printf("%d ���� ȭ�� >", value);
			printScreen(1);
		}
		else {
			printf("�ٽ� �Է��ϼ���!\n");
		}
	}

}

// �̹��� ���� ó��
void reverseImage() {
	equalImage();

	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			outImage[i][k] = 255 - inImage[i][k];
		}
	}
	printf("\t\t\t\t < ���� ���� ȭ�� > ");
	printScreen(1);
}

// �̹��� ��� ó��
void grayScaleImage() {
	equalImage();

	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			int px = inImage[i][k];

			if (px >= 128) {
				px = 255;
			}
			else if (px < 128) {
				px = 0;
			}

			outImage[i][k] = px;
		}
	}
	printf("\t\t\t\t < ���� ��� ó�� ȭ�� > ");
	printScreen(1);
}

// �̹��� �¿� �̷���
void L_R_mirroring() {
	equalImage();

	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			outImage[i][k] = inImage[i][COL - 1 - k];	// (�ִ뿭 - 1) - �ݺ���
		}
	}
	printf("\t\t\t\t < ���� �¿� �̷��� ȭ�� > ");
	printScreen(1);
}

// �̹��� ���� �̷���
void T_B_mirroring() {
	equalImage();

	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			outImage[i][k] = inImage[ROW - 1 - i][k];		// (�ִ��� - 1) - �ݺ���
		}
	}

	printf("\t\t\t\t < ���� ���� �̷��� ȭ�� > ");
	printScreen(1);
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

