#include <iostream>
#include <vector>
#include <cmath>
#include "Vecteur.h"
#include "ObjetMobile.h"
#include "ChampForces.h"


using namespace std;


double distance(ChampForces c, ObjetMobile const& b);

ostream& ChampForces::affiche(ostream& os) const {
	os << get_intensite() << "# intensite ";
    return os;
}

void ChampForces::agit_sur(ObjetMobile& b) {
	Vecteur f(0, 0, (b.get_masse() - 4*M_PI*1.2*pow(b.get_rayon(),3)/3)*(-9.81));
	b.set_force(b.get_force() + f);
}
	
double distance(ChampForces c, ObjetMobile const& b){
	return (c.get_intensite() -b.get_param()).norme();
	
}

Vecteur ChampForces::get_intensite() const{
	return intensite;
}

	
std::ostream& operator<<(std::ostream& os, const ChampForces& cf){
	
	return cf.affiche(os);
}

