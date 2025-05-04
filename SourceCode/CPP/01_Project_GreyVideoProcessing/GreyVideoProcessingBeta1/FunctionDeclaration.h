#pragma once
// FunctionDeclaration.h
// �Լ� ���� 


void printMenu();				// �޴� UI
void choiceMenu();				// �޴� ����

void openImage();				// �̹��� ���� open (�Է�)

void originImage(char oriImage);	// ���� �̹���
void resultImage(char oriImage);	// ��� �̹���
void ori_printScreen();				// ���� �̹��� ȭ�� ���
void res_printScreen();				// ��� �̹��� ȭ�� ���

//void equalImage();				// ���� �̹��� ���
// =========================== < ȭ���� ó�� ��� �Լ� ���� > ===========================
void brightControlImage();		// A.��� ����
void clearControlImage();		// B.���� ����
void reverseImage();			// C.����
void grayScaleImage();			// D.��� (128/���)
void bitCalcImage();			// E.��Ʈ ���� (And/Or/Xor/Not)
void gammaConverseImage();		// F.���� ��ȯ
void rangeEmphasisImage();		// G.���� ����
void parabolaImage();			// H.�Ķ󺼶� ��ȯ
void stretchedImage();			// I.��Ʈ��Ī
// ============================ < ������ ó�� �Լ� ���� > ===============================
void mirroringImage();  		// J.�̷��� (�¿�/����/�¿�+����)
void turnImage();				// K.ȸ�� (����, 90/180/270��/����)
void doubleUpDownImage();		// L.2�� Ȯ��/���
void moveImage();				// M.�̵�

// ============================ < ��� ó�� �Լ� ���� > ===============================
void clearUp();				// B.�����ϰ�
void clearDown();			// B.�帴�ϰ�

void grayScale128();		// D.���ó�� (128 ����)
void grayScaleAvg();		// D.���ó�� (��հ� ����)

void bitCalc_And(int val);		// E-1.��Ʈ����_And
void bitCalc_Or(int val);		// E-2.��Ʈ����_Or
void bitCalc_Xor(int val);		// E-3.��Ʈ����_Xor
void bitCalc_Not();				// E-4.��Ʈ����_Not

void L_R_mirroring();		// J.�¿� �̷���
void T_B_mirroring();		// J.���� �̷���
void TB_LR_mirroring();		// J.����/�¿� �̷���

void turn90Right();			// K.���������� 90�� ȸ��
void turn180Right();		// K.���������� 180�� ȸ��
void turn270Right();		// K.���������� 270�� ȸ��
void turn90Left();			// K.�������� 90�� ȸ��
void turn180Left();			// K.�������� 180�� ȸ��
void turn270Left();			// K.�������� 270�� ȸ��

void doubleUp();			// L.2�� Ȯ��
void doubleDown();			// L.2�� ���

