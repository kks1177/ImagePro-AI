// 0126_greyVideo


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
void histoStretch();	void endIn();		void histoEqual();
void embossing();		void blurring();



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
		case 'V':	case 'v':	histoStretch(); break;
		case 'W':	case 'w':	endIn(); break;
		case 'X':	case 'x':	histoEqual(); break;
		case '@':					embossing(); break;
		case '#':					blurring(); break;

		}
	}
	printf("�ȳ��� ������~");
}

void printMenu() {
	puts("\n ## �׷��� ����ó�� (Beta 1) ##\n");
	puts("0.���� 1.���� 9.����\n");
	puts("A.���� B.���� .....\n");
	puts("K.��� L.Ȯ�� M.Ȯ��(�����) N.ȸ�� O.ȸ��(�����+�߾�).....\n");
	puts("V.������׷� ��Ʈ��Ī W.����-�� Ž�� X.������׷� ��Ȱȭ \n");
	puts("@.������  #.���� \n");
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
			outImage[i / scale][k / scale] = inImage[i][k];
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
			outImage[i][k] = inImage[i / scale][k / scale];
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
			xs = cos(radian) * (xd - cx) + sin(radian) * (yd - cy);
			ys = -sin(radian) * (xd - cx) + cos(radian) * (yd - cy);
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



// ������׷� ��Ʈ��ġ
void histoStretch() {
	free2D_out();
	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	outH = inH;
	outW = inW;
	outImage = malloc2D(outH, outW);

	//**** ��¥ ����ó�� �˰��� ***//
	// ����. (����-�� Ž��)
	// out = (in - low) / (high - low) * 255.0;.

	int low = inImage[0][0], high = inImage[0][0];		// �ʱ�ȭ ���� ������ ���
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			if (inImage[i][k] < low)
				low = inImage[i][k];
			if (inImage[i][k] > high)
				high = inImage[i][k];
		}
	}

	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			outImage[i][k] = (double)(inImage[i][k] - low) / (high - low) * 255.0;
		}
	}
	//*****************************
	printImage();
}

// ������׷� ����-�� Ž��
void endIn() {
	free2D_out();
	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	outH = inH;
	outW = inW;
	outImage = malloc2D(outH, outW);

	//**** ��¥ ����ó�� �˰��� ***//
	int low = inImage[0][0], high = inImage[0][0];		// �ʱ�ȭ ���� ������ ���
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			if (inImage[i][k] < low)
				low = inImage[i][k];
			if (inImage[i][k] > high)
				high = inImage[i][k];
		}
	}
	low += 50;
	high -= 50;
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			double res = (double)(inImage[i][k] - low) / (high - low) * 255.0;
			if (res <= 0.0)
				outImage[i][k] = 0;
			else if (res > 255.0)
				outImage[i][k] = 255;
			else
				outImage[i][k] = res;
		}
	}
	//*****************************
	printImage();
}

// ������׷� ��Ȱȭ
/*
* 1�ܰ� : ��� �� j�� �󵵼� hist[j]�� ����� �Է� ������ ������׷� ����
* 2�ܰ� : �� ��� �� i���� 0~i������ ���� �󵵼�(������)�� ���
* 3�ܰ� : 2�ܰ迡�� ���� ���� �󵵼��� ����ȭ (����ȭ ������)
*/
void histoEqual() {
	free2D_out();
	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	outH = inH;
	outW = inW;
	outImage = malloc2D(outH, outW);

	//**** ��¥ ����ó�� �˰��� ***//
	// 1�ܰ� : ������׷� ����
	int histo[256] = { 0, };
	for (int i = 0; i < inH; i++)
		for (int k = 0; k < inW; k++)
			histo[inImage[i][k]]++;

	// 2�ܰ� : ���� ������׷� ���� (������ ����)
	int sumHisto[256] = { 0, };
	sumHisto[0] = histo[0];
	for (int i = 1; i < 256; i++)
		sumHisto[i] = sumHisto[i - 1] + histo[i];

	// 3 �ܰ� : ����ȭ�� ���� ������׷� ���� (����ȭ�� ������ ����)
	// n = sum * (1/(inH*inW)) * 255.0
	double normalHisto[256] = { 0, };
	for (int i = 0; i < 256; i++)
		normalHisto[i] = sumHisto[i] * (1.0 / (inH * inW)) * 255.0;

	// 4�ܰ� : �������� ����ȭ ������ ġȯ
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			outImage[i][k] = normalHisto[inImage[i][k]];
		}
	}	
	//*****************************
	printImage();
}




double** malloc2D_double(int row, int col) {
	double** retMemory;
	retMemory = (double**)malloc(row * sizeof(double*));
	for (int i = 0; i < row; i++)
		retMemory[i] = (double*)malloc(col * sizeof(double));
	return retMemory;
}
void free2D_double(double** memory, int h) {
	for (int i = 0; i < h; i++)
		free(memory[i]);
	free(memory);
}

