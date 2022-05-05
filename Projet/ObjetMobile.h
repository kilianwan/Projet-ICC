#pragma once
#include <vector>
#include "Vecteur.h"
#include "Support_A_Dessin.h"

using namespace std;

class ObjetMobile: public SupportADessin{
	
public:

//============= Constructeurs =====================
	ObjetMobile(double r=0.0, Vecteur p={0.0,0.0,0.0}, Vecteur v={0.0,0.0,0.0}, Vecteur f={0.0,0.0,0.0}, double mv=0.0) :rayon(r), param(p), deriveeparam(v), force(f), masse_volumique(mv)
	{}
//=================================================

//================== Méthodes =====================
	virtual Vecteur evolution() const = 0;
	void agit_sur(ObjetMobile& o);
	void dessine_sur();
	void point_plus_proche();
	double distance(const ObjetMobile& v) const;
	ostream& affiche(ostream& os) const;
//=================================================

//================== Accesseurs ===================
	Vecteur get_param() const;
	Vecteur get_deriveeparam() const;
	double get_rayon() const;
	Vecteur get_force() const;
	double get_masse_volumique() const; 
	double get_masse() const;
//=================================================

//============== Manipulateurs ====================
	void set_param(Vecteur);
	void set_deriveeparam(Vecteur);
	void set_rayon(double);
	void set_force(Vecteur);
	void set_masse_volumique(double);
	void ajoute_force(Vecteur const& df) ;
//=================================================
	
	
protected:
	double rayon; 
	Vecteur param;
	Vecteur deriveeparam;
	Vecteur force;
	double masse_volumique; 
	
};


std::ostream& operator<<(std::ostream& os, const ObjetMobile& o);

