// GreyVideoProcessing_Ver1.0 (RC 4).cpp


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
#include <Windows.h>		// GUI �������ִ� ���
#include <string>
using namespace std;	// C++ �߰� ���

#include "Declaration4.h"
#include "Difinition4.h"

int main()
{
	hwnd = GetForegroundWindow();
	hdc = GetWindowDC(hwnd);

	choiceMenu();

	printf("\n%60s \n", "���α׷� ����!");
}

