// Difinition_copy.h


//// *************************** < �޴� ���� �Լ� ���Ǻ� > *************************** ////
// �⺻ �޴� UI
void mainMenu() {
	printf("\n");
	printf(" =============================================================================== ");
	printf("\n = \t\t\t\t\t\t\t\t\t       =");
	printf("\n =             ### GreyScale Video Processing Ver 1.0_��⼺ ###               =");
	printf("\n = \t\t\t\t\t\t\t\t\t       =");
	printf("\n -------------------------------------------------------------------------------");
	printf("\n\n  [ ���� �޴� ���� ] \t 1.����  2.����  0.���� ");
	printf("\n\n  [ �˰��� ���� ] \t 1.ȭ����  2.������׷�  3.ȭ�ҿ���  4.����  5.������ \n");
	printf("\n =============================================================================== \n");
	printf(" ������ ���ϸ� : % s ", imgName);
}
// ��ü �޴� UI
void printMenu(char functionChoice) {
	/*if (functionChoice == 0) {
		mainMenu();

		while (1) {
			menuChoice = _getch();
			switch (menuChoice) {
			case '1': pix = 1;	openImage();	break;
			case '2': pix = 2;	saveImage(); break;
			case '0': free2D(inImage, inH); free2D(outImage, outH); break;
			default:
				printf(" �޴� �߸� ����! \n");
				Sleep(1000);		 system("cls");
				mainMenu();
			}
			if (pix != 0) break;
		}
		Sleep(2000);		system("cls");
	}*/

	while (1) {
		printf("\n");
		printf(" =============================================================================== ");
		printf("\n = \t\t\t\t\t\t\t\t\t       =");
		printf("\n =             ### GreyScale Video Processing Ver 1.0_��⼺ ###               =");
		printf("\n = \t\t\t\t\t\t\t\t\t       =");
		printf("\n -------------------------------------------------------------------------------");
		printf("\n\n  [ ���� �޴� ���� ] \t 1.����  2.����  0.���� ");
		printf("\n\n  [ �˰��� ���� ] \t 1.ȭ����  2.������׷�  3.ȭ�ҿ���  4.����  5.������ \n");

		// ȭ���� ó��
		if (functionChoice == 1) {
			algoPick = 1;
			puts("\n\n     [ 1.ȭ���� ó�� ��� ���� ] ");
			puts("\t A.���  B.����  C.����  D.���  E.��Ʈ����  F.������ȯ ");
			puts("\t G.��������  H.�Ķ󺼶� ��ȯ  I.��ϴ�� ��Ʈ��Ī ");
		}
		// ������׷� (ȭ����) ó��
		else if (functionChoice == 2) {
			algoPick = 2;
			puts("\n\n     [ 2.������׷� ó�� ��� ���� ] ");
			puts("\t A.������׷� ���  B.��Ʈ��Ī  C.����-�� Ž��  D.��Ȱȭ ");
		}
		// ȭ�ҿ��� ó��
		else if (functionChoice == 3) {
			algoPick = 3;
			puts("\n\n     [ 3.ȭ�ҿ��� ó�� ��� ���� ] ");
			puts("\t A.������  B.����  C.������  D.������  ");
		}
		// ȭ�ҿ��� (����) ó��
		else if (functionChoice == 4) {
			algoPick = 4;
			puts("\n\n     [ 4.ȭ�ҿ��� (���� ����) ó�� ��� ���� ] ");
			puts("\t A.���� ����  ");
		}
		// ������ ó��
		else if (functionChoice == 5) {
			algoPick = 5;
			puts("\n\n     [ 5.������ ó�� ��� ���� ] ");
			puts("\t A.�̷���  B.ȸ��  C.Ȯ��/���  D.�̵�  E.����  ");
		}
		/*switch (functionChoice) {
		case '1':
			pix = 1;
			puts("\n\n   [ 1.ȭ���� ó�� ��� �޴� ���� ] ");
			puts("      A.���  B.����  C.����  D.���  E.��Ʈ����  F.������ȯ ");
			puts("      G.��������  H.�Ķ󺼶� ��ȯ  I.��ϴ�� ��Ʈ��Ī ");
			break;
		case '2':
			pix = 2;
			puts("\n\n   [ 2.������׷� ó�� ��� �޴� ���� ] ");
			puts("      A.��Ʈ��Ī  B.����-�� Ž��  C.��Ȱȭ ");
			break;
		case '3':
			pix = 3;
			puts("\n\n   [ 3.ȭ�ҿ��� ó�� ��� �޴� ���� ] ");
			puts("      A.������  B.����  S., , , T., , , U., , , ");
			break;
		case '4':
			pix = 4;
			puts("\n\n   [ 4.������ ó�� ��� �޴� ���� ] ");
			puts("      A.�̷���  B.ȸ��  C.Ȯ��/���  D.�̵� ");
			break;
		default:
			printf("��� ��� �߸� �Է�! \n");
			Sleep(1000);		 system("cls");
			mainMenu();
		}*/
		printf("\n =============================================================================== \n");
		printf(" ������ ���ϸ� : % s ", imgName);
		if (algoPick != 0) break;
	}

}
// �޴� ����
int choiceMenu() {
	char menuChoice = 0;
	char algorithmChoice = 0;
	char menuPick = 0;
	//char algoPick = 0; 
	//char funcPick = 0;

	mainMenu();

	while (1) {
		printf("\t\t ���� �޴� ���� : ");
		menuChoice = _getch();
		switch (menuChoice) {
		case '1': menuPick = 1;		openImage();	break;
		case '2': menuPick = 2;		saveImage(); break;
		case '0': free2D(inImage, inH); free2D(outImage, outH); break;
		default:
			puts(" ���� �޴� ���� ����!!! \n");
			Sleep(500);		 system("cls");		mainMenu();
		}
		if (menuPick != 0)		break;
	}
	Sleep(2000);		system("cls");	 mainMenu();


	while (1) {
		printf("\t\t �˰��� ���� : ");
		algorithmChoice = _getch();
		system("cls");
		inImgCheck();

		switch (algorithmChoice) {
		case '1':	printMenu(1);	break;
		case '2':	printMenu(2);	break;
		case '3':	printMenu(3);	break;
		case '4':	printMenu(4);	break;
		case '5':	printMenu(5);	break;
		default:
			puts(" �˰��� ���� ����!!! \n");
			Sleep(500);		system("cls");	 mainMenu();
		}
		//if (algoPick != 0)	break;


		printf("\t\t ��� ���� : ");
		inKey = _getch();

		// ȭ���� ó��
		if (algoPick == 1) {
			switch (inKey) {
			case '1': system("cls");		mainMenu();		printf("\t\t ���� �޴� ���� : ");	openImage();	break;
			case '2': saveImage(); break;
			case '0': free2D(inImage, inH); free2D(outImage, outH); return 0;

			case 'A':	case 'a':	// ��� ����
				brightControlImage();	break;
			case 'B':	case 'b':	// ���� ����
				clearControlImage();	break;
			case 'C':	case 'c':	// ���� ����
				reverseImage();	break;
			case 'D':	case 'd':	// ��� (128/���)
				grayScaleImage();	break;
			case 'E':	case 'e':	// ��Ʈ ���� (And/Or/Xor/Not)
				bitCalcImage();	break;
			case 'F':	case 'f':	// ���� ��ȯ
				gammaConverseImage();	break;
			case 'G':	case 'g':	// ���� ���� 
				rangeEmphasisImage();	break;
			case 'H':	case 'h':	// �Ķ󺼶� ��ȯ 
				parabolaImage();	break;
			case 'I':	case 'i':		// ��ϴ�� ��Ʈ��Ī
				stretchedImage();	break;

			default:
				if (inKey != 'x' && inKey != 'X')		printf(" ȭ���� ó�� ��� ���� ����!!! \n"); break;
			}
			Sleep(2000);		system("cls");	printMenu(1);
		}

		// ������׷� (ȭ����) ó��
		else if (algoPick == 2) {
			switch (inKey) {
			case '1': system("cls");		mainMenu();		openImage();	break;
			case '2': saveImage(); break;
			case '0': free2D(inImage, inH); free2D(outImage, outH); return 0;

			case 'A':	case 'a':		// ������׷� ���
				printHisto();				break;
			case 'B':	case 'b':		// ������׷� ��Ʈ��Ī
				histoStretchImage();	break;
			case 'C':	case 'c':		// ������׷� ����-�� Ž��
				histoEndInImage();	break;
			case 'D':	case 'd':		// ������׷� ��Ȱȭ
				histoEqualImage();	break;

			default:
				if (inKey != 'x' && inKey != 'X')		printf(" ������׷� ó�� ��� ���� ����!!! \n"); break;
			}
			Sleep(2000);		system("cls");	printMenu(2);
		}

		// ȭ�ҿ��� ó��
		else if (algoPick == 3) {
			switch (inKey) {
			case '1': system("cls");		mainMenu();		openImage();	break;
			case '2': saveImage(); break;
			case '0': free2D(inImage, inH); free2D(outImage, outH); return 0;

			case 'A':	case 'a':	// ������
				embossingImage();	break;
			case 'B':	case 'b':	// ����
				blurringImage();	break;
			case 'C':	case 'c':	// ������
				sharpeningImage();	break;
			case 'D':	case 'd':	// ������ (����þ�)
				smoothingImage();	break;

			default:
				if (inKey != 'x' && inKey != 'X')		printf(" ȭ�ҿ��� ó�� ��� ���� ����!!! \n"); break;
			}
			Sleep(2000);		system("cls");	printMenu(3);
		}

		// ȭ�ҿ��� (����) ó��
		else if (algoPick == 4) {
			switch (inKey) {
			case '1': system("cls");		mainMenu();		openImage();	break;
			case '2': saveImage(); break;
			case '0': free2D(inImage, inH); free2D(outImage, outH); return 0;

			case 'A':	case 'a':	// �̵��� ���� ���� ���� (����, ����, ��������)
				shiftDifferEdgeImage();		break;

			default:
				if (inKey != 'x' && inKey != 'X')		printf(" ������ ó�� ��� ���� ����!!! \n"); break;
			}
			Sleep(2000);		system("cls");	printMenu(4);
		}

		// ������ ó��
		else if (algoPick == 5) {
			switch (inKey) {
			case '1': system("cls");		mainMenu();		openImage();	break;
			case '2': saveImage(); break;
			case '0': free2D(inImage, inH); free2D(outImage, outH); return 0;

			case 'A':	case 'a':	// �̷��� (�¿�/����/�¿�+����)
				mirroringImage();		break;
			case 'B':	case 'b':	// ȸ�� (����, 90/180/270��/����)
				turnImage();		break;
			case 'C':	case 'c':	// �̹��� ũ��(�԰�) Ȯ��/���
				imageSizeUpDown();	break;
			case 'D':	case 'd':	// �̹��� �̵�
				moveImage();	break;
			case 'E':	case 'e':	// ����
				warpingImage();	break;

			default:
				if (inKey != 'x' && inKey != 'X')		printf(" ������ ó�� ��� ���� ����!!! \n"); break;
			}
			Sleep(2000);		system("cls");	printMenu(5);
		}
	}
	system("cls");
	printf(" ����Ǿ����ϴ�.\n");
	free2D(inImage, inH); free2D(outImage, outH);
	return 0;
}

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
// ��� free �Լ�			// �Լ� ���� �� ����
void free2D_out() {
	if (outImage == NULL)
		return;

	for (int i = 0; i < outH; i++)
		free(outImage[i]);
	free(outImage);
}

