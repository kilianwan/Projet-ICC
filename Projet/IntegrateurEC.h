#pragma once
#include "Integrateur.h"


class IntegrateurEC : public Integrateur {
	
	public:
	IntegrateurEC(double dt) : Integrateur(dt) 
	{}
	
	void evolue(ObjetMobile& o) const override;
	
	
};
