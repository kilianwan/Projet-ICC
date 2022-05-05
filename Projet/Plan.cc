#include <iostream>
#include "Plan.h"
#include "Vecteur.h"
#include "ObjetMobile.h"
#include "Obstacles.h"

// ================== Méthodes ===================

ostream& Plan::affiche(ostream& os) const{
		os << get_position() << "#origine plan" << endl;
		os << get_normale() << "#normale plan" << endl;
        return os;
}

	Vecteur Plan::point_plus_proche(const ObjetMobile& p){
		return p.get_param() + normale*((normale*(position - p.get_param())));
	}
	
	double Plan::distance(const ObjetMobile& p) {
		return (p.get_param() - point_plus_proche(p)).norme() - p.get_rayon();
	}
	Vecteur Plan::coordonnes(const ObjetMobile& o, Vecteur x, Vecteur n, double L, Vecteur eL, double l, Vecteur el){
		double xL = (x - get_position())*eL;
		if (xL > (L*eL).norme()) x = x - (xL - (L*eL))*eL;
		else if (xL < 0) x = x - xL*eL;
		double xl = (x - get_position())*el;
		if (xl > (l*el).norme()) x = x - (xl - (l*el))*el;
		else if (xl < 0) x = x - xl*el;
		
		return x;
	}
	
//=================================================

//================== Accesseurs ===================

	Vecteur Plan::get_normale() const{
		return normale;
	}

//=================================================


//============== Manipulateurs ====================

	void Plan::set_normale(Vecteur n){
		normale = n;
	}

//=================================================	

std::ostream& operator<<(std::ostream& os, const Plan& p){
	p.affiche(os);
}


//==================================================================================================