// 1.�̹��� ���� ���� (�Է�)
void openImage() {
	char fullName[100] = "C:/images/Gallery/Gallery";			// C:/images/Pet_RAW(squre)/Pet_RAW(512x512)/";

	printf("\n\n\n     ���ϸ� --> ");	// cat01, dog13
	scanf("%s", imgName);

	while (1) {
		printf("\n\t [�ȼ� ����] \n");
		printf("\n\t   1.128  2.256  3.512 ");

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
			printf("\n\n\t �Է� ����! ���Է� �ٶ��ϴ�! \n");
			Sleep(1000);	system("cls");
			mainMenu();	printf("     ���ϸ� --> ");
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

	inH = inW = sqrt(fsize);			// (���� �߿�!) �ȼ� �� �ľ��ϴ� �ڵ�
	// �Է¿��� (inImage)�� �޸� �Ҵ�
	inImage = malloc2D(inH, inW);

	// ���� --> �޸𸮷� �ε�
	rfp = fopen(filePath, "rb");
	for (int i = 0; i < inH; i++) {
		fread(inImage[i], sizeof(unsigned char), inW, rfp);
	}

	//// ���� �ݱ� ////
	fclose(rfp);

	puts("");
	ori_printScreen();
}
// 2.��� �̹��� ���� �Լ�
void saveImage() {
	char fullName[100] = "C:/images/Gallery/Gallery";			// C:/images/Pet_RAW(squre)/Pet_RAW(512x512)/";

	printf("\n\n\n     (����) ���ϸ� --> ");	// cat01, dog13
	scanf("%s", imgName);

	while (1) {
		printf("\n\t [(����) �ȼ� ����] \n");
		printf("\n\t   1.128  2.256  3.512  0.���� ��� ");

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
			printf("\n\n\t ���� ����! ���Է� �ٶ��ϴ�! \n");
			Sleep(1000);	system("cls");
			mainMenu();	printf("     (����) ���ϸ� --> ");
			break;
		}
		if (pix != 0) break;
	}
	//// ���� ���� ////
	FILE* wfp = fopen(filePath, "wb");		// wb: Write Binary
	if (wfp == NULL)		// ���� ó��
		return;

	// �޸� --> ���Ϸ� �ε�
	for (int i = 0; i < outH; i++) {
		fwrite(outImage[i], sizeof(unsigned char), outW, wfp);
	}

	//// ���� �ݱ� ////
	fclose(wfp);
	if (inKey == '1' || inKey == '2' || inKey == '3') {
		MessageBox(hwnd, L"���� OK", L"���� â", NULL);
	}
	else
		MessageBox(hwnd, L"���� ����", L"���� â", NULL);

	puts("");
	ori_printScreen();
}
// ������ �̹��� open (�Է�)
/*
void openMorpImage() {
	char fullName[100] = "C:/images/Gallery/Gallery";			// C:/images/Pet_RAW(squre)/Pet_RAW(512x512)/";

	printf("\n\n     ���ϸ� --> ");	// cat01, dog13
	scanf("%s", imgName);

	while (1) {
		printf("\n\t [�ȼ� ����] \n");
		printf("\n\t   1.128  2.256  3.512 ");

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
			printf("\n\n\t �Է� ����! ���Է� �ٶ��ϴ�! \n");
			Sleep(1000);	system("cls");
			mainMenu();	printf("     ���ϸ� --> ");
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

	inH = inW = sqrt(fsize);			// (���� �߿�!) �ȼ� �� �ľ��ϴ� �ڵ�
	// �Է¿��� (inImage)�� �޸� �Ҵ�
	morpImage = malloc2D(inH, inW);

	// ���� --> �޸𸮷� �ε�
	rfp = fopen(filePath, "rb");
	for (int i = 0; i < inH; i++) {
		fread(morpImage[i], sizeof(unsigned char), inW, rfp);
	}

	//// ���� �ݱ� ////
	fclose(rfp);

	puts("\n");
	ori_printScreen();
}
*/

// ���� �̹���
void originImage(char oriImage) {
	// Original 128x128
	if (oriImage == 1)
		inImg_128();
	// Original 256x256
	else if (oriImage == 2)
		inImg_256();
	// Original 512x512
	else if (oriImage == 3)
		inImg_512();
	else
		printf("���� ���ε� ����! \n");
}
// ��� �̹���
void resultImage(char oriImage) {
	if (oriImage == 1)
		outImg_128();
	//else if (oriImage == 9)
	//	morpOutImg();

	// ��� �̹����� ���� �ٸ� ��ġ�� ���� ���� �� ���
	/*
	// Result 128x128
	if (oriImage == 1)
		outImg_128();
	// Result 256x256
	else if (oriImage == 2)
		outImg_256();
	// Result 512x512
	else if (oriImage == 3)
		outImg_512();
	*/
}
// ���� �̹��� ȭ�� ���
void ori_printScreen() {
	if (pix == 1)	originImage(1);				// 128x128
	else if (pix == 2)	originImage(2);		// 256x256
	else if (pix == 3)	originImage(3);		// 512x512
}
// ��� �̹��� ȭ�� ���
void res_printScreen() {
	if (pix == 1 || pix == 2 || pix == 3)
		resultImage(1);
	//else if (morpPix == 1)
	//	resultImage(9);

	// ��� �̹����� ���� �ٸ� ��ġ�� ���� ���� �� ���
	/*
	if (pix == 1)	resultImage(1);				// 128x128
	else if (pix == 2)	resultImage(2);		// 256x256
	else if (pix == 3)	resultImage(3);		// 512x512
	*/
}
//// ********************************************************************************* ////



//// ************************* < 1.ȭ���� ó�� ��� �Լ� ���Ǻ� > ********************** ////
// 1-A.�̹��� ��� �� ����
void brightControlImage() {
	// *******�Լ����� ���̱�******** //
	free2D_out();

	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	outH = inH;
	outW = inW;
	outImage = malloc2D(outH, outW);
	// ****************************** // 

	inImgCheck();

	int value;

	printf("\n\n\t ��� ���� �� --> ");
	scanf_s("%d", &value);

	ori_printScreen();
	// **************** �˰��� �κ� *****************  //
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
	if (value > 0)
		printf("\t\t\t\t\t  < ��� %d ���� ȭ�� >", value);
	else if (value < 0)
		printf("\t\t\t\t\t  < ��� %d ���� ȭ�� >", value);
	else
		printf("\n\n �ٽ� �Է��ϼ���! \n");
	res_printScreen();
}

// 1-B.�̹��� ���� ����
void clearControlImage() {
	free2D_out();

	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	outH = inH;
	outW = inW;
	outImage = malloc2D(outH, outW);

	inImgCheck();
	// **************** �˰��� �κ� *****************  
	int value = 0;

	printf("\n\n\t [���� ����] ");
	printf("\n\t   1.�����ϰ�  2.����ϰ� ");

	inKey = _getch();
	if (inKey == '1') {
		printf("\t   ���� ���� ��(���) --> ");
		scanf_s("%d", &value);

		while (1) {
			if (value > 0)		break;
			else
				printf("\n\t �Է¿���! ����� �ٽ� �Է��ϼ���! \n");
		}
	}
	else if (inKey == '2') {
		printf("\t   ���� ���� ��(���) --> ");
		scanf_s("%d", &value);

		while (1) {
			if (value > 0)		break;
			else
				printf("\n\t�Է¿���! ����� �ٽ� �Է��ϼ���! \n");
		}
	}
	else
		printf("\t\t �ٽ� �Է��ϼ���! \n");

	switch (inKey) {
	case '1':		// �����ϰ�
		clearUp(value);
		break;
	case '2':		// ����ϰ�
		clearDown(value);
		break;
	default:
		printf("�Է� ����! ���Է� �ٶ��ϴ�! \n");
		Sleep(1000);	system("cls");
		mainMenu();	printf("\t\t ���ϸ� --> ");
		break;
	}
}

// 1-C.�̹��� ���� ó��
void reverseImage() {
	free2D_out();

	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	outH = inH;
	outW = inW;
	outImage = malloc2D(outH, outW);

	inImgCheck();

	puts("\n\n");
	ori_printScreen();
	// **************** �˰��� �κ� *****************  
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			int px = inImage[i][k];

			outImage[i][k] = 255 - px;
		}
	}
	printf("\t\t\t\t\t  < ���� ���� ȭ�� > ");
	res_printScreen();
}

