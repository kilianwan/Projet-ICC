#include <iostream>
#include <vector>
#include <cmath>
#include "Vecteur.h"
#include "ObjetMobile.h"
#include "Pendule.h"
#include "ChampForces.h"

using namespace std;

int main() {
	
ChampForces c1;
Pendule p1(0.1, 0.2, 0.005, {0, 2 , 1}, {0, 1, 0}, 0.4, 0, {0, 2.077883668461730, 0.815787801199423});

	
	
cout << "Nous avons :" << endl;
cout << "un champ de force :" << endl;

cout << "un pendule" << endl;
cout << p1 << endl;


	
	
	
	
	
	return 0;
}
