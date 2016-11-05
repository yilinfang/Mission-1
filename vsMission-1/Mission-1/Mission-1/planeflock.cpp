#include <stdlib.h>
#include <stdio.h>
#include "planeflock.h"
#include "factory.h"
CPlaneFlock::CPlaneFlock()
{
	Init();
}
void CPlaneFlock::Init()
{
	head = rear = 0;
}

void CPlaneFlock::addPlane(int n)
{
	int i = 0;
	while (!Full() && i < n)
	{
		rear = (rear + 1) % MAXSIZE;
		//flock[rear].setAge(1);//����ɻ�
		flock[rear] = Factory::CreatePlaneModel();  //����ģʽ�������ɻ�ģ������
		i++;
	}
	//printf("%d,%d\n",i,GetQty());
}
void CPlaneFlock::surviveOne()
{
	int i = head;
	while (i != rear)
	{
		i = (i + 1) % MAXSIZE;
		flock[i].incAge();
	}
}

void CPlaneFlock::Shoot()
{
	float t;
	t = rand() / (RAND_MAX + 1.0);
	if (!Empty() && t > survivalRate)
	{
		head = (head + 1) % MAXSIZE;
		flock[head].setAge(0);
		//printf("%d\n",head);
	}
}
void CPlaneFlock::Simulate()
{
	int i, sign;
	float flyTime, dis, arriveTime;
	sign = 0;//0��ʾ��̨ʤ����1����ɻ�ʤ��
	dis = 0;//��ʾ�ɵ���Զ�ķɻ�������ľ���
	arriveTime = 0;//��ʾ�ɻ��ִ��ʱ��
	for (i = 1; i < 2400; i++) //ÿһִ֡��һ��
	{
		surviveOne();
		if (Result()) //�ɻ�ʤ��
		{
			sign = 1;
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
