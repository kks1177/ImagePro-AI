#define _CRT_SECURE_NO_WARNINGS
using namespace std; // C++ �߰����
#include <string>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h> // GUI�� �����ϴ� ���
#include <math.h>

//======================================================================================================
//*****************************������Ʈ�� : 2022 GrayScale Image Processing 
//*****************************��      �� : ver 1 preview
//======================================================================================================

//���� ������//
char filename[100];
int inH, inW, outH, outW; // ����� ������ ũ��, �� ����� ������ �̹�������, �ʺ� 
const double pi = 3.145926535897932; //�̹��� ȸ���� �ʿ��� ��
int inKey = 0; // �̹��� ó�� 4���� �� �з�


short x_mov = 0; // printImage ���÷��� ��ǥ
short y_mov = 0;

unsigned char** inImage = NULL, ** outImage = NULL; // �Է��̹���, ����̹���
unsigned char** tmpIn1 = NULL; unsigned char** tmpOut1 = NULL; // �ӽ� ����� �̹��� ����

HWND hwnd; // ���� ȭ��(�ܺ�, ������)
HDC  hdc;  // ���� ȭ��(����, ����)

////////////////////// **** �Լ� ����� ******/////////////////////////////////////////////
// 
//********�����Լ�**********//
unsigned char** malloc2D(int, int);// 2���� �迭 �޸� �Ҵ� �� ����
void free2D(unsigned char**, int);
void free2D_out();

void openImage(); void originalImage(); void print_ori_Image();
void printImage();

//********�̹��� ó�� �Լ�**********//

void equalImage();
void reverseImage(); void timesImage();
void divideImage(); void blackWhiteImage();
void mean(); void bitImage(); void GammaCorrection();
void rangeFocus(); void parabola(); void stretch();
void mirrorImage1(); void mirrorImage2(); void mirrorImage3();
void rot90(); void rot180(); void rot270();
void moving(); void rotate();
void enlarge();  void zoomInbiImage();  void backwarding();
void microprint(); void histostretch(); void endin();
void saveImage(); void histoEqual(); void blurring();
void embossing();

void printMenu() {
    char input = 0;

    puts("\n ## GrayScale Image Processing ver 1.0 RC5 ##\n");
    puts(" 0. ���� \t 1. ���� \t 2. ����\n");
    input = _getch();

    system("CLS"); // ����Ʈ�޴� ���� �����Ҷ� ȭ���� �����ϰ� �� 

    printf("0. ȭ����ó�� \n");
    printf("1. ������ó��\n");
    printf("2. ȭ�ҿ���ó�� \n");
    printf("3. ȭ�ҿ���ó��(����) \n");
    printf("4. ������׷�ó�� \n");

    while (input != 2)
    {
        char inKey = 0;

        inKey = _getch();
        switch (inKey) {
        case '0':
            puts(" ##################### 1. ȭ���� ó�� ####################### \n");
            puts("A.��� \t B.���� \t C.������ \t D.����\n");
            puts("E.���(128) \t F.���(���) \t G. ��Ʈ����\n");
            puts("H. �������� \t I.�������� \t J.�Ķ󺼶� \t K.��Ʈ��Ī\n");
            break;
        case '1':
            puts(" ##################### 2. ������ ó�� ###################### \n");
            break;
        case '2':
            puts(" ##################### 3. ȭ�ҿ���ó�� ##################### \n");
            break;
        case '3':
            puts(" ##################### 4. ȭ�ҿ���ó��(����) ############### \n");
            break;
        case '4':
            puts(" ##################### 5. ������׷� ó�� ################## \n");
            break;
        default: printf("\n �߸� �Է��ϼ̽��ϴ�. �ٽ� �����ϼ��� \n\n\n\n\n");
        }
        printf(" GrayScale Image Processing(ver 1.0) RC5 ������ �ּż� �����մϴ�.\n\n\n\n");
        printf("������ �̵��\n\n\n\n");
    }
}

// �����Լ� //

int main() {
    hwnd = GetForegroundWindow();
    hdc = GetWindowDC(hwnd);

    char button = 0;

    printMenu();
    button = _getch();
    if (inKey == 0) {
        switch (button) {
        case 'A':case 'a': openImage(); break;
        case 'B':case 'b': equalImage(); break;
        }
    }
    printf(" GrayScale Image Processing(ver 1.0) RC5 ������ �ּż� �����մϴ�.\n\n\n\n");
    printf("������ �̵��\n\n\n\n");
}

