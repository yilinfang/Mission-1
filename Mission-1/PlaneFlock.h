#ifndef PLANEFLOCK_H_INCLUDED
#define PLANEFLOCK_H_INCLUDED
#include "plane.h"

#define survivalRate 0.03125

class PlaneFlock{
public:
    PlaneFlock();
    void Init();
    void addPlane(int ,int);
    void surviveOne();
    float Shoot();
    void Simulate();
    bool Full()  //判断是不是满了
    {
        return (rear+1)% MAXSIZE == head;
    }
    bool Empty()
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
    static const int MAXSIZE=501;
    static const int MAXNUM = MAXSIZE - 1;
    Plane flock[MAXSIZE];
    int head;
    int rear;
};

#endif // PLANEFLOCK_H_INCLUDED
