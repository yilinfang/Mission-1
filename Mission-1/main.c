#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int a[500]; //飞机库,存放的值为飞机存活的时间
    int i,n,head,sign;
    n=0; //当前状态下存活的飞机数
    sign=0;//0表示炮台胜利，1代表飞机胜利
    head=0;//炮击目标
    srand((unsigned)time(NULL));
    for(i=0;i<=499;i++) //初始化
        a[i]=0;
    for(i=1;i<=2400;i++) //每一帧执行一次
    {
        int j;
        float c;//存放比对结果，t的值小于0.5的五次方，则飞机逃过这轮炮击
        for(j=0;j<=499;j++)
        {
            int t;
            t=0;
            if (a[j] > 0)
                a[j]++; //增加飞机存活时间
            if ((n < 500) && (a[j] == 0) && (t < 100))
            {
                a[j]=1;
                n++;
                t++;
            } //新建飞机
        }
        if (a[head]==600) //飞机胜利
        {
            sign=1;
            break;
        }
        c=rand()/(RAND_MAX+1.0);
        if (c > 0.03125) //躲过炮击的概率为0.03125。。。好可怜的飞机
        {
           a[head]=0;
           head=0;
           n--;
        }
        for (j=0;j<500;j++)
        {
            if (a[j] > a[head]) //寻找下次炮击目标
                head=j;
        }
    }
    if (sign == 1)
        printf("Planes Win!!!\n");
        else printf("Emplacements Win!!!\n");
    return 0;
}
