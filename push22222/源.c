#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//#include<graphics.h>
#define _CRT_SECURE_NO_WARNINGS
int  Key  = 0;
int score = 0;
int step  = 100;
int sum   = 0;
int num;
int life = 3;
extern int flag = 0;
int Keyskill;
int skflag = 0;
int gogogo;
int reguflag = 0;
int BACK;
int extendFun;
int exiitt;
int tui;
int flag2 = 1;
int difficultKey;
int difficultKey2;
int difficultKey3;
int waitgo0;
int waitgo1;
int waitgo2;
int waitgo3;
int diffflag = 1;
int waitbegin;
int tui2;
int tui3;
int tui4;
int irtui0;
int irtui1;
int irjin0;
int irjin1;
int irflag;
int irexit;

int map[10][10];
int IRmap[10][10];

//int map[10][10] =   {
//							{0,0,0,1,1,1,1,0,0,0},
//							{0,0,1,0,0,0,1,0,0,0},
//							{0,1,0,0,0,0,1,0,0,0},
//							{1,0,0,0,0,0,1,1,1,1},
//							{1,0,0,0,0,0,0,0,0,1},
//							{1,0,0,0,0,0,0,0,0,1},
//							{1,0,0,0,0,0,0,0,0,1},
//							{1,0,0,0,0,0,0,0,1,0},
//							{1,0,0,0,0,0,0,1,0,0},
//							{1,1,1,1,1,1,1,0,0,0}
//                   };

int mapready[3][10][10] = {
	                       {
	                        {1,1,1,1,1,1,1,1,1,1},
							{1,0,4,0,0,5,0,0,0,1},
							{1,0,4,0,0,0,4,4,0,1},
							{1,0,4,0,0,0,0,0,0,1},
							{1,5,0,0,0,5,1,1,1,1},
							{1,0,0,5,0,1,0,0,3,1},
							{1,5,1,0,4,0,5,0,0,1},
							{1,0,0,5,4,1,0,4,0,1},
							{1,0,0,0,4,5,5,0,0,1},
							{1,1,1,1,1,1,1,1,1,1}
	                       },
						   {
	                        {1,1,1,1,1,1,1,1,1,1},
							{1,0,5,4,0,0,4,5,0,1},
						    {1,0,5,4,0,0,4,5,0,1},
						    {1,0,5,4,0,3,0,0,0,1},
						    {1,0,5,4,0,0,0,0,0,1},
							{1,0,5,4,0,0,0,0,0,1},
							{1,0,5,4,0,0,0,0,0,1},
							{1,0,5,4,0,0,0,0,0,1},
							{1,0,5,4,0,0,0,0,0,1},
							{1,1,1,1,1,1,1,1,1,1}
			               },
	                       {
							{0,0,0,1,1,1,1,0,0,0},
    						{0,0,1,0,0,0,1,0,0,0},
							{0,1,0,0,0,0,1,0,0,0},
							{1,0,0,0,0,0,1,1,1,1},
							{1,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,1},
							{0,1,0,0,0,0,0,0,0,1},
							{0,0,1,0,0,0,0,0,1,0},
							{0,0,0,0,0,0,0,1,0,0},
							{0,0,0,0,1,1,1,0,0,0}
                           }
                         };

