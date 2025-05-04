// GreyVideoProcessing_Beta1-3.cpp

/*
 - ��� (���/��Ӱ�)
 - ���� (�����ϰ�/�帴�ϰ�)
 - ����
 - ���
 - ��� (���)

 - ��Ʈ And/Or/Xor/Not
 - // ����, ���� ����, �Ķ󺼶� ��ȯ, ��Ʈ��Ī

 - ���� �¿� �̷���
 - ���� ���� �̷���
 - �¿�+���� �̷���
 - ��� �̹��� 90�� ȸ��
 - ��� �̹��� 180�� ȸ��
 - ��� �̹��� 270�� ȸ��
 - // �̵�, ���� ���� ȸ��, 2�� ���, 2�� Ȯ��
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <string>
using namespace std;	// C++ �߰� ���


// **** ������ (�߿�!) **** //
char imgName[100] = { 0 };		// ���ϸ� + .Ȯ���ڸ�
char filePath[100] = { 0 };		// ���� ��� ���� ����
//char fileName[100] = { 0 };

char inKey = 0;				// Ű����� �Է� �޴� ����
char pix = 0;				// �̹��� ��� ����
int ROW = 512, COL = 512;
int imgSize = 0;

const int C_ROW = 512, C_COL = 512;

unsigned char inImage[C_ROW][C_COL] = { 0, 0 };		// input
unsigned char outImage[C_ROW][C_COL] = { 0, 0 };	// output

HWND hwnd;		// ������ ȭ�� (�ܺ�, ������)		// �ϱ�x
HDC  hdc;		// �޵��� ȭ�� (����, ����)		// �ϱ�x


void printMenu();				// �޴� UI
void choiceMenu();				// �޴� ����

void openImage();				// �̹��� ���� open (�Է�)

void originImage(char oriImage);	// ���� �̹���
void resultImage(char oriImage);	// ��� �̹���
void ori_printScreen();				// ���� �̹��� ȭ�� ���
void res_printScreen();				// ��� �̹��� ȭ�� ���

//void equalImage();				// ���� �̹��� ���
// =========================== < ȭ���� ó�� ��� �Լ� ���� > ===========================
void brightControlImage();		// A.��� ����
void clearControlImage();		// B.���� ����
void reverseImage();			// C.����
void grayScaleImage();			// D.��� (128/���)
void bitCalcImage();			// E.��Ʈ ���� (And/Or/Xor/Not)
void gammaConverseImage();		// F.���� ��ȯ
void rangeEmphasisImage();		// G.���� ����
void parabolaImage();			// H.�Ķ󺼶� ��ȯ
void stretchedImage();			// I.��Ʈ��Ī
// ============================ < ������ ó�� �Լ� ���� > ===============================
void mirroringImage();  		// J.�̷��� (�¿�/����/�¿�+����)
void turnImage();				// K.ȸ�� (����, 90/180/270��/����)
void doubleUpDownImage();		// L.2�� Ȯ��/���
void moveImage();				// M.�̵�

// ============================ < ��� ó�� �Լ� ���� > ===============================
void clearUp();				// B.�����ϰ�
void clearDown();			// B.�帴�ϰ�

void grayScale128();		// D.���ó�� (128 ����)
void grayScaleAvg();		// D.���ó�� (��հ� ����)

void bitCalc_And(int val);		// E-1.��Ʈ����_And
void bitCalc_Or(int val);		// E-2.��Ʈ����_Or
void bitCalc_Xor(int val);		// E-3.��Ʈ����_Xor
void bitCalc_Not();				// E-4.��Ʈ����_Not

void L_R_mirroring();		// J.�¿� �̷���
void T_B_mirroring();		// J.���� �̷���
void TB_LR_mirroring();		// J.����/�¿� �̷���

void turn90Right();			// K.���������� 90�� ȸ��
void turn180Right();		// K.���������� 180�� ȸ��
void turn270Right();		// K.���������� 270�� ȸ��
void turn90Left();			// K.�������� 90�� ȸ��
void turn180Left();			// K.�������� 180�� ȸ��
void turn270Left();			// K.�������� 270�� ȸ��

void doubleUp();			// L.2�� Ȯ��
void doubleDown();			// L.2�� ���



int main()
{
	hwnd = GetForegroundWindow();
	hdc = GetWindowDC(hwnd);

	choiceMenu();

	printf("\n%60s \n", "���α׷� ����!");
}


//// ********** �޴� ���� �Լ� ����  ********** ////
// �޴� UI
void printMenu() {
	puts("\n");
	puts("\t\t\t===========================================================================");
	puts("\t\t\t                    ### �׷��� ����ó�� (Alpha 1) ###\n");
	puts("\t\t\t---------------------------------------------------------------------------");
	puts("\t\t\t [ ���� �޴� ���� ] \t 1.����  2.����  0.���� \n\n");
	puts("\t\t\t [ ����ó�� �޴� ���� ] \n");
	puts("\t\t\t    A.���  B.����  C.����  D.���  E.��Ʈ����  F.������ȯ  G.��������");
	puts("\t\t\t    H.�Ķ󺼶� ��ȯ  I.��Ʈ��Ī     J.�̷���  K.ȸ��  L.Ȯ��/���  M.�̵�");
	puts("\t\t\t===========================================================================\n");
}
// �޴� ����
void choiceMenu() {
	printMenu();
	printf("\t\t\t �޴� ���� : ");

	while (inKey != '0') {
		inKey = _getch();

		switch (inKey) {
		case '0':	break;		// ����
		case '1':				// ���� open
			system("cls");	printMenu();	openImage();	break;

		case 'A':	case 'a':	// ��� ����
			system("cls");	printMenu();	brightControlImage();	break;
		case 'B':	case 'b':	// ���� ����
			system("cls");	printMenu();	clearControlImage();	break;
		case 'C':	case 'c':	// ���� ����
			system("cls");	printMenu();	reverseImage();	break;
		case 'D':	case 'd':	// ��� (128/���)
			system("cls");	printMenu();	grayScaleImage();	break;
		case 'E':	case 'e':	// ��Ʈ ���� (And/Or/Xor/Not)
			system("cls");	printMenu();	bitCalcImage();	break;
		case 'F':	case 'f':	// ���� ��ȯ
			system("cls");	printMenu();	gammaConverseImage();	break;
		case 'G':	case 'g':	// ���� ���� 
			system("cls");	printMenu();	rangeEmphasisImage();	break;
		case 'H':	case 'h':	// �Ķ󺼶� ��ȯ 
			system("cls");	printMenu();	parabolaImage();	break;
		case 'I':	case 'i':	// ��Ʈ��Ī
			system("cls");	printMenu();	stretchedImage();	break;

		case 'J':	case 'j':	// �̷��� (�¿�/����/�¿�+����)
			system("cls");	printMenu();	mirroringImage();	break;
		case 'K':	case 'k':	// ȸ�� (����, 90/180/270��/����)
			system("cls");	printMenu();	turnImage();	break;
		case 'L':	case 'l':	// 2�� Ȯ��/���
			system("cls");	printMenu();	doubleUpDownImage();	break;
		case 'M':	case 'm':	// �̹��� �̵�
			system("cls");	printMenu();	moveImage();	break;

		default:				// ����ó��
			printf("�Է� ����! ���Է� �ٶ��ϴ�! \n");
			Sleep(1000);	system("cls");
			printMenu();	printf("\t\t\t �޴� ���� : ");
		}
	}
}
//// ****************************************** ////



//// ********** �̹��� ����� �Լ� ���� ********** ////
// �̹��� ���� ���� (�Է�)
void openImage() {
	char fullName[100] = "C:/images/Gallery/Gallery";			// C:/images/Pet_RAW(squre)/Pet_RAW(512x512)/";
	short tmp_row = 0, tmp_col = 0;
	unsigned char tmp_inImage[C_ROW][C_COL] = { 0, 0 };

	printf("\t\t\t ���ϸ� --> ");	// cat01, dog13
	scanf("%s", imgName);

	while (1) {
		printf("\n\t\t\t[�ȼ� ����] \n");
		printf("\t\t\t  1.128  2.256  3.512 ");
		
		inKey = _getch();
		switch (inKey) {
		case '1':		// 128x128
			pix = 1;
			ROW = 128, COL = 128;

			// �ּ�(fullName) + ���ϸ�(imgName) + _128.raw ���ؼ� --> filePath��
			strcat(fullName, "(128x128)/");		// strcat : ���ڿ��� �̾���
			strcat(fullName, imgName);
			strcat(fullName, "_128.raw");
			strcat(imgName, "_128.raw");

			strcpy(filePath, fullName);

			break;
		case '2':		// 256x256
			pix = 2;
			ROW = 256, COL = 256;

			strcat(fullName, "(256x256)/");
			strcat(fullName, imgName);
			strcat(fullName, "_256.raw");
			strcat(imgName, "_256.raw");

			strcpy(filePath, fullName);

			break;
		case '3':		// 512x512
			pix = 3;
			ROW = 512, COL = 512;

			strcat(fullName, "(512x512)/");
			strcat(fullName, imgName);
			strcat(fullName, "_512.raw");
			strcat(imgName, "_512.raw");

			strcpy(filePath, fullName);

			break;
		default:
			printf("\t\t\t�Է� ����! ���Է� �ٶ��ϴ�! \n");
			Sleep(1000);	system("cls");
			printMenu();	printf("\t\t\t ���ϸ� --> ");
		}
		if (pix != 0) break;
	}

	//// ���� ���� ////
	FILE* rfp = fopen(filePath, "rb");		// rb: Read Binary

	// 512x512 �� �ݺ��ؼ� �аų�, �ѹ濡 512,512 �аų�
	fread(tmp_inImage, sizeof(unsigned char), ROW * COL, rfp);
	
	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			inImage[i][k] = tmp_inImage[tmp_row][tmp_col];
			tmp_col++;
			if (tmp_col == C_COL) {
				tmp_col = 0;
				tmp_row++;
			}
		}
	}

	//// ���� �ݱ� ////
	fclose(rfp);

	system("cls");
	printMenu();
	printf("\t\t\t  ������ ���ϸ� : %s", imgName);
	printf("\n\n");

	ori_printScreen();
}

// ���� �̹���
void originImage(char oriImage) {
	short px = 0;

	// Original 128x128
	if (oriImage == 1) {
		printf("\n\t\t\t < ���� �̹��� ȭ��(128) > ");
		for (int i = 0; i < ROW; i++) {
			for (int k = 0; k < COL; k++) {
				px = inImage[i][k];
				SetPixel(hdc, k + 300, i + 420, RGB(px, px, px));		// hdc�� �������ִ� �Լ�		// i, k -> k+50, i+250
			}
		}
	}
	// Original 256x256
	else if (oriImage == 2) {
		printf("\n\t\t\t < ���� �̹��� ȭ��(256) > ");
		for (int i = 0; i < ROW; i++) {
			for (int k = 0; k < COL; k++) {
				px = inImage[i][k];
				SetPixel(hdc, k + 250, i + 420, RGB(px, px, px));		// hdc�� �������ִ� �Լ�		// i, k -> k+50, i+250
			}
		}
	}
	// Original 512x512
	else if (oriImage == 3) {
		printf("\n\t\t < ���� �̹��� ȭ��(512) > ");
		for (int i = 0; i < ROW; i++) {
			for (int k = 0; k < COL; k++) {
				px = inImage[i][k];
				SetPixel(hdc, k + 50, i + 420, RGB(px, px, px));		// hdc�� �������ִ� �Լ�		// i, k -> k+50, i+250
			}
		}
	}
	else
		printf("���� ���ε� ����! \n");
}
// ��� �̹���
void resultImage(char oriImage) {
	short px = 0;

	// ���� ������� ���
	if (imgSize == 0) {
		// Result 128x128
		if (oriImage == 1) {
			for (int i = 0; i < ROW; i++) {
				for (int k = 0; k < COL; k++) {
					px = outImage[i][k];
					SetPixel(hdc, k + 800, i + 420, RGB(px, px, px));		// hdc�� �������ִ� �Լ�		// i, k -> k+50, i+250
				}
			}
		}
		// Result 256x256
		else if (oriImage == 2) {
			for (int i = 0; i < ROW; i++) {
				for (int k = 0; k < COL; k++) {
					px = outImage[i][k];
					SetPixel(hdc, k + 720, i + 420, RGB(px, px, px));		// hdc�� �������ִ� �Լ�		// i, k -> k+50, i+250
				}
			}
		}
		// Result 512x512
		else if (oriImage == 3) {
			for (int i = 0; i < ROW; i++) {
				for (int k = 0; k < COL; k++) {
					px = outImage[i][k];
					SetPixel(hdc, k + 600, i + 420, RGB(px, px, px));		// hdc�� �������ִ� �Լ�		// i, k -> k+50, i+250
				}
			}
		}
		else
			printf("���� ���ε� ����!");
	}
	// 2�� Ȯ�� ���
	else if (imgSize == 1) {
		// Result 128x128
		if (oriImage == 1) {
			for (int i = 0; i < ROW; i++) {
				for (int k = 0; k < COL; k++) {
					px = outImage[i][k];
					SetPixel(hdc, k + 800, i + 420, RGB(px, px, px));		// hdc�� �������ִ� �Լ�		// i, k -> k+50, i+250
				}
			}
		}
		// Result 256x256
		else if (oriImage == 2) {
			for (int i = 0; i < ROW; i++) {
				for (int k = 0; k < COL; k++) {
					px = outImage[i][k];
					SetPixel(hdc, k + 720, i + 420, RGB(px, px, px));		// hdc�� �������ִ� �Լ�		// i, k -> k+50, i+250
				}
			}
		}
		// Result 512x512
		else if (oriImage == 3) {
			for (int i = 0; i < ROW; i++) {
				for (int k = 0; k < COL; k++) {
					px = outImage[i][k];
					SetPixel(hdc, k + 600, i + 420, RGB(px, px, px));		// hdc�� �������ִ� �Լ�		// i, k -> k+50, i+250
				}
			}
		}
		else
			printf("���� ���ε� ����!");
	}
	// 2�� ��� ���
	else if (imgSize == 2) {
		// Result 128x128
		if (oriImage == 1) {
			for (int i = 0; i < ROW; i++) {
				for (int k = 0; k < COL; k++) {
					px = outImage[i][k];
					SetPixel(hdc, k + 800, i + 420, RGB(px, px, px));		// hdc�� �������ִ� �Լ�		// i, k -> k+50, i+250
				}
			}
		}
		// Result 256x256
		else if (oriImage == 2) {
			for (int i = 0; i < ROW; i++) {
				for (int k = 0; k < COL; k++) {
					px = outImage[i][k];
					SetPixel(hdc, k + 720, i + 420, RGB(px, px, px));		// hdc�� �������ִ� �Լ�		// i, k -> k+50, i+250
				}
			}
		}
		// Result 512x512
		else if (oriImage == 3) {
			for (int i = 0; i < ROW; i++) {
				for (int k = 0; k < COL; k++) {
					px = outImage[i][k];
					SetPixel(hdc, k + 600, i + 420, RGB(px, px, px));		// hdc�� �������ִ� �Լ�		// i, k -> k+50, i+250
				}
			}
		}
		else
			printf("���� ���ε� ����!");
	}
	else
		printf("���� �Է� ����!");
}
// ���� �̹��� ȭ�� ���
void ori_printScreen() {
	if		(pix == 1)	originImage(1);		// 128x128
	else if (pix == 2)	originImage(2);		// 256x256
	else if (pix == 3)	originImage(3);		// 512x512
}
// ��� �̹��� ȭ�� ���
void res_printScreen() {
	if		(pix == 1)	resultImage(1);		// 128x128
	else if (pix == 2)	resultImage(2);		// 256x256
	else if (pix == 3)	resultImage(3);		// 512x512
}
//// ********************************************* ////



//// ********** ȭ���� ó�� ��� �Լ� ���� ********** ////
// ���� �̹��� ���
/*
void equalImage() {		// previousImage()
	system("cls");
	printMenu();
	printf("\t\t\t  ������ ���ϸ� : %s", imgName);
	printf("\n\n");

	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			int px = inImage[i][k];

			outImage[i][k] = px;
		}
	}
	printf("\n");
	res_printScreen();
}
*/

