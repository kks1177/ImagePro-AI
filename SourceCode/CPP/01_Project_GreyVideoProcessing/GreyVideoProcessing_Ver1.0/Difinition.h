// Difinition.h


//// *************************** < �޴� ���� �Լ� ���Ǻ� > *************************** ////
// �޴� UI
void printMenu() {
	puts("\n");
	puts("\t\t\t===========================================================================");
	puts("\t\t\t                  ### �׷��� ����ó�� Ver 1.0 (RC 1) ###\n");
	puts("\t\t\t---------------------------------------------------------------------------");
	puts("\t\t\t [ ���� �޴� ���� ] \t 1.����  2.����  0.���� \n\n");
	puts("\t\t\t [ ����ó�� �޴� ���� ] \n");
	puts("\t\t\t    A.���  B.����  C.����  D.���  E.��Ʈ����  F.������ȯ  G.��������");
	puts("\t\t\t    H.�Ķ󺼶� ��ȯ  I.��Ʈ��Ī     J.�̷���  K.ȸ��  L.Ȯ��/���  M.�̵�");
	puts("\t\t\t===========================================================================\n");
}
// �޴� ����
void choiceMenu() {
	printMenu();
	printf("\t\t\t �޴� ���� : ");

	while (inKey != '0') {
		inKey = _getch();

		switch (inKey) {
		case '0':	free2D(inImage, inH); free2D(outImage, outH);	break;		// ����
		case '1':				// ���� open
			system("cls");	printMenu();	openImage();	break;

		case 'A':	case 'a':	// ��� ����
			system("cls");	printMenu();	brightControlImage();	break;
		case 'B':	case 'b':	// ���� ����
			system("cls");	printMenu();	clearControlImage();	break;
		case 'C':	case 'c':	// ���� ����
			system("cls");	printMenu();	reverseImage();	break;
		case 'D':	case 'd':	// ��� (128/���)
			system("cls");	printMenu();	grayScaleImage();	break;
		case 'E':	case 'e':	// ��Ʈ ���� (And/Or/Xor/Not)
			system("cls");	printMenu();	bitCalcImage();	break;
		case 'F':	case 'f':	// ���� ��ȯ
			system("cls");	printMenu();	gammaConverseImage();	break;
		case 'G':	case 'g':	// ���� ���� 
			system("cls");	printMenu();	rangeEmphasisImage();	break;
		case 'H':	case 'h':	// �Ķ󺼶� ��ȯ 
			system("cls");	printMenu();	parabolaImage();	break;
		case 'I':	case 'i':	// ��Ʈ��Ī
			system("cls");	printMenu();	stretchedImage();	break;

		case 'J':	case 'j':	// �̷��� (�¿�/����/�¿�+����)
			system("cls");	printMenu();	mirroringImage();	break;
		case 'K':	case 'k':	// ȸ�� (����, 90/180/270��/����)
			system("cls");	printMenu();	turnImage();	break;
		case 'L':	case 'l':	// 2�� Ȯ��/���
			system("cls");	printMenu();	doubleUpDownImage();	break;
		case 'M':	case 'm':	// �̹��� �̵�
			system("cls");	printMenu();	moveImage();	break;

		default:				// ����ó��
			printf("�Է� ����! ���Է� �ٶ��ϴ�! \n");
			Sleep(1000);	system("cls");
			printMenu();	printf("\t\t\t �޴� ���� : ");
		}
	}
}
//// ********************************************************************************* ////