//{
//	
//	printf("��ѡ��ؿ�������ؿ����֣�1-3��");
//	printf("\n");
//	scanf("%d", &num);
//	if (num == 1)
//	{
//		int  map[10][10] = { {1,1,1,1,1,1,1,0,0,0},
//							{1,0,0,0,0,0,1,0,0,0},
//							{1,0,0,0,0,0,1,0,0,0},
//							{1,1,1,1,0,0,1,1,1,1},
//							{0,0,0,1,0,0,0,0,0,1},
//							{1,1,1,1,0,0,0,0,0,1},
//							{1,0,0,0,0,0,0,0,0,1},
//							{1,0,0,0,0,0,0,0,1,0},
//							{1,0,0,0,0,0,0,1,0,0},
//							{1,1,1,1,1,1,1,0,0,0}
//		};
//		printf("�ؿ�һ��׼����");
//		print("\n");
//	}
//	else if (num == 2)
//	{
//		int map[10][10] = { {0,0,0,1,1,1,1,0,0,0},
//							{0,0,1,0,0,0,1,0,0,0},
//							{0,1,0,0,0,0,1,0,0,0},
//							{1,0,0,0,0,0,1,1,1,1},
//							{1,0,0,0,0,0,0,0,0,1},
//							{1,0,0,0,0,0,0,0,0,1},
//							{1,0,0,0,0,0,0,0,0,1},
//							{1,0,0,0,0,0,0,0,1,0},
//							{1,0,0,0,0,0,0,1,0,0},
//							{1,1,1,1,1,1,1,0,0,0}
//		};
//		printf("�ؿ�����׼����");
//		print("\n");
//	}
//	else if (num == 3)
//	{
//		int map[10][10] = { {0,0,0,1,1,1,1,0,0,0},
//							{0,0,1,0,0,0,1,0,0,0},
//						    {0,1,0,0,0,0,1,0,0,0},
//							{1,0,0,0,0,0,1,1,1,1},
//							{1,0,0,0,0,0,0,0,0,1},
//							{1,0,0,0,0,0,0,0,0,1},
//							{0,1,0,0,0,0,0,0,0,1},
//							{0,0,1,0,0,0,0,0,1,0},
//							{0,0,0,1,0,0,0,1,0,0},
//							{0,0,0,0,1,1,1,0,0,0}
//		};
//		printf("�ؿ�����׼����");
//		print("\n");
//	}
//
//}

void Initmap()
{
	printf("										�÷� = %d", score);
	printf("\n");
	printf("\n");
	printf("										���� = %d", step);
	printf("\n");
	printf("\n");
	printf("										����ֵʣ�� = %d", life);
	printf("\n");
	printf("\n");

	for (int i = 0; i < 10; i++)
	{
		printf("							");
		for (int j = 0; j < 10; j++)
		{
			switch (map[i][j])
			{
			case 0:
				printf("  ");
				break;
			case 1:
				printf("����");
				break;
			case 3:
				printf("�� ");
				break;
			case 4:
				printf("$ ");
				break;
			case 5:
				printf("��");
				break;
			case 6:
				printf("^ ");
				break;
			}

		}
		printf("\n");
	}
}
void difficultmap1()
{

	for (int i = 0; i < 10; i++)
		{
		 for (int j = 0; j < 10; j++)
		  {
			map[i][j] = mapready[0][i][j];
		  }
		}
	for (int i = 0; i < 10; i++)
	{
		printf("					");
		for (int j = 0; j < 10; j++)
		{
			switch (mapready[0][i][j])
			{
			case 0:
				printf("  ");
				break;
			case 1:
				printf("����");
				break;
			case 3:
				printf("�� ");
				break;
			case 4:
				printf("$ ");
				break;
			case 5:
				printf("��");
				break;
			case 6:
				printf("^ ");
				break;
			}

		}
		printf("\n");
	}
}
void difficultmap2()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			map[i][j] = mapready[1][i][j];
		}
	}
	for (int i = 0; i < 10; i++)
	{
		printf("					");
		for (int j = 0; j < 10; j++)
		{
			switch (mapready[1][i][j])
			{
			case 0:
				printf("  ");
				break;
			case 1:
				printf("����");
				break;
			case 3:
				printf("�� ");
				break;
			case 4:
				printf("$ ");
				break;
			case 5:
				printf("��");
				break;
			case 6:
				printf("^ ");
				break;
			}

		}
		printf("\n");
	}
}
void difficultmap3()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			map[i][j] = mapready[2][i][j];
		}
	}
	for (int i = 0; i < 10; i++)
	{
		printf("					");
		for (int j = 0; j < 10; j++)
		{
			switch (mapready[2][i][j])
			{
			case 0:
				printf("  ");
				break;
			case 1:
				printf("����");
				break;
			case 3:
				printf("�� ");
				break;
			case 4:
				printf("$ ");
				break;
			case 5:
				printf("��");
				break;
			}

		}
		printf("\n");
	}
}
void locate()
{
	int x = 0;
	int y = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (map[i][j] == 3)
			{
				x = i;
				y = j;
				/*printf("%d,%d", x, y);
				printf("\n");*/
			}
		}
	}
}
void Keyevent()
{
	Key = _getch();
	//printf("%d", Key);
}