// 1-D.�̹��� ��� ó��
void grayScaleImage() {
	free2D_out();

	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	outH = inH;
	outW = inW;
	outImage = malloc2D(outH, outW);

	inImgCheck();

	printf("\n\n\t\t  1.128 ����  2.��հ� ���� \n");

	ori_printScreen();
	// **************** �˰��� �κ� *****************  
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

// 1-E.��Ʈ���� (And/Or/Xor/Not)
void bitCalcImage() {
	free2D_out();

	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	outH = inH;
	outW = inW;
	outImage = malloc2D(outH, outW);

	inImgCheck();
	// **************** �˰��� �κ� *****************  
	int value = 0;

	printf("\n\n\t\t 1.And  2.Or  3.Xor  4.Not ");

	inKey = _getch();
	if (inKey == '1' || inKey == '2' || inKey == '3') {
		while (1) {
			printf("\t ������ �� (0 or 255) : ");
			scanf_s("%d", &value);

			if (0 <= value && value <= 255)
				break;
			else
				printf("\n\t �Է¿���! ��(0~255)�� �ٽ� �Է��ϼ���! \n");
		}
	}
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

// 1-F.���� ��ȯ
// ���� : ���� ��ȭ�� ���������� ��ȭ��Ų ��
void gammaConverseImage() {
	free2D_out();

	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	// ��� ���� ����
	outH = inH;
	outW = inW;
	// ��� �̹��� ���� �Ҵ�
	outImage = malloc2D(outH, outW);

	inImgCheck();
	// **************** �˰��� �κ� ***************** 
	float value = 0;

	printf("\n\n\t ���� �� �Է� : ");
	scanf_s("%f", &value);

	ori_printScreen();

	if (value != 0)
		for (int i = 0; i < inH; i++)
			for (int k = 0; k < inW; k++) {
				float gamma = pow(float(inImage[i][k]), 1 / value);
				if (gamma > 255)
					outImage[i][k] = 255;
				else if (gamma < 0)
					outImage[i][k] = 0;
				else
					outImage[i][k] = gamma;
			}
	else
		printf(" �ٽ� �Է��ϼ���! \n");
	printf("\t\t\t\t\t  < ���� ��ȯ(%.1f) ȭ�� > ", value);
	res_printScreen();
}

// 1-G.���� ����
void rangeEmphasisImage() {
	free2D_out();

	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	outH = inH;
	outW = inW;
	outImage = malloc2D(outH, outW);

	inImgCheck();
	// **************** �˰��� �κ� *****************  //
	int start = 0;
	int end = 0;

	printf("\n\t ���� ���� �ʱⰪ : ");
	scanf("%d", &start);
	printf("\t ���� ���� ���ᰪ : ");
	scanf("%d", &end);

	ori_printScreen();

	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			if ((start <= inImage[i][k]) && (inImage[i][k] < end))
				outImage[i][k] = 255;
			else
				outImage[i][k] = inImage[i][k];
		}
	}
	printf("\t\t\t\t\t  < ���� ���� ȭ�� (���� : %d ~ %d) > ", start, end);
	res_printScreen();
}

// 1-H.�Ķ󺼶� ��ȯ
// (CAP : ���� ���� ��ü������ ����, CUP : ��ο� ���� ��ü��)
void parabolaImage() {
	free2D_out();

	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	outH = inH;
	outW = inW;
	outImage = malloc2D(outH, outW);

	inImgCheck();

	printf("\n\n\t\t 1.�Ķ󺼶�(CAP)  2.�Ķ󺼶�(CUP) \n");

	ori_printScreen();
	// **************** �˰��� �κ� *****************  //
	inKey = _getch();
	switch (inKey) {
	case '1':
		parabolaCap();
		break;
	case '2':
		parabolaCup();
		break;
	default:
		printf("\t\t �ٽ� �Է��ϼ���! \n");
		break;
	}
	res_printScreen();
}

// 1-I.��ϴ�� ��Ʈ��Ī
void stretchedImage() {
	free2D_out();

	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	outH = inH;
	outW = inW;
	outImage = malloc2D(outH, outW);

	inImgCheck();
	// **************** �˰��� �κ� ***************** 
	float value = 0;
	printf("\n\n\t\t ��Ʈ��Ī ���� �� : ");
	scanf("%f", &value);

	ori_printScreen();

	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			float px = inImage[i][k] + (outImage[i][k] - 128) * value;
			if (px > 255)
				outImage[i][k] = 255;
			else if (px < 0)
				outImage[i][k] = 0;
			else
				outImage[i][k] = (unsigned char)px;
		}
	}
	printf("\t\t\t\t\t  < ��Ʈ��Ī ȭ�� > ");
	res_printScreen();
}
//// ********************************************************************************* ////


//// ************************ < 2.ȭ����(������׷�) ó�� ��� �Լ� ���Ǻ� > ************************ ////
// 2-A.������׷� ���
void printHisto() {
	// ���� ��� �޸� ����
	free2D(outImage, outH);
	outH = 256;
	outW = 256;
	int reSize = outH * outW;

	puts("\n\n\n");
	ori_printScreen();

	unsigned char hist[256] = { 0 };		// ������׷� ���
	int LOW = 0;
	int HIGH = 255;
	unsigned char value = 0;

	//�ʱ�ȭ
	for (int i = 0; i < 256; i++) {
		hist[i] = 0;
	}

	//�󵵼� ����
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			value = inImage[i][k];
			hist[value]++;
		}
	}

	// ����ȭ
	unsigned char min = 0;// �ּҰ� �ʱ�ȭ
	unsigned char max = 0; // �ִ밪 �ʱ�ȭ
	unsigned char dif;
	int hNum = 0;
	for (int i = 0; i < 256; i++) {
		if (hist[i] <= min) min = (unsigned char)hist[i];
		if (hist[i] >= max) max = (unsigned char)hist[i];
	}
	dif = max - min;
	unsigned char scaleHist[256] = { 0 };

	// ����ȭ �� ������׷�
	for (int i = 0; i < 256; i++) {
		scaleHist[i] = (unsigned char)((hist[i] - min) * HIGH / dif);
	}

	// ����ȭ�� ������׷� ���
	unsigned char* OutImage = (unsigned char*)malloc((reSize) * sizeof(unsigned char));

	// ����ȭ��������׷��ǰ�����¹迭��������(0)����ǥ��
	for (int i = 0; i < outH; i++) {
		for (int k = 0; k < scaleHist[i]; k++) {
			OutImage[outW * (outH - k - 1) + i] = 0;
		}
	}
	hNum = 0;
	outImage = malloc2D(outH, outW);
	for (int i = 0; i < outH; i++) {
		for (int k = 0; k < outW; k++) {
			outImage[i][k] = OutImage[hNum];
			hNum++;
		}
	}
	free(OutImage);
	res_printScreen();
}

// 2-B.������׷� ��Ʈ��Ī
void histoStretchImage() {
	free2D_out();

	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	outH = inH;
	outW = inW;
	outImage = malloc2D(outH, outW);

	inImgCheck();

	puts("\n\n\n");
	ori_printScreen();
	// **************** �˰��� �κ� ***************** 
	/* ����.
	 out = (in - low) / (high - low) * 255.0;.*/

	int low = inImage[0][0], high = inImage[0][0];		// �ʱ�ȭ ���� ������ ���
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			if (inImage[i][k] < low)
				low = inImage[i][k];
			if (inImage[i][k] > high)
				high = inImage[i][k];
		}
	}
	for (int i = 0; i < inH; i++)
		for (int k = 0; k < inW; k++)
			outImage[i][k] = (double)(inImage[i][k] - low) / (high - low) * 255.0;

	printf("\t\t\t\t\t  < �̹��� ������׷� ��Ʈ��Ī ȭ�� > ");
	res_printScreen();
}

// 2-C.������׷� ����-�� Ž��
void histoEndInImage() {
	free2D_out();

	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	outH = inH;
	outW = inW;
	outImage = malloc2D(outH, outW);

	inImgCheck();

	puts("\n\n\n");
	ori_printScreen();
	// **************** �˰��� �κ� ***************** 
	int low = inImage[0][0], high = inImage[0][0];		// �ʱ�ȭ ���� ������ ���
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			if (inImage[i][k] < low)
				low = inImage[i][k];
			if (inImage[i][k] > high)
				high = inImage[i][k];
		}
	}
	low += 50;
	high -= 50;
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			double res = (double)(inImage[i][k] - low) / (high - low) * 255.0;
			if (res <= 0.0)
				outImage[i][k] = 0;
			else if (res > 255.0)
				outImage[i][k] = 255;
			else
				outImage[i][k] = res;
		}
	}
	printf("\t\t\t\t\t  < �̹��� ������׷� ����-�� Ž�� ȭ�� > ");
	res_printScreen();
}

// 2-D.������׷� ��Ȱȭ
/*
* 1�ܰ� : ��� �� j�� �󵵼� hist[j]�� ����� �Է� ������ ������׷� ����
* 2�ܰ� : �� ��� �� i���� 0~i������ ���� �󵵼�(������)�� ���
* 3�ܰ� : 2�ܰ迡�� ���� ���� �󵵼��� ����ȭ (����ȭ ������)
*/
void histoEqualImage() {
	free2D_out();

	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	outH = inH;
	outW = inW;
	outImage = malloc2D(outH, outW);

	inImgCheck();

	puts("\n\n\n");
	ori_printScreen();

	// **************** �˰��� �κ� ***************** 
	// 1�ܰ� : ������׷� ����
	int histo[256] = { 0, };
	for (int i = 0; i < inH; i++)
		for (int k = 0; k < inW; k++)
			histo[inImage[i][k]]++;

	// 2�ܰ� : ���� ������׷� ���� (������ ����)
	int sumHisto[256] = { 0, };
	sumHisto[0] = histo[0];
	for (int i = 1; i < 256; i++)
		sumHisto[i] = sumHisto[i - 1] + histo[i];

	// 3 �ܰ� : ����ȭ�� ���� ������׷� ���� (����ȭ�� ������ ����)
	// n = sum * (1/(inH*inW)) * 255.0
	double normalHisto[256] = { 0, };
	for (int i = 0; i < 256; i++)
		normalHisto[i] = sumHisto[i] * (1.0 / (inH * inW)) * 255.0;

	// 4�ܰ� : �������� ����ȭ ������ ġȯ
	for (int i = 0; i < inH; i++)
		for (int k = 0; k < inW; k++)
			outImage[i][k] = normalHisto[inImage[i][k]];

	printf("\t\t\t\t\t  < �̹��� ������׷� ��Ȱȭ ȭ�� > ");
	res_printScreen();
}
//// ******************************************************************************* ////


//// ************************** < 3.ȭ�� ���� ó�� ��� �Լ� ���Ǻ� > ************************** ////
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

