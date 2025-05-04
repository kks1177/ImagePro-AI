// 0125_greyVideo.cpp

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>		// GUI�� �����ϴ� ���
#include <string>
using namespace std;


// **** ���� ������(�߿�!)
char filename[100];
int inH, inW, outH, outW; // ����� ������ ũ��
unsigned char** inImage = NULL, ** outImage = NULL;
HWND hwnd; // ���� ȭ��(�ܺ�, ������)
HDC  hdc;  // ���� ȭ��(����, ����)

// ***** �Լ� �����(�̸��� ǥ��) ***** //
unsigned char** malloc2D(int, int);
void free2D(unsigned char**, int);
void free2D_out();
void printMenu();
void printImage(); void openImage(); void saveImage();
void equalImage(); void reverseImage();
void zoomOut();	void zoomIn();	void zoomIn2(); 
void LotateImage();	 void Lotate2Image();


// ***** ���� �Լ� ***** //
int main() {
	hwnd = GetForegroundWindow();		// ������ â �Է� �޴� �Լ�
	hdc = GetWindowDC(hwnd);

	char inKey = 0;
	while (inKey != '9') {
		printMenu();
		inKey = _getch();
		switch (inKey) {
		case '0': openImage(); break;
		case '1': saveImage(); break;														// @@@@@@@�߰�
		case '9': free2D(inImage, inH); free2D(outImage, outH); break;
		case 'A':	case 'a':	equalImage(); break;
		case 'B':	case 'b':	reverseImage(); break;
		case 'K':	case 'k':	zoomOut(); break;
		case 'L':	case 'l':	zoomIn(); break;
		case 'M':	case 'm':	zoomIn2(); break;
		case 'N':	case 'n':	LotateImage(); break;
		case 'O':	case 'o':	Lotate2Image(); break;
		}
	}
	printf("�ȳ��� ������~");
}

void printMenu() {
	puts("\n ## �׷��� ����ó�� (Beta 1) ##\n");
	puts("0.���� 1.���� 9.����\n");
	puts("A.���� B.���� .....\n");
	puts("K.��� L.Ȯ�� M.Ȯ��(�����) N.ȸ�� O.ȸ��(�����+�߾�).....\n");
}
// *********************** //


// ***** ���� �Լ��� ***** //
unsigned char** malloc2D(int row, int col) {
	unsigned char** retMemory;
	retMemory = (unsigned char**)malloc(row * sizeof(unsigned char*));
	for (int i = 0; i < row; i++)
		retMemory[i] = (unsigned char*)malloc(col * sizeof(unsigned char));
	return retMemory;
}

void free2D(unsigned char** memory, int h) {
	for (int i = 0; i < h; i++)
		free(memory[i]);
	free(memory);
}
void free2D_out() {
	if (outImage == NULL)
		return; 

	for (int i = 0; i < outH; i++)
		free(outImage[i]);
	free(outImage);
}

void printImage() {
	// �̹����� ȭ�� ���
	system("cls");
	int px;
	for (int i = 0; i < outH; i++) {
		for (int k = 0; k < outW; k++) {
			px = outImage[i][k];
			SetPixel(hdc, k + 50, i + 250, RGB(px, px, px));
		}
	}
}

void openImage() {
	char fullName[100] = "C:/images/Etc_Raw(squre)/";
	char tmpName[100];

	printf("���ϸ�-->"); // cat01, doc13
	scanf("%s", tmpName);

	strcat(fullName, tmpName);
	strcat(fullName, ".raw");
	strcpy(filename, fullName);

	FILE* rfp = fopen(filename, "rb");
	if (rfp == NULL)																// ���� �߸� ���������� ���ϴ°�
		return;

	// �Է� ������ ũ�⸦ �˾Ƴ��� ��. --> inH, inW�� ����
	fseek(rfp, 0L, SEEK_END); // ������ ������ �̵�
	unsigned long fsize = ftell(rfp); // �� ����? 262144
	fclose(rfp);

	inH = inW = sqrt(fsize); // 512x512												// (���� �߿�!) �ȼ� �� �ľ��ϴ� �Լ�
	// �Է¿���(inImage)�� �޸𸮸� �Ҵ�.  uc inImage[inH][inW];
	inImage = malloc2D(inH, inW);
	// ���� --> �޸𸮷� �ε�
	rfp = fopen(filename, "rb");
	for (int i = 0; i < inH; i++)
		fread(inImage[i], sizeof(unsigned char), inW, rfp);
	// ���� �ݱ�
	fclose(rfp);
	equalImage();
}

