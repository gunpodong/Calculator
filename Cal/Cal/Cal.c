#include<stdio.h>
#include<stdbool.h>

// 함수에서 사용하기 위한 전역변수 선언 부분
int Input_1 = 0;		// 계산할 숫자1
int Input_2 = 0;		// 계산할 숫자2
char Input_Opr;			// 연산자를 입력받는 변수
bool EndCal = false;	// 계산기 종료여부를 묻는 변수

// 식을 입력받는 함수
void Input_All()
{
	scanf_s("%d%c%d",&Input_1,&Input_Opr,1,&Input_2);
}

// 입력받은 식을 연산자에 따라 계산하는 함수
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
		if (Input_2 == 0)	// 0으로 나눌경우 호출
		{
			printf("0으로 나눌수 없습니다.");
		}
		else
		{
			if (Input_1 % Input_2 > 0)	// 나머지가 있을 경우 나머지도 함께 출력해주는 부문
				printf("%d / %d = %d...%d", Input_1, Input_2, Input_1 / Input_2, Input_1 % Input_2);
			else
				printf("%d / %d = %d", Input_1, Input_2, Input_1 / Input_2);
		}
		break;
	default:
		printf("잘못된 연산자를 입력하셨습니다.");
		break;
	}
}

// 변수의 초기화 및 재시작 여부를 묻는 함수
void Restart()
{
	// 사용한 전역변수 초기화
	Input_1 = 0;
	Input_2 = 0;
	Input_Opr = "";

	char Last[] = "";

	printf("\n계속해서 연산하시려면 엔터를, 종료하려면 다른 버튼을 누르세요\n");

	// Last를 입력 받는 부문
	*Last = _getch();

	// 엔터를 눌렀을때는 계속, 아닐경우 종료
	if (*Last == '\r')
		EndCal = false;
	else
		EndCal = true;
}

// 메인문
int main()
{
	while (1)
	{
		printf("식을 입력하세요 : ");
		Input_All();
		Calculation(Input_Opr);
		Restart();
		
		// 계산기를 끝내는 부문
		if (EndCal == true)
			break;
	}
}