// 3-A.������ ó��
// �Է� ������ �簢 ���·� ���̰� �ϴ� ���
void embossingImage() {
	free2D_out();

	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	outH = inH;
	outW = inW;
	outImage = malloc2D(outH, outW);

	inImgCheck();

	puts("\n\n\n");
	ori_printScreen();
	// **************** �˰��� �κ� ***************** 
	const int MSIZE = 3;
	// ������ ����ũ (�� ��ɿ� ���� ����ũ�� ���糪 ���۸�)
	double mask[MSIZE][MSIZE] =
	{ { -1,  0,  0},
	  {  0,  0,  0},
	  {  0,  0,  1} };

	// �ӽ� ����� �޸� �Ҵ�
	double** tmpIn, ** tmpOut;
	tmpIn = malloc2D_double(inH + 2, inW + 2);
	tmpOut = malloc2D_double(outH, outW);

	// �ӽ� �Է��� 0���� �ʱ�ȭ
	for (int i = 0; i < inH + 2; i++)
		for (int k = 0; k < inW + 2; k++)
			tmpIn[i][k] = 0.0;

	// �Է� ���� --> �ӽ� �Է� ���� (inImage --> tmpInImage)
	for (int i = 0; i < inH; i++)
		for (int k = 0; k < inW; k++)
			tmpIn[i + 1][k + 1] = inImage[i][k];

	// ȸ�� ���� --> ����ũ�� �ܾ�鼭 ����ϱ�
	double S; // ������ ���� �Է¿���X����ũ�� �հ�
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			S = 0.0;
			for (int m = 0; m < MSIZE; m++)
				for (int n = 0; n < MSIZE; n++)
					S += tmpIn[i + m][k + n] * mask[m][n];
			tmpOut[i][k] = S;
		}
	}

	// ��ó�� (����ũ�� �հ迡 ���� ����...)
	// ����ũ �հ谡 0�� ��쿡�� �߰� 
	for (int i = 0; i < outH; i++)
		for (int k = 0; k < outW; k++)
			tmpOut[i][k] += 127.0;

	// �ӽ� ��� --> ��� �޸�
	for (int i = 0; i < outH; i++)
		for (int k = 0; k < outW; k++) {
			double v = tmpOut[i][k];
			if (v > 255.0)
				v = 255.0;
			else if (v < 0.0)
				v = 0.0;

			outImage[i][k] = v;
		}
	free2D_double(tmpIn, inH + 2);
	free2D_double(tmpOut, outH);
	//*****************************
	printf("\t\t\t\t\t  < ������ ó�� ȭ�� > ");
	res_printScreen();
}

// 3-B.���� ó�� (3x3, 5x5)
// ������ �帮�� �ϰų� �ε巴�� �ϴ� ���
// ������(Low Pass Filter) ���, ������(High Pass Filter) ����  --> �δ���
void blurringImage() {
	free2D_out();

	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	outH = inH;
	outW = inW;
	outImage = malloc2D(outH, outW);

	inImgCheck();

	printf("\n\n\t 1.3x3  2.5x5 ");

	puts("\n\n");
	ori_printScreen();
	// **************** �˰��� �κ� ***************** 
	inKey = _getch();

	switch (inKey) {
	case '1':	blurring33();		break;
	case '2':	blurring55();		break;
	default:
		printf("\n\n\t �ٽ� �Է��ϼ���!!! \n");
	}
	res_printScreen();
}

// 3-C.������ ó�� (������, ���������� ó�� ������, ���������� ó�� ������)
// ���� �ݴ�, ���� �κ� ���� ����
// ������(High Pass Filter) ���, ������(Low Pass Filter) ����  --> Ŀ�н���
void sharpeningImage() {
	free2D_out();

	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	outH = inH;
	outW = inW;
	outImage = malloc2D(outH, outW);

	inImgCheck();

	printf("\n\n\t 1.������  2.HPF������  3.LPF������ ");

	puts("\n\n");
	ori_printScreen();
	// **************** �˰��� �κ� ***************** 
	inKey = _getch();

	switch (inKey) {
	case '1':	sharpening();	break;
	case '2':	HPF_sharp();	break;
	case '3':	LPF_sharp();		break;
	}
	res_printScreen();
}

// 3-D.������(����þ�) ó��
// ������ �κ��� �����Ͽ� �ε巴�� ��
void smoothingImage() {
	free2D_out();

	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	outH = inH;
	outW = inW;
	outImage = malloc2D(outH, outW);

	inImgCheck();

	puts("\n\n\n");
	ori_printScreen();
	// **************** �˰��� �κ� ***************** 
	const int MSIZE = 3;
	// ������ ����ũ (�� ��ɿ� ���� ����ũ�� ���糪 ���۸�)
	double mask[MSIZE][MSIZE] =
	{ {  1. / 16,  1. / 8,  1. / 16},
	  {   1. / 8,   1. / 4,   1. / 8},
	  {  1. / 16,  1. / 8,  1. / 16} };

	// �ӽ� ����� �޸� �Ҵ�
	double** tmpIn, ** tmpOut;
	tmpIn = malloc2D_double(inH + 2, inW + 2);
	tmpOut = malloc2D_double(outH, outW);

	// �ӽ� �Է��� 0���� �ʱ�ȭ
	for (int i = 0; i < inH + 2; i++)
		for (int k = 0; k < inW + 2; k++)
			tmpIn[i][k] = 0.0;

	// �Է� ���� --> �ӽ� �Է� ����
	for (int i = 0; i < inH; i++)
		for (int k = 0; k < inW; k++)
			tmpIn[i + 1][k + 1] = inImage[i][k];

	// ȸ�� ���� --> ����ũ�� �ܾ�鼭 ����ϱ�
	double S; // ������ ���� �Է¿���X����ũ�� �հ�
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			S = 0.0;
			for (int m = 0; m < MSIZE; m++)
				for (int n = 0; n < MSIZE; n++)
					S += tmpIn[i + m][k + n] * mask[m][n];
			tmpOut[i][k] = S;
		}
	}

	// ��ó�� (����ũ�� �հ迡 ���� ����...)
	// ����ũ�� ���� 0�� �ƴϹǷ� �ּ� ó��
	/*
	for (int i = 0; i < outH; i++)
		for (int k = 0; k < outW; k++)
			tmpOut[i][k] += 127.0;
	*/

	// �ӽ� ��� --> ��� �޸�
	for (int i = 0; i < outH; i++)
		for (int k = 0; k < outW; k++) {
			double v = tmpOut[i][k];
			if (v > 255.0)
				v = 255.0;
			else if (v < 0.0)
				v = 0.0;

			outImage[i][k] = v;
		}

	free2D_double(tmpIn, inH + 2);
	free2D_double(tmpOut, outH);
	//*****************************
	printf("\t\t\t\t\t  < ������(����þ�) ó�� ȭ�� > ");
	res_printScreen();
}
//// ********************************************************************************* ////


//// ************************** < 4.ȭ�� ���� (���� ����) ó�� ��� �Լ� ���Ǻ� > ************************** ////
// 4-A.�̵��� ���� ���� ���� (����, ����, ��������)
// ȭ���� ��ġ�� ��/�Ʒ�/��/���������� �ϳ��� �̵� -> ���� ȭ�� �� - �̵���ġ ȭ�� ��
// ���� ������ ��κ� �� ��� ����
// Shift & Difference
void shiftDifferEdgeImage() {
	free2D_out();

	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	outH = inH;
	outW = inW;
	outImage = malloc2D(outH, outW);

	inImgCheck();

	printf("\n\n\t 1.����  2.����  3.����*���� ");

	puts("\n");
	ori_printScreen();
	// **************** �˰��� �κ� ***************** 
	inKey = _getch();

	switch (inKey) {
	case '1':	horizontalEdge();			break;
	case '2':	verticalEdge();		break;
	case '3':	horiVertiEdge();	break;
	}
	res_printScreen();
}
//// ********************************************************************************* ////


//// ************************** < 5.������ ó�� ��� �Լ� ���Ǻ� > ************************** ////
// 5-A.�̷��� (�¿�/����/�¿�+����) 
void mirroringImage() {
	free2D_out();

	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	outH = inH;
	outW = inW;
	outImage = malloc2D(outH, outW);

	inImgCheck();

	printf("\n\n\t 1.�¿�  2.����  3.����+�¿� ");

	puts("");
	ori_printScreen();
	// **************** �˰��� �κ� ***************** 
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
		printf(" �ٽ� �Է��ϼ���! \n");
		break;
	}
	res_printScreen();
}

// 5-B.ȸ��(������,���� 90/180/270/����-�����+�߾�)
void turnImage() {
	free2D_out();

	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	outH = inH;
	outW = inW;
	outImage = malloc2D(outH, outW);

	inImgCheck();
	// **************** �˰��� �κ� ***************** 
	int direct = 0;

	printf("\n\n\t [����] 1.������  2.����  3.���� ");
	scanf_s("%d", &direct);

	// �ð���� ȸ��
	if (direct == 1) {
		printf("\n\t\t    [����_�ð����] 1.90  2.180  3.270 ");
		inKey = _getch();

		ori_printScreen();

		switch (inKey) {
		case '1':	// 90�� ȸ��
			turn90Right();	break;
		case '2':	// 180�� ȸ��
			turn180Right();	break;
		case '3':	// 270�� ȸ��
			turn270Right();	break;
		default:
			break;
		}
	}
	// �ݽð���� ȸ��
	else if (direct == 2) {
		printf("\n\t\t    [����_�ݽð����] 1.90  2.180  3.270 ");
		inKey = _getch();

		ori_printScreen();

		switch (inKey) {
		case '1':	// 90�� ȸ��
			turn90Left();	break;
		case '2':	// 180�� ȸ�� 
			turn180Left();	break;
		case '3':	// 270�� ȸ��
			turn270Left();	break;
		default:
			break;
		}
	}
	// ����ȸ��
	else if (direct == 3) {
		int angle;
		printf("\n\t\tȸ�� ���� --> ");
		scanf("%d", &angle);

		printf("\t\t 1.����ȸ��  2.����ȸ��(�����+�߾�) ");

		ori_printScreen();

		inKey = _getch();
		switch (inKey) {
		case '1':		// ����ȸ��
			turnFree(angle);		break;
		case '2':		// ����ȸ�� (�����+�߾�)
			turnFreeCenter(angle);		break;
		default:
			printf("\n\t\t �Է� ����! ���Է� �ٶ��ϴ�! \n");
			Sleep(1000);	system("cls");
			mainMenu();	printf("\t\t ���ϸ� --> ");
		}
	}
	else {
		printf("\t\t�ٽ� �Է����ּ���! \n");
		return;
	}
	res_printScreen();
}

// 5-C.�̹��� ũ��(�԰�) Ȯ��/���
void imageSizeUpDown() {
	free2D_out();

	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	outH = inH;
	outW = inW;
	outImage = malloc2D(outH, outW);

	inImgCheck();
	// **************** �˰��� �κ� ***************** 
	int scale = 0;

	printf("\n\n\t\t 1.�̹��� ũ�� Ȯ�� (������)   2.�̹��� ũ�� Ȯ�� (�����) ");
	printf("\n\n\t\t 3.�̹��� ũ�� ��� (������)   4.�̹��� ũ�� ��� (�����) ");

	inKey = _getch();
	if (inKey == '1' || inKey == '2') {
		printf("\t\t �̹��� Ȯ�� ���� : ");
		scanf("%d", &scale);

		while (1) {
			if (scale > 0)
				break;
			else
				printf("\n\t\t �Է¿���! ����� �ٽ� �Է��ϼ���! \n");
		}
	}
	else if (inKey == '3' || inKey == '4') {
		printf("\t\t �̹��� ��� ���� : ");
		scanf("%d", &scale);

		while (1) {
			if (scale > 0)
				break;
			else
				printf("\n\t\t �Է¿���! ����� �ٽ� �Է��ϼ���! \n");
		}
	}
	else
		printf("\t\t �ٽ� �Է��ϼ���! \n");

	ori_printScreen();

	switch (inKey) {
	case '1':	sizeUp(scale);	break;
	case '2':	backwardMappingSizeUp(scale);		break;
	case '3':	sizeDown(scale);	break;
	case '4':	backwardMappingSizeDown(scale);		break;
	default:		printf("\t\t�ٽ� �Է��ϼ���! \n");	break;
	}
	res_printScreen();
}

