#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int checkCondition(const char* str, int length);
void encode(const char* str, int length, const char* encodingTable, char* newStr);
void decode(const char* str, int length, const char* encodingTable, char* newStr);
int main(void)
{
	char str[30] = { 0, };
	int length, a;
	char* encodingTable = "wyhfxumtjvsgenbrdzlqapcoki";
	char newStr[30] = { 0, };
	printf("====================================================\n");
	printf("\n");
	printf("�н����带 �Է��ϼ��� (���ڿ� ���ĺ��� ȥ���Ͽ� 8-12��): ");
	scanf("%s", str);
	length = strlen(str);
	while (1)
	{
		if (checkCondition(str, length) == 0 )
		{
			printf("���ڿ� ���ĺ��� ȥ���� �ּ���: ");
			scanf("%s", str);
			length = strlen(str);
		}
		if (checkCondition(str, length) == 2)
		{
			printf("���� ���� ���� ���� �ٽ� �Է��ϼ���: ");
			scanf("%s", str);
			length = strlen(str);
		}
		if (checkCondition(str, length) == 1)
		{
			encode(str, length, encodingTable, newStr);
			printf("�Է��Ͻ� �н����尡 %s�� ��ȣȭ �Ǿ����ϴ�.\n", newStr);
			decode(str, length, encodingTable, newStr);
			printf("�̸� �ٽ� ��ȣȭ�� ���, �н������ %s�Դϴ�.\n", newStr);
			printf("\n");
			printf("====================================================\n");
			return 0;
		}
	}
}
int checkCondition(const char* str, int length)
{
	int i;
	// ���ڳ� ���ڰ� ������ ���� 1�� �ٲ��
	int checkalpabat = 0;
	int checknumber = 0;
	// 1 ���� Ȯ��
	if (length < 8 || length>12)
	{
		return 2;
	}
	// 2 ȥ�� Ȯ��
	for (i = 0;i < length;i++)
	{
		// ���� Ȯ��
		if (48 <= str[i] && str[i] <= 57)
			checknumber = 1;
		// �ҹ��� Ȯ��
		if (97 <= str[i] && str[i] <= 122)
			checkalpabat = 1;
		// �빮�� Ȯ��
		if (65 <= str[i] && str[i] <= 90)
			checkalpabat = 1;
	}
	// ��� ����
	if (checkalpabat + checknumber == 2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void encode(const char* str, int length, const char* encodingTable, char* newStr)
{
	int i;
	for (i = 0;i < length;i++)
	{
		// ���� ���ڵ�
		if (48 <= str[i] && str[i] <= 57)
			if (48 <= str[i] && str[i] <= 57)
				newStr[i] = str[i] + 2;
			else
				newStr[i] = str[i] - 8;
		// �ҹ��� ���ڵ�
		else if (97 <= str[i] && str[i] <= 122)
			newStr[i] = encodingTable[str[i] - 97];
		// �빮��,Ư������ �״�� ���α�
		else
			newStr[i] = str[i];
	}
}
void decode(const char* str, int length, const char* encodingTable, char* newStr)
{
	int i, j;
	for (i = 0;i < length;i++)
	{
		//���� ���ڵ�
		if (48 <= newStr[i] && newStr[i] <= 57)
			if (50 <= newStr[i] && newStr[i] <= 57)
				newStr[i] = newStr[i] - 2;
			else
				newStr[i] = newStr[i] + 8;
		// �ҹ��� ���ڵ�
		else if (97 <= newStr[i] && newStr[i] <= 122)
			for (j = 0;j < 26;j++)
			{
				// �����Կ��� ����� ���� �̻���
				if (newStr[i] == encodingTable[j])
				{
					newStr[i] = j + 97;
					break;
				}

			}
		// �빮��,Ư������ �״�� ���α�
		else
			newStr[i] = newStr[i];
	}
}
