#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int a[500]; //�ɻ���,��ŵ�ֵΪ�ɻ�����ʱ��
    int i,n,head,sign;
    n=0; //��ǰ״̬�´��ķɻ���
    sign=0;//0��ʾ��̨ʤ����1����ɻ�ʤ��
    head=0;//�ڻ�Ŀ��
    srand((unsigned)time(NULL));
    for(i=0;i<=499;i++) //��ʼ��
        a[i]=0;
    for(i=1;i<=2400;i++) //ÿһִ֡��һ��
    {
        int j;
        float c;//��űȶԽ����t��ֵС��0.5����η�����ɻ��ӹ������ڻ�
        for(j=0;j<=499;j++)
        {
            int t;
            t=0;
            if (a[j] > 0)
                a[j]++; //���ӷɻ����ʱ��
            if ((n < 500) && (a[j] == 0) && (t < 100))
            {
                a[j]=1;
                n++;
                t++;
            } //�½��ɻ�
        }
        if (a[head]==600) //�ɻ�ʤ��
        {
            sign=1;
            break;
        }
        c=rand()/(RAND_MAX+1.0);
        if (c > 0.03125) //����ڻ��ĸ���Ϊ0.03125�������ÿ����ķɻ�
        {
           a[head]=0;
           head=0;
           n--;
        }
        for (j=0;j<500;j++)
        {
            if (a[j] > a[head]) //Ѱ���´��ڻ�Ŀ��
                head=j;
        }
    }
    if (sign == 1)
        printf("Planes Win!!!\n");
        else printf("Emplacements Win!!!\n");
    return 0;
}
