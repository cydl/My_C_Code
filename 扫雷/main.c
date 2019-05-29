#define _CRT_SECURE_NO_WARNINGS 1
#include"mine.h"
void Menu()
{
	printf("##########################\n");
	printf("######### 1.Play #########\n");
	printf("######### 2.Exit #########\n");
	printf("please select:\n");
}
int main()
{
	int quit = 0;
	int select = 0;
	while (!quit)
	{
		Menu();//显示菜单，让用户进行选择
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			Game();//实现游戏的玩法
			break;
		case 2:
			printf("byebye!\n");
			quit = 1;
			break;
		default:
			printf("select error,please select again!\n");
			break;
		}
	}
	system("pause");
	return 0;
}