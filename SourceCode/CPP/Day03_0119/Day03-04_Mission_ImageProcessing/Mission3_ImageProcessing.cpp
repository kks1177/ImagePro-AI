// Mission3_ImageProcessing.cpp

// �̼�3. 5x7 ũ���� 2���� �迭 2�� �غ�, 0~255 ������ ���� ��
//		5x7 ũ���� ��� ������ �� �迭 1�� �غ�, ����Ͽ� Ȯ��
/*
* (�̼�3-1.) �� �̹��� ��ø, ��� �̹����� ����
* (�̼�3-2.) �� �̹��� ��, ��հ� ���� �̹��� ���
* (�̼�3-3.) �� �̹��� ��, �߾Ӱ� ���� �̹��� ���
* (�̼�3-4.) ��� �̹��� ���ó��
* (�̼�3-5.) ��� �̹��� ��հ����� ���ó��
* (�̼�3-6.) ��� �̹��� �߾Ӱ����� ���ó��
* (�̼�3-7.) ��� �̹��� 90�� ȸ��
*/


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
using namespace std;

const int ROW = 5, COL = 7;			// �� : 5, �� : 7
const int ARY_SIZE = ROW * COL;		// �迭 ������ ũ��
unsigned char m_image1[ROW][COL] = { 0,0 };				// ���� �̹��� �迭1 �ʱ�ȭ
unsigned char m_image2[ROW][COL] = { 0,0 };				// ���� �̹��� �迭2 �ʱ�ȭ
unsigned char tempArrayImage[ROW][COL] = { 0,0 };		// ��� ����� �� �迭 �ʱ�ȭ

void cleanScreen();			// ȭ�� �ʱ�ȭ
void imageAryInit();		// �迭 �ʱ�ȭ
void imageToArray();		// �迭 ������
void printScreen1();		// �̹��� ȭ��1 ���
void printScreen2();		// �̹��� ȭ��2 ���
void printResScreen();		// ��� ȭ�� ���
void full_image();			// ��ü �̹��� ȭ�� ���
void overlapImage();		// �� ���� �̹��� �迭 ��ø
void findHighAvr_image();	// ��հ� ���� �̹��� ���
void findHighMid_image();	// �߾Ӱ� ���� �̹��� ���
void blackWhite();			// ��� �̹��� ���
void turnRight();			// ��� �̹��� ���������� 90�� ȸ��
void turnLeft();			// ��� �̹��� �������� 90�� ȸ��

int main()
{
	printf("============< �ʱ� ���� >============\n");
	imageAryInit();
	imageToArray();
	full_image();

	cleanScreen();

	// �̼�3-1. �̹��� ��ø
	printf("============< �̼� 3-1 >============\n");
	overlapImage();
	full_image();

	cleanScreen();

	// �̼�3-2. ��հ� ���� �̹��� ���
	printf("============< �̼� 3-2 >============\n");
	findHighAvr_image();

	cleanScreen();

	// �̼�3-3. �߾Ӱ� ���� �̹��� ���
	printf("============< �̼� 3-3 >============\n");
	findHighMid_image();

	/*
	cleanScreen();

	// �̼�3-4. ��� �̹��� ��� ó��
	printf("============< �̼� 3-4 >============\n");
	blackWhite();
	printResScreen();

	cleanScreen();

	// �̼�3-5. ��� �̹��� ��հ����� ���ó��
	printf("============< �̼� 3-5 >============\n");

	cleanScreen();

	// �̼�3-6. ��� �̹��� �߾Ӱ����� ���ó��
	printf("============< �̼� 3-6 >============\n");

	cleanScreen();

	// �̼�3-7-01 ��� �̹��� ���������� 90�� ȸ��
	printf("============< �̼� 3-7-01 >============\n");
	turnRight();

	cleanScreen();

	// �̼�3-7-02 ��� �̹��� �������� 90�� ȸ��
	printf("============< �̼� 3-7-02 >============\n");
	turnLeft();
	*/
}


// ȭ�� �ʱ�ȭ
void cleanScreen() {
	Sleep(3000);		// 2�� ������
	system("cls");		// ȭ�� �ʱ�ȭ
}

// �迭 �ʱ�ȭ
void imageAryInit() {
	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			m_image1[i][k] = 0;
			m_image2[i][k] = 0;
			tempArrayImage[i][k] = 0;
		}
	}
}

// �迭 ������ 
void imageToArray() {
	unsigned char data;
	srand((int)time(NULL));
	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			data = rand() % 256;
			m_image1[i][k] = data;
		}
	}
	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			data = rand() % 256;
			m_image2[i][k] = data;
		}
	}
}

// �̹��� ȭ��1 ���
void printScreen1() {
	// ����1 �̹��� ȭ�� ���
	printf("\t< �̹��� 1 ȭ�� > \n");
	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			printf(" %3d ", m_image1[i][k]);
		}
		printf("\n");
	}
}

