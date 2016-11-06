#ifndef FACTORY_H_INCLUDED
#define FACTORY_H_INCLUDED
#include "plane.h"
class Factory
{
public:
    static void CreatePlane(Plane& plane)
    {
        plane.incAge();
    }
};


#endif // FACTORY_H_INCLUDED
