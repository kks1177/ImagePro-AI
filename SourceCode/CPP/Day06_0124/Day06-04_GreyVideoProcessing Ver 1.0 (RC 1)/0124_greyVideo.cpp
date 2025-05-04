// 0124_greyVideo.cpp

#define _CRT_SECURE_NO_WARNINGS
using namespace std; // C++ �߰����												// 0124_14:15 �����ؾߵǴ� �� Ȯ��
#include <string>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h> // GUI�� �����ϴ� ���

// **** ���� ������(�߿�!)
char filename[100];
int inH, inW, outH, outW;		// ����� ������ ũ��								////////////// �߰�
unsigned char **inImage, **outImage;												////////////// **�� ����
HWND hwnd; // ���� ȭ��(�ܺ�, ������)
HDC  hdc;  // ���� ȭ��(����, ����)

// **** �Լ� �����(�̸��� ǥ��)
unsigned char** melloc2D(int, int);
void free2D(unsigned char**, int);

void printImage(); void openImage();
void equalImage(); void addImage();
void reverseImage();

void printMenu() {
	puts("\n ## �׷��� ����ó�� (Beta 1) ##\n");
	puts("0.���� 1.���� 9.����\n");
	puts("A.���� B.���/��Ӱ� C.���� .....\n");
}

int main() {
	hwnd = GetForegroundWindow();
	hdc = GetWindowDC(hwnd);

	char inKey = 0;
	while (inKey != '9') {
		printMenu();
		inKey = _getch();
		switch (inKey) {
		case '0': openImage(); break;
		case '9': free2D(inImage, inH); free2D(outImage, outH); break;
		case 'A':
		case 'a': equalImage(); break;
		case 'B':
		case 'b': addImage(); break;
		case 'C':
		case 'c': reverseImage(); break;
		}
	}

	printf("�ȳ��� ������~");
}

// *** ���� �Լ���
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


// 2���� �迭�� ������ִ� �Լ�
unsigned char** malloc2D(int row, int col) {
	unsigned char** retMemory;			// retMemory == inImage

	// �Է¿���(inImage)�� �޸� �Ҵ�. 
	retMemory = (unsigned char**)malloc(row * sizeof(unsigned char*));					// unsigned char �ڿ� * ���� ����!
	for (int i = 0; i < row; i++) {				// ���� �ȼ�, ���� �ȼ� �ٲ� �� ���� ����!
		retMemory[i] = (unsigned char*)malloc(col * sizeof(unsigned char));
	}
	return retMemory;
}														///////// 2���� �迭

// free �Լ�
void free2D(unsigned char** memory, int h) {
	for (int i = 0; i < h; i++) {
		free(memory[i]);
	}
	free(memory);
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
	if (rfp == NULL)																										///////////// ���� ó��
		return;



	// �Է� ������ ũ�⸦ �˾Ƴ��� �ڵ�. --> inH, inW ����
	fseek(rfp, 0L, SEEK_END);		// ������ ������ �̵�
	unsigned long fsize = ftell(rfp);			// �� ����?    262144(=512x512)
	fclose(rfp);

	inH = inW = sqrt(fsize);			// if, 512x512
	// �Է¿��� (inImage)�� �޸� �Ҵ�
	inImage = malloc2D(inH, inW);

	// ���� --> �޸𸮷� �ε�
	rfp = fopen(filename, "rb");
	for (int i = 0; i < inH; i++) {
		fread(inImage[i], sizeof(unsigned char), inW, rfp);
	}


	// ���� �ݱ�
	fclose(rfp);
	equalImage();
}


//***** ���� ó�� �Լ� ���� ******
void equalImage() {
	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	outH = inH;
	outW = inW;
	outImage = malloc2D(outH, outW);

	//// ** ��¥ ����ó�� �˰��� ** ////
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			outImage[i][k] = inImage[i][k];
		}
	}
	// ******************************** //
	printImage();
}

void addImage() {
	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	outH = inH;
	outW = inW;
	outImage = malloc2D(outH, outW);

	//// ** ��¥ ����ó�� �˰��� ** ////
	int value;
	printf("����� ��-->");
	scanf("%d", &value);
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			int px = inImage[i][k] + value;
			if (px > 255)
				px = 255;
			else if (px < 0)
				px = 0;
			outImage[i][k] = px;
		}
	}
	printImage();
}

void reverseImage() {// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	outH = inH;
	outW = inW;
	outImage = malloc2D(outH, outW);

	//// ** ��¥ ����ó�� �˰��� ** ////

	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			outImage[i][k] = 255 - inImage[i][k];
		}
	}
	printImage();
}
//******************************