// A.�̹��� ��� �� ����
void brightControlImage() {
	int value;

	system("cls");
	printMenu();
	printf("\t\t\t  ������ ���ϸ� : %s", imgName);

	printf("\t\t  ��� ���� �� --> ");
	scanf("%d", &value);
	printf("\n");

	ori_printScreen();

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
		printf("\t\t\t < ��� %d ���� ȭ�� >", value);
		res_printScreen();
	}
	else if (value < 0) {
		printf("\t\t\t < ��� %d ���� ȭ�� >", value);
		res_printScreen();
	}
	else {
		printf("�ٽ� �Է��ϼ���!\n");
	}
}

// B.�̹��� ���� ����
void clearControlImage() {
	int choice = 0;

	system("cls");
	printMenu();
	printf("\t\t\t  ������ ���ϸ� : %s", imgName);
	printf("\n\n");
	
	printf("\n\t\t\t[���� ����] \n");
	printf("\t\t\t  1.�����ϰ�  2.����ϰ�");

	inKey = _getch();
	switch (inKey) {
	case '1':		// �����ϰ�
		clearUp();
		break;
	case '2':		// ����ϰ�
		clearDown();
		break;
	default:
		printf("�Է� ����! ���Է� �ٶ��ϴ�! \n");
		Sleep(1000);	system("cls");
		printMenu();	printf("\t\t\t ���ϸ� --> ");
		break;
	}
}

