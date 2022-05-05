#include <iostream>
#include <vector>
#include <cmath>
#include "Vecteur.h"
#include "Balle.h"
#include "ObjetMobile.h"


using namespace std;

Vecteur Balle::evolution() const{
	return get_force()*(1/get_masse());
}o

ostream& Balle::affiche(ostream& os) const{
	cout << get_masse() << " # masse balle" << endl;
    cout << get_rayon() << " # rayon balle" << endl;
    cout << get_masse_volumique() << " # masse volumique balle" << endl;
	cout << get_param() << " # position balle" << endl;
	cout << get_deriveeparam() << " # vitesse balle" << endl;
	cout << get_force() << " # force balle" << endl;
}
//=================================================

std::ostream& operator<<(std::ostream& os, const Balle& b) {
    b.affiche(os);
	return os;
}
