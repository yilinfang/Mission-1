#include<iostream>
#include "plane.h"
Plane::Plane():birth(0),speed(10),hp(1),position(100),age(0)
{

}
void Plane::setBirth(int t)//帧
{
    birth=t;
}
void Plane::setSpeed(int t)
{
    speed=t;
}
void Plane::setHp(int t)
{
    hp=t;
}
void Plane::setPosition()//帧
{
    position=100-age/6.0;
}
void Plane::setAge(int t)//帧
{
    age = t;

}

float Plane:: getPosition()
{
    return position;
}
int Plane::getSpeed()
{
    return speed;
}
int Plane::getBirth()
{
    return birth;
}
int Plane::getHp()
{
    return hp;
}
int Plane::getAge()
{
    return age;
}
void Plane::Display()
{

    std::cout<<"位置："<<position<<" 存活时间:"<<age<<" 出现时间："<<birth<<" 速度："<<speed<<" "<<std::endl;
}
void Plane::incAge()
{
    age++;
}
