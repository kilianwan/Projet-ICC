#pragma once
#include <vector>
#include "Vecteur.h"
#include "ObjetMobile.h"
#include "Obstacles.h"



class Brique : public Obstacle{

	public: 
	Brique(Vecteur p= {0.0, 0.0, 0.0}, Vecteur l={0.0, 0.0, 0.0}, Vecteur la= {0.0, 0.0, 0.0}, double h=0.0) :Obstacle(p), longueur(l), largeur(orthogonale(l, la)), hauteur(h*(~(longueur^largeur)).norme()) {}
	
// ================== Méthodes ===================
	
	std::ostream& affiche(std::ostream& os) const override;
	Vecteur o_hauteur();
	Vecteur point_plus_proche(const ObjetMobile& o) override;
	double distance(const ObjetMobile& o) override;
	
	
//=================================================


//================== Accesseurs ===================

	Vecteur get_longueur() const;
	Vecteur get_largeur() const;
	double get_hauteur() const;
	Vecteur normale() const;

//=================================================


//============== Manipulateurs ====================

	void set_longueur(Vecteur);
	void set_largeur(Vecteur);
	void set_hauteur(double);

//=================================================		
	
	
	private:
	Vecteur longueur;
	Vecteur largeur;
	double hauteur;
	
	
};

std::ostream& operator<<(std::ostream& os, const Brique& b) ;

