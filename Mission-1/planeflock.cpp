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

void PlaneFlock::addPlane(int n)
{
    int i=0;
    while(!Full() && i<n)
    {
        rear = (rear + 1) % MAXSIZE;
        //flock[rear].setAge(1);//补充飞机
        Factory::CreatePlane(flock[rear]); //工厂模式，建立飞机模型数据
        //printf("%d ",flock[rear].getAge());//测试用句
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

void PlaneFlock::Shoot()
{
    float t;
    t=rand()/(RAND_MAX+1.0);
    if(!Empty() && t> survivalRate)
    {
        head = (head + 1) % MAXSIZE;
        flock[head].setAge(0);
        //printf("%d\n",head);
    }
}
void PlaneFlock::Simulate()
{
    int i,sign;
    float flyTime,dis,arriveTime;
    sign=0;//0表示炮台胜利，1代表飞机胜利
    dis=0;//表示飞的最远的飞机所到达的距离
    arriveTime=0;//表示飞机抵达的时间
    for(i=1;i<2400;i++) //每一帧执行一次
    {
        surviveOne();
        if (Result()) //飞机胜利
        {
            sign=1;
            break;
        }
        if (i % 60 == 0)
            addPlane(100);
        Shoot();
    }
    if (sign == 1)
      printf("Planes Win!!!");
        else printf("Emplacements Win!!!\n");
}
