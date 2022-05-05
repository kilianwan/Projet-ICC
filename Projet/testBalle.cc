#include <iostream>
#include <vector>
#include <cmath>
#include "Vecteur.h"
#include "Balle.h"
#include "ObjetMobile.h"
#include "ChampForces.h"


using namespace std;

int main(){
	
	Balle balle1(0.2, {1,2,3}, {0, 0.1, 0.2}, {0,0,0}) ; 
	balle1.ajoute_force({0.0, 0.0, -9.81});
	
	Balle balle2(0.1, {-1,1.2,1.3}, {0,0.1,0}, {0,0,0});
	balle2.set_masse_volumique(1.1);
	Balle b1;
	Balle b2;
	ChampForces c1({0, 0, -9.81});

cout << "Nous avons :" << endl;
cout << "un champs de force :" << endl;

c1.agit_sur(balle2);

//affiche plutôt ? quelles conditions ?
cout << "une balle :" << endl; 
cout << balle1 << endl;

cout << "et une autre balle :" << endl;
cout << balle2 << endl;

cout << "Distance :" << balle1.distance(balle2) << endl;
}