//// ************************* < �̹��� ����� �Լ� ���Ǻ� > ************************* ////
// 2���� �迭 ���� �Լ� (�����Ҵ�)
unsigned char** malloc2D(int row, int col) {
	unsigned char** retMemory;			// retMemory == inImage

	// �Է¿���(inImage)�� �޸� �Ҵ�. 
	retMemory = (unsigned char**)malloc(row * sizeof(unsigned char*));					// unsigned char �ڿ� * ���� ����!
	for (int i = 0; i < row; i++) {				// ���� �ȼ�, ���� �ȼ� �ٲ� �� ���� ����!
		retMemory[i] = (unsigned char*)malloc(col * sizeof(unsigned char));
	}
	return retMemory;
}
// free �Լ�			// ���α׷� ����� ����
void free2D(unsigned char** memory, int h) {
	for (int i = 0; i < h; i++) {
		free(memory[i]);
	}
	free(memory);
}
// �̹��� ���� ���� (�Է�)
void openImage() {
	char fullName[100] = "C:/images/Gallery/Gallery";			// C:/images/Pet_RAW(squre)/Pet_RAW(512x512)/";

	printf("\t\t\t ���ϸ� --> ");	// cat01, dog13
	scanf("%s", imgName);

	while (1) {
		printf("\n\t\t\t[�ȼ� ����] \n");
		printf("\t\t\t  1.128  2.256  3.512 ");

		inKey = _getch();
		switch (inKey) {
		case '1':		// 128x128
			pix = 1;
			inW = 128, inH = 128;

			// �ּ�(fullName) + ���ϸ�(imgName) + _128.raw ���ؼ� --> filePath��
			strcat(fullName, "(128x128)/");		// strcat : ���ڿ��� �̾���
			strcat(fullName, imgName);
			strcat(fullName, "_128.raw");
			strcat(imgName, "_128.raw");

			strcpy(filePath, fullName);

			break;
		case '2':		// 256x256
			pix = 2;
			inW = 256, inH = 256;

			strcat(fullName, "(256x256)/");
			strcat(fullName, imgName);
			strcat(fullName, "_256.raw");
			strcat(imgName, "_256.raw");

			strcpy(filePath, fullName);

			break;
		case '3':		// 512x512
			pix = 3;
			inW = 512, inH = 512;

			strcat(fullName, "(512x512)/");
			strcat(fullName, imgName);
			strcat(fullName, "_512.raw");
			strcat(imgName, "_512.raw");

			strcpy(filePath, fullName);

			break;
		default:
			printf("\t\t\t�Է� ����! ���Է� �ٶ��ϴ�! \n");
			Sleep(1000);	system("cls");
			printMenu();	printf("\t\t\t ���ϸ� --> ");
		}
		if (pix != 0) break;
	}

	//// ���� ���� ////
	FILE* rfp = fopen(filePath, "rb");		// rb: Read Binary
	if (rfp == NULL)		// ���� ó��
		return;

	// �Է� ������ ũ�⸦ �˾Ƴ��� �ڵ�. --> inH, inW ����
	fseek(rfp, 0L, SEEK_END);		// ������ ������ �̵�
	unsigned long fsize = ftell(rfp);			// �� ����?    262144(=512x512)
	fclose(rfp);

	inH = inW = sqrt(fsize);			// if, 512x512
	// �Է¿��� (inImage)�� �޸� �Ҵ�
	inImage = malloc2D(inH, inW);

	rfp = fopen(filePath, "rb");
	for (int i = 0; i < inH; i++) {
		fread(inImage[i], sizeof(unsigned char), inW, rfp);
	}

	//// ���� �ݱ� ////
	fclose(rfp);

	system("cls");
	printMenu();
	printf("\t\t\t  ������ ���ϸ� : %s", imgName);
	printf("\n\n");

	ori_printScreen();
}

// ���� �̹���
void originImage(char oriImage) {

	// Original 128x128
	if (oriImage == 1) {
		inImg_128();
	}
	// Original 256x256
	else if (oriImage == 2) {
		inImg_256();
	}
	// Original 512x512
	else if (oriImage == 3) {
		inImg_512();
	}
	else
		printf("���� ���ε� ����! \n");
}
// ��� �̹���
void resultImage(char oriImage) {
	// ���� ������� ���
	if (imgSize == 0) {
		// Result 128x128
		if (oriImage == 1) 
			outImg_128();
		// Result 256x256
		else if (oriImage == 2) 
			outImg_256();
		// Result 512x512
		else if (oriImage == 3) 
			outImg_512();
		else
			printf("���� ���ε� ����!");
	}
	// 2�� Ȯ�� ���
	else if (imgSize == 1) {
		// Result 128x128
		if (oriImage == 1)
			outImg_128();
		// Result 256x256
		else if (oriImage == 2)
			outImg_256();
		// Result 512x512
		else if (oriImage == 3)
			outImg_512();
		else
			printf("���� ���ε� ����!");
	}
	// 2�� ��� ���
	else if (imgSize == 2) {
		// Result 128x128
		if (oriImage == 1)
			outImg_128();
		// Result 256x256
		else if (oriImage == 2)
			outImg_256();
		// Result 512x512
		else if (oriImage == 3)
			outImg_512();
		else
			printf("���� ���ε� ����!");
	}
	else
		printf("���� �Է� ����!");
}
// ���� �̹��� ȭ�� ���
void ori_printScreen() {
	if (pix == 1)	originImage(1);		// 128x128
	else if (pix == 2)	originImage(2);		// 256x256
	else if (pix == 3)	originImage(3);		// 512x512
}
// ��� �̹��� ȭ�� ���
void res_printScreen() {
	if (pix == 1)	resultImage(1);		// 128x128
	else if (pix == 2)	resultImage(2);		// 256x256
	else if (pix == 3)	resultImage(3);		// 512x512
}
//// ********************************************************************************* ////



