// operator.cpp

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int intNum1, intNum2;		// ���� == �׸�
	float result;

	printf("����1 �Է� : ");
	scanf("%d", &intNum1);
	printf("����2 �Է� : ");
	scanf("%d", &intNum2);

	result = intNum1 + intNum2;
	printf("%d + %d = %.1f \n", intNum1, intNum2, result);

	result = intNum1 - intNum2;
	printf("%d - %d = %.1f \n", intNum1, intNum2, result);

	result = intNum1 * intNum2;
	printf("%d * %d = %.1f \n", intNum1, intNum2, result);

	if (intNum2 != 0) {
		result = (float)intNum1 / intNum2;								// ������ ������ ���� --> ����
		printf("%d / %d = %.1f \n", intNum1, intNum2, result);			// ������ �Ǽ��� ���� --> �Ǽ�
	}
	else
		printf("0���� ������ �ȵ˴ϴ�. \n");

	if (intNum2 != 0) {
		result = intNum1 % intNum2;
		printf("%d %% %d = %.1f \n", intNum1, intNum2, result);
	}
	else
		printf("0���� ������ ���� �ȵ˴ϴ�. \n");
}

