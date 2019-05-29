#define _CRT_SECURE_NO_WARNINGS 1
#include"mine.h"
int GetRandIndex(int start, int end)
{
	return rand() % (end - start + 1) + start;
}
void SetMine(char mine[][COL], int row, int col)
{
	srand((unsigned long)time(NULL));
	int count = 0;
	while (count<MINE_NUM)
	{
		int x = GetRandIndex(1,10);//生成随机数x:1-10
		int y = GetRandIndex(1,10);//生成随机数y:1-10
		if (mine[x][y] == '0' )
		{
			mine[x][y] = '1';
			count++;
		}
	}
}
void ShowBoard(char board[][COL], int row, int col)
{
	printf("   ");//第一行数字前面的空格数
	int i = 1;
	for (; i <= 10; i++)
	{
		printf("%3d ", i);//打印行1-10
	}
	printf("\n--------");
	for (i = 1; i <10; i++) 
	{
		printf("----");
	}
	printf("\n");
	for (i = 1; i <= 10; i++)
	{
		printf("%2d |",i);//打印列1-10
		int j = 1;
		for (; j <= 10; j++)
		{
			printf(" %c |",board[i][j]);//打印数组board每一个单元格为*
		}
		printf("\n----");
		int k = 1;
		for (k = 1; k <= 10; k++)
		{
			printf("----");
		}
		printf("\n");
	}
}
char GetMines(char mine[][COL], int row, int col)
{
	return mine[row - 1][col - 1] + mine[row - 1][col] +\
		mine[row - 1][col + 1]+ mine[row - 2][col - 1] +\
		mine[row - 2][col + 1] + mine[row - 3][col - 1]
		+ mine[row - 3][col] + mine[row - 3][col + 1] - 7 * '0';
	//周围8个单元格加起来减去8*‘0’，为该坐标周围雷的个数，是整型，但要\
	返回的是char类型，所以再加上‘0’，即减去7*‘0’
}
void Game()
{
	char mine[ROW][COL];//显示，判断雷的数组
	char board[ROW][COL];//向用户展示的数组
	//memset，常用于内存空间初始化，在这里，对数组进行初始化，\
	函数里边的顺序依次为初始化对象、初始化结果、初始化对象的长度
	memset(mine,'0',sizeof(mine));//将mine数组初始化为‘0’
	memset(board, '*', sizeof(board));//将board数组初始化为*
	SetMine(mine, ROW, COL);//布雷
	int count = TOTAL;
	//x,y为用户输入的坐标
	int x = 0;
	int y = 0;
	while (1)
	{
		ShowBoard(board, ROW, COL);//显示扫雷界面
		printf("请输入坐标:");
		scanf("%d%d", &x, &y);
		//判断用户输入坐标是否合法
		if (x >= 1 && x <= ROW - 2 && y >= 1 && \
			y <= COL - 2)
		{
			if (mine[x][y] == '0')
			{
				char num = GetMines(mine, x, y);//获得输入坐标周边雷的个数 
				board[x][y] = num;//让用户看到雷的个数
				count--;
				if (count <= 20)
				{
					printf("你赢了，厉害!\n");
					break;
				}
			}
			    else
			    {
				    printf("不好意思，你被炸死了!\n");
				    ShowBoard(mine, ROW, COL);
				    break;
			    }
		}
		else
		{
			printf("enter error,please try again:\n");
	    }
	}
}