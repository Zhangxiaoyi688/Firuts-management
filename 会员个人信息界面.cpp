#include "会员head.h"

void MemMenu(char name[]) 
{
	int choice = 0;
	while (true) {
		system("cls");
		printf("1.余额查询\n");
		printf("2.余额充值\n");
		printf("0.退出\n");
		scanf_s("%d", &choice);
		if (choice < 0 || choice>2)break;
		
		ShowMemMenu(choice, name);
	}
}

void ShowMemMenu(int choice, char name[]) {
	switch (choice)
	{
	case 1:  //余额查询
		CheckMemMoney(name);
		break;
	case 2:  //余额充值
		RechargeMoney(name);
		break;
	default:
		break;
	}
}

void CheckMemMoney(char name[]) 
{
	Mem* head, * p = NULL;
	int flag = 0;
	p = head = read_Count();
	while (p != NULL)
	{
		if (strcmp(name, p->id) == 0)
		{
			printf("您的余额为： %2lf", p->money);
			flag = 1;
			break;
		}
		p = p->next;
	}

}


void RechargeMoney(char name[])
{
	Mem* head, * p = NULL;
	int i = 0, flag = 0;
	double money;
	char keyword[30];
	printf("请输入您的密码：");
	while (true) {
		//fflush(stdin);
		keyword[i] = getch();
		if (keyword[i] == '\x0d') {  //遇到回车符退出循环
			keyword[i] = '\0';
			break;
		}
		printf("* ");   //保护用户隐私
		i++;
	}
	p = head = read_Count();
	while (p != NULL)
	{
		if (strcmp(name, p->id) == 0 && strcmp(keyword, p->key))
		{
			printf("请输入您要充值的金额： ");
			scanf_s("%lf", &money);
			p->money += money;
			flag = 1;
			break;
		}
		p = p->next;
	}
	SaveMem(head);
}
