#include <iostream>
#include <vector>
#include "Vecteur.h"
#include "ObjetMobile.h"
#include "Obstacles.h"
#include "Brique.h"
#include "Plan.h"


// ================== Méthodes ===================

ostream& Brique::affiche(ostream& os) const {
	os << get_position() << " #origine brique" << endl;
	os << get_longueur() << " #longueur brique" << endl;
	os << get_largeur() << " #largeur brique" << endl;
	os << get_hauteur() << " #hauteur brique" << endl;
	return os;
}
	
	
	Vecteur Brique::o_hauteur(){
		Vecteur eh = (longueur^largeur);
		return hauteur*(~eh);
	}


	double Brique::distance(const ObjetMobile& p) {
		return (p.get_param() - point_plus_proche(p)).norme() - p.get_rayon();
	}
	
	Vecteur Brique::point_plus_proche(const ObjetMobile& o){
        Vecteur h = hauteur*(longueur^largeur);
		Plan p1(get_position(), ~h);
		Vecteur c1(p1.coordonnes(o,p1.point_plus_proche(o),~h, longueur.norme(), ~longueur, largeur.norme(), ~largeur));
		Plan p2(get_position(), -~largeur);
		Vecteur c2(p2.coordonnes(o,p2.point_plus_proche(o),-~largeur, h.norme(), -~h, longueur.norme(), ~longueur));
		Plan p3(get_position(), -~longueur);
		Vecteur c3(p3.coordonnes(o,p3.point_plus_proche(o),-~longueur, largeur.norme(), ~largeur, h.norme(), -~h));
		Plan p4(get_position() + (longueur).norme()*~longueur, ~longueur);
		Vecteur c4(p4.coordonnes(o,p4.point_plus_proche(o),~longueur, h.norme(), -~h, largeur.norme(), ~largeur));
		Plan p5(get_position() + ((largeur).norme())*~largeur, ~largeur);
		Vecteur c5(p5.coordonnes(o,p5.point_plus_proche(o),~largeur, longueur.norme(), ~longueur, hauteur, -~h));
		Plan p6(get_position() - (h).norme()*~h, -~h);
		Vecteur c6(p6.coordonnes(o,p6.point_plus_proche(o),-~h, largeur.norme(), ~largeur, longueur.norme(), ~longueur));
		
			
			
			vector<Vecteur> plans={c1 - o.get_param(), c2 - o.get_param(), c3 - o.get_param(), c4 - o.get_param(), c5 - o.get_param(), c6 - o.get_param()};
			Vecteur minV(plans[0]);
			double minD(plans[0].norme());
		
		for(size_t i(0) ; i < plans.size() -1; i++){
				if (plans[i].norme() < minD){
					minD = plans[i].norme();
					minV = plans[i];
					//Vecteur Brique::coordonnes(const ObjetMobile& o, Vecteur x, Vecteur n, double L, Vecteur eL, double l, Vecteur el){
				}
			}
			
		return minV;
	}
//=================================================


//================== Accesseurs ===================

	Vecteur Brique::get_longueur() const{
		return longueur;
	}
	Vecteur Brique::get_largeur() const{
		return largeur;
	}
	double Brique::get_hauteur() const{
		return hauteur*((~(longueur^largeur)).norme());
	}
	Vecteur Brique::normale() const{
		return orthogonale(get_longueur(), get_largeur());
	}
//=================================================


//============== Manipulateurs ====================

	void Brique::set_longueur(Vecteur lo){
		longueur = lo;
	}
	void Brique::set_largeur(Vecteur la){
		largeur = la;
	}
	void Brique::set_hauteur(double h){
		hauteur = h;
	}

//=================================================		

//==================================================================================================

	

//==================================================================================================




std::ostream& operator<<(std::ostream& os, const Brique& b){
	
	b.affiche(os);
	
	return os;
}