//// ************************* < ����� ó�� ��� �Լ� ���Ǻ� > ********************** ////
// ���� �̹��� ���
/*
void equalImage() {		// previousImage()
	system("cls");
	printMenu();
	printf("\t\t\t  ������ ���ϸ� : %s", imgName);
	printf("\n\n");

	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			int px = inImage[i][k];

			outImage[i][k] = px;
		}
	}
	printf("\n");
	res_printScreen();
}
*/

// A.�̹��� ��� �� ����
void brightControlImage() {
	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	// *******�Լ����� ���̱�******** //
	outH = inH;
	outW = inW;
	outImage = malloc2D(outH, outW);
	// ****************************** // 

	int value;

	system("cls");
	printMenu();
	printf("\t\t\t  ������ ���ϸ� : %s", imgName);

	printf("\t\t  ��� ���� �� --> ");
	scanf("%d", &value);
	printf("\n");

	ori_printScreen();

	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			int px = inImage[i][k] + value;		// px : pixel

			if (px > 255)
				px = 255;
			else if (px < 0)
				px = 0;

			outImage[i][k] = px;
		}
	}
	if (value > 0) {
		printf("\t\t\t < ��� %d ���� ȭ�� >", value);
		res_printScreen();
	}
	else if (value < 0) {
		printf("\t\t\t < ��� %d ���� ȭ�� >", value);
		res_printScreen();
	}
	else {
		printf("�ٽ� �Է��ϼ���!\n");
	}
}

// B.�̹��� ���� ����
void clearControlImage() {
	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	outH = inH;
	outW = inW;
	outImage = malloc2D(outH, outW);

	int choice = 0;

	system("cls");
	printMenu();
	printf("\t\t\t  ������ ���ϸ� : %s", imgName);
	printf("\n\n");

	printf("\n\t\t\t[���� ����] \n");
	printf("\t\t\t  1.�����ϰ�  2.����ϰ�");

	inKey = _getch();
	switch (inKey) {
	case '1':		// �����ϰ�
		clearUp();
		break;
	case '2':		// ����ϰ�
		clearDown();
		break;
	default:
		printf("�Է� ����! ���Է� �ٶ��ϴ�! \n");
		Sleep(1000);	system("cls");
		printMenu();	printf("\t\t\t ���ϸ� --> ");
		break;
	}
}

// C.�̹��� ���� ó��
void reverseImage() {
	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	outH = inH;
	outW = inW;
	outImage = malloc2D(outH, outW);

	system("cls");
	printMenu();
	printf("\t\t\t  ������ ���ϸ� : %s", imgName);
	printf("\n\n");

	ori_printScreen();

	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			int px = inImage[i][k];

			outImage[i][k] = 255 - px;
		}
	}
	printf("\t\t\t < ���� ���� ȭ�� > ");
	res_printScreen();
}

// D.�̹��� ��� ó��
void grayScaleImage() {
	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	outH = inH;
	outW = inW;
	outImage = malloc2D(outH, outW);

	system("cls");
	printMenu();
	printf("\t\t\t  ������ ���ϸ� : %s", imgName);

	printf("\t\t  1.128 ����  2.��հ� ���� \n");

	ori_printScreen();

	inKey = _getch();
	switch (inKey) {
	case '1':		// 128 ����
		grayScale128();
		break;
	case '2':		// ��հ� ����
		grayScaleAvg();
		break;
	default:
		printf("�ٽ� �Է��ϼ���! \n");
		break;
	}
}

