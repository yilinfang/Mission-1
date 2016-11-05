#pragma once
#include "plane.h"
class Factory
{
public:
	static CPlane CreatePlaneModel()
	{
		CPlane t;
		return t;
	}
	static CPlane *CreatePlane()
	{

		return new CPlane();
	}
};