// �̹��� ȭ��2 ���
void printScreen2() {
	printf("\n");
	// ����2 �̹��� ȭ�� ���
	printf("\t< �̹��� 2 ȭ�� > \n");
	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			printf(" %3d ", m_image2[i][k]);
		}
		printf("\n");
	}
}

// ��� �̹��� ȭ�� ���
void printResScreen() {
	printf("\n -----------------------------------");

	// ��� ����� �迭 ���
	printf("\n\n <  ��� ����� �̹��� ȭ�� > \n");
	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			printf(" %3d ", tempArrayImage[i][k]);
		}
		printf("\n");
	}
	printf("\n\n");
}

// ��ü �̹��� ȭ�� ��� 
void full_image() {
	printScreen1();
	printScreen2();
	printResScreen();
}

// �̼�3-1
// �� ���� �̹��� ��ø
void overlapImage() {
	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			tempArrayImage[i][k] = m_image1[i][k] + m_image2[i][k];
		}
	}
}

// �̼�3-2
// ��հ� ���� �̹��� ���
void findHighAvr_image() {
	int hap1 = 0, hap2 = 0;
	float avr1 = 0, avr2 = 0;

	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			hap1 += m_image1[i][k];
			hap2 += m_image2[i][k];
		}
	}
	avr1 = (float)(hap1 / ARY_SIZE);
	avr2 = (float)(hap2 / ARY_SIZE);

	//// ��հ� �� �� �̹��� ��� ////
	if (avr1 > avr2) {
		printScreen1();
	}
	else if (avr1 < avr2) {
		printScreen2();
	}
	else
		printf("��հ� ���� \n");

	printf("\n\n --- ��հ� ---");
	printf("\n�̹���1 : %.2f, �̹���2 : %.2f\n", avr1, avr2);
}

// �̼�3-3
// �߾Ӱ� ���� �̹��� ���
void findHighMid_image() {
	int mid1 = 0, mid2 = 0;		// �߾Ӱ�1, 2
	int temp = 0;
	int count = 0;
	int image1_sort[ARY_SIZE] = {0, 0};
	int image2_sort[ARY_SIZE] = {0, 0};

	/// 2���� �迭 -> 1���� �迭 ��ȯ ////
	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			image1_sort[count] = m_image1[i - 1][k - 1];
			image2_sort[count] = m_image2[i - 1][k - 1];
			count += 1;
		}
	}

	//// �迭 ���� ////
	for (int i = 0; i < ARY_SIZE-1; i++) {
		for (int k = i+1; k < ARY_SIZE; k++) {
			if (image1_sort[i] > image1_sort[k]) {
				temp = image1_sort[i];
				image1_sort[i] = image1_sort[k];
				image1_sort[k] = temp;
			}
		}
	}
	for (int i = 0; i < ARY_SIZE - 1; i++) {
		for (int k = i + 1; k < ARY_SIZE; k++) {
			if (image2_sort[i] > image2_sort[k]) {
				temp = image2_sort[i];
				image2_sort[i] = image2_sort[k];
				image2_sort[k] = temp;
			}
		}
	}
	//// ������ �߾Ӱ� ���� ////
	mid1 = image1_sort[(ARY_SIZE - 1) / 2];
	mid2 = image2_sort[(ARY_SIZE - 1) / 2];

	//// �߾Ӱ� �� �� �̹��� ��� ////
	if (mid1 >= mid2) {
		printScreen1();
	}
	else if (mid1 < mid2) {
		printScreen2();
	}
	else
		printf("�߾Ӱ� ���� \n");

	printf("\n\n --- �߾Ӱ� ---");
	printf("\n�̹���1 : %d, �̹���2 : %d\n", mid1, mid2);
}

// �̼�3-4
// ��� �̹��� ��� ó��
void blackWhite() {
	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			if (tempArrayImage[i][k] <= 127) {
				tempArrayImage[i][k] = 0;
			}
			else
				tempArrayImage[i][k] = 255;
		}
		printf("\n");
	}
	printf("\n");
}

// �̼�3-5
// ��� �̹��� ��հ����� ���ó��
//void avrBlackWhite() {
//	
//}

// �̼� 3-6
// ��� �̹��� �߾Ӱ����� ���ó��

// �̼� 3-7-01
// ��� �̹��� ���������� 90�� ȸ��
void turnRight() {
	for (int i = 0; i < COL; i++) {
		for (int k = (ROW - 1); k >= 0; k--) {
			printf("%3d ", tempArrayImage[k][i]);
		}
		printf("\n");
	}
	printf("\n");
}

// �̼� 3-7-02
// ��� �̹��� �������� 90�� ȸ��
void turnLeft() {
	for (int i = 0; i < COL; i++) {
		for (int k = (ROW - 1); k >= 0; k--) {
			printf("%3d ", tempArrayImage[i][k]);
		}
		printf("\n");
	}
	printf("\n");
}

