#include<iostream>
#include<time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Plane.h"
#include "PlaneFlock.h"
#include "Factory.h"
#define survivalRate 0.03125
using namespace std;
PlaneFlock::PlaneFlock()
{
    Init();
}
void PlaneFlock::Init()
{
    head=rear=0;
}
void PlaneFlock::surviveOne()
{
    int i=head;
    while (i != rear)
    {
        i=(i+1)% MAXSIZE;
        flock[i]->incAge();
    }
}

void PlaneFlock::Shoot()
{
    float t;
    t=rand()/(RAND_MAX+1.0);
    if(!Empty() && t> survivalRate)
    {
        head = (head + 1) % MAXSIZE;
        flock[head]->setAge(0);
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
            rear=factory.createPlane(head,rear,100,flock);
        Shoot();
    }
    if (sign == 1)
      printf("Planes Win!!!\n");
        else printf("Emplacements Win!!!\n");
}
int main()
{
    srand((unsigned)time(NULL));
    PlaneFlock mission1;
    mission1.Simulate();
    return 0;
}

