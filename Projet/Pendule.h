#pragma once
#include <vector>
#include "Vecteur.h"
#include "ObjetMobile.h"
#include "Balle.h"

class Pendule : public ObjetMobile {
	
	public:
	Pendule(Balle bp, Vecteur o={0.0, 0.0, 0.0}, Vecteur d={0.0, 0.0, 0.0}, double l=0.0, double f=0.0, double th=0.0, double thp=0.0, Vecteur u={0.0, 0.0, 0.0} )
    : bout_pendule(bp), origine(o), direction(d), longueur(l), frottement(f), theta(th), theta_point(thp), unitaire(u)
    {}
	
	
//================= Méthodes ==========================

	Vecteur evolution() const override;
	Vecteur orthogonale(Vecteur g) const;
	void affiche() const;
	
//=====================================================
	
//================= Accesseurs =========================


	double get_longueur() const;
	double get_frottement() const;
	Vecteur get_origine() const;
	Vecteur get_direction() const;
	double get_theta() const;
	double get_theta_point() const;
	Balle get_position_bout() const;

//=====================================================

//================= Manipulateurs =====================

	void set_longueur(double l) ;
	void set_frottement(double f);
	void set_origine(Vecteur o) ;
	void set_direction(Vecteur d) ;
	void set_theta(double t) ;
	void set_theta_point(double t_p) ;
	void set_position_bout(Balle p_b) ;


//=====================================================
	
	protected:
    Balle bout_pendule;
    Vecteur origine;
    Vecteur direction;
    double longueur;
    double frottement;
    double theta;
    double theta_point;
    Vecteur unitaire;
};

//=====================================================



std::ostream& operator<<(std::ostream& os, const Pendule& p);

