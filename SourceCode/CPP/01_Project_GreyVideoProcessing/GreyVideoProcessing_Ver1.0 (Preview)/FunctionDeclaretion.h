// FunctionDeclaretion.h


// ============================== < ���� ������ (�߿�!) > ============================== //
char imgName[100] = { 0 };			// ���ϸ� + .Ȯ���ڸ�
char filePath[100] = { 0 };			// ���� ��� ���� ����
// = char fileName[100]

char inKey = 0;			// Ű����� �Է� �޴� ����
char pix = 0;				// �̹��� ��� ����
int imgSize = 0;			// �̹��� ������

int inH, inW, outH, outW;		// ����� ������ ũ��

unsigned char** inImage = NULL, ** outImage = NULL;

HWND hwnd;		// ������ ȭ�� (�ܺ�, ������)		// �ϱ�x
HDC  hdc;			// �޵��� ȭ�� (����, ����)		// �ϱ�x


// ============================= < �޴� ���� �Լ� ����� > ============================= //
void printMenu();				// �޴� UI
void choiceMenu();			// �޴� ����

unsigned char** melloc2D(int, int);		// 2���� �迭 ���� �Լ�
void free2D(unsigned char**, int);		// free �Լ�
void free2D_out();									// ��� free �Լ�

// =========================== < �̹��� ����� �Լ� ����� > =========================== //
void openImage();								// �̹��� ���� open (�Է�)
void saveImage();								// ��� �̹��� ���� �Լ�

void originImage(char oriImage);		// ���� �̹���
void resultImage(char oriImage);		// ��� �̹���
void ori_printScreen();						// ���� �̹��� ȭ�� ���
void res_printScreen();						// ��� �̹��� ȭ�� ���



// =========================== < ȭ���� ó�� ��� �Լ� ����� > ======================== //
void brightControlImage();			// A.��� ����									// �� �Է�
void clearControlImage();				// B.���� ����									// �� �Է�
void reverseImage();						// C.����
void grayScaleImage();					// D.��� (128/���)
void bitCalcImage();						// E.��Ʈ ���� (And/Or/Xor/Not)			// �� �Է�
void gammaConverseImage();		// F.���� ��ȯ
void rangeEmphasisImage();		// G.���� ����
void parabolaImage();					// H.�Ķ󺼶� ��ȯ
void stretchedImage();					// I.��Ʈ��Ī


// ===================== < ȭ����(������׷�) ó�� ��� �Լ� ����� > ===================== //
void histoStretchImage();				// N.������׷� ��Ʈ��Ī
void histoEndInImage();				// O.������׷� ����-�� Ž��
void histoEqualImage();				// P.������׷� ��Ȱȭ


// ========================== < ȭ�ҿ��� ó�� ��� �Լ� ����� > ======================= //
double** malloc2D_double(int row, int col) {
	double** retMemory;
	retMemory = (double**)malloc(row * sizeof(double*));
	for (int i = 0; i < row; i++)
		retMemory[i] = (double*)malloc(col * sizeof(double));
	return retMemory;
}
void free2D_double(double** memory, int h) {
	for (int i = 0; i < h; i++)
		free(memory[i]);
	free(memory);
}

void embossingImage();				// Q.������ 
void blurringImage();					// R.����


// ============================ < ������ ó�� �Լ� ����� > =========================== //
void mirroringImage();  				// J.�̷��� (�¿�/����/�¿�+����)
void turnImage();							// K.ȸ�� (����, 90/180/270��/����-�����+�߾�)		// �� �Է�
void imageSizeUpDown();				// L.�̹��� ũ��(�԰�) Ȯ��/���									// �� �Է�
//void doubleUpDownImage();		zoom in out// L.2�� Ȯ��/���
void moveImage();						// M.�̵�																	// �� �Է�



// ============================ < ��� ó�� �Լ� ����� > ============================== //
void inImgCheck();		// �Է� �̹��� �Է� ���� Ȯ��
void inImg_128();			// �̹��� ���� �Է�_128x128
void inImg_256();			// �̹��� ���� �Է�_256x256
void inImg_512();			// �̹��� ���� �Է�_512x512
void outImg_128();		// �̹��� ���� ���_128x128
void outImg_256();		// �̹��� ���� ���_256x256
void outImg_512();		// �̹��� ���� ���_512x512

void clearUp(int val);				// B.�����ϰ�
void clearDown(int val);		// B.�帴�ϰ�

void grayScale128();				// D.���ó�� (128 ����)
void grayScaleAvg();				// D.���ó�� (��հ� ����)

void bitCalc_And(int val);		// E-1.��Ʈ����_And
void bitCalc_Or(int val);			// E-2.��Ʈ����_Or
void bitCalc_Xor(int val);		// E-3.��Ʈ����_Xor
void bitCalc_Not();				// E-4.��Ʈ����_Not

void parabolaCap();				// H.�Ķ󺼶�_CAP ��ȯ
void parabolaCup();				// H.�Ķ󺼶�_CUP ��ȯ

void L_R_mirroring();			// J.�¿� �̷���
void T_B_mirroring();			// J.���� �̷���
void TB_LR_mirroring();		// J.����/�¿� �̷���

void turn90Right();						// K.���������� 90�� ȸ��
void turn180Right();						// K.���������� 180�� ȸ��
void turn270Right();						// K.���������� 270�� ȸ��
void turn90Left();							// K.�������� 90�� ȸ��
void turn180Left();						// K.�������� 180�� ȸ��
void turn270Left();						// K.�������� 270�� ȸ��
void turnFree(int val);					// K.����ȸ�� (������)
void turnFreeCenter(int val);			// K.����ȸ�� (�����+�߾�ȸ��)

void sizeUp(int val);									// L.�̹��� ũ�� Ȯ�� (������)
void backwardMappingSizeUp(int val);		// L.�̹��� ũ�� Ȯ�� (�����, Backward Mapping)
void sizeDown(int val);								// L.�̹��� ũ�� ��� (������)
void backwardMappingSizeDown(int val);	// L.�̹��� ũ�� ��� (�����)

//void doubleUp();				// L.2�� Ȯ��
//void doubleDown();			// L.2�� ���


