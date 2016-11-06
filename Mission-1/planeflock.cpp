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
        //flock[rear].setAge(1);//补充飞机
        Factory::wakePlane(flock[rear]); //工厂模式，建立飞机模型数据
        flock[rear].setBirth(t);
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
    sign=0;//0表示炮台胜利，1代表飞机胜利
    position=100;//表示飞的最远的飞机所到达的坐标
    arriveTime=0;//表示飞机抵达的时间
    for(i=0;i<=2400;i++) //每一帧执行一次
    {
        surviveOne();
        if (i % 60 == 0)
            addPlane(100,i);
        if (Result()) //飞机胜利
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

