// Quiz04-02.cpp

#define _CRT_SECURE_NO_WARNINGS
#define LEN 80

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string>
using namespace std;

// c:\windows\win.ini ����
int main()
{
	char str[LEN];
	FILE* rfp;		// FILE* : ��������� ���� �׳� ������ ���			// rfp : Read File Pointer (Disk�� �ִ� ���Ͽ� ����)

	//// (1) ���� ���� ////
	rfp = fopen("c:\\windows\\win.ini", "r");		// �б�

	//// (2) ���� �б� �Ǵ� ���� ��� ////
	int lineNum = 1;		// ���� ���ȣ�� ���� ����
	while(1) {
		fgets(str, LEN, rfp);	// str ������ �־��, �ִ� 80 ���� �о�Ͷ�, rfp����

		// ���Ͽ� ������ ���̻� ������ ����
		if (feof(rfp))		// feof : File end of File
			break;

		// ASCII �ڵ�ǥ�� ���� �ҹ��� -> �빮�� ��ȯ, ���� -> # ��ȯ
		for (int i = 0; i < LEN; i++) {
			if (str[i] == '\n')
				break;

			// �ҹ��� -> �빮��
			if ('a' <= str[i] && str[i]  <= 'z') {
				str[i] -= ('a' - 'A');
			}

			// ���� -> #
			else if ('0' <= str[i] && str[i] <= '9') {
				str[i] = '#';
			}
			printf("%c", str[i]);
		}
		printf("%d : %s", lineNum, str);
		lineNum++;
	}

	//// (3) ���� �ݱ� ////
	fclose(rfp);

}
