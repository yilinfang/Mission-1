#ifndef PLANE_H_INCLUDED
#define PLANE_H_INCLUDED
#include<iostream>
using namespace std;
class Plane{
public:
    Plane():position(0),birth(0),speed(10),hp(1),age(1){}
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
        cout<<"位置："<<position<<" 存活时间:"<<age<<" 出现时间："<<birth<<" 速度："<<speed<<" "<<endl;
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
#endif // PLANE_H_INCLUDED