// 5-D.�̵�
void moveImage() {
	free2D_out();

	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	outH = inH;
	outW = inW;
	outImage = malloc2D(outH, outW);

	inImgCheck();
	// **************** �˰��� �κ� ***************** 
	int value = 0;

	printf("\n\n\t\t  �̵��� �� : ");
	scanf("%d", &value);

	puts("\n");
	ori_printScreen();

	// ��� �̹��� 0���� �ʱ�ȭ
	for (int i = 0; i < inH; i++)
		for (int k = 0; k < inW; k++)
			outImage[i][k] = 0;

	for (int i = 0; i < inH - value; i++)
		for (int k = 0; k < inW - value; k++)
			outImage[i][k] = inImage[i + value][k + value];

	printf("\t\t\t\t\t  < %d��ŭ �̵��� ȭ�� > ", value);
	res_printScreen();
}

// 5-E.����
void warpingImage() {
	free2D_out();

	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	outH = inH;
	outW = inW;
	outImage = malloc2D(outH, outW);

	inImgCheck();

	puts("\n\n\n");
	ori_printScreen();
	// **************** �˰��� �κ� ***************** 
	for (int i = 0; i < outH; i++)
		for (int k = 0; k < outW; k++)
			outImage[i][k] = 0;

	for (int k = 0; k < outW; k++) {
		double f_px = (4.0 / outH) * k * (outW - k);
		double b_px = (4.0 / outH) * (k + 1) * (outW - k - 1);
		int px = int((f_px + b_px) / 2);
		double rate = double(outH) / px;

		for (int i = 0; i < px; i++) {
			unsigned long sum = 0;
			for (int l = int(i * rate); l<int((i + 1) * rate); l++)
				sum += inImage[l][k];
			outImage[i][k] = sum / (int((i + 1) * rate) - int(i * rate));
		}
	}
	printf("\t\t\t\t\t  < ���ε� �̹��� > ");
	res_printScreen();
}

// 5-F.����
/*
void morphingImage() {
	free2D_out();

	// (�߿�!) ��¿����� ũ�⸦ ���� --> �˰��� ����
	outH = inH;
	outW = inW;
	outImage = malloc2D(outH, outW);

	inImgCheck();

	puts("\n\n");
	ori_printScreen();
	// **************** �˰��� �κ� *****************
	printf("\n\n ������ �̹��� �߰� \n");


	printf("\t\t\t\t\t  < ���ε� �̹��� > ");
	res_printScreen();
}
*/

// E.�缱�� ������ ȸ��
// Binary interpolation rotation
//void rotateBinaryInterpol() {// ���� ȸ�� �˰���. �߾�ȸ��+�����+Ȯ��
//
//	// ���� ��� �޸� ����
//	free2D(m_OutImage, m_outH); // ������ ���� ���� ������ ��� width,height�� �Է°� �ٸ� �� �ֱ� ������ ������ �������� �ؾ��Ѵ�.
//
//
//	// ��¥ ����ó�� �˰���
//
//	int angle; // 0~ 360 �ε� ��ǻ�ʹ� radian���� �ν� ���� ��ȯ���־����
//	printf("�̵� ���� ũ�� �Է�:\n  ");
//	scanf("%d", &angle);
//
//
//
//	double radian = (angle * 3.141592) / 180.0;
//	double radian90 = ((90 - angle) * 3.141592) / 180.0;  // 90�� �Ѵ� ���� ��� ������� ����
//	// newX = cos * x - sin * y  ���� ȸ�� ���� x = i , y = k
//	// newY = sin * x + cos * y
//
//
//
//	//(�߿�!) ��� ������ ���̿� ���� �����ؾ��Ѵ� --> �˰��� ���� �޶�������
//
//	m_outH = (int)(m_inH * fabs(cos(radian90)) + m_inW * fabs(cos(radian)));     // Ȯ�븦 ���� �Է¹��� �� �� ��� �� ���� ���ؾ� �ؼ� ��ġ�� �Ʒ���
//	m_outW = (int)(m_inW * fabs(cos(radian)) + m_inW * fabs(cos(radian90)));   // �Ǽ����� ������ �مf��. �Ǽ��� ���� �� �ֱ� ����  
//																				 // cos���� ������ �� �ֱ� ������ fabs�� �Ǽ��϶� ���밪 ������
//	// ��� ���� �޸� �Ҵ�
//
//	m_OutImage = malloc2D(m_outH, m_outW);
//
//	// �ӽ� �Է� ���� -----> ��°� ũ�Ⱑ ���� �ϰ� , �Է� ���� �α�
//
//	UC** tmpInput = malloc2D(m_outH, m_outW); // �ӽ� �Է� ���� �޸� �Ҵ� (���ũ��� �Ҵ�) 
//
//
//	int dx = (m_outW - m_inW) / 2;
//	int dy = (m_outH - m_inH) / 2;
//
//	for (int i = 0; i < m_inH; i++) {
//		for (int k = 0; k < m_inW; k++) {
//
//			tmpInput[i + dy][k + dx] = m_InImage[i][k]; // ���������� tmpInput�� �״�� �����ϴµ� tmpInput�� (0,0) ��ǥ���� �߾����� �̵���Ŵ(dy,dx)
//			m_OutImage[i][k] = 0;
//		}
//	}
//
//
//	// �߾� ��ġ ���ϱ�
//	int centerx = m_outW / 2; //ȸ�� ������ �߾�
//	int centery = m_outH / 2;
//
//	int x1, x2, y1, y2;
//	double rx, ry, p, q, value;
//
//
//	//for (int i = 0; i < m_outH; i++) { // �����, ������ ��� : ��� �������� for�� ��������
//	//	for (int k = 0; k < m_outW; k++) {
//
//	//		int oldI = (cos(radian) * (i - centerx) + sin(radian) * (k - centery)) + centery;  // �߾ӱ��� ȸ���� ���� ���� ���� , ������������� �ٲ� ��ȣ��
//	//		int oldK = (-sin(radian) * (i - centerx) + cos(radian) * (k - centery)) + centerx;
//
//	//		if (((0 <= oldI) && (oldI < m_outH)) && ((0 <= oldK) && (oldK < m_outW))) {
//
//
//	//			tmpOutput[i][k] = tmpInput[oldI][oldK] ;   // �߾ӿ� ���� tmpInput�� �����ش�. 
//
//
//	//		}
//	//		
//
//
//	//	}
//	//}
//
//	for (int i = 0; i < m_outH; i++) {
//		for (int k = 0; k < m_outW; k++) {
//
//			// �Ǽ��� ���� rx, ry�� �Է� ���󿡼� ������ �ȼ� ���� �Ǽ� ��ǥ 
//			rx = (double)(-sin(radian)) * (i - centerx) + cos(radian) * (k - centery) + centerx;
//			ry = (double)(cos(radian)) * (i - centerx) + sin(radian) * (k - centery) + centery;
//
//			if (0 <= rx && rx < m_outW && 0 <= ry && ry < m_outH) {
//				// x1, x2, y1, y2�� ����(rx, ry) ��ǥ�� �ѷ��� 4���� �ȼ� ��ǥ�� ��Ÿ����.
//				x1 = (int)rx;
//				y1 = (int)ry;
//
//				x2 = x1 + 1;
//				if (x2 == m_outW) {
//					x2 = m_outW - 1;
//				}
//
//				y2 = y1 + 1;
//				if (y2 == m_outH) {
//					y2 = m_outH - 1;
//				}
//				// p�� q�� 0���� 1 ������ ���� ���� �Ǽ��� ���� 
//				p = rx - x1;
//				q = ry - y1;
//
//				value = (1. - p) * (1. - q) * tmpInput[y1][x1]
//					+ p * (1. - q) * tmpInput[y2][x1]
//					+ (1. - p) * q * tmpInput[y1][x2]
//					+ p * q * tmpInput[y2][x2];
//
//
//				if (value > 255) {
//					value = 255;
//				}
//				else if (value < 0) {
//					value = 0;
//				}
//				m_OutImage[i][k] = (UC)value;
//			}
//
//		}
//	}
//
//	free2D(tmpInput, m_outH); // �ӽ� �Է� ���� �޸� ����� RAM ���� ���Ͼ
//	displayImage();
//
//}

// F.�缱�� ������ Ȯ��
// Enlarging bimodal interpolation.
//void enlargeBinaryInterpol() {
//
//}

//// ******************************************************************************* ////




//// *************************** < ��� ó�� �Լ� ���Ǻ� > *************************** ////
// �Է� �̹��� �Է� ���� Ȯ��
void inImgCheck() {
	if (inImage == NULL) {
		printf("\n\n  < ����!!! > �Է� �̹��� ����!! �̹����� ���� �ҷ�������! \n");
		Sleep(1500);
		system("cls");
		mainMenu();
		//return;
	}
}

