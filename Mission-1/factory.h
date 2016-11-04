#ifndef FACTORY_H_INCLUDED
#define FACTORY_H_INCLUDED
#include "plane.h"
class Factory
{
public:
    static Plane CreatePlane()
    {
        Plane t;
        return t;
    }
};


#endif // FACTORY_H_INCLUDED