// E.��Ʈ���� (And/Or/Xor/Not)
void bitCalcImage() {
	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	outH = inH;
	outW = inW;
	outImage = malloc2D(outH, outW);

	int value = 0;

	system("cls");
	printMenu();
	printf("\t\t\t  ������ ���ϸ� : %s", imgName);

	printf("\n\n\t\t 1.And  2.Or  3.Xor  4.Not ");

	inKey = _getch();
	if (inKey == '1' || inKey == '2' || inKey == '3') {
		while (1) {
			printf("\t\t ������ �� (0 or 255) : ");
			scanf("%d", &value);

			if (value >= 0 && value <= 255) {
				break;
			}
			else
				printf("\t\t �Է¿���! ��(0~255)�� �ٽ� �Է��ϼ���! \n");
		}
	}
	system("cls");
	printMenu();
	printf("\t\t\t  ������ ���ϸ� : %s", imgName);
	printf("\n\n");

	ori_printScreen();

	switch (inKey) {
	case '1':
		bitCalc_And(value);
		break;
	case '2':
		bitCalc_Or(value);
		break;
	case '3':
		bitCalc_Xor(value);
		break;
	case '4':
		bitCalc_Not();
		break;
	default:
		printf("�ٽ� �Է��ϼ���! \n");
		break;
	}


}

// F.���� ��ȯ
void gammaConverseImage() {
	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	outH = inH;
	outW = inW;
	outImage = malloc2D(outH, outW);

	int value = 0;

	system("cls");
	printMenu();
	printf("\t\t\t  ������ ���ϸ� : %s", imgName);

	printf("\t\t   ���� �� �Է� : ");
	scanf("%d", &value);

	ori_printScreen();

	if (value != 0) {
		for (int i = 0; i < inH; i++) {
			for (int k = 0; k < inW; k++) {
				outImage[i][k] = pow(inImage[i][k] / 255., value) * 255 + 0.5;
			}
		}
	}
	else
		printf("�ٽ� �Է��ϼ���! \n");
	printf("\t\t\t < ���� ��ȯ ȭ�� > ");
	res_printScreen();
}

// G.���� ����
void rangeEmphasisImage() {
	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	outH = inH;
	outW = inW;
	outImage = malloc2D(outH, outW);

}

// H.�Ķ󺼶� ��ȯ
void parabolaImage() {
	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	outH = inH;
	outW = inW;
	outImage = malloc2D(outH, outW);

}

// I.��Ʈ��Ī
void stretchedImage() {
	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	outH = inH;
	outW = inW;
	outImage = malloc2D(outH, outW);

}
//// ********************************************************************************* ////



//// ************************** < ������ ó�� �Լ� ���Ǻ� > ************************** ////
// J.�̷��� (�¿�/����/�¿�+����) 
void mirroringImage() {
	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	outH = inH;
	outW = inW;
	outImage = malloc2D(outH, outW);

	system("cls");
	printMenu();
	printf("\t\t\t  ������ ���ϸ� : %s", imgName);

	printf("\t\t 1.�¿�  2.����  3.����+�¿� \n");

	ori_printScreen();

	inKey = _getch();
	switch (inKey) {
	case '1':
		L_R_mirroring();
		break;
	case '2':
		T_B_mirroring();
		break;
	case '3':
		TB_LR_mirroring();
		break;
	default:
		printf("�ٽ� �Է��ϼ���! \n");
		break;
	}
	res_printScreen();
}