// ȭ�ҿ��� ó��
// ������
void embossing() {
	free2d_out();
	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	outh = inh;
	outw = inw;
	outimage = malloc2d(outh, outw);

	//**** ��¥ ����ó�� �˰��� ***//
	const int msize = 3;		// ����ũ ũ��
	// ������ ����ũ (�� ��ɿ� ���� ����ũ�� ���糪 ���۸�)
		double mask[msize][msize] = { {-1,0,0},
										{ 0,0, 0},
										{0,0,1} };

	// �ӽ� ����� �޸� �Ҵ�
	double** tmpin, ** tmpout;
	tmpin = malloc2d_double(inh + 2, inw + 2);
	tmpout = malloc2d_double(outh, outw);

	// �ӽ� �Է��� 0���� �ʱ�ȭ
	for (int i = 0; i < inh + 2; i++)
		for (int k = 0; k < inw + 2; k++)
			tmpin[i][k] = 0.0;

	// �Է� ���� --> �ӽ� �Է� ���� (inimage --> tmpinimage)
	for (int i = 0; i < inh; i++)
		for (int k = 0; k < inw; i++)
			tmpin[i + 1][k + 1] = inimage[i][k];

	// ȸ�� ���� --> ����ũ�� �ܾ�鼭 ����ϱ�
	double s;		// ������ ���� �Է� ���� x ����ũ�� �հ�
	for (int i = 0; i < inh; i++) {
		for (int k = 0; k < inw; k++) {
			s = 0.0;
			for (int m = 0; m < msize; m++) {
				for (int n = 0; n < msize; n++) {
					s += tmpin[i + m][k + n] * mask[m][n];
				}
			}
			tmpout[i][k] = s;
		}
	}
	// ��ó�� (����ũ�� �հ迡 ���� ����...)
	// ����ũ �հ谡 0�� ��쿡�� �߰� 
	for (int i = 0; i < outh; i++) {
		for (int k = 0; k < outw; k++) {
			tmpout[i][k] += 127.0;
		}
	}
	//  �ӽ� ��� --> ��� �޸�
	for (int i = 0; i < outh; i++) {
		for (int k = 0; k < outw; k++) {
			double v = tmpout[i][k];
			if (v > 255.0)
				v = 255.0;
			else if (v < 0.0)
				v = 0.0;
			outimage[i][k] = v;
		}
	}
	free2d_double(tmpin, inh + 2);
	free2d_double(tmpout, outh);

	printimage();
}

// ����
void blurring() {
	free2D_out();
	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	outH = inH;
	outW = inW;
	outImage = malloc2D(outH, outW);

	//**** ��¥ ����ó�� �˰��� ***//
	const int MSIZE = 3;		// ����ũ ũ��
	// ������ ����ũ (�� ��ɿ� ���� ����ũ�� ���糪 ���۸�)
	double mask[MSIZE][MSIZE] = { {1./9, 1./9, 1./9},
												      {1./9, 1./9, 1./9},
													  {1./9, 1./9, 1./9} };

	// �ӽ� ����� �޸� �Ҵ�
	double** tmpIn, ** tmpOut;
	tmpIn = malloc2D_double(inH + 2, inW + 2);
	tmpOut = malloc2D_double(outH, outW);

	// �ӽ� �Է��� 0���� �ʱ�ȭ
	for (int i = 0; i < inH + 2; i++)
		for (int k = 0; k < inW + 2; k++)
			tmpIn[i][k] = 0.0;

	// �Է� ���� --> �ӽ� �Է� ���� (inImage --> tmpInImage)
	for (int i = 0; i < inH; i++)
		for (int k = 0; k < inW; i++)
			tmpIn[i + 1][k + 1] = inImage[i][k];

	// ȸ�� ���� --> ����ũ�� �ܾ�鼭 ����ϱ�
	double S;		// ������ ���� �Է� ���� x ����ũ�� �հ�
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			S = 0.0;
			for (int m = 0; m < MSIZE; m++) {
				for (int n = 0; n < MSIZE; n++) {
					S += tmpIn[i + m][k + n] * mask[m][n];
				}
			}
			tmpOut[i][k] = S;
		}
	}
	// ��ó�� (����ũ�� �հ迡 ���� ����...)
	/*
	for (int i = 0; i < outH; i++) {
		for (int k = 0; k < outW; k++) {
			tmpOut[i][k] += 127.0;
		}
	}
	*/

	//  �ӽ� ��� --> ��� �޸�
	for (int i = 0; i < outH; i++) {
		for (int k = 0; k < outW; k++) {
			double v = tmpOut[i][k];
			if (v > 255.0)
				v = 255.0;
			else if (v < 0.0)
				v = 0.0;
			outImage[i][k] = v;
		}
	}
	free2D_double(tmpIn, inH + 2);
	free2D_double(tmpOut, outH);

	printImage();
}



