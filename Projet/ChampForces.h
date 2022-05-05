#pragma once
#include <vector>
#include <cmath>
#include "Vecteur.h"
#include "ObjetMobile.h"

class ChampForces {
	
	public:
	ChampForces(Vecteur i={0.0, 0.0, 0.0}) : intensite(i) {}
	
	ostream& affiche(ostream& os) const;
	void agit_sur(ObjetMobile& b); 
	
	Vecteur get_intensite() const;
	
	private:
	Vecteur intensite;
	
};


std::ostream& operator<<(std::ostream& os, const ChampForces& cf) ;
