#include <iostream>
#include <vector>
#include <cmath>
#include "Vecteur.h"


using namespace std;


int main(){
	
	Vecteur vect1;
	Vecteur vect2;
	Vecteur vect3;
	Vecteur vect4;
	Vecteur vect5(5);
	Vecteur vect6(0.1, -5, 10);

/* Cette partie
 * (1) pourrait être écrite autrement, par exemple avec des
 *     manipulateurs (set_coord()) ;
 * (2) sera revue dans 2 semaines (constructeurs, surcharge des opérateurs).
 */
// v1 = (1.0, 2.0, -0.1)
vect1.augmente(1.0); vect1.augmente(0.0); vect1.augmente(-0.1);
vect1.set_coord(1, 2.0); // pour tester set_coord()

// v2 = (2.6, 3.5,  4.1)
vect2.augmente(2.6); vect2.augmente(3.5); vect2.augmente(4.1);

vect3 = vect1;

cout << "Vecteur 1 : " << vect1;
cout << endl;

cout << "Vecteur 2 : " << vect2;
cout << endl;

cout << "Le vecteur 1 est ";
if (vect1 == vect2) {
    cout << "égal au";
} else {
    cout << "différent du";
}
cout << " vecteur 2," << endl << "et est ";
if (not (vect1 == vect3)){
    cout << "différent du";
} else {
    cout << "égal au";
}
cout << " vecteur 3." << endl;

cout << "Norme du vecteur" << vect1.norme2() << endl;

vect4.augmente(1.0); vect4.augmente(5.0);
cout << "Le produit vectoriel est égal à :" << (vect4 ^ vect1);
cout << endl;
 
cout << "Le produit vectoriel est égal à :" << (vect2 ^ vect1) << endl;
 
cout << "Somme nulle : " << vect5 + vect5;

cout << "Produit nul : "  << vect5*vect1 << endl;

cout << "Soustraction : " << vect5 - vect6;
cout << endl;

cout << "Somme et soustraction : " << vect2 + vect1 - vect3;
cout << endl;

cout << "Opposé : " << - vect1;

cout << "La norme est :" << (vect1).norme2() << endl;

cout << "Somme et opposé :" << -vect1 + vect2*3;
cout << endl;


cout << "Vecteur 1 :" << vect1 << endl;

Vecteur a(1., 2.5, -3.4);
Vecteur direction( ~a );
cout << direction << endl;
	
	
vect1 += vect2;
cout << "Vecteur 1 :" << vect1 << endl;

cout << 3*vect1 << endl;

	return 0;
}
