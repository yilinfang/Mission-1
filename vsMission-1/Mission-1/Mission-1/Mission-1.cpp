// Mission-1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


#include<iostream>
#include <stdlib.h>
#include <time.h>
#include "planeflock.h"


using namespace std;



int main()
{
	srand((unsigned)time(NULL));
	CPlaneFlock mission1;
	mission1.Simulate();
	getchar();
	return 0;
}