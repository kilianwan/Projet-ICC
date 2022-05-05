#include <iostream>
#include <vector>
#include "Vecteur.h"
#include "Obstacles.h"

using namespace std;




void Obstacle::agit_sur(const ObjetMobile& o){
	Vecteur fn1;
}


Vecteur Obstacle::get_position() const{
	return position;
}
	
void Obstacle::set_position(double p){
	position = p;
}
std::ostream& operator<<(std::ostream& os, const Obstacle& p) {
	os << p.get_position() << endl;
    return os;
}

//==========================================================================
