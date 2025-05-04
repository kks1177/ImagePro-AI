// Mission2_ImageProcessing.cpp
// 0119_�̼�

// �̼�2. 5x8ũ���� 2���� �迭 �غ�, 0~255���� ���� ��, �迭 ���
/*
* (�̼�2-1.) �̹��� 50 ��� ó��
* (�̼�2-2.) �̹��� 100 ��Ӱ� ó�� 
* (�̼�2-3.) �̹��� ���� ��� ó��
* (�̼�2-4.) �̹��� ���� ó��
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>		// rand
#include <stdlib.h>		// rand
using namespace std;

// ���� ����
const int ROW = 5, COL = 8;
unsigned char m_image[ROW][COL] = { 0,0 };

void imageAryInit();		// �̹��� �迭 �ʱ�ȭ
void imageToArray();		// �̹��� ���� --> �迭
void printScreen();			// �̹��� ȭ�� ���

int main()
{
	// �̹��� �迭 �ʱ�ȭ
	imageAryInit();

	// �̹��� ���� --> �迭
	imageToArray();

	// (����) �̹��� ȭ��
	printf(" < (����) �̹��� ȭ�� > \n");
	printScreen();

	
	/////// ���� ó�� ///////
	//// (�̼�2-1.) ������ 50 ��� ó��
	/*
	int value = 50;
	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			int px = m_image[i][k] + value;
			if (px > 255) {
				m_image[i][k] = 255;
			}
			else if (px < 0) {
				m_image[i][k] = 0;
			}
			else {
				m_image[i][k] += value;
			}
		}
	}
	printf(" < ���� 50 ���� ȭ�� > \n");
	printScreen();
	*/

	//// (�̼�2-2.) ������ 100 ��Ӱ� ó��
	/*
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
			else {
				m_image[i][k] -= value;
			}
		}
	}
	printf(" < ���� 100 ���� ȭ�� > \n");
	printScreen();
	*/

	//// (�̼�2-3.) ���� ���� ��� ó�� 
	/*
	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			int px = m_image[i][k];
			if (px > 127) {
				m_image[i][k] = 255;
			}
			else {
				m_image[i][k] = 0;
			}
		}
	}
	printf(" < ���� ��� ó�� ȭ�� > \n");
	printScreen();
	*/

	//// (�̼�2-4.) �̹��� ���� ó��
	/*
	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			int px = 255 - m_image[i][k];
			m_image[i][k] = px;
		}
	}
	printf(" < ���� ���� ó�� ȭ�� > \n");
	printScreen();
	*/

}



// �̹��� �迭 �ʱ�ȭ
void imageAryInit() {
	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			m_image[i][k] = 0;
		}
	}
}

// �̹��� ���� --> �迭 Loading
void imageToArray() {
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
void printScreen() {
	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			printf(" %3d ", m_image[i][k]);
		}
		printf("\n");
	}
	printf("\n\n");
}



