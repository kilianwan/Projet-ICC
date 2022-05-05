#include <iostream>
#include <vector>
#include "Vecteur.h"
#include "ObjetMobile.h"


using namespace std;

ostream& ObjetMobile::affiche(ostream& os) const{
	os << "Position : " << get_param() << ", " << "Vitesse : " << get_deriveeparam();
    return os;
	
}

// ================== Méthodes ===================

void ObjetMobile::agit_sur(ObjetMobile& o){
	double mu = 0.01;
	double alpha = 0.8;
	double lambda = (1 + alpha)*(o.get_masse()/(o.get_masse() + get_masse()));
	Vecteur dv;
	Vecteur n(~(param - o.get_param()));
	Vecteur Fn1(force*n);
	Vecteur Fn2(o.get_force()*n);
	if ((Fn1).norme() < 0) {
		force = force - Fn1*n;
		o.set_force(o.get_force() + Fn1*n);
	}
	if ((Fn2).norme() < 0){
		force = force + Fn2*n;
		o.set_force(o.get_force() - Fn2*n);
	}
	Vecteur v_etoile((o.get_param() - param)*n);
	Vecteur v_c(param - o.get_param() + v_etoile*n);
	if ((7*mu*(1 + alpha)*v_etoile).norme() >= 2*v_c.norme()){
		dv = lambda*v_etoile*n - v_c*((2*o.get_masse())/(7*(get_masse() + o.get_masse())));
	}
	else dv = lambda*v_etoile*(n - mu*(~v_c));
	param = param + dv;
	o.set_param(o.get_param() - (get_masse()/o.get_masse())*dv);
}
/*
void ObjetMobile::dessine_sur(){
}

void ObjetMobile::point_plus_proche(){
}
*/

double ObjetMobile::distance(const ObjetMobile& v) const{
	return (get_param() - v.get_param()).norme();
}
//=================================================

//================== Accesseurs ===================
Vecteur ObjetMobile::get_param() const{
	return param;
}

Vecteur ObjetMobile::get_deriveeparam() const{
	return deriveeparam;
}

double ObjetMobile::get_rayon() const{
	return rayon;
}
Vecteur ObjetMobile::get_force() const{
	return force;
}
double ObjetMobile::get_masse_volumique() const{
	return masse_volumique;
} 

double ObjetMobile::get_masse() const {
return (get_masse_volumique()*(4.0/3.0)*(M_PI*(get_rayon()*get_rayon()*get_rayon())));
}
//=================================================


//==================== Manipulateurs ==============
void ObjetMobile::set_param(Vecteur p)
{
param = p;
}
void ObjetMobile::set_deriveeparam(Vecteur v)
{
deriveeparam = v;
}
void ObjetMobile::set_rayon(double r)
{
rayon= r;
	
}
void ObjetMobile::set_force(Vecteur f)
{
force = f;
}
void ObjetMobile::set_masse_volumique(double mv)
{
masse_volumique = mv;
}
//=================================================


void ObjetMobile::ajoute_force(Vecteur const& df) {
for (size_t i(0); i < df.get_dimension(); ++i) {
		force.set_coord(i, force.get_coord(i) + df.get_coord(i)) ;
	}
}

//==================== Affiche =====================
std::ostream& operator<<(std::ostream& os, const ObjetMobile& o){
	o.affiche(os);
}
//==================================================
