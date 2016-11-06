#ifndef PLANE_H_INCLUDED
#define PLANE_H_INCLUDED
class Plane{
public:
    Plane();
    void setBirth(int t);
    void setSpeed(int t);
    void setHp(int t);
    void setPosition();
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


#endif // PLANE_H_INCLUDED
