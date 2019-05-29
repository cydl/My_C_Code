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
		int x = GetRandIndex(1,10);//���������x:1-10
		int y = GetRandIndex(1,10);//���������y:1-10
		if (mine[x][y] == '0' )
		{
			mine[x][y] = '1';
			count++;
		}
	}
}
void ShowBoard(char board[][COL], int row, int col)
{
	printf("   ");//��һ������ǰ��Ŀո���
	int i = 1;
	for (; i <= 10; i++)
	{
		printf("%3d ", i);//��ӡ��1-10
	}
	printf("\n--------");
	for (i = 1; i <10; i++) 
	{
		printf("----");
	}
	printf("\n");
	for (i = 1; i <= 10; i++)
	{
		printf("%2d |",i);//��ӡ��1-10
		int j = 1;
		for (; j <= 10; j++)
		{
			printf(" %c |",board[i][j]);//��ӡ����boardÿһ����Ԫ��Ϊ*
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
	//��Χ8����Ԫ���������ȥ8*��0����Ϊ��������Χ�׵ĸ����������ͣ���Ҫ\
	���ص���char���ͣ������ټ��ϡ�0��������ȥ7*��0��
}
void Game()
{
	char mine[ROW][COL];//��ʾ���ж��׵�����
	char board[ROW][COL];//���û�չʾ������
	//memset���������ڴ�ռ��ʼ�����������������г�ʼ����\
	������ߵ�˳������Ϊ��ʼ�����󡢳�ʼ���������ʼ������ĳ���
	memset(mine,'0',sizeof(mine));//��mine�����ʼ��Ϊ��0��
	memset(board, '*', sizeof(board));//��board�����ʼ��Ϊ*
	SetMine(mine, ROW, COL);//����
	int count = TOTAL;
	//x,yΪ�û����������
	int x = 0;
	int y = 0;
	while (1)
	{
		ShowBoard(board, ROW, COL);//��ʾɨ�׽���
		printf("����������:");
		scanf("%d%d", &x, &y);
		//�ж��û����������Ƿ�Ϸ�
		if (x >= 1 && x <= ROW - 2 && y >= 1 && \
			y <= COL - 2)
		{
			if (mine[x][y] == '0')
			{
				char num = GetMines(mine, x, y);//������������ܱ��׵ĸ��� 
				board[x][y] = num;//���û������׵ĸ���
				count--;
				if (count <= 20)
				{
					printf("��Ӯ�ˣ�����!\n");
					break;
				}
			}
			    else
			    {
				    printf("������˼���㱻ը����!\n");
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