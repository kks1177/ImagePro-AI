// Image_Processing.cpp

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string>
#include <time.h>		// rand
#include <stdlib.h>	
using namespace std;

// ���� ����
const int ROW = 8, COL = 8;
unsigned char m_image[ROW][COL];

int main()
{
	// �̹��� �迭 �ʱ�ȭ
	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			m_image[i][k] = 0;
		}
	}

	// �̹��� ���� --> �迭 Loading
	unsigned char pixel;	// �� �� ���� �� (0~255)
	srand(time(NULL));		// ���� �ʱ�ȭ
	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			pixel = rand() % 256;		// ���Ͽ��� �� �� �б�
			m_image[i][k] = pixel;
		}
	}
	
	// �̹����� ȭ�� ���
	/*
	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			printf("%3d ", m_image[i][k]);
		}
		printf("\n");
	}
	printf("\n\n");
	*/




	////////// ���� ó�� ////////////
	/// (1) ������ ��� ó�� --> ���� ���� (50)
	int value = 50;
	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			int px = m_image[i][k] + value;
			if (px > 255) {
				m_image[i][k] = 255;
			}
			else
				m_image[i][k] += value;
		}
	}

	// �̹����� ȭ�� ���
	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			printf("%3d ", m_image[i][k]);
		}
		printf("\n");
	}
	printf("\n\n");
}


