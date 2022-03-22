#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<conio.h>
#include<windows.h>
#pragma warning(disable:4996)



//typedef struct supermarket
//{
//    fruit* fruit_Head,
//        * fruit_End;
//    record* record_Head;//头结点是哨兵结点
//    double all_Money;
//}supermarket;

//char name[20 + 1] = { 0 };

struct  member
{
    char id[20+1]={0};	                     //用户账号
    char key[20+1]={0};                       //用户账号密码
    
    double money = 0;                         //用户余额                  
    struct  member* next;                //节点指针
};
typedef  struct  member  Mem;

//函数

//用户注册函数
void MemRegister();

//读取函数
Mem* read_Count();

//会员登陆验证函数
int ConfirmMem(char Count[], char key[]);

//会员登陆  子函数1
int LogInMem(char name[]);

//会员保存文件函数
void SaveMem(Mem* head);

//会员登录主界面
void MemLogInMenu();

//会员个人信息界面
void MemMenu(char name[]);

//展示会员功能
void ShowMemMenu(int choice, char name[]);

//会员余额查询
void CheckMemMoney(char name[]);

//会员余额充值
void RechargeMoney(char name[]);
