#include<iostream>
#include "plane.h"
CPlane::CPlane() :position(0), birth(0), speed(10), hp(1), age(1)
{

}
void CPlane::setBirth(int t)
{
	birth = t;
}
void CPlane::setSpeed(int t)
{
	speed = t;
}
void CPlane::setHp(int t)
{
	hp = t;
}
void CPlane::setPosition(float t)
{
	position = t;
}
void CPlane::setAge(int t)
{
	age = t;

}

float CPlane::getPosition()
{
	return position;
}
int CPlane::getSpeed()
{
	return speed;
}
int CPlane::getBirth()
{
	return birth;
}
int CPlane::getHp()
{
	return hp;
}
int CPlane::getAge()
{
	return age;
}
void CPlane::Display()
{

	std::cout << "λ�ã�" << position << " ���ʱ��:" << age << " ����ʱ�䣺" << birth << " �ٶȣ�" << speed << " " << std::endl;
}
void CPlane::incAge()
{
	age++;
}
