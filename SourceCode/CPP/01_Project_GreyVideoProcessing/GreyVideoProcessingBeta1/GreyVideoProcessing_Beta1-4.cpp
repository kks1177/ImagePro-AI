// GreyVideoProcessing_Beta1-4.cpp

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

#include "GreyVideoProcessing_Beta1-4.h"

int main()
{
	hwnd = GetForegroundWindow();
	hdc = GetWindowDC(hwnd);

	choiceMenu();

	printf("\n%60s \n", "���α׷� ����!");
}

