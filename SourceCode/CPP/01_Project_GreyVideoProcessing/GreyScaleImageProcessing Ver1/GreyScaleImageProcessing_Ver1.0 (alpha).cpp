// GreyScaleImageProcessing_Ver1.0 (alpha).cpp
// 2022.01.17 ~ 2022.02.06
/*
=======================================================================
  * ������Ʈ�� : GreyScaleImageProcessing (�̴�������Ʈ)
  * ���� : Ver 1.0
  * ���
   - �⺻ ���
		: ���� Open/Save, ����
   - ����ó�� �˰���
		: ȭ���� ó��, ������׷� ó��, ȭ�ҿ��� ó��, �������� ó��, ������ ó��

 * ��ǥ�� : ��⼺
 * �ۼ����� : 2022/01/08
 * ������ : �Ӻ���� ������ ����
 * ����� : ���α׷��� (���糲 ������)
 * ������Ʈ �� : Grey Scale Image Processing (Ver.1.0)
=======================================================================
*/


#include "FunctionDeclaretion.h"
#include "FunctionDifinition.h"

int main()
{
	hwnd = GetForegroundWindow();
	hdc = GetWindowDC(hwnd);

	choiceMenu();

	printf("\n %60s \n", "���α׷� ����! \n");
}