// C.�̹��� ���� ó��
void reverseImage() {
	system("cls");
	printMenu();
	printf("\t\t\t  ������ ���ϸ� : %s", imgName);
	printf("\n\n");

	ori_printScreen();

	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			int px = inImage[i][k];

			outImage[i][k] = 255 - px;
		}
	}
	printf("\t\t\t < ���� ���� ȭ�� > ");
	res_printScreen();
}

// D.�̹��� ��� ó��
void grayScaleImage() {
	system("cls");
	printMenu();
	printf("\t\t\t  ������ ���ϸ� : %s", imgName);

	printf("\t\t  1.128 ����  2.��հ� ���� \n");

	ori_printScreen();

	inKey = _getch();
	switch (inKey) {
	case '1':		// 128 ����
		grayScale128();
		break;
	case '2':		// ��հ� ����
		grayScaleAvg();
		break;
	default:
		printf("�ٽ� �Է��ϼ���! \n");
		break;
	}
}

// E.��Ʈ���� (And/Or/Xor/Not)
void bitCalcImage() {
	int value = 0;

	system("cls");
	printMenu();
	printf("\t\t\t  ������ ���ϸ� : %s", imgName);

	printf("\n\n\t\t 1.And  2.Or  3.Xor  4.Not ");

	inKey = _getch();
	if (inKey == '1' || inKey == '2' || inKey == '3') {
		while (1) {
			printf("\t\t ������ �� (0~255) : ");
			scanf("%d", &value);

			if (value >= 0 && value <= 255) {
				break;
			}
			else
				printf("\t\t �Է¿���! ��(0~255)�� �ٽ� �Է��ϼ���! \n");
		}
	}
	system("cls");
	printMenu();
	printf("\t\t\t  ������ ���ϸ� : %s", imgName);
	printf("\n\n");

	ori_printScreen();

	switch (inKey) {
	case '1':
		bitCalc_And(value);
		break;
	case '2':
		bitCalc_Or(value);
		break;
	case '3':
		bitCalc_Xor(value);
		break;
	case '4':
		bitCalc_Not();
		break;
	default:
		printf("�ٽ� �Է��ϼ���! \n");
		break;
	}


}

