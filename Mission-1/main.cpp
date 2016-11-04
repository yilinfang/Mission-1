#include<iostream>
#include<time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "CPlane.h"
#include "CPlaneFlock.h"
#define survivalRate 0.03125
using namespace std;
CPlaneFlock::CPlaneFlock()
{
    Init();
}
void CPlaneFlock::Init()
{
    head=rear=0;
}

void CPlaneFlock::addPlane(int n)
{
    int i=0;
    while(!Full() && i<n)
    {
        rear = (rear + 1) % MAXSIZE;
        flock[rear].incAge();//����ɻ�
        i++;
    }
}
void CPlaneFlock::surviveOne()
{
    int i=head;
    while (i != rear)
    {
        i=(i+1)% MAXSIZE;
        flock[i].incAge();
    }
}

void CPlaneFlock::Shoot()
{
    float t;
    t=rand()/(RAND_MAX+1.0);
    if(!Empty() && t> survivalRate)
    {
        head = (head + 1) % MAXSIZE;
        flock[head].setAge(0);
    }
}
void CPlaneFlock::Simulate()
{
    int i,sign;
    float flyTime,dis,arriveTime;
    sign=0;//0��ʾ��̨ʤ����1����ɻ�ʤ��
    dis=0;//��ʾ�ɵ���Զ�ķɻ�������ľ���
    arriveTime=0;//��ʾ�ɻ��ִ��ʱ��
    for(i=1;i<2400;i++) //ÿһִ֡��һ��
    {
        surviveOne();
        if (Result()) //�ɻ�ʤ��
        {
            sign=1;
            break;
        }
        if (i % 60 == 0)
            addPlane(100);
        Shoot();
    }
    if (sign == 1)
      printf("Planes Win!!!\n");
        else printf("Emplacements Win!!!\n");
}
int main()
{
    srand((unsigned)time(NULL));
    CPlaneFlock mission1;
    mission1.Simulate();
    return 0;
}

