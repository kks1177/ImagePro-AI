// GreyVideoProcessing_Ver1.0 (Preview1).cpp
// 22.01.26		������׷� ��Ʈ��Ī, ����-�� Ž��, ������׷� ��Ȱȭ �߰�


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>		// GUI �������ִ� ���
#include <string>
using namespace std;	// C++ �߰� ���

#include "FunctionDeclaretion.h"
#include "FunctionDifinition.h"

int main()
{
	hwnd = GetForegroundWindow();
	hdc = GetWindowDC(hwnd);

	choiceMenu();

	printf("\n%60s \n", "���α׷� ����!");
}