// F.���� ��ȯ
void gammaConverseImage() {
	int value = 0;

	system("cls");
	printMenu();
	printf("\t\t\t  ������ ���ϸ� : %s", imgName);

	printf("\t\t   ���� �� �Է� : ");
	scanf("%d", &value);

	ori_printScreen();

	if (value != 0) {
		for (int i = 0; i < ROW; i++) {
			for (int k = 0; k < COL; k++) {
				outImage[i][k] = pow(inImage[i][k] / 255., value) * 255 + 0.5;
			}
		}
	}
	else
		printf("�ٽ� �Է��ϼ���! \n");
	printf("\t\t\t < ���� ��ȯ ȭ�� > ");
	res_printScreen();
}

// G.���� ����
void rangeEmphasisImage() {

}

// H.�Ķ󺼶� ��ȯ
void parabolaImage() {

}

// I.��Ʈ��Ī
void stretchedImage() {

}
//// ************************************************ ////



//// ********** ������ ó�� �Լ� ����  ********** ////
// J.�̷��� (�¿�/����/�¿�+����) 
void mirroringImage() {
	system("cls");
	printMenu();
	printf("\t\t\t  ������ ���ϸ� : %s", imgName);

	printf("\t\t 1.�¿�  2.����  3.�¿�+���� \n");

	ori_printScreen();

	inKey = _getch();
	switch (inKey) {
	case '1':
		L_R_mirroring();
		break;
	case '2':
		T_B_mirroring();
		break;
	case '3':
		TB_LR_mirroring();
		break;
	default:
		printf("�ٽ� �Է��ϼ���! \n");
		break;
	}
}

