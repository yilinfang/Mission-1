#ifndef FACTORY_H_INCLUDED
#define FACTORY_H_INCLUDED
#include"Plane.h"
class Factory{
public:
    int createPlane(int h,int r,int n,Plane *flock[]){
        int i=0;
        while(!((r+1)% MAXSIZE == h) && (i<n))
        {
            r = (r + 1) % MAXSIZE;
            flock[r]->incAge();//²¹³ä·É»ú
            i++;
        }
        return r;
    }
private:
    static const int MAXSIZE=501;
    static const int MAXNUM = MAXSIZE - 1;
};


#endif // FACTORY_H_INCLUDED