// �̹��� ���� �Է�_128x128
void inImg_128() {
	short px = 0;
	printf("\n\n     < ���� �̹��� ȭ��(128) > ");
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			px = inImage[i][k];
			SetPixel(hdc, k + 50, i + 470, RGB(px, px, px));		// hdc�� �������ִ� �Լ�		// i, k -> k+50, i+250
		}
	}
}
// �̹��� ���� �Է�_256x256
void inImg_256() {
	short px = 0;
	printf("\n\n     < ���� �̹��� ȭ��(256) > ");
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			px = inImage[i][k];
			SetPixel(hdc, k + 50, i + 470, RGB(px, px, px));		// hdc�� �������ִ� �Լ�		// i, k -> k+50, i+250
		}
	}
}
// �̹��� ���� �Է�_512x512
void inImg_512() {
	short px = 0;
	printf("\n\n     < ���� �̹��� ȭ��(512) > ");
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			px = inImage[i][k];
			SetPixel(hdc, k + 50, i + 470, RGB(px, px, px));		// hdc�� �������ִ� �Լ�		// i, k -> k+50, i+250
		}
	}
}
// �̹��� ���� ���_128x128
void outImg_128() {
	short px = 0;
	for (int i = 0; i < outH; i++) {
		for (int k = 0; k < outW; k++) {
			px = outImage[i][k];
			SetPixel(hdc, k + 600, i + 470, RGB(px, px, px));		// hdc�� �������ִ� �Լ�		// i, k -> k+50, i+250
		}
	}
}
// �̹��� ���� ���_256x256
void outImg_256() {
	short px = 0;
	for (int i = 0; i < outH; i++) {
		for (int k = 0; k < outW; k++) {
			px = outImage[i][k];
			SetPixel(hdc, k + 600, i + 470, RGB(px, px, px));		// hdc�� �������ִ� �Լ�		// i, k -> k+50, i+250
		}
	}
}
// �̹��� ���� ���_512x512
void outImg_512() {
	short px = 0;
	for (int i = 0; i < outH; i++) {
		for (int k = 0; k < outW; k++) {
			px = outImage[i][k];
			SetPixel(hdc, k + 600, i + 470, RGB(px, px, px));		// hdc�� �������ִ� �Լ�		// i, k -> k+50, i+250
		}
	}
}
// ������ �̹��� ���
/*
void morpOutImg() {
	short px = 0;
	for (int i = 0; i < outH; i++) {
		for (int k = 0; k < outW; k++) {
			px = outImage[i][k];
			SetPixel(hdc, k + 1000, i + 200, RGB(px, px, px));		// hdc�� �������ִ� �Լ�		// i, k -> k+50, i+250
		}
	}
}
*/


// 1-B.�����ϰ�
void clearUp(int val) {
	ori_printScreen();

	if (val > 0) {
		for (int i = 0; i < inH; i++) {
			for (int k = 0; k < inW; k++) {
				int px = inImage[i][k] * val;		// px : pixel

				if (px > 255)
					outImage[i][k] = 255;
				else
					outImage[i][k] = px;
			}
		}
		printf("\t\t\t\t\t  < ���� %d ���� ȭ�� >", val);
		res_printScreen();
	}
	else
		printf("\t\t���� �Ǵ� 0 �Է�.. ����� �Է����ּ���.");
}
// 1-B.�帴�ϰ�
void clearDown(int val) {
	ori_printScreen();

	if (val > 0) {
		for (int i = 0; i < inH; i++) {
			for (int k = 0; k < inW; k++) {
				int px = inImage[i][k] / val;		// px : pixel

				if (px > 255)
					outImage[i][k] = 255;
				else
					outImage[i][k] = px;
			}
		}
		printf("\t\t\t\t\t  < ���� %d ���� ȭ�� >", val);
		res_printScreen();
	}
	else
		printf("\t\t���� �Ǵ� 0 �Է�.. ����� �Է����ּ���.");
}

// 1-D.���ó�� (128 ����)
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
	printf("\t\t\t\t\t  < ���� ��� ó��(128 ����) ȭ�� > ");
	res_printScreen();
}
// 1-D.���ó�� (��հ� ����)
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
	printf("\t\t\t\t\t  < ���� ��� ó��(��հ� %d ����) ȭ�� > ", pixelAvg);
	res_printScreen();
}

// 1-E.��Ʈ����_And
void bitCalc_And(int val) {
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			unsigned char px = inImage[i][k] & val;

			outImage[i][k] = px;
		}
	}
	printf("\t\t\t\t\t  < AND ��Ʈ ���� ȭ��, �Է°� : %d > ", val);
	res_printScreen();
}
// 1-E.��Ʈ����_Or
void bitCalc_Or(int val) {
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			unsigned char px = inImage[i][k] | val;

			outImage[i][k] = px;
		}
	}
	printf("\t\t\t\t\t  < OR ��Ʈ ���� ȭ��, �Է°� : %d > ", val);
	res_printScreen();
}
// 1-E.��Ʈ����_Xor
void bitCalc_Xor(int val) {
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			unsigned char px = inImage[i][k] ^ val;

			outImage[i][k] = px;
		}
	}
	printf("\t\t\t\t\t  < XOR ��Ʈ ���� ȭ��, �Է°� : %d > ", val);
	res_printScreen();
}
// 1-E.��Ʈ����_Not
void bitCalc_Not() {
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			unsigned char px = ~inImage[i][k];

			outImage[i][k] = px;
		}
	}
	printf("\t\t\t\t\t  < NOT ��Ʈ ���� ȭ�� > ");
	res_printScreen();
}

// 1-H.�Ķ󺼶�_CAP ��ȯ
void parabolaCap() {
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			float px = (4 / 255.0) * inImage[i][k] * (255 - inImage[i][k]);
			outImage[i][k] = (unsigned char)px;
		}
	}
	printf("\t\t\t\t\t  < �Ķ󺼶�_CAP ��ȯ ȭ�� > ");
}
// 1-H.�Ķ󺼶�_CUP ��ȯ
void parabolaCup() {
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			float px = (4 / 255.0) * inImage[i][k] * (inImage[i][k] - 255) + 255;
			outImage[i][k] = (unsigned char)px;
		}
	}
	printf("\t\t\t\t\t  < �Ķ󺼶�_CUP ��ȯ ȭ�� > ");
}


// 3-B.3x3 ����
void blurring33() {
	const int MSIZE = 3;
	// 3x3 ���� ����ũ (�� ��ɿ� ���� ����ũ�� ���糪 ���۸�)
	double mask[MSIZE][MSIZE] =
	{ {  1. / 9,  1. / 9,  1. / 9  },
	  {  1. / 9,  1. / 9,  1. / 9  },
	  {  1. / 9,  1. / 9,  1. / 9  } };

	// �ӽ� ����� �޸� �Ҵ�
	double** tmpIn, ** tmpOut;
	tmpIn = malloc2D_double(inH + 2, inW + 2);
	tmpOut = malloc2D_double(outH, outW);

	// �ӽ� �Է��� 0���� �ʱ�ȭ
	for (int i = 0; i < inH + 2; i++)
		for (int k = 0; k < inW + 2; k++)
			tmpIn[i][k] = 0.0;

	// �Է� ���� --> �ӽ� �Է� ����
	for (int i = 0; i < inH; i++)
		for (int k = 0; k < inW; k++)
			tmpIn[i + 1][k + 1] = inImage[i][k];

	// ȸ�� ���� --> ����ũ�� �ܾ�鼭 ����ϱ�
	double S; // ������ ���� �Է¿���X����ũ�� �հ�
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			S = 0.0;
			for (int m = 0; m < MSIZE; m++)
				for (int n = 0; n < MSIZE; n++)
					S += tmpIn[i + m][k + n] * mask[m][n];

			tmpOut[i][k] = S;
		}
	}

	// ��ó�� (����ũ�� �հ迡 ���� ����...)
	// ����ũ�� ���� 0�� �ƴϹǷ� �ּ� ó��
	/*
	for (int i = 0; i < outH; i++)
		for (int k = 0; k < outW; k++)
			tmpOut[i][k] += 127.0;
	*/

	// �ӽ� ��� --> ��� �޸�
	for (int i = 0; i < outH; i++)
		for (int k = 0; k < outW; k++) {
			double v = tmpOut[i][k];
			if (v > 255.0)
				v = 255.0;
			else if (v < 0.0)
				v = 0.0;

			outImage[i][k] = v;
		}

	free2D_double(tmpIn, inH + 2);
	free2D_double(tmpOut, outH);
	//*****************************
	printf("\t\t\t\t\t  < 3x3 ���� ó�� ȭ�� > ");
}
// 3-B.5x5 ����
void blurring55() {
	const int MSIZE = 5;
	// 5x5 ���� ����ũ (�� ��ɿ� ���� ����ũ�� ���糪 ���۸�)
	double mask[MSIZE][MSIZE] =
	{ {1 / 25.,1 / 25.,1 / 25.,1 / 25.,1 / 25.},
	  {1 / 25.,1 / 25.,1 / 25.,1 / 25.,1 / 25.},
	  {1 / 25.,1 / 25.,1 / 25.,1 / 25.,1 / 25.},
	  {1 / 25.,1 / 25.,1 / 25.,1 / 25.,1 / 25.},
	  {1 / 25.,1 / 25.,1 / 25.,1 / 25.,1 / 25.} };

	// �ӽ� ����� �޸� �Ҵ�
	double** tmpIn, ** tmpOut;
	tmpIn = malloc2D_double(inH + 4, inW + 4);		// �������� ����ŷ�� �����ϰ� �ϱ�����. (�о��� �������� ������ ����)
	tmpOut = malloc2D_double(outH, outW);

	// �ӽ� �Է��� 0���� �ʱ�ȭ
	for (int i = 0; i < inH + 2; i++)
		for (int k = 0; k < inW + 2; k++)
			tmpIn[i][k] = 0.0;

	// �Է� ���� --> �ӽ� �Է� ����
	for (int i = 0; i < inH; i++)
		for (int k = 0; k < inW; k++)
			tmpIn[i + 2][k + 2] = inImage[i][k];

	// ȸ�� ���� --> ����ũ�� �ܾ�鼭 ����ϱ�
	double S; // ������ ���� �Է¿���X����ũ�� �հ�
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			S = 0.0;
			for (int m = 0; m < MSIZE; m++)
				for (int n = 0; n < MSIZE; n++)
					S += tmpIn[i + m][k + n] * mask[m][n];

			tmpOut[i][k] = S;
		}
	}

	// ��ó�� (����ũ�� �հ迡 ���� ����...)
	// ����ũ�� ���� 0�� �ƴϹǷ� �ּ� ó��
	/*
	for (int i = 0; i < outH; i++)
		for (int k = 0; k < outW; k++)
			tmpOut[i][k] += 127.0;
	*/

	// �ӽ� ��� --> ��� �޸�
	for (int i = 0; i < outH; i++)
		for (int k = 0; k < outW; k++) {
			double v = tmpOut[i][k];
			if (v > 255.0)
				v = 255.0;
			else if (v < 0.0)
				v = 0.0;

			outImage[i][k] = v;
		}

	free2D_double(tmpIn, inH + 4);
	free2D_double(tmpOut, outH);
	//*****************************
	printf("\t\t\t\t\t  < 5x5 ���� ó�� ȭ�� > ");
}

