#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Vecteur{
	
	public:
	

	void augmente(double d) {
		vecteur.push_back(d);
	}
	
	void set_coord(unsigned int n,double c) {
		vecteur[n]=c;
	}
	
	
	
	size_t get_dimension() const{
		return vecteur.size();
	}
	
	void affiche() const {
		for (size_t i(0); i < vecteur.size(); ++i) {
		
		cout << vecteur[i] << " ";
	}
		cout << endl;
	}
	
	bool compare(Vecteur v1) const {
		int n(vecteur.size());
		int m(v1.get_dimension());
		if(n==m){
			for (int i(0); i < n; ++i){
				if (vecteur[i]!= v1.getvect()[i]) {
					return false;
				}
			}
		return true;
		}
		return false;
	}
	
	/*Vecteur meme_dimension(Vecteur const& v1) {
		int n(vecteur.size());
		int m(v1.get_dimension());
		Vecteur copie;
		if (n>m) {
			copie(v1);
			for (int i(0); i < n-m; ++i){
				augmente(0.0);
			}
		}
		else if (m>n) {
			copie(vecteur);
			for (int i(0); i < m-n; ++i){
				augmente(0);
			}
		}
		return copie;
	}
	*/
			
	Vecteur addition(Vecteur v1) const {
		int n(vecteur.size());
		Vecteur v2;
		for (int i(0); i < n; ++i){										// Lancer une exception, mais indiquer si l'utilisateur veut avoir ses vecteurs de même dimension.
			v2.augmente(vecteur[i] + (v1.getcoord(i)));
		}
		return v2;
			
	}
	
	Vecteur soustraction(Vecteur v1) const {
		int n(vecteur.size());
		Vecteur v2;
		for (int i(0); i < n; ++i){										// Lancer une exception, mais indiquer si l'utilisateur veut avoir ses vecteurs de même dimension.
			v2.augmente(vecteur[i] - (v1.getcoord(i)));
		}
		return v2;
		
	}
	
	Vecteur mult(double x) const {
		int n(vecteur.size());
		Vecteur v2;
		for (int i(0); i < n; ++i) {
			v2.augmente(x*getcoord(i));
		}
		return v2;
	}
	
		
	Vecteur oppose() const {
		return this->mult(-1.0);	
	}
	
	
	
	vector<double> getvect()const {
		return vecteur;
	}
	
	double getcoord(int i) const {
		return getvect()[i];
	}
	
	double prod_scal(Vecteur v1) const {
		double x(0);
		int n(vecteur.size());
		for (int i(0); i < n; ++i) {
			x+= vecteur[i]*v1.getcoord(i);
		}
		return x;
	}
	
	Vecteur prod_vect(Vecteur v1) const {	                            // Lancer exception si la dimension différente de 3
		Vecteur v2;
		v2.augmente(vecteur[1]*v1.getcoord(2) - vecteur[2]*v1.getcoord(1));
		v2.augmente(vecteur[2]*v1.getcoord(0) - vecteur[0]*v1.getcoord(2));
		v2.augmente(vecteur[0]*v1.getcoord(1) - vecteur[1]*v1.getcoord(0));
		
		return v2;		
	}
			
	double norme2() const {												// mucho texto
		return (*this).prod_scal(*this);
	}												
									
	double norme() const{
		return sqrt(norme2());
	}
	
	Vecteur unitaire() const {
		double x(norme());
		return mult(1/x);
		}
		
	
	private:
	vector<double> vecteur;
	
	
	
	
};

int main(){
	
	Vecteur vect1;
Vecteur vect2;
Vecteur vect3;

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

cout << "Vecteur 1 : ";
vect1.affiche();
cout << endl;

cout << "Vecteur 2 : ";
vect2.affiche();
cout << endl;

cout << "Le vecteur 1 est ";
if (vect1.compare(vect2)) {
    cout << "égal au";
} else {
    cout << "différent du";
}
cout << " vecteur 2," << endl << "et est ";
if (not vect1.compare(vect3)) {
    cout << "différent du";
} else {
    cout << "égal au";
}
cout << " vecteur 3." << endl;

cout << "Norme du vecteur" << vect1.norme2();
	
	return 0;
}
