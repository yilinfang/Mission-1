#include <stdlib.h>
#include <stdio.h>
#include "planeflock.h"
#include "factory.h"
PlaneFlock::PlaneFlock()
{
    Init();
}
void PlaneFlock::Init()
{
    head=rear=0;
}

void PlaneFlock::addPlane(int n,int t)
{
    int i=0;
    while(!Full() && i<n)
    {
        rear = (rear + 1) % MAXSIZE;
        //flock[rear].setAge(1);//����ɻ�
        Factory::wakePlane(flock[rear]); //����ģʽ�������ɻ�ģ������
        flock[rear].setBirth(t);
        //printf("%d ",flock[rear].getAge());//�����þ�
        i++;
    }
    //printf("%d,%d\n",i,GetQty());
}
void PlaneFlock::surviveOne()
{
    int i=head;
    while (i != rear)
    {
        i=(i+1)% MAXSIZE;
        flock[i].incAge();
    }
}

float PlaneFlock::Shoot()
{
    float c;
    c=rand()/(RAND_MAX+1.0);
    if(!Empty() && c>= survivalRate)
    {
        head = (head + 1) % MAXSIZE;
        flock[head].setPosition();
        float t = flock[head].getPosition();
        printf("%.2f ",t);
        flock[head].setAge(0);
        return t;
        //printf("%d\n",head);
    }
    else return 100;
}
void PlaneFlock::Simulate()
{
    int i,sign;
    float position,arriveTime;
    sign=0;//0��ʾ��̨ʤ����1����ɻ�ʤ��
    position=100;//��ʾ�ɵ���Զ�ķɻ������������
    arriveTime=0;//��ʾ�ɻ��ִ��ʱ��
    for(i=0;i<=2400;i++) //ÿһִ֡��һ��
    {
        surviveOne();
        if (i % 60 == 0)
            addPlane(100,i);
        if (Result()) //�ɻ�ʤ��
        {
            sign=1;
            arriveTime=i/60.0;
            break;
        }
        float m=Shoot();
        if(m < position)
        {
            position=m;
        }
    }
    if (sign == 1)
      printf("Planes Win!!!The first planes arrived at %.1fs.\n",arriveTime);
        else printf("Emplacements Win!!!The most lucky planes were brought down at (0,%.1f).\n",position);
}