// 3-C.������
void sharpening() {
	const int MSIZE = 3;
	// ������ ����ũ (�� ��ɿ� ���� ����ũ�� ���糪 ���۸�)
	double mask[MSIZE][MSIZE] =
	{ { -1, -1, -1},
	  { -1,  9, -1},
	  { -1, -1, -1} };

	// �ӽ� ����� �޸� �Ҵ�
	double** tmpIn, ** tmpOut;
	tmpIn = malloc2D_double(inH + 2, inW + 2);
	tmpOut = malloc2D_double(outH, outW);

	// �ӽ� �Է��� 0���� �ʱ�ȭ
	for (int i = 0; i < inH + 2; i++)
		for (int k = 0; k < inW + 2; k++)
			tmpIn[i][k] = 0.0;

	// �Է� ���� --> �ӽ� �Է� ����
	for (int i = 0; i < inH; i++)
		for (int k = 0; k < inW; k++)
			tmpIn[i + 1][k + 1] = inImage[i][k];

	// ȸ�� ���� --> ����ũ�� �ܾ�鼭 ����ϱ�
	double S; // ������ ���� �Է¿���X����ũ�� �հ�
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			S = 0.0;
			for (int m = 0; m < MSIZE; m++)
				for (int n = 0; n < MSIZE; n++)
					S += tmpIn[i + m][k + n] * mask[m][n];

			tmpOut[i][k] = S;
		}
	}

	// ��ó�� (����ũ�� �հ迡 ���� ����...)
	// ����ũ�� ���� 0�� �ƴϹǷ� �ּ� ó��
	/*
	for (int i = 0; i < outH; i++)
		for (int k = 0; k < outW; k++)
			tmpOut[i][k] += 127.0;
	*/

	// �ӽ� ��� --> ��� �޸�
	for (int i = 0; i < outH; i++)
		for (int k = 0; k < outW; k++) {
			double v = tmpOut[i][k];
			if (v > 255.0)
				v = 255.0;
			else if (v < 0.0)
				v = 0.0;

			outImage[i][k] = v;
		}

	free2D_double(tmpIn, inH + 2);
	free2D_double(tmpOut, outH);
	//*****************************
	printf("\t\t\t\t\t  < ������ ó�� ȭ�� > ");
}
// 3-C.���������� ó�� ������
void HPF_sharp() {
	const int MSIZE = 3;
	// ���������� ����ũ (�� ��ɿ� ���� ����ũ�� ���糪 ���۸�)
	double mask[MSIZE][MSIZE] =
	{ {  -1. / 9,  -1. / 9,  -1. / 9  },
	  {  -1. / 9,   8. / 9,  -1. / 9  },
	  {  -1. / 9,  -1. / 9,  -1. / 9  } };

	// �ӽ� ����� �޸� �Ҵ�
	double** tmpIn, ** tmpOut;
	tmpIn = malloc2D_double(inH + 2, inW + 2);
	tmpOut = malloc2D_double(outH, outW);

	// �ӽ� �Է��� 0���� �ʱ�ȭ
	for (int i = 0; i < inH + 2; i++)
		for (int k = 0; k < inW + 2; k++)
			tmpIn[i][k] = 0.0;

	// �Է� ���� --> �ӽ� �Է� ����
	for (int i = 0; i < inH; i++)
		for (int k = 0; k < inW; k++)
			tmpIn[i + 1][k + 1] = inImage[i][k];

	// ȸ�� ���� --> ����ũ�� �ܾ�鼭 ����ϱ�
	double S; // ������ ���� �Է¿���X����ũ�� �հ�
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			S = 0.0;
			for (int m = 0; m < MSIZE; m++)
				for (int n = 0; n < MSIZE; n++)
					S += tmpIn[i + m][k + n] * mask[m][n];

			tmpOut[i][k] = S;
		}
	}

	// ��ó�� (����ũ�� �հ迡 ���� ����...)
	for (int i = 0; i < outH; i++)
		for (int k = 0; k < outW; k++)
			tmpOut[i][k] += 127.0;

	// �ӽ� ��� --> ��� �޸�
	for (int i = 0; i < outH; i++)
		for (int k = 0; k < outW; k++) {
			double v = tmpOut[i][k];
			if (v > 255.0)
				v = 255.0;
			else if (v < 0.0)
				v = 0.0;

			outImage[i][k] = v;
		}

	free2D_double(tmpIn, inH + 2);
	free2D_double(tmpOut, outH);
	//*****************************
	printf("\t\t\t\t\t  < ���������� ó�� ������ ȭ�� > ");
}
// 3-C.���������� ó�� ������
void LPF_sharp() {
	const int MSIZE = 3;
	// ������ ���� ����ũ (�� ��ɿ� ���� ����ũ�� ���糪 ���۸�)
	double mask[MSIZE][MSIZE] =
	{ {	1. / 16,	2. / 16,	1. / 16},
	  {	2. / 16,	4. / 16,	2. / 16},
	  {	1. / 16,	2. / 16,	1. / 16} };

	// �ӽ� ����� �޸� �Ҵ�
	double** tmpIn, ** tmpOut;
	tmpIn = malloc2D_double(inH + 2, inW + 2);
	tmpOut = malloc2D_double(outH, outW);

	// �ӽ� �Է��� 0���� �ʱ�ȭ
	for (int i = 0; i < inH + 2; i++)
		for (int k = 0; k < inW + 2; k++)
			tmpIn[i][k] = 0.0;

	// �Է� ���� --> �ӽ� �Է� ����
	for (int i = 0; i < inH; i++)
		for (int k = 0; k < inW; k++)
			tmpIn[i + 1][k + 1] = inImage[i][k];

	// ȸ�� ���� --> ����ũ�� �ܾ�鼭 ����ϱ�
	double S; // ������ ���� �Է¿���X����ũ�� �հ�
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			S = 0.0;
			for (int m = 0; m < MSIZE; m++)
				for (int n = 0; n < MSIZE; n++)
					S += tmpIn[i + m][k + n] * mask[m][n];

			tmpOut[i][k] = S;
		}
	}

	// ��ó�� (����ũ�� �հ迡 ���� ����...)
	for (int i = 0; i < outH; i++)
		for (int k = 0; k < outW; k++)
			tmpOut[i][k] += 127.0;

	// �ӽ� ��� --> ��� �޸�
	for (int i = 0; i < outH; i++)
		for (int k = 0; k < outW; k++) {
			double v = tmpOut[i][k];
			if (v > 255.0)
				v = 255.0;
			else if (v < 0.0)
				v = 0.0;

			outImage[i][k] = v;
		}

	free2D_double(tmpIn, inH + 2);
	free2D_double(tmpOut, outH);
	//*****************************
	printf("\t\t\t\t\t  < ���������� ó�� ������ ȭ�� > ");
}


// 4-A.���� ����
void horizontalEdge() {
	const int MSIZE = 3;
	// ���� ���� ����ũ (�� ��ɿ� ���� ����ũ�� ���糪 ���۸�)
	double Hmask[MSIZE][MSIZE] =
	{ {0,0,0},
	  {-1,1,0},
	  {0,0,0} };

	// �ӽ� ����� �޸� �Ҵ�
	double** tmpIn, ** tmpOut;
	tmpIn = malloc2D_double(inH + 2, inW + 2);
	tmpOut = malloc2D_double(outH, outW);

	// �ӽ� �Է��� 0���� �ʱ�ȭ
	for (int i = 0; i < inH + 2; i++)
		for (int k = 0; k < inW + 2; k++)
			tmpIn[i][k] = 0.0;

	// �Է� ���� --> �ӽ� �Է� ����
	for (int i = 0; i < inH; i++)
		for (int k = 0; k < inW; k++)
			tmpIn[i + 1][k + 1] = inImage[i][k];

	// ȸ�� ���� --> ����ũ�� �ܾ�鼭 ����ϱ�
	double S; // ������ ���� �Է¿���X����ũ�� �հ�
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			S = 0.0;
			for (int m = 0; m < MSIZE; m++)
				for (int n = 0; n < MSIZE; n++)
					S += tmpIn[i + m][k + n] * Hmask[m][n];

			tmpOut[i][k] = S;
		}
	}

	// ��ó�� (����ũ�� �հ迡 ���� ����...)
	for (int i = 0; i < outH; i++)
		for (int k = 0; k < outW; k++)
			tmpOut[i][k] += 127.0;

	// �ӽ� ��� --> ��� �޸�
	for (int i = 0; i < outH; i++)
		for (int k = 0; k < outW; k++) {
			double v = tmpOut[i][k];
			if (v > 255.0)
				v = 255.0;
			else if (v < 0.0)
				v = 0.0;

			outImage[i][k] = v;
		}

	free2D_double(tmpIn, inH + 2);
	free2D_double(tmpOut, outH);
	//*****************************
	printf("\t\t\t\t\t  < ���� ���� ó�� ȭ�� > ");
}
// 4-A.���� ����
void verticalEdge() {
	const int MSIZE = 3;
	// ���� ���� ����ũ (�� ��ɿ� ���� ����ũ�� ���糪 ���۸�)
	double Vmask[MSIZE][MSIZE] =
	{ {0,-1,0},
	  {0,1,0},
	  {0,0,0} };

	// �ӽ� ����� �޸� �Ҵ�
	double** tmpIn, ** tmpOut;
	tmpIn = malloc2D_double(inH + 2, inW + 2);
	tmpOut = malloc2D_double(outH, outW);

	// �ӽ� �Է��� 0���� �ʱ�ȭ
	for (int i = 0; i < inH + 2; i++)
		for (int k = 0; k < inW + 2; k++)
			tmpIn[i][k] = 0.0;

	// �Է� ���� --> �ӽ� �Է� ����
	for (int i = 0; i < inH; i++)
		for (int k = 0; k < inW; k++)
			tmpIn[i + 1][k + 1] = inImage[i][k];

	// ȸ�� ���� --> ����ũ�� �ܾ�鼭 ����ϱ�
	double S; // ������ ���� �Է¿���X����ũ�� �հ�
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			S = 0.0;
			for (int m = 0; m < MSIZE; m++)
				for (int n = 0; n < MSIZE; n++)
					S += tmpIn[i + m][k + n] * Vmask[m][n];

			tmpOut[i][k] = S;
		}
	}

	// ��ó�� (����ũ�� �հ迡 ���� ����...)
	for (int i = 0; i < outH; i++)
		for (int k = 0; k < outW; k++)
			tmpOut[i][k] += 127.0;

	// �ӽ� ��� --> ��� �޸�
	for (int i = 0; i < outH; i++)
		for (int k = 0; k < outW; k++) {
			double v = tmpOut[i][k];
			if (v > 255.0)
				v = 255.0;
			else if (v < 0.0)
				v = 0.0;

			outImage[i][k] = v;
		}

	free2D_double(tmpIn, inH + 2);
	free2D_double(tmpOut, outH);
	//*****************************
	printf("\t\t\t\t\t  < ���� ���� ó�� ȭ�� > ");
}
// 4-A.�������� ����
void horiVertiEdge() {
	const int MSIZE = 3;
	// ���� ���� ����ũ (�� ��ɿ� ���� ����ũ�� ���糪 ���۸�)
	double Hmask[MSIZE][MSIZE] =
	{ {0,0,0},
	  {-1,1,0},
	  {0,0,0} };
	// ���� ���� ����ũ (�� ��ɿ� ���� ����ũ�� ���糪 ���۸�)
	double Vmask[MSIZE][MSIZE] =
	{ {0,-1,0},
	  {0,1,0},
	  {0,0,0} };

	// �ӽ� ����� �޸� �Ҵ�
	double** tmpIn, ** tmpOut1, ** tmpOut2;
	tmpIn = malloc2D_double(inH + 2, inW + 2);
	tmpOut1 = malloc2D_double(outH, outW);
	tmpOut2 = malloc2D_double(outH, outW);

	// �ӽ� �Է��� 0���� �ʱ�ȭ
	for (int i = 0; i < inH + 2; i++)
		for (int k = 0; k < inW + 2; k++)
			tmpIn[i][k] = 0.0;

	// �Է� ���� --> �ӽ� �Է� ����
	for (int i = 0; i < inH; i++)
		for (int k = 0; k < inW; k++)
			tmpIn[i + 1][k + 1] = inImage[i][k];

	// ȸ�� ���� --> ����ũ�� �ܾ�鼭 ����ϱ�
	double S1; // ������ ���� �Է¿���X����ũ�� �հ�
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			S1 = 0.0;
			for (int m = 0; m < MSIZE; m++)
				for (int n = 0; n < MSIZE; n++)
					S1 += tmpIn[i + m][k + n] * Hmask[m][n];

			tmpOut1[i][k] = S1;
		}
	}
	// ȸ�� ���� --> ����ũ�� �ܾ�鼭 ����ϱ�
	double S2; // ������ ���� �Է¿���X����ũ�� �հ�
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			S2 = 0.0;
			for (int m = 0; m < MSIZE; m++)
				for (int n = 0; n < MSIZE; n++)
					S2 += tmpIn[i + m][k + n] * Vmask[m][n];

			tmpOut2[i][k] = S2;
		}
	}

	// ��ó�� (����ũ�� �հ迡 ���� ����...)
	for (int i = 0; i < outH; i++)
		for (int k = 0; k < outW; k++)
			tmpOut1[i][k] += 127.0;

	// �ӽ� ��� --> ��� �޸�
	for (int i = 0; i < outH; i++)
		for (int k = 0; k < outW; k++) {
			double v1 = tmpOut1[i][k];
			double v2 = tmpOut2[i][k];
			double v = v1 + v2;
			if (v > 255.0)
				v = 255.0;
			else if (v < 0.0)
				v = 0.0;

			outImage[i][k] = v;
		}

	free2D_double(tmpIn, inH + 2);
	free2D_double(tmpOut1, outH);
	free2D_double(tmpOut2, outH);
	//*****************************
	printf("\t\t\t\t\t  < ����/���� ���� ó�� ȭ�� > ");
}


