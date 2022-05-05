#include <iostream>
#include <vector>
#include <cmath>
#include "Vecteur.h"

using namespace std;

void Vecteur::augmente(double d) {
	vecteur.push_back(d);
}

const void Vecteur::set_coord(unsigned int n,double c) {
		vecteur[n]=c;
	}

const size_t Vecteur::get_dimension() const{
		return vecteur.size();
	}
	
vector<double> Vecteur::get_vect()const {								// Fonction qui renvoie le vecteur en entier
		return vecteur;
	}

bool Vecteur::operator ==(Vecteur const& v1) const {
		int n(vecteur.size());
		int m(v1.get_dimension());
		if(n==m){
			for (int i(0); i < n; ++i){
				if (vecteur[i]!= v1.get_vect()[i]) { 
					return false;
				}
			}
		return true;
		}
		return false;
	}

void Vecteur::operator+=(Vecteur const& v1) {
		int n(vecteur.size());
		try {
			size_t p(vecteur.size());
			size_t m(v1.get_dimension());
			if (p!=m)
				throw "Erreur dans la somme. Les vecteurs ne sont pas de même dimension.";
			
				for (int i(0); i < n; ++i){										// Lancer une exception, mais indiquer si l'utilisateur veut avoir ses vecteurs de même dimension.
					vecteur[i] =vecteur[i] + v1.get_coord(i);
				}
			}
		
			catch(const char* t)
		{
			cout << t << endl;
		}	
			
	}

void Vecteur::operator-=(Vecteur const& v1) {
		int n(vecteur.size());
		try {
			size_t p(vecteur.size());
			size_t m(v1.get_dimension());
			if (p!=m)
				throw "Erreur dans la soustraction. Les vecteurs ne sont pas de même dimension.";
			
				for (int i(0); i < n; ++i){										// Lancer une exception, mais indiquer si l'utilisateur veut avoir ses vecteurs de même dimension.
					vecteur[i] =vecteur[i] - v1.get_coord(i);
				}
			}
		
			catch(const char* t)
		{
			cout << t << endl;
		}
		
	}
	

Vecteur Vecteur::operator-() const {
		return (*this)*(-1.0);	
	}


	
const double Vecteur::get_coord(int i) const {								// Fonction qui renvoie la valeur d'une coordonnée du vecteur
		return get_vect()[i];
	}
	

	
void Vecteur::operator^=(Vecteur v1) {	                        
		Vecteur resultat;
		try      {	
			size_t n(vecteur.size()), m(v1.get_dimension());
			if ((n!= 3) and (m!=2))
				throw "Le produit vectoriel n'est pas défini pour des vecteurs de dimension différente de 3. Prenez des bons vecteurs!" ;
			
		resultat.augmente((vecteur[1]*v1.get_coord(2) - vecteur[2]*v1.get_coord(1)));
		resultat.augmente((vecteur[2]*v1.get_coord(0) - vecteur[0]*v1.get_coord(2)));
		resultat.augmente((vecteur[0]*v1.get_coord(1) - vecteur[1]*v1.get_coord(0)));
		v1=resultat;
			}
		catch(const char* pv){
			cout << pv << endl;
		}	
	}
	
double Vecteur::somme_vecteurs() const{
	double somme(0);
	for (int i(0); i < (*this).get_dimension(); ++i){
		
		somme += vecteur[i]*vecteur[i];
		
	}
	return somme;
}
	
double Vecteur::norme2() const{		
	return somme_vecteurs();
	}												
									
double Vecteur::norme() const{											// Pour la norme on fait la racine de la norme au carré en utilisant "sqrt" de <cmath>
		return sqrt(norme2());
	}
	
Vecteur Vecteur::operator~() const {
		double x(norme());
		return (*this)*(1/x);
		}

ostream& operator<<(ostream& os, const Vecteur& v){
			for (size_t i(0); i < v.get_dimension(); ++i){
			os << v.get_coord(i) << " ";
		}
			
    return os;
}

//======================================================================


//======================================================================

const Vecteur operator+(Vecteur v1, Vecteur const& v2){
	try{
		if (v1.get_dimension()==0) return v2;
		if (v2.get_dimension()==0) return v1;
		if (v1.get_dimension() != v2.get_dimension())
			throw "Erreur dans la somme. Les vecteurs ne sont pas de même dimension. ";
		
			v1 += v2;
		}
		
		catch(const char* t)
		{
			cout << t << endl;
		}
	
	return v1;
}



const Vecteur operator-(Vecteur v1, Vecteur const& v2){
	try{
		if (v1.get_dimension()==0) return v2;
		if (v2.get_dimension()==0) return v1;
		if (v1.get_dimension() != v2.get_dimension())
			throw "Erreur dans la somme. Les vecteurs ne sont pas de même dimension. ";
		
			v1 -= v2;
		}
		catch(const char* t)
		{
			cout << t << endl;
		}
	
	return v1;
	
}

const double operator*(Vecteur v1, Vecteur const& v2) {
 		double scalaire(0);
 		try {
 			size_t p(v1.get_dimension());
 			size_t m(v2.get_dimension());
 			if (p!=m) 
 			throw "Erreur dans le produit scalaire! Les vecteurs ne sont pas de même dimension.";

 			for (int i(0); i < p; ++i) {
 				scalaire+= v1.get_coord(i)*v2.get_coord(i);
 			}
 		}
 		catch(const char* t)
 		{
 			cout << t << endl;
 		}

 		return scalaire;
 
}



const Vecteur operator^(Vecteur v1, Vecteur const& v2){
	
	v1 ^= v2;
	return v1;	
}


const Vecteur operator*(Vecteur v1, double const& x){
	Vecteur resultat;
	for (int i(0); i < v1.get_dimension() ; ++i){
		resultat.augmente(x*v1.get_coord(i));
	}
	
	return resultat;
	
	
}

const Vecteur operator*(double x, Vecteur const& v2){
	Vecteur resultat;
	for (int i(0); i < v2.get_dimension(); ++i) {
		resultat.augmente(x*v2.get_coord(i));
	}
	return resultat;
}



Vecteur orthogonale(const Vecteur& l, const Vecteur& l2){
		if ((l*l2)==0) return l2;
			else return l2 - (l2*(~l))*(~l);
	}
	
Vecteur::Vecteur(size_t n) {
	for (size_t i(0); i < n; ++i) augmente(0);
}
Vecteur::Vecteur(double x, double y, double z){
	augmente(x);
	augmente(y);
	augmente(z);
}
Vecteur::Vecteur(double x, double y){
	augmente(x);
	augmente(y);
}

//==========================================================================