void  Moveup()
{
	int x = 0;
	int y = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (map[i][j] == 3)
			{
				x = i;
				y = j;
				/*printf("%d,%d", x, y);
				printf("\n");*/
			}
		}
	}
	
	switch (Key)
	{
	case 119://����
		
		if (skflag == 0)
		{
			
			if (map[x - 1][y] == 0)
			{
				map[x - 1][y] += 3;
				map[x][y] -= 3;
			}
			else if (map[x - 1][y] == 1)
			{
				map[x - 1][y] += 0;
				map[x][y] -= 0;
			}
			else if (map[x - 1][y] == 4)
			{
				if (map[x - 2][y] == 0)
				{
					map[x - 2][y] += 4;
					map[x - 1][y] = 3;
					map[x][y] = 0;
				}
				else if (map[x - 2][y] == 5)
				{
					map[x - 2][y] = 0;//�����ӵ���ȷ�ط���������ʧ
					map[x - 1][y] = 3;
					map[x][y] = 0;
					score += 1;//�÷ּ�һ
				}
				else if (map[x - 2][y] == 4)
				{
					life -= 1;
					printf("						���Ʋ���������һ������");
					printf("\n");
					printf("\n");
				}
			}
			else if (map[x - 1][y] == 5)
			{
				life -= 1;
				printf("						������������һ������");
				printf("\n"); 
				printf("\n");
			}
		}
		if (skflag == 1)
		{
			step += 2;
			if (map[x - 1][y] == 0)
			{
				map[x - 1][y] += 6;
				map[x][y] -= 6;
			}
			else if (map[x - 1][y] == 1)
			{
				map[x - 1][y] += 0;
				map[x][y] -= 0;
			}
			else if (map[x - 1][y] == 4)
			{
				printf("					���Ʋ���������һ������");
				printf("\n");
				printf("\n");
			}
			else if (map[x - 1][y] == 5)
			{
				map[x - 1][y] =0;
				map[x][y] = 3;
				score += 1;
			}
			
		}
	}
}

void  Movedown()
{
	int x = 0;
	int y = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (map[i][j] == 3)
			{
				x = i;
				y = j;
				/*printf("%d,%d", x, y);
				printf("\n");*/
			}
		}
	}

	switch (Key)
	{
	case 115://����
		
		if (map[x + 1][y] == 0)
		{
			map[x + 1][y] += 3;
			map[x][y] -= 3;
		}
		else if (map[x + 1][y] == 1)
		{
			map[x + 1][y] += 0;
			map[x][y] -= 0;
		}
		else if (map[x + 1][y] == 4)
		{
			if (map[x + 2][y] == 0)
			{
				map[x + 2][y] += 4;
				map[x + 1][y] = 3;
				map[x][y] = 0;
			}
			else if (map[x + 2][y] == 5)
			{
				map[x + 2][y] = 0;//�����ӵ���ȷ�ط���������ʧ
				map[x + 1][y] = 3;
				map[x][y] = 0;
				score += 1;//�÷ּ�һ
			}
			else if (map[x + 2][y] == 4)
			{
				life -= 1;
				printf("						���Ʋ���������һ������ֵ");
			    printf("\n");
				printf("\n");
			}
		}
		else if (map[x + 1][y] == 5)
		{
			life -= 1;
			printf("						������������һ������");
			printf("\n");
			printf("\n");
		}


	}
}
void Moveleft()
{
	int x = 0;
	int y = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (map[i][j] == 3)
			{
				x = i;
				y = j;
				/*printf("%d,%d", x, y);
				printf("\n");*/
			}
		}
	}

	switch (Key)
	{

	case 97:
		
		if (map[x][y - 1] == 0)
		{
			map[x][y - 1] += 3;
			map[x][y] -= 3;
		}
		else if (map[x][y - 1] == 1)
		{
			map[x][y - 1] += 0;
			map[x][y] -= 0;
		}
		else if (map[x][y - 1] == 4)
		{
			if (map[x][y - 2] == 0)
			{
				map[x][y - 2]  = 4;
				map[x][y - 1]  = 3;
				map[x][y] = 0;
			}
			else if (map[x][y - 2] == 1)
			{
				map[x][y - 2] += 0;
				map[x][y - 1] += 0;
				map[x][y] += 0;
			}
			else if (map[x][y - 2] == 5)
			{
				map[x][y - 2]  = 0;
				map[x][y - 1]  = 3;
				map[x][y] = 0;  //�Ƶ�Ŀ��λ��������ʧ
				score += 1;
			}
			else if (map[x][y - 2] == 4)
			{
				life -= 1;
				printf("						���Ʋ���������һ������ֵ");
				printf("\n");
				printf("\n");
			}
		}
		else if (map[x][y - 1] == 5)
		{
			life -= 1;
			printf("						������������һ������");
			printf("\n");
			printf("\n");
		}
    }
}

