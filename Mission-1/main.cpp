#include<iostream>
#include<time.h>
#include<vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define survivalRate 0.03125
using namespace std;
class CPlane{
public:
    CPlane():position(0),birth(0),speed(10),hp(1),age(1){}
    void setBirth(int t){
        birth=t;
    }
    void setSpeed(int t){
        speed=t;
    }
    void setHp(int t){
        hp=t;
    }
    void setPosition(float t){
        position=t;
    }
    void setAge(int t){
        age=t;
    }
    float getPosition(){
        return position;
    }
    int getSpeed(){
        return speed;
    }
    int getBirth(){
        return birth;
    }
    int getHp(){
        return hp;
    }
    int getAge(){
        return age;
    }
    void Display(){
        cout<<"λ�ã�"<<position<<" ���ʱ��:"<<age<<" ����ʱ�䣺"<<birth<<" �ٶȣ�"<<speed<<" "<<endl;
    }
    void incAge(){
        age++;
    }
private:
    float position;
    int age;
    int birth;
    int speed;
    int hp;
};
class CPlaneFlock{
public:
    CPlaneFlock();
    void Init();
    void addPlane(int n);
    void surviveOne();
    void Shoot();
    void Simulate();
    bool Full()  //�ж��ǲ�������
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
    CPlane flock[MAXSIZE];
    int head;
    int rear;
};

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
      printf("Planes Win!!!");
        else printf("Emplacements Win!!!\n");
}
int main()
{
    srand((unsigned)time(NULL));
    CPlaneFlock mission1;
    mission1.Simulate();
    return 0;
}

