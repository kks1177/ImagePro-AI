// FileInputOutput.cpp
// ���� �����

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string>
using namespace std;

// c:\windows\win.ini ����
int main()
{
	char str[80];
	FILE* rfp;		// FILE* : ��������� ���� �׳� ������ ���			// rfp : Read File Pointer

	//// (1) ���� ���� ////
	rfp = fopen("c:\\windows\\win.ini", "r");		// �б�

	//// (2) ���� �б� �Ǵ� ���� ��� ////
	while (1) {
		fgets(str, 80, rfp);	// str ������ �־��, �ִ� 80 ���� �о�Ͷ�, rfp����
		if (feof(rfp))			// => ������ ������ �� �̻� ������ ����		// feof : File end of File
			break;
		printf("%s", str);
	}

	//// (3) ���� �ݱ� ////
	fclose(rfp);

}
