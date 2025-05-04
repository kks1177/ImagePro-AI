// Declaretion_copy.h


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>		// GUI �������ִ� ���
#include <string>
using namespace std;		// C++ �߰� ���


// ============================== < ���� ������ (�߿�!) > ============================== //
char imgName[100] = { 0 };		// ���ϸ� + .Ȯ���ڸ�
char filePath[100] = { 0 };			// ���� ��� ���� ����

char inKey = 0;			// Ű����� �Է� �޴� ����
char algoPick = 0;		// Ű����� �Է� �޴� �˰��� �޴� ����
char pix = 0;				// pixel, �̹��� ��� ����
//char morpPix = 0;

int inH, inW, outH, outW;		// ����� �̹����� ũ�� (����/�ʺ�)

unsigned char** inImage = NULL, ** outImage = NULL;		// �Է� �̹���(�̹��� �ʱⰪ), ����̹���
unsigned char** morpImage = NULL;

HWND hwnd;	// ������ ȭ�� (�ܺ�, ������)		// �ϱ�x
HDC  hdc;			// �޵��� ȭ�� (����, ����)		// �ϱ�x


// ============================= < �޴� ���� �Լ� ����� > ============================= //
void mainMenu();									// �⺻ �޴� UI
void printMenu(char functionChoice);	// ��ü �޴� UI
int choiceMenu();									// �޴� ����


// =========================== < �̹��� ����� �Լ� ����� > =========================== //
unsigned char** melloc2D(int, int);		// 2���� �迭 ���� �Լ�
void free2D(unsigned char**, int);		// free �Լ�
void free2D_out();									// ��� free �Լ�

void openImage();									// �̹��� ���� open (�Է�)
void saveImage();									// ��� �̹��� ���� �Լ�
//void openMorpImage();							// ������ �̹��� open (�Է�)

void originImage(char oriImage);			// ���� �̹���
void resultImage(char oriImage);			// ��� �̹���
void ori_printScreen();							// ���� �̹��� ȭ�� ���
void res_printScreen();							// ��� �̹��� ȭ�� ���


// =========================== < 1.ȭ���� ó�� ��� �Լ� ����� > ======================== //
void brightControlImage();			// A.��� ����	
void clearControlImage();				// B.���� ����
void reverseImage();						// C.����
void grayScaleImage();					// D.��� (128/���)
void bitCalcImage();						// E.��Ʈ ���� (And/Or/Xor/Not)
void gammaConverseImage();		// F.���� ��ȯ
void rangeEmphasisImage();		// G.���� ����
void parabolaImage();					// H.�Ķ󺼶� ��ȯ 
void stretchedImage();					// I.��ϴ�� ��Ʈ��Ī


// ===================== < 2.ȭ����(������׷�) ó�� ��� �Լ� ����� > ===================== //
void printHisto();							// A.������׷� ���
void histoStretchImage();				// B.������׷� ��Ʈ��Ī
void histoEndInImage();				// C.������׷� ����-�� Ž��
void histoEqualImage();				// D.������׷� ��Ȱȭ


// ========================== < 3.ȭ�ҿ��� ó�� ��� �Լ� ����� > ======================= //
double** malloc2D_double(int row, int col);
void free2D_double(double** memory, int h);

void embossingImage();				// A.������ 
void blurringImage();					// B.����
void sharpeningImage();				// C.������
void smoothingImage();				// D.������ (����þ�)


// ========================== < 4.ȭ�ҿ��� (���� ����) ó�� ��� �Լ� ����� > ======================= //
void shiftDifferEdgeImage();			// A.�̵��� ���� ���� ���� (����, ����, ��������)


// ============================ < 5.������ ó�� �Լ� ����� > =========================== //
void mirroringImage();  				// A.�̷��� (�¿�/����/�¿�+����)
void turnImage();							// B.ȸ�� (����, 90/180/270��/����-�����+�߾�)	
void imageSizeUpDown();				// C.�̹��� ũ��(�԰�) Ȯ��/���
void moveImage();						// D.�̵�
void warpingImage();					// E.����
//void morphingImage();					// F.����



// ============================ < ��� ó�� �Լ� ����� > ============================== //
void inImgCheck();		// �Է� �̹��� �Է� ���� Ȯ��

void inImg_128();			// �̹��� ���� �Է�_128x128
void inImg_256();			// �̹��� ���� �Է�_256x256
void inImg_512();			// �̹��� ���� �Է�_512x512
void outImg_128();		// �̹��� ���� ���_128x128
void outImg_256();		// �̹��� ���� ���_256x256
void outImg_512();		// �̹��� ���� ���_512x512
//void morpOutImg();		// ������ �̹��� ���

void clearUp(int val);					// 1-B.�����ϰ�
void clearDown(int val);			// 1-B.�帴�ϰ�

void grayScale128();					// 1-D.���ó�� (128 ����)
void grayScaleAvg();					// 1-D.���ó�� (��հ� ����)

void bitCalc_And(int val);			// 1-E.��Ʈ����_And
void bitCalc_Or(int val);				// 1-E.��Ʈ����_Or
void bitCalc_Xor(int val);			// 1-E.��Ʈ����_Xor
void bitCalc_Not();					// 1-E.��Ʈ����_Not

void parabolaCap();					// 1-H.�Ķ󺼶�_CAP ��ȯ
void parabolaCup();					// 1-H.�Ķ󺼶�_CUP ��ȯ


void blurring33();						// 3-B.3x3 ����
void blurring55();						// 3-B.5x5 ����

void sharpening();						// 3-C.������
void HPF_sharp();						// 3-C.���������� ó�� ������
void LPF_sharp();						// 3-C.���������� ó�� ������


void horizontalEdge();				// 4-A.���� ����
void verticalEdge();					// 4-A.���� ����
void horiVertiEdge();					// 4-A.���� ���� ����


void L_R_mirroring();				// 5-A.�¿� �̷���
void T_B_mirroring();				// 5-A.���� �̷���
void TB_LR_mirroring();			// 5-A.����/�¿� �̷���

void turn90Right();					// 5-B.���������� 90�� ȸ��
void turn180Right();					// 5-B.���������� 180�� ȸ��
void turn270Right();					// 5-B.���������� 270�� ȸ��
void turn90Left();						// 5-B.�������� 90�� ȸ��
void turn180Left();					// 5-B.�������� 180�� ȸ��
void turn270Left();					// 5-B.�������� 270�� ȸ��
void turnFree(int val);				// 5-B.����ȸ�� (������)
void turnFreeCenter(int val);		// 5-B.����ȸ�� (�����+�߾�ȸ��)

void sizeUp(int val);									// 5-C.�̹��� ũ�� Ȯ�� (������)
void backwardMappingSizeUp(int val);		// 5-C.�̹��� ũ�� Ȯ�� (�����, Backward Mapping)
void sizeDown(int val);								// 5-C.�̹��� ũ�� ��� (������)
void backwardMappingSizeDown(int val);	// 5-C.�̹��� ũ�� ��� (�����)