// K.ȸ��(������,���� 90/180/270/����)
void turnImage() {
	int direct = 0;

	system("cls");
	printMenu();
	printf("\t\t\t  ������ ���ϸ� : %s", imgName);

	printf("\t\t [����] 1.������  2.���� ");
	scanf("%d", &direct);
	printf("\n\t\t\t\t\t\t\t    [����] A.90  B.180  C.270  D.���� ");

	// ���������� ȸ��
	if (direct == 1) {
		inKey = _getch();
		switch (inKey) {
		case 'A':	case 'a':		// 90�� ȸ��
			system("cls");	printMenu();	turn90Right();	break;
		case 'B':	case 'b':		// 180�� ȸ��
			system("cls");	printMenu();	turn180Right();	break;
		case 'C':	case 'c':		// 270�� ȸ��
			system("cls");	printMenu();	turn270Right();	break;
		case 'D':	case 'd':		// ���� ȸ��
			break;
		default:
			break;
		}
	}
	// �������� ȸ��
	else if (direct == 2) {
		inKey = _getch();
		switch (inKey) {
		case 'A':	case 'a':		// 90�� ȸ��
			system("cls");	printMenu();	turn90Left();	break;
		case 'B':	case 'b':		// 180�� ȸ�� 
			system("cls");	printMenu();	turn180Left();	break;
		case 'C':	case 'c':		// 270�� ȸ��
			system("cls");	printMenu();	turn270Left();	break;
		case 'D':	case 'd':		// ���� ȸ��
			break;
		default:
			break;
		}
	}
	else {
		printf("�ٽ� �Է����ּ���! \n");
		return;
	}
	res_printScreen();
}