// K.ȸ��(������,���� 90/180/270/����)
void turnImage() {
	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	outH = inH;
	outW = inW;
	outImage = malloc2D(outH, outW);

	int direct = 0;

	system("cls");
	printMenu();
	printf("\t\t\t  ������ ���ϸ� : %s", imgName);

	printf("\t\t [����] 1.������  2.���� ");
	scanf("%d", &direct);
	printf("\n\t\t\t\t\t\t\t    [����] A.90  B.180  C.270  D.���� ");

	// ���������� ȸ��
	if (direct == 1) {
		inKey = _getch();
		switch (inKey) {
		case 'A':	case 'a':		// 90�� ȸ��
			system("cls");	printMenu();	turn90Right();	break;
		case 'B':	case 'b':		// 180�� ȸ��
			system("cls");	printMenu();	turn180Right();	break;
		case 'C':	case 'c':		// 270�� ȸ��
			system("cls");	printMenu();	turn270Right();	break;
		case 'D':	case 'd':		// ���� ȸ��
			break;
		default:
			break;
		}
	}
	// �������� ȸ��
	else if (direct == 2) {
		inKey = _getch();
		switch (inKey) {
		case 'A':	case 'a':		// 90�� ȸ��
			system("cls");	printMenu();	turn90Left();	break;
		case 'B':	case 'b':		// 180�� ȸ�� 
			system("cls");	printMenu();	turn180Left();	break;
		case 'C':	case 'c':		// 270�� ȸ��
			system("cls");	printMenu();	turn270Left();	break;
		case 'D':	case 'd':		// ���� ȸ��
			break;
		default:
			break;
		}
	}
	else {
		printf("�ٽ� �Է����ּ���! \n");
		return;
	}
	res_printScreen();
}

// L.2�� Ȯ��/���
void doubleUpDownImage() {
	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	outH = inH;
	outW = inW;
	outImage = malloc2D(outH, outW);

	system("cls");
	printMenu();
	printf("\t\t\t  ������ ���ϸ� : %s", imgName);

	printf("\t\t 1.2�� Ȯ��  2.2�� ��� ");

	ori_printScreen();

	inKey = _getch();
	switch (inKey) {
	case '1':
		doubleUp();
		break;
	case '2':
		doubleDown();
		break;
	default:
		printf("�ٽ� �Է��ϼ���! \n");
		break;
	}
}

// M.�̵�
void moveImage() {
	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	outH = inH;
	outW = inW;
	outImage = malloc2D(outH, outW);

	int value = 0;

	system("cls");
	printMenu();
	printf("\t\t\t  ������ ���ϸ� : %s", imgName);

	printf("\t\t  �̵��� �� : ");
	scanf("%d", &value);

	ori_printScreen();

	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			outImage[i][k] = 0;
		}
	}
	for (int i = 0; i < inH - value; i++) {
		for (int k = 0; k < inW - value; k++) {
			outImage[i][k] = inImage[i + value][k + value]; // = inImage[i][k];
		}
	}
	res_printScreen();
}
//// ********************************************************************************* ////



//// *************************** < ��� ó�� �Լ� ���Ǻ� > *************************** ////
// �̹��� ���� �Է�_128x128
void inImg_128() {
	short px = 0;
	printf("\n\t\t\t < ���� �̹��� ȭ��(128) > ");
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			px = inImage[i][k];
			SetPixel(hdc, k + 300, i + 420, RGB(px, px, px));		// hdc�� �������ִ� �Լ�		// i, k -> k+50, i+250
		}
	}
}
// �̹��� ���� �Է�_256x256
void inImg_256() {
	short px = 0;
	printf("\n\t\t\t < ���� �̹��� ȭ��(256) > ");
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			px = inImage[i][k];
			SetPixel(hdc, k + 250, i + 420, RGB(px, px, px));		// hdc�� �������ִ� �Լ�		// i, k -> k+50, i+250
		}
	}
}
// �̹��� ���� �Է�_512x512
void inImg_512() {
	short px = 0;
	printf("\n\t\t < ���� �̹��� ȭ��(512) > ");
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			px = inImage[i][k];
			SetPixel(hdc, k + 50, i + 420, RGB(px, px, px));		// hdc�� �������ִ� �Լ�		// i, k -> k+50, i+250
		}
	}
}
// �̹��� ���� ���_128x128
void outImg_128() {
	short px = 0;
	for (int i = 0; i < outH; i++) {
		for (int k = 0; k < outW; k++) {
			px = outImage[i][k];
			SetPixel(hdc, k + 800, i + 420, RGB(px, px, px));		// hdc�� �������ִ� �Լ�		// i, k -> k+50, i+250
		}
	}
}
// �̹��� ���� ���_256x256
void outImg_256() {
	short px = 0;
	for (int i = 0; i < outH; i++) {
		for (int k = 0; k < outW; k++) {
			px = outImage[i][k];
			SetPixel(hdc, k + 720, i + 420, RGB(px, px, px));		// hdc�� �������ִ� �Լ�		// i, k -> k+50, i+250
		}
	}
}
// �̹��� ���� ���_512x512
void outImg_512() {
	short px = 0;
	for (int i = 0; i < outH; i++) {
		for (int k = 0; k < outW; k++) {
			px = outImage[i][k];
			SetPixel(hdc, k + 600, i + 420, RGB(px, px, px));		// hdc�� �������ִ� �Լ�		// i, k -> k+50, i+250
		}
	}
}

