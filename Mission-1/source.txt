#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct plane{
    int age;
    int birth;
};
typedef struct plane plane;
int main()
{
    plane a[500]; //飞机库,存放的值为飞机存活的时间
    int i,n,head,sign;
    float flyTime,dis,arriveTime;
    n=0; //当前状态下存活的飞机数
    sign=0;//0表示炮台胜利，1代表飞机胜利
    head=0;//炮击目标
    dis=0;//表示飞的最远的飞机所到达的距离
    arriveTime=0;//表示飞机抵达的时间
    srand((unsigned)time(NULL));
    for(i=0;i<=499;i++) //初始化
    {
        a[i].age=0;
        a[i].birth=0;
    }
    for(i=1;i<2400;i++) //每一帧执行一次
    {
        int j;
        float c;//存放比对结果，t的值小于0.5的五次方，则飞机逃过这轮炮击
        for(j=0;j<=499;j++)
        {
            int t;
            t=0;
            if (a[j].age > 0)
                a[j].age++; //增加飞机存活时间
            if ((n < 500) && (a[j].age == 0) && (t < 100))
            {
                a[j].age=1;
                a[j].birth=i;
                n++;
                t++;
            } //新建飞机
        }
        if (a[head].age==600) //飞机胜利
        {
            sign=1;
            arriveTime=a[head].birth/60.0 + 10.0;
            break;
        }
        c=rand()/(RAND_MAX+1.0);
        //printf("%f ",c);  测试为什么出错
        if (c > 0.03125) //躲过炮击的概率为0.03125。。。好可怜的飞机
        {
           float t;
           t=((i-a[head].birth)/60.0)*10.0;
           if (t > dis)
           {
            dis=t;
            flyTime=(i-a[head].birth)/60.0;
           }
           a[head].age=0;
           a[head].birth=0;
           head=0;
           n--;
        }
        for (j=0;j<500;j++)
        {
            if (a[j].age > a[head].age) //寻找下次炮击目标
                head=j;
        }
    }
    if (sign == 1)
      printf("Planes Win!!!\nThe planes first arrived at %.3fs.",arriveTime);
        else printf("Emplacements Win!!!\nthe most lucky planes flewd for %.3fs,and were brought down at(0,%.2f).",flyTime,100.0-dis);
    return 0;
}
