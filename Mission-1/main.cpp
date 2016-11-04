#include<iostream>
//#include<vector>
//#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "planeflock.h"


using namespace std;



int main()
{
    srand((unsigned)time(NULL));
    PlaneFlock mission1;
    mission1.Simulate();
    return 0;
}
