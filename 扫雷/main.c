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
		Menu();//��ʾ�˵������û�����ѡ��
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			Game();//ʵ����Ϸ���淨
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