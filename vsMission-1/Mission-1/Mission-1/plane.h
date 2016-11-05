#pragma once
class CPlane {
public:
	CPlane();
	void setBirth(int t);
	void setSpeed(int t);
	void setHp(int t);
	void setPosition(float t);
	void setAge(int t);
	float getPosition();
	int getSpeed();
	int getBirth();
	int getHp();
	int getAge();
	void Display();
	void incAge();
private:
	float position;
	int age;
	int birth;
	int speed;
	int hp;
};
