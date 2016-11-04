#ifndef PLANEFLOCK_H_INCLUDED
#define PLANEFLOCK_H_INCLUDED
#include "Plane.h"
#include "Factory.h"
class PlaneFlock{
public:
    PlaneFlock();
    void Init();
    /*void addPlane(int n);*/
    void surviveOne();
    void Shoot();
    void Simulate();
    bool Empty()
    {
        return rear == head;
    }
    bool Result()
    {
        if (!Empty() && (flock[(head + 1) % MAXSIZE]->getAge() % 600) == 0)
            return 1;
        else return 0;
    }
private:
    static const int MAXSIZE=501;
    static const int MAXNUM = MAXSIZE - 1;
    Plane *flock[MAXSIZE];
    Factory factory;
    int head;
    int rear;
};
#endif // PLANEFLOCK_H_INCLUDED
