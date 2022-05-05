#pragma once
#include <vector>
#include "Vecteur.h"
#include "ObjetMobile.h"
#include "Obstacles.h"

class Plan : public Obstacle {
	
	public:
	Plan(Vecteur p = {0.0 ,0.0, 0.0}, Vecteur n = {0.0, 0.0, 0.0}) : Obstacle(p), normale(n) {}
	
// ================== Méthodes ===================

	ostream& affiche(ostream& os) const override;
	double distance(const ObjetMobile& p) override;
	Vecteur coordonnes(const ObjetMobile& o, Vecteur x, Vecteur n, double L, Vecteur eL, double l, Vecteur el);
	Vecteur point_plus_proche(const ObjetMobile& p) override;
	
//=================================================


//================== Accesseurs ===================

	Vecteur get_normale() const;

//=================================================


//============== Manipulateurs ====================

	void set_normale(Vecteur u);

//=================================================		
	
	
	
	
	private:
	Vecteur normale;
	
};


std::ostream& operator<<(std::ostream& os, const Plan& p) ;
