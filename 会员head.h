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
//    record* record_Head;//ͷ������ڱ����
//    double all_Money;
//}supermarket;

struct  member
{
    char id[30];	                     //�û��˺�
    char key[20];                       //�û��˺�����
    
    double money = 0;                         //�û����                  
    struct  member* next;                //�ڵ�ָ��
};
typedef  struct  member  Mem;

//����

//�û�ע�ắ��
void MemRegister();

//��ȡ����
Mem* read_Count();

//��Ա��½��֤����
int ConfirmMem(char Count[], char key[]);

//��Ա��½  �Ӻ���1
int LogInMem(char name[]);

//��Ա�����ļ�����
void SaveMem(Mem* head);

//��Ա��¼������
void MemLogIn();

//��Ա������Ϣ����
void MemMenu(char name[]);

//չʾ��Ա����
void ShowMemMenu(int choice, char name[]);

//��Ա����ѯ
void CheckMemMoney(char name[]);

//��Ա����ֵ
void RechargeMoney(char name[]);