void saveImage() {
	char fullName[100] = "C:/images/Etc_Raw(squre)/";
	char tmpName[100];
	printf("(����) ���ϸ�-->"); // cat01, doc13
	scanf("%s", tmpName);

	strcat(fullName, tmpName);
	strcat(fullName, ".raw");
	strcpy(filename, fullName);

	FILE* wfp = fopen(filename, "wb");												// rfp --> wfp             rb -> wb
	if (wfp == NULL)																// �۾��ϴٰ� USB�� ���ڱ� ������ �� �߻��ϴ� ���� ó��
		return;

	// �޸� --> ���Ϸ� �ε�
	for (int i = 0; i < outH; i++)
		fwrite(outImage[i], sizeof(unsigned char), outW, wfp);						// inImage[i] --> outImage[i],     intW--->outW, rfp --> wfp
	// ���� �ݱ�
	fclose(wfp);
	MessageBox(hwnd, L"���� OK", L"���� â", NULL);										// �߰�, 
}


//***** ���� ó�� �Լ��� ***** //
void equalImage() {
	free2D_out();
	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	outH = inH;
	outW = inW;
	outImage = malloc2D(outH, outW);
	//**** ��¥ ����ó�� �˰��� ***//
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			outImage[i][k] = inImage[i][k];
		}
	}
	//*****************************
	printImage();
}

void reverseImage() {
	free2D_out();
	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	outH = inH;
	outW = inW;
	outImage = malloc2D(outH, outW);
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			outImage[i][k] = 255 - inImage[i][k];
		}
	}
	printImage();
}

// ���� ��� �˰���
void zoomOut() {
	free2D_out();
	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	int scale;
	printf("��� ���� --> ");
	scanf("%d", &scale);

	// output�� ũ�� ����
	outH = inH / scale;					// output�� input �� �޶���
	outW = inW / scale;
	outImage = malloc2D(outH, outW);

	//**** ��¥ ����ó�� �˰��� ***//
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			outImage[i/scale][k/scale] = inImage[i][k];
		}
	}
	//*****************************
	printImage();
}

// ���� Ȯ�� �˰��� (������)
void zoomIn() {
	free2D_out();
	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	int scale;
	printf("Ȯ�� ���� --> ");
	scanf("%d", &scale);

	// output�� ũ�� ����
	outH = inH * scale;					// output�� input �� �޶���
	outW = inW * scale;
	outImage = malloc2D(outH, outW);

	//*** ��¥ ����ó�� �˰��� ***//
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			outImage[i * scale][k * scale] = inImage[i][k];
		}
	}
	//*****************************
	printImage();
}
// ���� Ȯ�� �˰���2 (�����)		// ����� Ȧ�� ä��� �˰���
void zoomIn2() {
	free2D_out();
	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	int scale;
	printf("Ȯ�� ���� --> ");
	scanf("%d", &scale);

	// output�� ũ�� ����
	outH = inH * scale;					// output�� input �� �޶���
	outW = inW * scale;
	outImage = malloc2D(outH, outW);

	//*** ��¥ ����ó�� �˰��� ***//
	for (int i = 0; i < outH; i++) {
		for (int k = 0; k < outW; k++) {
			outImage[i][k] = inImage[i/scale][k/scale];
		}
	}
	//*****************************
	printImage();
}

void LotateImage() {
	free2D_out();
	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	outH = inH;
	outW = inW;
	outImage = malloc2D(outH, outW);

	//**** ��¥ ����ó�� �˰��� ***//
	int angle;
	printf("ȸ�� ���� --> ");
	scanf("%d", &angle);
	double radian = angle * 3.141592 / 180.0;

	/* ����
	xd = cos * xs - sin * ys
	yd = sin * xs + cos * ys
	*/
	int xd, yd;
	for (int xs = 0; xs < inH; xs++) {
		for (int ys = 0; ys < inW; ys++) {
			xd = cos(radian) * xs - sin(radian) * ys;
			yd = sin(radian) * xs + cos(radian) * ys;

			if ((0 <= xd && xd < outH) && (0 <= yd && yd < outW)) {
				outImage[xd][yd] = inImage[xs][ys];
			}
		}
	}
	//*****************************
	printImage();
}

// ȸ�� (����� + �߾�ȸ��)				// ����� : Ȧ�� ����� ��
void Lotate2Image() {
	free2D_out();
	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	outH = inH;
	outW = inW;
	outImage = malloc2D(outH, outW);

	//**** ��¥ ����ó�� �˰��� ***//
	int angle;
	printf("ȸ�� ���� --> ");
	scanf("%d", &angle);
	double radian = angle * 3.141592 / 180.0;

	/* ����
	xd = cos * xs - sin * ys
	yd = sin * xs + cos * ys
	*/

	int cx = outH / 2;
	int cy = outW / 2;

	int xs, ys;
	for (int xd = 0; xd < outH; xd++) {
		for (int yd = 0; yd < outW; yd++) {
			xs = cos(radian) * (xd-cx) + sin(radian) * (yd-cy);
			ys = -sin(radian) * (xd-cx) + cos(radian) * (yd-cy);
			xs += cx;
			ys += cy;
			if ((0 <= xs && xs < inH) && (0 <= ys && ys < inW)) {
				outImage[xd][yd] = inImage[xs][ys];
			}
		}
	}
	//*****************************
	printImage();
}

//**************************** //