void Moveright()
{
	int x = 0;
	int y = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (map[i][j] == 3)
			{
				x = i;
				y = j;
				/*printf("%d,%d", x, y);
				printf("\n");*/
			}
		}
	}


	switch (Key)
	{
	case 100:
		if (map[x][y + 1] == 0)
		{
			map[x][y + 1] += 3;
			map[x][y] -= 3;
		}
		else if (map[x][y + 1] == 1)
		{
			map[x][y + 1] += 0;
			map[x][y] -= 0;
		}
		else if (map[x][y + 1] == 4)
		{
			if (map[x][y + 2] == 0)
			{
				map[x][y + 2] = 4;
				map[x][y + 1] = 3;
				map[x][y] = 0;
			}
			else if (map[x][y + 2] == 1)
			{
				map[x][y - 2] += 0;
				map[x][y - 1] += 0;
				map[x][y] += 0;
			}
			else if (map[x][y + 2] == 5)
			{
				map[x][y + 2] = 0;
				map[x][y + 1] = 3;
				map[x][y] = 0;  //�Ƶ�Ŀ��λ��������ʧ
				score += 1;
			}
			else if (map[x][y + 2] == 4)
			{
				life -= 1;
				printf("						���Ʋ���������һ������");
				printf("\n");
				printf("\n");
			}
			//else if(�����شţ���һ��Ѫ)
		}
		else if (map[x][y + 1] == 5)
		{
			life -= 1;
			printf("						������������һ������");
			printf("\n");
			printf("\n");
		}
	}
}
void ENDFLag()
{

	if (score == 9)
	{
		flag = 0;
		irflag = 0;
		diffflag = 1;
		printf("%d", score);
		printf("						��Ϸ����,��Ӯ��");
		printf("\n");
		printf("						��---Space---������");
		printf("\n");
		waitgo0 = _getch();
		system("cls");
		switch (life)
		{
		case 3:
			printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
			printf("\n");
			printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
			printf("\n");
			printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
			printf("\n");
			printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
			printf("\n");
			printf(".............................................tttttttttttttttttttttt.................................*");
			printf("\n");
			printf("*............................................ttttttttttttttttttttttt.................................*");
			printf("\n");
			printf("*............................................tttttttttttttttttttttt..................................*");
			printf("\n");
			printf("*...........................................tttttttttttttttttttttt...................................*");
			printf("\n");
			printf("*..........................................ttttttttttttttttttttttt...................................*");
			printf("\n");
			printf("*..........................................tttttttttttttttttttttt....................................*");
			printf("\n");
			printf("*..........................................ttttttttttttttttttttt.....................................*");
			printf("\n");
			printf("*....................................................................................................*");
			printf("\n");
			printf("*....................ttttttttttttt.......tttttttttttttttttttttt...tttttttttt.........................*");
			printf("\n");
			printf("*...................tttttttttttt.....ttttttttttttttttttttttttt....tttttttttt.........................*"); 
			printf("\n");
			printf("*...................tttttttt......tttttttttttttttttttttttttttt...tttttttttt..........................*");
			printf("\n");
			printf("*.................ttt......ttttttttttttttttttttttttttttttttt....tttttttttt...........................*");
			printf("\n");
			printf("*................tt....ttttttttttttttttttttttttttttttttttttt...tttttttttt............................*");
			printf("\n");
			printf("*...................ttttttttttttttttttttttttttttttttttttttt....ttttttttt.............................*");
			printf("\n");
			printf("*................................ttttttttttttttttttttttttt...........................................*");
			printf("\n");
			printf("*...............................tttttttttttttttttttttttttt...........................................*");
			printf("\n");
			printf("*..............................tttttttttttttttttttttttttt............................................*");
			printf("\n");
			printf("*..............................ttttttttttttttttttttttttt.............................................*");
			printf("\n");
			printf("*.............................tttttttttttttttttttttttttt.............................................*");
			printf("\n");
			printf("*............................ttttttttttttttttttttttttttt........ttt..................................*");
			printf("\n");
			printf("*............................ttttttttttttttttttttttttttttttttttttt...................................*");
			printf("\n");
			printf("*...........................ttttttttttttttttttttttttttttttttttttt....................................*");
			printf("\n");
			printf("*...........................tttttttttttttttttttttttttttttttttttt.....................................*");
			printf("\n");
			printf("*...........................tttttttttttttttttttttttttttttttttttt.....................................*");
			printf("\n");
			printf("*...........................ttttttttttttttttttttttttttttttttttt......................................*");
			printf("\n");
			printf("*............................ttttttttttttttttttttttttttttttttt.......................................*");
			printf("\n");
			printf("*.............................ttttttttttttttttttttttttttttttt........................................*");
			printf("\n");
			printf("*..............................tttttttttttttttttttttttttttt..........................................*");
			printf("\n");
			printf("*.................................ttttttttttttttttttttt..............................................*");
			printf("\n");
			printf("*........................................tttttt......................................................*");
			printf("\n");
			printf("*....................................................................................................*");
			printf("\n");
			printf("*....................................................................................................*");
			printf("\n");
			printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * " );
			printf("						  ��---space---�˻�������");
			life = 3;
			score = 0;
			step = 200;
			waitgo1 = _getch();
			system("cls");
			break;
		case 2:
			printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
			printf("\n");
			printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
			printf("\n");
			printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
			printf("\n");
			printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
			printf("\n");
			printf(".............................................tttttttttttttttttttttt.................................*");
			printf("\n");
			printf("*............................................ttttttttttttttttttttttt.................................*");
			printf("\n");
			printf("*............................................tttttttttttttttttttttt..................................*");
			printf("\n");
			printf("*...........................................tttttttttttttttttttttt...................................*");
			printf("\n");
			printf("*..........................................ttttttttttttttttttttttt...................................*");
			printf("\n");
			printf("*..........................................tttttttttttttttttttttt....................................*");
			printf("\n");
			printf("*..........................................ttttttttttttttttttttt.....................................*");
			printf("\n");
			printf("*....................................................................................................*");
			printf("\n");
			printf("*....................ttttttttttttt.......tttttttttttttttttttttt...tttttttttt.........................*");
			printf("\n");
			printf("*...................tttttttttttt.....ttttttttttttttttttttttttt....tttttttttt.........................*");
			printf("\n");
			printf("*...................tttttttt......tttttttttttttttttttttttttttt...tttttttttt..........................*");
			printf("\n");
			printf("*.................ttt......ttttttttttttttttttttttttttttttttt....tttttttttt...........................*");
			printf("\n");
			printf("*................tt....ttttttttttttttttttttttttttttttttttttt...tttttttttt............................*");
			printf("\n");
			printf("*...................ttttttttttttttttttttttttttttttttttttttt....ttttttttt.............................*");
			printf("\n");
			printf("*................................ttttttttttttttttttttttttt...........................................*");
			printf("\n");
			printf("*...............................tttttttttttttttttttttttttt...........................................*");
			printf("\n");
			printf("*..............................tttttttttttttttttttttttttt............................................*");
			printf("\n");
			printf("*..............................ttttttttttttttttttttttttt.............................................*");
			printf("\n");
			printf("*.............................tttttttttttttttttttttttttt.............................................*");
			printf("\n");
			printf("*............................ttttttttttttttttttttttttttt........ttt..................................*");
			printf("\n");
			printf("*............................ttttttttttttttttttttttttttttttttttttt...................................*");
			printf("\n");
			printf("*...........................ttttttttttttttttttttttttttttttttttttt....................................*");
			printf("\n");
			printf("*...........................tttttttttttttttttttttttttttttttttttt.....................................*");
			printf("\n");
			printf("*...........................tttttttttttttttttttttttttttttttttttt.....................................*");
			printf("\n");
			printf("*...........................ttttttttttttttttttttttttttttttttttt......................................*");
			printf("\n");
			printf("*............................ttttttttttttttttttttttttttttttttt.......................................*");
			printf("\n");
			printf("*.............................ttttttttttttttttttttttttttttttt........................................*");
			printf("\n");
			printf("*..............................tttttttttttttttttttttttttttt..........................................*");
			printf("\n");
			printf("*.................................ttttttttttttttttttttt..............................................*");
			printf("\n");
			printf("*........................................tttttt......................................................*");
			printf("\n");
			printf("*....................................................................................................*");
			printf("\n");
			printf("*....................................................................................................*");
			printf("\n");
			printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
			printf("						  ��---space---�˻�������");
			life = 3;
			score = 0;
			flag = 0;
			irflag = 0;
			diffflag = 1;
			step = 200;
			waitgo2 = _getch();
			system("cls");
			break;
		case 1:
			printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
			printf("\n");
			printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
			printf("\n");
			printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
			printf("\n");
			printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
			printf("\n");
			printf(".............................................tttttttttttttttttttttt.................................*");
			printf("\n");
			printf("*............................................ttttttttttttttttttttttt.................................*");
			printf("\n");
			printf("*............................................tttttttttttttttttttttt..................................*");
			printf("\n");
			printf("*...........................................tttttttttttttttttttttt...................................*");
			printf("\n");
			printf("*..........................................ttttttttttttttttttttttt...................................*");
			printf("\n");
			printf("*..........................................tttttttttttttttttttttt....................................*");
			printf("\n");
			printf("*..........................................ttttttttttttttttttttt.....................................*");
			printf("\n");
			printf("*....................................................................................................*");
			printf("\n");
			printf("*....................ttttttttttttt.......tttttttttttttttttttttt...tttttttttt.........................*");
			printf("\n");
			printf("*...................tttttttttttt.....ttttttttttttttttttttttttt....tttttttttt.........................*");
			printf("\n");
			printf("*...................tttttttt......tttttttttttttttttttttttttttt...tttttttttt..........................*");
			printf("\n");
			printf("*.................ttt......ttttttttttttttttttttttttttttttttt....tttttttttt...........................*");
			printf("\n");
			printf("*................tt....ttttttttttttttttttttttttttttttttttttt...tttttttttt............................*");
			printf("\n");
			printf("*...................ttttttttttttttttttttttttttttttttttttttt....ttttttttt.............................*");
			printf("\n");
			printf("*................................ttttttttttttttttttttttttt...........................................*");
			printf("\n");
			printf("*...............................tttttttttttttttttttttttttt...........................................*");
			printf("\n");
			printf("*..............................tttttttttttttttttttttttttt............................................*");
			printf("\n");
			printf("*..............................ttttttttttttttttttttttttt.............................................*");
			printf("\n");
			printf("*.............................tttttttttttttttttttttttttt.............................................*");
			printf("\n");
			printf("*............................ttttttttttttttttttttttttttt........ttt..................................*");
			printf("\n");
			printf("*............................ttttttttttttttttttttttttttttttttttttt...................................*");
			printf("\n");
			printf("*...........................ttttttttttttttttttttttttttttttttttttt....................................*");
			printf("\n");
			printf("*...........................tttttttttttttttttttttttttttttttttttt.....................................*");
			printf("\n");
			printf("*...........................tttttttttttttttttttttttttttttttttttt.....................................*");
			printf("\n");
			printf("*...........................ttttttttttttttttttttttttttttttttttt......................................*");
			printf("\n");
			printf("*............................ttttttttttttttttttttttttttttttttt.......................................*");
			printf("\n");
			printf("*.............................ttttttttttttttttttttttttttttttt........................................*");
			printf("\n");
			printf("*..............................tttttttttttttttttttttttttttt..........................................*");
			printf("\n");
			printf("*.................................ttttttttttttttttttttt..............................................*");
			printf("\n");
			printf("*........................................tttttt......................................................*");
			printf("\n");
			printf("*....................................................................................................*");
			printf("\n");
			printf("*....................................................................................................*");
			printf("\n");
			printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
			printf("						  ��---space---�˻�������");
			life = 3;
			score = 0;
			flag = 0;
			irflag = 0;
			diffflag = 1;
			step = 200;
			waitgo3 = _getch();
			system("cls");
			break;
		}
	}
	if (life==0)
	{
		life = 3;
		irflag = 0;
		flag = 0;
		diffflag = 1;
		score = 0;
		printf("								������ֵ�ľ�����Ϸ����");
		printf("\n");
		printf("\n");
	}
	if (step == 0)
	{
		printf("						       �����ľ���������Ϸ�޽���");
		printf("\n");
	}
	

}
void WARM()
{
	if (life == 2)
	{
		int x = 0;
		int y = 0;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (map[i][j] == 3)
				{
					x = i;
					y = j;
					/*printf("%d,%d", x, y);
					printf("\n");*/
				}
			}
		}
		printf("						ʣ������Ϊ2��ע��Ѫ������");
		printf("\n");
		printf("\n");
		
	}
	if (life == 1)
	{
		int x = 0;
		int y = 0;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (map[i][j] == 3)
				{
					x = i;
					y = j;
					/*printf("%d,%d", x, y);
					printf("\n");*/
				}
			}
		}
		//flag == 0;
		printf("						ʣ������Ϊ1��ע��Ѫ������");
		printf("\n");
		printf("\n");
		//flag == 1;
	}

}
void cliam2()
{
	printf("                          ____________________________________");
	printf("\n");
	printf("                         |     ����Ӧ���������л���ͼԤ��      |");
	printf("\n");
	printf("                         |                                   |");
	printf("\n");
	printf("                         |       1         2      3          |");
	printf("\n");
	printf("                         |                                   |");
	printf("\n"); 
	printf("                         |           ��ѡ���ͼ             |");
	printf("\n");
	printf("                         |                                   |");
	printf("\n");
	printf("                         |                                   |");
	printf("\n");
	printf("                         | __________________________________|");
	printf("\n");
	printf("\n");                   
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
}
void difficult()
{
	printf("						��ѡ���Ѷȹؿ�........");
	printf("\n");
	printf("\n");
	printf("						��---Space---����ʼѡ��........");
	printf("\n");
	printf("\n");
	difficultKey = _getch();
	system("cls");
	printf("						������Ӧ�������Բ鿴��ͼԤ��");
	printf("\n");
	printf("\n");
	printf("						��---Enter---ȷ��ѡ��");
	printf("\n");
	printf("\n");
	difficultmap1();
	while (diffflag)
	{
		difficultKey3= _getch();
		switch (difficultKey3)
		{
		case 49:
			system("cls");
			cliam2();
			difficultmap1();
			printf("\n");
			printf("						��ͼһ");
			break;
		case 50:
			system("cls");
			cliam2();
			difficultmap2();
			printf("\n");
			printf("						��ͼ��");
			break;
		case 51:
			system("cls");
			cliam2();
			difficultmap3();
			printf("\n");
			printf("						��ͼ��");
			break;
		case 13:
			flag = 1;
			diffflag = 0;
			printf("						��---Space---����ʼ��Ϸ");
			printf("\n");
			waitbegin = _getch();
			system("cls");
			break;
		}
	}
}

