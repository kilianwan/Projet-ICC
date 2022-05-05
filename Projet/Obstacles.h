#pragma once
#include <vector>
#include "Vecteur.h"
#include "ObjetMobile.h"
#include "Support_A_Dessin.h"


class Obstacle: public SupportADessin{
	
	public:
	Obstacle(Vecteur p={0.0, 0.0, 0.0}) : position(p) {}

//================ Méthodes =======================
	virtual std::ostream& affiche(std::ostream& os) const;
	virtual Vecteur point_plus_proche(const ObjetMobile& o) = 0;
	void agit_sur(const ObjetMobile& o);
	virtual double distance (const ObjetMobile& o) = 0;
	
//=================================================
	
	
//================= Accesseurs ====================

	Vecteur get_position() const;
	
//=================================================	

//=================== Manipulateurs ===============
	
	void set_position(double p);
	
//=================================================
	
	protected:
	Vecteur position;

	
};
std::ostream& operator<<(std::ostream& os, const Obstacle& p) ;
