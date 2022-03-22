#include "会员head.h"

//用户登录界面
void MemLogIn()
{
	int sw = 0;
	int cnt = 0;
	char name[30];

	while (true)
	{
		system("cls");//清屏操作
		printf("1.注册新账号\n");
		printf("2.已有账户，直接登录\n");
		printf("请输入您需要的服务：\n");
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
			//printf("登录成功！！！");
			//system("pause");//登录成功，展示会员界面
		}
		else
		{
			cnt++;
			if (cnt >= 3){
				printf("输错次数达到3次，请您过一会再登录！\n");
				getchar();
				break;
					//printf("输入密码有误，您还有%d次机会", 5 - cnt);
					//getchar();
					////system("cls");
					//printf("请重新输入：");
			}
				/*if (cnt > 5) {
					printf("请您过会再登陆，按任意键返回主菜单");
					break;
				}*/
			printf("账号或密码输入错误\n");
			system("cls");
			printf("请重新输入：");
			goto FLAG;
		}
			break;
		}

		default:
			break;

		}

	}
}