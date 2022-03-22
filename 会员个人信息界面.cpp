#include "��Աhead.h"

void MemMenu(char name[]) 
{
	int choice = 0;
	while (true) {
		system("cls");
		printf("1.����ѯ\n");
		printf("2.����ֵ\n");
		printf("0.�˳�\n");
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
	case 1:  //����ѯ
		CheckMemMoney(name);
		break;
	case 2:  //����ֵ
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
			printf("�������Ϊ�� %2lf", p->money);
			flag = 1;
			break;
		}
		else
		{
			printf("��ѯʧ�ܣ�");
			getchar();
		}
		p = p->next;
	}

}


void RechargeMoney(char name[])
{
	Mem* head = NULL, * p = NULL;
	int i = 0, flag = 0;
	double money;
	char keyword[30];
	printf("�������������룺");
	while (true) {
		//fflush(stdin);
		keyword[i] = getch();
		if (keyword[i] == '\x0d') {  //�����س����˳�ѭ��
			keyword[i] = '\0';
			break;
		}
		printf("* ");   //�����û���˽
		i++;
	}
	head = read_Count();
	p = read_Count();
	while (p != NULL)
	{
		if (strcmp(name, p->id) == 0 && strcmp(keyword, p->key))
		{
			printf("��������Ҫ��ֵ�Ľ� ");
			scanf_s("%lf", &money);
			p->money += money;
			flag = 1;
			break;
		}
		/*else
		{
			printf("��ֵʧ�ܣ�");
			getchar();
		}*/
		p = p->next;
	}
	SaveMem(head);
}
