#pragma once
#include "ObjetMobile.h"

class Integrateur {
	
	public:
	Integrateur(double t=0.0) : dt(t) 
	{}
	
	virtual void evolue(ObjetMobile& o) const = 0;
	
	double get_dt() const;
	
	
	
	protected:
	double dt;
	
};
