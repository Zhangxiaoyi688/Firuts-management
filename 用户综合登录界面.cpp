#include "��Աhead.h"

//�û���¼����
void MemLogIn()
{
	int sw = 0;
	int cnt = 0;
	char name[30];

	while (true)
	{
		system("cls");//��������
		printf("1.ע�����˺�\n");
		printf("2.�����˻���ֱ�ӵ�¼\n");
		printf("����������Ҫ�ķ���\n");
		//fflush(stdin);
		scanf_s("%d", &sw);
		getchar();
		//fflush(stdin);
		if(sw > 2 || sw < 1) break;
		switch(sw)
		{
		case 1:
			MemRegister();

		case 2:
		{
		FLAG:if (LogInMem(name)) 
		{
			MemMenu(name);
			//printf("��¼�ɹ�������");
			//system("pause");//��¼�ɹ���չʾ��Ա����
		}
		else
		{
			cnt++;
			if (cnt >= 3){
				printf("�������ﵽ3�Σ�������һ���ٵ�¼��\n");
				getchar();
				break;
					//printf("������������������%d�λ���", 5 - cnt);
					//getchar();
					////system("cls");
					//printf("���������룺");
			}
				/*if (cnt > 5) {
					printf("���������ٵ�½����������������˵�");
					break;
				}*/
			printf("�˺Ż������������\n");
			system("cls");
			printf("���������룺");
			goto FLAG;
		}
			break;
		}

		default:
			break;

		}

	}
}