void IRRUPT()
{
	int x = 0;
	int y = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (map[i][j] == 3)
			{
				x = i;
				y = j;
			}
		}
	}
	switch (Key)
	{
	case 27:

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				IRmap[i][j] = map[i][j];
			}
		}
		printf("                          ȷ��Ҫ�˳���Ϸ��");
		printf("\n");
		printf("                           1.��       2.�� ");
		irtui0 = _getch();
		switch (irtui0)
		{
		case 49:
			irflag = 1;
			system("cls");
			flag = 0;
			break;
		case 50:
			system("cls");
			break;
		}

	}
}
void MOVE()
{
	step--;
	Moveup();
	Movedown();
	Moveleft();
	Moveright();
	IRRUPT();
}

void regulation()
{
	
	printf("						��ӭ������������Ϸ");
	printf("\n");
	printf("\n");
	printf("						�����ӹ���˵��: ");
	printf("\n");
	printf("\n");
	printf("						1.������������Ϸ ");
	printf("\n");
	printf("\n");
	printf("						2.��ʼѪ����������Ϊ�� ");
	printf("\n");
	printf("\n");
	printf("						3.����Ϸ�У������������ͬʱ���������Ӷ������һ��Ѫ�� ");
	printf("\n");
	printf("\n");
	printf("						4.�������ƽ����ڣ��÷ּ�һ ");
	printf("\n");
	printf("\n");
	printf("						5.�����ӱ��ƽ�����ʱ���Ӷ�������˿������˾���	");
	printf("\n");
	printf("\n");
	printf("						6.�����Ʋ������������������Ϸ���� ");
	printf("\n");
	printf("\n");
	printf("						7.���Ʋ����þ���ÿ�ƶ�һ��������һ��ʣ������");
	printf("\n");
	printf("\n");
	printf("						8.��Ϸ������ʣ������������÷ֽ�ת��Ϊ�������������ȼ� ");
	printf("\n");
	printf("\n");
	printf("						9.��ͬ�Ǽ���Ӧ��ͬ����");
	printf("\n");
	printf("\n");
	printf("						10.Ѫ���ľ���Ϸ�����������Ϸ����");
	printf("\n");
	printf("\n");
	printf("						��---Space---�ص���ҳ��");
	printf("\n");
	BACK = _getch();
	system("cls");

}
void summary()
{
	printf("						�����¼�˸��µ���Ϣ");
	printf("\n");
	printf("\n");
	printf("						��---Space---������");
	tui2 = _getch();
	system("cls");
}
void cliam()
{
	printf("						��������Ϸ");
	printf("\n");
	printf("\n");
	printf("						1.<��ʼ�µ���Ϸ>");
	printf("\n");
	printf("\n");
	printf("						2.<����鿴>");
	printf("\n");
	printf("\n");
	printf("						3.<�ص��ϸ��浵>");
	printf("\n");
	printf("\n");
	printf("						4.<�˳���Ϸ>");
	printf("\n");
	printf("\n");
	printf("						5.<������־>");
	printf("\n");
	printf("\n");
	printf("						�����Ӧ���ּ�����.........");
	printf("\n");	
	printf("\n");
}
void beginkeyevent()
{
	gogogo = _getch();
	
}
void extendfun()
{
	switch (irflag)
	{
	case 0:
		printf("						��Ǹ����û�б��ش浵");
		printf("\n");
		printf("						��---space---����");
		irexit = _getch();
		system("cls");
		break;
	case 1:
		printf("						��---Enter---����ʼ�ص�");
		irjin1 = _getch();
		printf("                ��������");
		system("cls");
		Sleep(500);
		printf("                ����������������");
		system("cls");
		Sleep(500);
		printf("                ����������������������������");
		system("cls");
		Sleep(500);
		printf("                ����������������������������������������������������������������������������");
		system("cls");
		Sleep(500);
		printf("                ��������������������������������������������������������������������������������������������");
		system("cls");
		Sleep(500);
		printf("                ��������������������������������������������������������������������������������������������������������������������������");
		system("cls");
		Sleep(500);
		printf("                ������������������������������������������������������������������������������������������������������������������������������������������������������������");
		system("cls");
		Sleep(500);
		printf("                ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������");
		printf("\n");
		printf("                ������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������");
		system("cls");
		Sleep(500);
		printf("                ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������");
		system("cls");
		Sleep(500);
		printf("                ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������");
		system("cls");
		printf("\n");
		printf("\n");
		printf("						�ص��ɹ�");
		printf("\n");
		printf("						��Enter��������Ϸ");
		printf("\n");
		printf("\n");
		printf("						��Esc�˳�");
		printf("\n");
		printf("		��������������������������������������������                      ������������������������������������������������");
		printf("\n");
		printf("		|                     |                     |                       |");
		printf("\n");
		printf("		|                     |                     |                       |");
		printf("\n");
		printf("		|                     |                     |                       |");
		printf("\n");
		printf("		|      Enter          |                     |          Esc          |");
		printf("\n");
		printf("		|                     |                     |                       |");
		printf("\n");
		printf("		|                     |                     |                       |");
		printf("\n");
		printf("		��������������������������������������������                      ��������������������������������������������������");
		printf("\n");
		irjin0 = _getch();
		system("cls");
		switch (irjin0)
		{
		case 13:
			flag = 1;
			system("cls");
			break;
		case 27:
			break;
			system("cls");
		}
		break;
	}
	
	/*printf("					���ܿ�����.......");
	printf("\n");
	printf("\n");
	printf("					�����������");
	extendFun = _getch();
	system("cls");*/
}
void exxiit()
{

	printf("					________________________________");
	printf("\n");
	printf("				   |                                |");
	printf("\n");
	printf("				   |         ���Ҫ�˳���Ϸ��        |");
	printf("\n");
	printf("				   |                                | ");
	printf("\n");
	printf("				   |    1.��              2.��      |");
	printf("\n");
	printf("				   |                                |");
	printf("\n");
	printf("				   |����������������������������������������������������������������|");
	printf("\n");
	printf("\n");
	exiitt = _getch();
	system("cls");
	switch (exiitt)
	{
	case 49:
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("						�ټ����ڴ��´�����");
		printf("\n");
		printf("\n");
		printf("						��������˳���Ϸ");
		tui = _getch();
		flag2 = 0;
		break;
	case 50:
		break;
	}


}
void fun()
{
	switch (gogogo)
	{
	case 49:
		difficult();
		break;
	case 50:
		regulation();
		break;
	case 51:
		extendfun();
		break;
	case 52:
		exxiit();
		break;
	case 53:
		summary();
		break;
	}
		
}

int main()
{
	while (flag2)
	{
		cliam();
		beginkeyevent();
		system("cls");
		fun();
		while (flag)
		{
			WARM();
			Initmap();
			Keyevent();
			system("cls");
			MOVE();
			ENDFLag();
		}
	}
	return 0;
}