// B.�����ϰ�
void clearUp() {
	int value = 0;

	printf("   ���� ���� ��(���) --> ");
	scanf("%d", &value);

	system("cls");
	printMenu();
	printf("\t\t\t  ������ ���ϸ� : %s", imgName);
	printf("\n\n");

	ori_printScreen();

	if (value > 0) {
		for (int i = 0; i < inH; i++) {
			for (int k = 0; k < inW; k++) {
				int px = inImage[i][k] * value;		// px : pixel

				if (px > 255)
					outImage[i][k] = 255;
				else 
					outImage[i][k] = px;
			}
		}
		printf("\t\t\t< ���� %d ���� ȭ�� >", value);
		res_printScreen();
	}
	else
		printf("\t\t\t���� �Ǵ� 0 �Է�.. ����� �Է����ּ���.");
}
// B.�帴�ϰ�
void clearDown() {
	int value = 0;

	printf("\t   ���� ���� ��(���) --> ");
	scanf("%d", &value);

	system("cls");
	printMenu();
	printf("\t\t\t  ������ ���ϸ� : %s", imgName);
	printf("\n\n");

	ori_printScreen();

	if (value > 0) {
		for (int i = 0; i < inH; i++) {
			for (int k = 0; k < inW; k++) {
				int px = inImage[i][k] / value;		// px : pixel

				if (px > 255)
					outImage[i][k] = 255;
				else
					outImage[i][k] = px;
			}
		}
		printf("\t\t\t< ���� %d ���� ȭ�� >", value);
		res_printScreen();
	}
	else
		printf("\t\t\t���� �Ǵ� 0 �Է�.. ����� �Է����ּ���.");
}

// D.���ó�� (128 ����)
void grayScale128() {
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			int px = inImage[i][k];

			if (px > 128) {
				px = 255;
			}
			else if (px <= 128) {
				px = 0;
			}
			outImage[i][k] = px;
		}
	}
	printf("\t\t\t < ���� ��� ó��(128 ����) ȭ�� > ");
	res_printScreen();
}
// D.���ó�� (��հ� ����)
void grayScaleAvg() {
	int pixelSum = 0;
	int pixelAvg = 0;

	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			int px = inImage[i][k];
			pixelSum += px;
		}
	}
	pixelAvg = pixelSum / (inH * inW);

	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			int px = inImage[i][k];
			if (px > pixelAvg) {
				px = 255;
			}
			else {
				px = 0;
			}
			outImage[i][k] = px;
		}
	}
	printf("\t\t\t < ���� ��� ó��(��հ� %d ����) ȭ�� > ", pixelAvg);
	res_printScreen();
}

// E-1.��Ʈ����_And
void bitCalc_And(int val) {
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			unsigned char px = inImage[i][k] & val;

			outImage[i][k] = px;
		}
	}
	printf("\t\t\t < AND ��Ʈ ���� ȭ�� > ");
	res_printScreen();
}
// E-2.��Ʈ����_Or
void bitCalc_Or(int val) {
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			unsigned char px = inImage[i][k] | val;
			outImage[i][k] = px;
		}
	}
	printf("\t\t\t < OR ��Ʈ ���� ȭ�� > ");
	res_printScreen();
}
// E-3.��Ʈ����_Xor
void bitCalc_Xor(int val) {
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			unsigned char px = inImage[i][k] ^ val;
			outImage[i][k] = px;
		}
	}
	printf("\t\t\t < XOR ��Ʈ ���� ȭ�� > ");
	res_printScreen();
}
// E-4.��Ʈ����_Not
void bitCalc_Not() {
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			unsigned char px = ~inImage[i][k];
			outImage[i][k] = px;
		}
	}
	printf("\t\t\t < NOT ��Ʈ ���� ȭ�� > ");
	res_printScreen();
}

