////Quiz4-3 ���� ���ó��
//unsigned char ref = 255 / 2;

//for (int i = 0; i < ROW; i++)
//{
//	for (int j = 0; j < COL; j++)
//	{
//		if (m_img[i][j] <= ref) m_img[i][j] = 0;
//		else m_img[i][j] = 255;

//		printf("%3d ", m_img[i][j]);
//	}
//	printf("\n");
//}
//printf("\n");



////Quiz4-4 ���� �¿� �̷���
//unsigned char temp[ROW][COL] = { 0, };

//for (int i = 0; i < ROW; i++)
//	for (int j = 0; j < COL; j++)
//		temp[i][j] = m_img[i][j];
//
//for (int i = 0; i < ROW; i++)
//{
//	for (int j = 0; j < COL; j++)
//	{
//		int mir_j = COL - 1 - j;
//		m_img[i][j] = temp[i][mir_j];
//		
//		printf("%3d ", m_img[i][j]);
//	}
//	printf("\n");
//}
//printf("\n");


////Quiz4-3 ���� ���� �̷���
//unsigned char temp[ROW][COL] = { 0, };
//
//for (int i = 0; i < ROW; i++)
//	for (int j = 0; j < COL; j++)
//		temp[i][j] = m_img[i][j];

//for (int i = 0; i < ROW; i++)
//{
//	for (int j = 0; j < COL; j++)
//	{
//		int mir_i = ROW - 1 - i;
//		m_img[i][j] = temp[mir_i][j];

//		printf("%3d ", m_img[i][j]);
//	}
//	printf("\n");
//}
//printf("\n");


//Quiz4-6 ���� 90�� ȸ��
unsigned char temp[ROW][COL] = { 0, };

for (int i = 0; i < ROW; i++)
	for (int j = 0; j < COL; j++)
		temp[i][j] = m_img[i][j];

for (int i = 0; i < ROW; i++)
{
	for (int j = 0; j < COL; j++)
	{
		int rev_i, rev_j;
		rev_i = COL - 1 - j;
		rev_j = i;

		m_img[i][j] = temp[rev_i][rev_j];

		printf("%3d ", m_img[i][j]);
	}
	printf("\n");
}
printf("\n");

}