// L.2�� Ȯ��/���
void doubleUpDownImage() {
	system("cls");
	printMenu();
	printf("\t\t\t  ������ ���ϸ� : %s", imgName);

	printf("\t\t 1.2�� Ȯ��  2.2�� ��� ");

	ori_printScreen();

	inKey = _getch();
	switch (inKey) {
	case '1':
		doubleUp();
		break;
	case '2':
		doubleDown();
		break;
	default:
		printf("�ٽ� �Է��ϼ���! \n");
		break;
	}
}

// M.�̵�
void moveImage() {
	int value = 0;

	system("cls");
	printMenu();
	printf("\t\t\t  ������ ���ϸ� : %s", imgName);

	printf("\t\t  �̵��� �� : ");
	scanf("%d", &value);

	ori_printScreen();

	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			outImage[i][k] = 0;
		}
	}
	for (int i = 0; i < ROW - value; i++) {
		for (int k = 0; k < COL - value; k++) {
			outImage[i][k] = inImage[i + value][k + value]; // = inImage[i][k];
		}
	}
	res_printScreen();
}




// B.�����ϰ�
void clearUp() {
	float value = 0;

	printf("   ���� ���� ��(���) --> ");
	scanf("%f", &value);

	system("cls");
	printMenu();
	printf("\t\t\t  ������ ���ϸ� : %s", imgName);
	printf("\n\n");

	ori_printScreen();

	if (value > 0) {
		for (int i = 0; i < ROW; i++) {
			for (int k = 0; k < COL; k++) {
				float px = inImage[i][k] * value;		// px : pixel

				if (px > 255)
					outImage[i][k] = 255;
				else if (px < 0)
					outImage[i][k] = 0;
				outImage[i][k] = (int)px;
			}
		}
		printf("\t\t\t< ���� %.1f ���� ȭ�� >", value);
		res_printScreen();
	}
	else
		printf("\t\t\t���� �Ǵ� 0 �Է�.. ����� �Է����ּ���.");
}
// B.�帴�ϰ�
void clearDown() {
	float value = 0;

	printf("\t   ���� ���� ��(���) --> ");
	scanf("%f", &value);

	system("cls");
	printMenu();
	printf("\t\t\t  ������ ���ϸ� : %s", imgName);
	printf("\n\n");

	ori_printScreen();

	if (value > 0) {
		for (int i = 0; i < ROW; i++) {
			for (int k = 0; k < COL; k++) {
				float px = inImage[i][k] / value;		// px : pixel

				if (px > 255)
					outImage[i][k] = 255;
				else if (px < 0)
					outImage[i][k] = 0;
				outImage[i][k] = float(px);
			}
		}
		printf("\t\t\t< ���� %.1f ���� ȭ�� >", value);
		res_printScreen();
	}
	else
		printf("\t\t\t���� �Ǵ� 0 �Է�.. ����� �Է����ּ���.");
}

