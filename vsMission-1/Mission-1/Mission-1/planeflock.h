#pragma once
#include "plane.h"

#define survivalRate 0.03125

class CPlaneFlock {
public:
	CPlaneFlock();
	void Init();
	void addPlane(int n);
	void surviveOne();
	void Shoot();
	void Simulate();
	bool Full()  //判断是不是满了
	{
		return (rear + 1) % MAXSIZE == head;
	}
	bool Empty()//错了
	{
		return rear == head;
	}
	bool Result()
	{
		if (!Empty() && (flock[(head + 1) % MAXSIZE].getAge() % 600) == 0)
			return 1;
		else return 0;
	}
private:
	static const int MAXSIZE = 501;
	static const int MAXNUM = MAXSIZE - 1;
	CPlane flock[MAXSIZE];
	int head;
	int rear;
};