// 5-A.�̹��� �¿� �̷���
void L_R_mirroring() {
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			int px = inImage[i][inW - 1 - k];		// (�ִ뿭 - 1) - �ݺ���

			outImage[i][k] = px;
		}
	}
	printf("\t\t\t\t\t  < ���� �¿� �̷��� ȭ�� > ");
}
// 5-A.�̹��� ���� �̷���
void T_B_mirroring() {
	for (int i = 0; i < inH; i++) {
		for (int k = 0; k < inW; k++) {
			int px = inImage[inH - 1 - i][k];		// (�ִ��� - 1) - �ݺ���

			outImage[i][k] = px;
		}
	}
	printf("\t\t\t\t\t  < ���� ���� �̷��� ȭ�� > ");
}
// 5-A.�̹��� ����+�¿� �̷���
void TB_LR_mirroring() {
	for (int i = 0; i < inW; i++) {
		for (int k = 0; k < inH; k++) {
			int mirror_i = inH - 1 - i;
			int mirror_k = inW - 1 - k;

			outImage[i][k] = inImage[mirror_i][mirror_k];
		}
	}
	printf("\t\t\t\t\t  < ���� ����/�¿� �̷��� ȭ�� > ");
}

// 5-B.��� �̹��� �ð�������� 90�� ȸ��
void turn90Right() {
	for (int i = 0; i < inW; i++)
		for (int k = 0; k < inH; k++)
			outImage[i][k] = inImage[inH - k - 1][i];

	printf("\t\t\t\t\t  < �ð���� 90�� ȸ�� ȭ�� > ");
}
// 5-B.��� �̹��� �ð�������� 180�� ȸ��
void turn180Right() {
	for (int i = 0; i < inW; i++)
		for (int k = 0; k < inH; k++)
			outImage[i][k] = inImage[inH - i - 1][inW - k - 1];

	printf("\t\t\t\t\t  < �ð���� 180�� ȸ�� ȭ�� > ");
}
// 5-B.��� �̹��� �ð�������� 270�� ȸ��
void turn270Right() {
	for (int i = 0; i < inW; i++)
		for (int k = 0; k < inH; k++)
			outImage[i][k] = inImage[k][inH - i - 1];

	printf("\t\t\t\t\t  < �ð���� 270�� ȸ�� ȭ�� > ");
}
// 5-B.��� �̹��� �ݽð�������� 90�� ȸ��
void turn90Left() {
	for (int i = 0; i < inH; i++)
		for (int k = 0; k < inW; k++)
			outImage[i][k] = inImage[k][inH - 1 - i];

	printf("\t\t\t\t\t  < �ݽð���� 90�� ȸ�� ȭ�� > ");
}
// 5-B.��� �̹��� �ݽð�������� 180�� ȸ��
void turn180Left() {
	for (int i = 0; i < inH; i++)
		for (int k = 0; k < inW; k++)
			outImage[i][k] = inImage[inH - 1 - i][inW - k - 1];

	printf("\t\t\t\t\t  < �ݽð���� 180�� ȸ�� ȭ�� > ");
}
// 5-B.��� �̹��� �ݽð�������� 270�� ȸ��
void turn270Left() {
	for (int i = 0; i < inH; i++)
		for (int k = 0; k < inW; k++)
			outImage[i][k] = inImage[inH - k - 1][i];

	printf("\t\t\t\t\t  < �ݽð���� 270�� ȸ�� ȭ�� > ");
}
// 5-B.����ȸ��_�ð���� (������)
void turnFree(int val) {
	/* ����
	xd = cos * xs - sin * ys
	yd = sin * xs + cos * ys
	*/

	double radian = val * 3.141592 / 180.0;
	int xd, yd;
	for (int xs = 0; xs < inH; xs++) {
		for (int ys = 0; ys < inW; ys++) {
			xd = cos(radian) * xs - sin(radian) * ys;
			yd = sin(radian) * xs + cos(radian) * ys;

			if ((0 <= xd && xd < outH) && (0 <= yd && yd < outW))
				outImage[xd][yd] = inImage[ys][xs];
		}
	}
	printf("\t\t\t\t\t  < ����ȸ�� %d�� ȸ�� ȭ�� > ", val);
}
// 5-B.����ȸ��_�ð���� (�����+�߾�ȸ��)
void turnFreeCenter(int val) {
	/* ����
	xs = cos * (xd-cx) + sin * (yd-cy)
	ys = -sin * (xd-cs) + cos * (yd-cy)
	xs += cx;
	ys += cy;
	*/

	double radian = val * 3.141592 / 180.0;
	int cx = outH / 2;
	int cy = outW / 2;
	int xs, ys;
	for (int xd = 0; xd < outH; xd++) {
		for (int yd = 0; yd < outW; yd++) {
			xs = cos(radian) * (xd - cx) + sin(radian) * (yd - cy);
			ys = -sin(radian) * (xd - cx) + cos(radian) * (yd - cy);
			xs += cx;
			ys += cy;

			if ((0 <= xs && xs < inH) && (0 <= ys && ys < inW))
				outImage[xd][yd] = inImage[ys][xs];
		}
	}
	printf("\t\t\t\t\t  < ����ȸ��_����� %d�� ȸ�� ȭ�� > ", val);
}

// 5-C.�̹��� ũ�� Ȯ�� (������)
void sizeUp(int val) {
	// output�� ũ�� ����
	outH = inH * val;					// output�� input �� �޶���
	outW = inW * val;
	outImage = malloc2D(outH, outW);

	//*** ��¥ ����ó�� �˰��� ***//
	for (int i = 0; i < inH; i++)
		for (int k = 0; k < inW; k++)
			outImage[i * val][k * val] = inImage[i][k];

	printf("\t\t\t\t\t  < �̹��� %d�� Ȯ�� (������) ȭ�� > ", val);
}
// 5-C.�̹��� ũ�� Ȯ�� (�����)
void backwardMappingSizeUp(int val) {
	// output�� ũ�� ����
	outH = inH * val;					// output�� input �� �޶���
	outW = inW * val;
	outImage = malloc2D(outH, outW);

	//*** ��¥ ����ó�� �˰��� ***//
	for (int i = 0; i < outH; i++)
		for (int k = 0; k < outW; k++)
			outImage[i][k] = inImage[i / val][k / val];

	printf("\t\t\t\t\t  < �̹��� %d�� Ȯ�� (�����) ȭ�� > ", val);
}
// 5-C.�̹��� ũ�� ��� (������)
void sizeDown(int val) {
	// output�� ũ�� ����
	outH = inH / val;					// output�� input �� �޶���
	outW = inW / val;
	outImage = malloc2D(outH, outW);

	//**** ��¥ ����ó�� �˰��� ***//
	for (int i = 0; i < inH; i++)
		for (int k = 0; k < inW; k++)
			outImage[i / val][k / val] = inImage[i][k];

	printf("\t\t\t\t\t  < �̹��� %d�� ��� (������) ȭ�� > ", val);
}
// 5-C.�̹��� ũ�� ��� (�����)
void backwardMappingSizeDown(int val) {
	// output�� ũ�� ����
	outH = inH / val;					// output�� input �� �޶���
	outW = inW / val;
	outImage = malloc2D(outH, outW);

	//**** ��¥ ����ó�� �˰��� ***
	for (int i = 0; i < outH; i++)
		for (int k = 0; k < outW; k++)
			outImage[i][k] = inImage[i * val][k * val];

	printf("\t\t\t\t\t  < �̹��� %d�� ��� (�����) ȭ�� > ", val);
}

// 5-F.���� �̹��� 

//// ********************************************************************************* ////