// D.���ó�� (128 ����)
void grayScale128() {
	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			int px = inImage[i][k];

			if (px > 128) {
				px = 255;
			}
			else if (px <= 128) {
				px = 0;
			}
			outImage[i][k] = px;
		}
	}
	printf("\t\t\t < ���� ��� ó��(128 ����) ȭ�� > ");
	res_printScreen();
}
// D.���ó�� (��հ� ����)
void grayScaleAvg() {
	int pixelSum = 0;
	int pixelAvg = 0;

	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			int px = inImage[i][k];
			pixelSum += px;
		}
	}
	pixelAvg = pixelSum / (ROW * COL);

	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			int px = inImage[i][k];
			if (px > pixelAvg) {
				px = 255;
			}
			else {
				px = 0;
			}
			outImage[i][k] = px;
		}
	}
	printf("\t\t\t < ���� ��� ó��(��հ� %d ����) ȭ�� > ", pixelAvg);
	res_printScreen();
}

// E-1.��Ʈ����_And
void bitCalc_And(int val) {
	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			unsigned char px = inImage[i][k] & val;

			outImage[i][k] = px;
		}
	}
	printf("\t\t\t < AND ��Ʈ ���� ȭ�� > ");
	res_printScreen();
}
// E-2.��Ʈ����_Or
void bitCalc_Or(int val) {
	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			unsigned char px = inImage[i][k] | val;
			outImage[i][k] = px;
		}
	}
	printf("\t\t\t < OR ��Ʈ ���� ȭ�� > ");
	res_printScreen();
}
// E-3.��Ʈ����_Xor
void bitCalc_Xor(int val) {
	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			unsigned char px = inImage[i][k] ^ val;
			outImage[i][k] = px;
		}
	}
	printf("\t\t\t < XOR ��Ʈ ���� ȭ�� > ");
	res_printScreen();
}
// E-4.��Ʈ����_Not
void bitCalc_Not() {
	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			unsigned char px = ~inImage[i][k];
			outImage[i][k] = px;
		}
	}
	printf("\t\t\t < NOT ��Ʈ ���� ȭ�� > ");
	res_printScreen();
}

