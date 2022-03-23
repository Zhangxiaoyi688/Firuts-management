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
	case 0:
		exit(0);
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
	FILE* fp;
	Mem* p, * q, * head = NULL, * ptr;
	if ((fp = fopen("zhanghao.txt", "r")) == 0) {
		printf("\n无法查询到该账号");
		return;
	}
	rewind(fp);
	p = (Mem*)malloc(sizeof(Mem));
	//memset(p, 0x00, sizeof(Mem));
	head = q = p;
	while (!feof(fp)) {
		if (fread(p, sizeof(Mem), 1, fp) != 1) {
			break;
		}
		p->next = (Mem*)malloc(sizeof(Mem));
		//memset(p->next, 0x00, sizeof(Mem));
		q = p;           //q是真正的尾节点
		p = p->next;     //p向后移动一个节点
	}
	q->next = NULL;
	fclose(fp);
	ptr = head;
	while (ptr != NULL) {
		if (strcmp(ptr->id, name) == 0) {
			printf("您的余额为： %2lf", ptr->money);
			break;
		}
		ptr = ptr->next;
	}
	

	/*Mem* head, * p = NULL;
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
		else
		{
			printf("查询失败！");
			getchar();
		}
		p = p->next;
	}*/

}


void RechargeMoney(char name[])
{
	//Mem* head = NULL, * p = NULL;
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
	FILE* fp;
	Mem* p, * q, * head = NULL, * ptr;
	if ((fp = fopen("zhanghao.txt", "r")) == 0) {
		printf("\n无法查询到该账号");
		return;
	}
	rewind(fp);
	p = (Mem*)malloc(sizeof(Mem));
	//memset(p, 0x00, sizeof(Mem));
	head = q = p;
	while (!feof(fp)) {
		if (fread(p, sizeof(Mem), 1, fp) != 1) {
			break;
		}
		p->next = (Mem*)malloc(sizeof(Mem));
		//memset(p->next, 0x00, sizeof(Mem));
		q = p;           //q是真正的尾节点
		p = p->next;     //p向后移动一个节点
	}
	q->next = NULL;
	fclose(fp);
	ptr = head;
	
	while (ptr != NULL) {
		if (strcmp(ptr->id, name) == 0 && strcmp(keyword, p->key) == 0) {
			printf("请输入您要充值的金额： ");
			scanf_s("%lf", &money);
			ptr->money += money;
			break;
		}
		ptr = ptr->next;
	}
	SaveMem(head);
	/*head = read_Count();
	p = read_Count();
	while (p != NULL)
	{
		if (strcmp(name, p->id) == 0 && strcmp(keyword, p->key))
		{
			printf("请输入您要充值的金额： ");
			scanf_s("%lf", &money);
			p->money += money;
			flag = 1;
			break;
		}*/
		/*else
		{
			printf("充值失败！");
			getchar();
		}*/
		/*p = p->next;*/
	
	
}
