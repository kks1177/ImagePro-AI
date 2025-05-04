// Quiz03-03.cpp

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string>
#include <time.h>		// rand
#include <stdlib.h>	
using namespace std;

// **** ���� ������ (�߿�!) **** //
const int ROW = 8, COL = 8;
unsigned char m_image[ROW][COL];

// **** ����� ���� �Լ� **** //
//void cleanScreen();		// ȭ�� �ʱ�ȭ
void image_arr_init();		// �迭 �ʱ�ȭ
void imageToArray();		// �迭 ������
void print_screen();		// �̹��� ȭ�� ���

void addImage();			// (1) ������ ��� ó�� --> ���� ���� (50)
void subImage();			// (����3-1.) ������ ��Ӱ� ó�� --> ���� ���� (100)
void reverseImage();		// (����3-2.) ���� ���� --> if, value:50 => value:205
void grayScaleImage();		// (���� 3-3.) ���� ���ó�� --> 0 or 255�θ�
void L_R_mirroring();		// (���� 3-4.) ���� �¿� �̷���  -->  2���� �̹����� �ʿ�
void T_B_mirroring();		// (���� 3-5.) ���� ���� �̷���
void turnRight();			// (��ȭ ���� 3-6.)��� �̹��� ���������� 90�� ȸ��
void turnLeft();			// (��ȭ ���� 3-6-2.)��� �̹��� �������� 90�� ȸ��

int main()
{
	image_arr_init();
	imageToArray();
	
	// (����)�̹��� ȭ��
	printf(" < ���� �̹��� ȭ�� > \n");
	print_screen();


	////////// ���� ó�� ////////////
	//// (1) ������ ��� ó�� --> ���� ���� (50)
//	addImage();

	//// (����3-1.) ������ ��Ӱ� ó�� --> ���� ���� (100)
//	subImage();

	//// (����3-2.) ���� ���� --> if, value:50 => value:205
//	reverseImage();

	//// (���� 3-3.) ���� ���ó�� --> 0 or 255�θ�
//	grayScaleImage();

	//// (���� 3-4.) ���� �¿� �̷���  -->  2���� �̹����� �ʿ�
//	L_R_mirroring();

	//// (���� 3-5.) ���� ���� �̷���
//	T_B_mirroring();

	//// (��ȭ ���� 3-6.)  ���������� 90�� ȸ��
	turnRight();

	//// (��ȭ ���� 3-6-2.)  �������� 90�� ȸ��
	turnLeft();
}

// ȭ�� �ʱ�ȭ
/*
void cleanScreen() {
	Sleep(3000);		// 2�� ������
	system("cls");		// ȭ�� �ʱ�ȭ
}
*/

// �迭 �ʱ�ȭ
void image_arr_init() {
	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			m_image[i][k] = 0;
		}
	}
}

// �迭 ������
void imageToArray() {
	// �̹��� ���� --> �迭 Loading
	unsigned char pixel;	// �� �� ���� �� (0~255)
	srand(time(NULL));		// ���� �ʱ�ȭ
	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			pixel = rand() % 256;		// ���Ͽ��� �� �� �б�
			m_image[i][k] = pixel;
		}
	}
}

// �̹��� ȭ�� ���
void print_screen() {
	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			printf("%3d ", m_image[i][k]);
		}
		printf("\n");
	}
	printf("\n\n");
}

// (1) ������ ��� ó�� --> ���� ���� (50)
void addImage() {
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
}

// (����3-1.) ������ ��Ӱ� ó�� --> ���� ���� (100)
void subImage() {
	int value = 100;
	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			int px = m_image[i][k] - value;
			if (px > 255) {
				m_image[i][k] = 255;
			}
			else if (px < 0) {
				m_image[i][k] = 0;
			}
			else
				m_image[i][k] -= value;
		}
	}
	printf(" < ���� 100 ���� ȭ�� > \n");
	print_screen(); 
}

// (����3-2.) ���� ���� --> if, value:50 => value:205
void reverseImage() {
	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			int px = 255 - m_image[i][k];
			m_image[i][k] = px;
		}
	}
	printf(" < ���� ���� ȭ�� > \n");
	print_screen();
}

// (���� 3-3.) ���� ���ó�� --> 0 or 255�θ�
void grayScaleImage() {
	int value = 127;
	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			int px = m_image[i][k];
			if (px > value) {
				m_image[i][k] = 255;
			}
			else if (px <= value) {
				m_image[i][k] = 0;
			}
		}
	}
	printf(" < ���� ��� ó�� ȭ�� > \n");
	print_screen();
}

// (���� 3-4.) ���� �¿� �̷���  -->  2���� �̹����� �ʿ�
void L_R_mirroring() {
	unsigned char temp[ROW][COL] = { 0,0 };

	for (int i = 0; i < ROW; i++) 
		for (int k = 0; k < COL; k++) 
			temp[i][k] = m_image[i][k];

	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			int lr_mirror = (COL - 1) - k;

			m_image[i][k] = temp[i][lr_mirror];
		}
	}
	printf(" < ���� �¿� �̷��� ȭ�� > \n");
	print_screen();
}

// (���� 3 - 5.) ���� ���� �̷���
void T_B_mirroring() {
	unsigned char temp[ROW][COL] = { 0,0 };

	for (int i = 0; i < ROW; i++)
		for (int k = 0; k < COL; k++)
			temp[i][k] = m_image[i][k];

	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			int tb_mirror = (ROW - 1) - i;

			m_image[i][k] = temp[tb_mirror][k];
		}
	}

	printf(" < ���� ���� �̷��� ȭ�� > \n");
	print_screen();
}

// (��ȭ ���� 3-6.)��� �̹��� ���������� 90�� ȸ��
void turnRight() {
	printf(" < ���� 90�� ���������� ȸ�� ȭ�� > \n");
	print_screen();
}

// (��ȭ ���� 3-6-2.)��� �̹��� �������� 90�� ȸ��
void turnLeft() {
	printf(" < ���� 90�� �������� ȸ�� ȭ�� > \n");
	print_screen();
}


