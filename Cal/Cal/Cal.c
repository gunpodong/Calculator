#include<stdio.h>
#include<stdbool.h>

// �Լ����� ����ϱ� ���� �������� ���� �κ�
int Input_1 = 0;		// ����� ����1
int Input_2 = 0;		// ����� ����2
char Input_Opr;			// �����ڸ� �Է¹޴� ����
bool EndCal = false;	// ���� ���Ῡ�θ� ���� ����

// ���� �Է¹޴� �Լ�
void Input_All()
{
	scanf_s("%d%c%d",&Input_1,&Input_Opr,1,&Input_2);
}

// �Է¹��� ���� �����ڿ� ���� ����ϴ� �Լ�
void Calculation(char Operator)
{
	switch (Operator)
	{
	case '+':
		printf("%d + %d = %d", Input_1, Input_2, Input_1 + Input_2);
		break;
	case '-':
		printf("%d - %d = %d", Input_1, Input_2, Input_1 - Input_2);
		break;
	case '*':
		printf("%d * %d = %d", Input_1, Input_2, Input_1 * Input_2);
		break;
	case '/':
		if (Input_2 == 0)	// 0���� ������� ȣ��
		{
			printf("0���� ������ �����ϴ�.");
		}
		else
		{
			if (Input_1 % Input_2 > 0)	// �������� ���� ��� �������� �Բ� ������ִ� �ι�
				printf("%d / %d = %d...%d", Input_1, Input_2, Input_1 / Input_2, Input_1 % Input_2);
			else
				printf("%d / %d = %d", Input_1, Input_2, Input_1 / Input_2);
		}
		break;
	default:
		printf("�߸��� �����ڸ� �Է��ϼ̽��ϴ�.");
		break;
	}
}

// ������ �ʱ�ȭ �� ����� ���θ� ���� �Լ�
void Restart()
{
	// ����� �������� �ʱ�ȭ
	Input_1 = 0;
	Input_2 = 0;
	Input_Opr = "";

	char Last[] = "";

	printf("\n����ؼ� �����Ͻ÷��� ���͸�, �����Ϸ��� �ٸ� ��ư�� ��������\n");

	// Last�� �Է� �޴� �ι�
	*Last = _getch();

	// ���͸� ���������� ���, �ƴҰ�� ����
	if (*Last == '\r')
		EndCal = false;
	else
		EndCal = true;
}

// ���ι�
int main()
{
	while (1)
	{
		printf("���� �Է��ϼ��� : ");
		Input_All();
		Calculation(Input_Opr);
		Restart();
		
		// ���⸦ ������ �ι�
		if (EndCal == true)
			break;
	}
}