// J.�̹��� �¿� �̷���
void L_R_mirroring() {
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			int px = inImage[i][inW - 1 - k];	// (�ִ뿭 - 1) - �ݺ���

			outImage[i][k] = px;
		}
	}
	printf("\t\t\t < ���� �¿� �̷��� ȭ�� > ");
}
// J.�̹��� ���� �̷���
void T_B_mirroring() {
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			int px = inImage[inH - 1 - i][k];		// (�ִ��� - 1) - �ݺ���

			outImage[i][k] = px;
		}
	}
	printf("\t\t\t < ���� ���� �̷��� ȭ�� > ");
}
// J.�̹��� ����+�¿� �̷���
void TB_LR_mirroring() {
	for (int i = 0; i < inW; i++) {
		for (int k = 0; k < inH; k++) {
			int mirror_i = inH - 1 - i;
			int mirror_k = inW - 1 - k;

			outImage[i][k] = inImage[mirror_i][mirror_k];
		}
	}
	printf("\t\t\t < ���� ����/�¿� �̷��� ȭ�� > ");
}

// K.��� �̹��� �ð�������� 90�� ȸ��
void turn90Right() {
	ori_printScreen();

	for (int i = 0; i < inW; i++) {
		for (int k = 0; k < inH; k++) {
			outImage[i][k] = inImage[inH - k - 1][i];
		}
	}
	printf("\t\t\t < �ð���� 90�� ȸ�� ȭ�� > ");
}
// K.��� �̹��� �ð�������� 180�� ȸ��
void turn180Right() {
	ori_printScreen();

	for (int i = 0; i < inW; i++) {
		for (int k = 0; k < inH; k++) {
			outImage[i][k] = inImage[inH - i - 1][inW - k - 1];
		}
	}
	printf("\t\t\t < �ð���� 180�� ȸ�� ȭ�� > ");
}
// K.��� �̹��� �ð�������� 270�� ȸ��
void turn270Right() {
	ori_printScreen();

	for (int i = 0; i < inW; i++) {
		for (int k = 0; k < inH; k++) {
			outImage[i][k] = inImage[k][inH - i - 1];
		}
	}
	printf("\t\t\t < �ð���� 270�� ȸ�� ȭ�� > ");
}
// K.��� �̹��� �ݽð�������� 90�� ȸ��
void turn90Left() {
	ori_printScreen();

	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			outImage[i][k] = inImage[k][inH - 1 - i];
		}
	}
	printf("\t\t\t < �ݽð���� 90�� ȸ�� ȭ�� > ");
}
// K.��� �̹��� �ݽð�������� 180�� ȸ��
void turn180Left() {
	ori_printScreen();

	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			outImage[i][k] = inImage[inH - 1 - i][inW - k - 1];
		}
	}
	printf("\t\t\t < �ݽð���� 180�� ȸ�� ȭ�� > ");
}
// K.��� �̹��� �ݽð�������� 270�� ȸ��
void turn270Left() {
	ori_printScreen();

	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			outImage[i][k] = inImage[inH - k - 1][i];
		}
	}
	printf("\t\t\t < �ݽð���� 270�� ȸ�� ȭ�� > ");
}

// L.2�� Ȯ��
void doubleUp() {
	imgSize = 1;

	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			outImage[i][k] = inImage[i / 2][k / 2];
		}
	}
	res_printScreen();
}
// L.2�� ���
void doubleDown() {
	imgSize = 2;

	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			outImage[i][k] = 0;
		}
	}
	for (int i = 0; i < inH / 2; i++) {
		for (int k = 0; k < inW / 2; k++) {
			outImage[i][k] = inImage[i * 2][k * 2];
		}
	}
	res_printScreen();
}
//// ********************************************************************************* ////


