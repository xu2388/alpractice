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
//	printf("请选择关卡：输入关卡数字（1-3）");
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
//		printf("关卡一请准备：");
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
//		printf("关卡二请准备：");
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
//		printf("关卡三请准备：");
//		print("\n");
//	}
//
//}

void Initmap()
{
	printf("										得分 = %d", score);
	printf("\n");
	printf("\n");
	printf("										步数 = %d", step);
	printf("\n");
	printf("\n");
	printf("										生命值剩余 = %d", life);
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
				printf("▓▓");
				break;
			case 3:
				printf("♀ ");
				break;
			case 4:
				printf("$ ");
				break;
			case 5:
				printf("？");
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
				printf("▓▓");
				break;
			case 3:
				printf("♀ ");
				break;
			case 4:
				printf("$ ");
				break;
			case 5:
				printf("？");
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
				printf("▓▓");
				break;
			case 3:
				printf("♀ ");
				break;
			case 4:
				printf("$ ");
				break;
			case 5:
				printf("？");
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
				printf("▓▓");
				break;
			case 3:
				printf("♀ ");
				break;
			case 4:
				printf("$ ");
				break;
			case 5:
				printf("？");
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
	case 119://向上
		
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
					map[x - 2][y] = 0;//推箱子到正确地方，箱子消失
					map[x - 1][y] = 3;
					map[x][y] = 0;
					score += 1;//得分加一
				}
				else if (map[x - 2][y] == 4)
				{
					life -= 1;
					printf("						你推不动，减少一滴生命");
					printf("\n");
					printf("\n");
				}
			}
			else if (map[x - 1][y] == 5)
			{
				life -= 1;
				printf("						你掉进坑里，减少一点生命");
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
				printf("					你推不动，减少一点生命");
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
	case 115://向下
		
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
				map[x + 2][y] = 0;//推箱子到正确地方，箱子消失
				map[x + 1][y] = 3;
				map[x][y] = 0;
				score += 1;//得分加一
			}
			else if (map[x + 2][y] == 4)
			{
				life -= 1;
				printf("						你推不动，减少一点生命值");
			    printf("\n");
				printf("\n");
			}
		}
		else if (map[x + 1][y] == 5)
		{
			life -= 1;
			printf("						你掉进坑里，减少一点生命");
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
				map[x][y] = 0;  //推到目标位，箱子消失
				score += 1;
			}
			else if (map[x][y - 2] == 4)
			{
				life -= 1;
				printf("						你推不动，减少一点生命值");
				printf("\n");
				printf("\n");
			}
		}
		else if (map[x][y - 1] == 5)
		{
			life -= 1;
			printf("						你掉进坑里，减少一点生命");
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
				map[x][y] = 0;  //推到目标位，箱子消失
				score += 1;
			}
			else if (map[x][y + 2] == 4)
			{
				life -= 1;
				printf("						你推不动，减少一点生命");
				printf("\n");
				printf("\n");
			}
			//else if(遇到地磁，少一滴血)
		}
		else if (map[x][y + 1] == 5)
		{
			life -= 1;
			printf("						你掉进坑里，减少一点生命");
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
		printf("						游戏结束,你赢了");
		printf("\n");
		printf("						按---Space---键继续");
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
			printf("						  按---space---退回主界面");
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
			printf("						  按---space---退回主界面");
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
			printf("						  按---space---退回主界面");
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
		printf("								你生命值耗尽，游戏结束");
		printf("\n");
		printf("\n");
	}
	if (step == 0)
	{
		printf("						       步数耗尽，本次游戏无奖励");
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
		printf("						剩余生命为2，注意血量健康");
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
		printf("						剩余生命为1，注意血量健康");
		printf("\n");
		printf("\n");
		//flag == 1;
	}

}
void cliam2()
{
	printf("                          ____________________________________");
	printf("\n");
	printf("                         |     按相应按键可以切换地图预览      |");
	printf("\n");
	printf("                         |                                   |");
	printf("\n");
	printf("                         |       1         2      3          |");
	printf("\n");
	printf("                         |                                   |");
	printf("\n"); 
	printf("                         |           请选择地图             |");
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
	printf("						请选择难度关卡........");
	printf("\n");
	printf("\n");
	printf("						按---Space---键开始选择........");
	printf("\n");
	printf("\n");
	difficultKey = _getch();
	system("cls");
	printf("						按下相应按键可以查看地图预览");
	printf("\n");
	printf("\n");
	printf("						按---Enter---确认选择");
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
			printf("						地图一");
			break;
		case 50:
			system("cls");
			cliam2();
			difficultmap2();
			printf("\n");
			printf("						地图二");
			break;
		case 51:
			system("cls");
			cliam2();
			difficultmap3();
			printf("\n");
			printf("						地图三");
			break;
		case 13:
			flag = 1;
			diffflag = 0;
			printf("						按---Space---键开始游戏");
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
		printf("                          确定要退出游戏吗");
		printf("\n");
		printf("                           1.是       2.否 ");
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
	
	printf("						欢迎来到推箱子游戏");
	printf("\n");
	printf("\n");
	printf("						推箱子规则说明: ");
	printf("\n");
	printf("\n");
	printf("						1.这是推箱子游戏 ");
	printf("\n");
	printf("\n");
	printf("						2.初始血量（生命）为三 ");
	printf("\n");
	printf("\n");
	printf("						3.在游戏中，掉进坑里或者同时推两个箱子都会减少一滴血量 ");
	printf("\n");
	printf("\n");
	printf("						4.将箱子推进坑内，得分加一 ");
	printf("\n");
	printf("\n");
	printf("						5.当箱子被推进坑内时，坑洞被填补，人可以无伤经过	");
	printf("\n");
	printf("\n");
	printf("						6.在限制步数内完成所有任务，游戏结束 ");
	printf("\n");
	printf("\n");
	printf("						7.限制步数用尽后，每移动一步，减少一点剩余生命");
	printf("\n");
	printf("\n");
	printf("						8.游戏结束后，剩余生命与所获得分将转化为星星用于评定等级 ");
	printf("\n");
	printf("\n");
	printf("						9.不同星级对应不同奖励");
	printf("\n");
	printf("\n");
	printf("						10.血量耗尽游戏或完成任务，游戏结束");
	printf("\n");
	printf("\n");
	printf("						按---Space---回到主页面");
	printf("\n");
	BACK = _getch();
	system("cls");

}
void summary()
{
	printf("						这里记录了更新的信息");
	printf("\n");
	printf("\n");
	printf("						按---Space---键返回");
	tui2 = _getch();
	system("cls");
}
void cliam()
{
	printf("						推箱子游戏");
	printf("\n");
	printf("\n");
	printf("						1.<开始新的游戏>");
	printf("\n");
	printf("\n");
	printf("						2.<规则查看>");
	printf("\n");
	printf("\n");
	printf("						3.<回到上个存档>");
	printf("\n");
	printf("\n");
	printf("						4.<退出游戏>");
	printf("\n");
	printf("\n");
	printf("						5.<更新日志>");
	printf("\n");
	printf("\n");
	printf("						点击相应数字键继续.........");
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
		printf("						抱歉，您没有本地存档");
		printf("\n");
		printf("						按---space---返回");
		irexit = _getch();
		system("cls");
		break;
	case 1:
		printf("						按---Enter---键开始回档");
		irjin1 = _getch();
		printf("                ▓▓▓▓");
		system("cls");
		Sleep(500);
		printf("                ▓▓▓▓▓▓▓▓");
		system("cls");
		Sleep(500);
		printf("                ▓▓▓▓▓▓▓▓▓▓▓▓▓▓");
		system("cls");
		Sleep(500);
		printf("                ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓");
		system("cls");
		Sleep(500);
		printf("                ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓");
		system("cls");
		Sleep(500);
		printf("                ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓");
		system("cls");
		Sleep(500);
		printf("                ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓");
		system("cls");
		Sleep(500);
		printf("                ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓");
		printf("\n");
		printf("                ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓");
		system("cls");
		Sleep(500);
		printf("                ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓");
		system("cls");
		Sleep(500);
		printf("                ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓");
		system("cls");
		printf("\n");
		printf("\n");
		printf("						回档成功");
		printf("\n");
		printf("						按Enter键进入游戏");
		printf("\n");
		printf("\n");
		printf("						按Esc退出");
		printf("\n");
		printf("		——————————————————————                      ————————————————————————");
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
		printf("		——————————————————————                      —————————————————————————");
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
	
	/*printf("					功能开发中.......");
	printf("\n");
	printf("\n");
	printf("					按任意键返回");
	extendFun = _getch();
	system("cls");*/
}
void exxiit()
{

	printf("					________________________________");
	printf("\n");
	printf("				   |                                |");
	printf("\n");
	printf("				   |         真的要退出游戏吗        |");
	printf("\n");
	printf("				   |                                | ");
	printf("\n");
	printf("				   |    1.是              2.否      |");
	printf("\n");
	printf("				   |                                |");
	printf("\n");
	printf("				   |————————————————————————————————|");
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
		printf("						再见，期待下次相遇");
		printf("\n");
		printf("\n");
		printf("						按任意键退出游戏");
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