// J.�̹��� �¿� �̷���
void L_R_mirroring() {
	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			int px = inImage[i][COL - 1 - k];	// (�ִ뿭 - 1) - �ݺ���
			
			outImage[i][k] = px;
		}
	}
	printf("\t\t\t < ���� �¿� �̷��� ȭ�� > ");
	res_printScreen();
}
// J.�̹��� ���� �̷���
void T_B_mirroring() {
	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			int px = inImage[ROW - 1 - i][k];		// (�ִ��� - 1) - �ݺ���
			
			outImage[i][k] = px;
		}
	}
	printf("\t\t\t < ���� ���� �̷��� ȭ�� > ");
	res_printScreen();
}
// J.�̹��� ����+�¿� �̷���
void TB_LR_mirroring() {
	for (int i = 0; i < COL; i++) {
		for (int k = 0; k < ROW; k++) {
			unsigned char mirror_i = ROW - 1 - i;
			unsigned char mirror_k = COL - 1 - k;

			outImage[i][k] = inImage[mirror_i][mirror_k];
		}
	}
	printf("\t\t\t < ���� ����/�¿� �̷��� ȭ�� > ");
	res_printScreen();
}

// K.��� �̹��� �ð�������� 90�� ȸ��
void turn90Right() {
	ori_printScreen();

	for (int i = 0; i < COL; i++) {
		for (int k = 0; k < ROW; k++) {
			outImage[i][k] = inImage[ROW - k - 1][i];
		}
	}
	printf("\t\t\t < �ð���� 90�� ȸ�� ȭ�� > ");
}
// K.��� �̹��� �ð�������� 180�� ȸ��
void turn180Right() {
	ori_printScreen();

	for (int i = 0; i < COL; i++) {
		for (int k = 0; k < ROW; k++) {
			outImage[i][k] = inImage[ROW - i - 1][COL - k - 1];
		}
	}
	printf("\t\t\t < �ð���� 180�� ȸ�� ȭ�� > ");
}
// K.��� �̹��� �ð�������� 270�� ȸ��
void turn270Right() {
	ori_printScreen();

	for (int i = 0; i < COL; i++) {
		for (int k = 0; k < ROW; k++) {
			outImage[i][k] = inImage[k][ROW - i - 1];
		}
	}
	printf("\t\t\t < �ð���� 270�� ȸ�� ȭ�� > ");
}

// K.��� �̹��� �ݽð�������� 90�� ȸ��
void turn90Left() {
	ori_printScreen();

	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			outImage[i][k] = inImage[k][ROW - 1 - i];
		}
	}
	printf("\t\t\t < �ݽð���� 90�� ȸ�� ȭ�� > ");
}
// K.��� �̹��� �ݽð�������� 180�� ȸ��
void turn180Left() {
	ori_printScreen();

	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			outImage[i][k] = inImage[ROW - 1 - i][COL - k - 1];
		}
	}
	printf("\t\t\t < �ݽð���� 180�� ȸ�� ȭ�� > ");
}
// K.��� �̹��� �ݽð�������� 270�� ȸ��
void turn270Left() {
	ori_printScreen();

	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			outImage[i][k] = inImage[ROW - k - 1][i];
		}
	}
	printf("\t\t\t < �ݽð���� 270�� ȸ�� ȭ�� > ");
}

// L.2�� Ȯ��
void doubleUp() {
	imgSize = 1;

	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			outImage[i][k] = inImage[i / 2][k / 2];
		}
	}
	res_printScreen();
}
// L.2�� ���
void doubleDown() {
	imgSize = 2;

	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			outImage[i][k] = 0;
		}
	}
	for (int i = 0; i < ROW / 2; i++) {
		for (int k = 0; k < COL / 2; k++) {
			outImage[i][k] = inImage[i * 2][k * 2];
		}
	}
	res_printScreen();
}
//// ******************************************** ////


