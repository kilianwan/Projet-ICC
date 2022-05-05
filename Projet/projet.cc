#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Vecteur{
	
	public:
	
	Vecteur(int n=0): vecteur(std::vector<double>(n)){ }
	Vecteur(double x, double y, double z): vecteur(std::vector<double>({x, y, z})) {}
	
	
	void augmente(double d);
	
	void set_coord(unsigned int n,double c);
	
	
	size_t get_dimension() const;
	
	void affiche() const;
	
	bool operator ==(Vecteur v1) const;
			
	Vecteur addition(Vecteur v1) const;
	
	Vecteur soustraction(Vecteur v1) const;
	
	Vecteur mult(double x) const;
	
		
	Vecteur oppose() const;
	
	std::vector<double> get_vect()const;
	
	double get_coord(int i) const;
	
	double prod_scal(Vecteur v1) const;
	
	Vecteur operator ^(Vecteur v1) const;
			
	double norme2() const;											
									
	double norme() const;
	
	Vecteur unitaire() const;
	
	bool vect_nul();
	
	private:
	std::vector<double> vecteur;
};


/*======================================================================
Définitions des méthodes
=======================================================================*/

void Vecteur::augmente(double d) {
	vecteur.push_back(d);
}

void Vecteur::set_coord(unsigned int n,double c) {
		vecteur[n]=c;
	}

size_t Vecteur::get_dimension() const{
		return vecteur.size();
	}

void Vecteur::affiche() const {
		for (size_t i(0); i < vecteur.size(); ++i) {
		
		cout << vecteur[i] << " ";
	}
		cout << endl;
	}


bool Vecteur::operator ==(Vecteur v1) const {
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

Vecteur Vecteur::addition(Vecteur v1) const {
		int n(vecteur.size());
		Vecteur resultat;
		/*try {
			size_t p(vecteur.size()); //m(v1.get_dimension());
			if (p==0)
				throw v1;
			if (m==0)
				throw vecteur;
				*/
			for (int i(0); i < n; ++i){										// Lancer une exception, mais indiquer si l'utilisateur veut avoir ses vecteurs de même dimension.
				resultat.augmente(vecteur[i] + (v1.get_coord(i)));
			}
		/*
		catch( const Vecteur* v)
		{
			return v1;
		}
		*/
		return resultat;
			
	}

Vecteur Vecteur::soustraction(Vecteur v1) const {
		int n(vecteur.size());
		Vecteur resultat;
		for (int i(0); i < n; ++i){										// Lancer une exception, mais indiquer si l'utilisateur veut avoir ses vecteurs de même dimension.
			resultat.augmente(vecteur[i] - (v1.get_coord(i)));
		}
		return resultat;
		
	}

Vecteur Vecteur::mult(double x) const {
		int n(vecteur.size());
		Vecteur resultat;
		for (int i(0); i < n; ++i) {
			resultat.augmente(x*get_coord(i));
		}
		return resultat;
	}

Vecteur Vecteur::oppose() const {
		return (*this).mult(-1.0);	
	}

vector<double> Vecteur::get_vect()const {								// Fonction qui renvoie le vecteur en entier
		return vecteur;
	}
	
double Vecteur::get_coord(int i) const {								// Fonction qui renvoie la valeur d'une coordonnée du vecteur
		return get_vect()[i];
	}
	
double Vecteur::prod_scal(Vecteur v1) const {
		double scalaire(0);
		int n(vecteur.size());
		for (int i(0); i < n; ++i) {
			scalaire+= vecteur[i]*v1.get_coord(i);
		}
		return scalaire;
	}
	
Vecteur Vecteur::operator ^(Vecteur v1) const {	                        // Lancer exception si la dimension différente de 3
		Vecteur resultat;
		try      {	
			size_t n(vecteur.size()), m(v1.get_dimension());
			if ((n!= 3) and (m!=2))
				throw "Le produit vectoriel n'est pas défini pour des vecteurs de dimension différente de 3. Prenez des bons vecteurs!" ;
			
		
		resultat.augmente(vecteur[1]*v1.get_coord(2) - vecteur[2]*v1.get_coord(1));
		resultat.augmente(vecteur[2]*v1.get_coord(0) - vecteur[0]*v1.get_coord(2));
		resultat.augmente(vecteur[0]*v1.get_coord(1) - vecteur[1]*v1.get_coord(0));
			}
		catch(const char* pv){
			cout << pv << endl;
		}
		return resultat;		
	}
	
double Vecteur::norme2() const {										// Pour la norme au carré on fait juste le produit scalaire du vecteur avec lui même
		return (*this).prod_scal(*this);
	}												
									
double Vecteur::norme() const{											// Pour la norme on fait la racine de la norme au carré en utilisant "sqrt" de <cmath>
		return sqrt(norme2());
	}
	
Vecteur Vecteur::unitaire() const {
		double x(norme());
		return mult(1/x);
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
	
//======================================================================

int main(){
	
	Vecteur vect1;
	Vecteur vect2;
	Vecteur vect3;
	Vecteur vect4;

/*Cette partie
 * (1) pourrait être écrite autrement, par exemple avec des
 *     manipulateurs (set_coord()) ;
 * (2) sera revue dans 2 semaines (constructeurs, surcharge des opérateurs).
 */
//v1 = (1.0, 2.0, -0.1)
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
if (vect1 == vect2) {
    cout << "égal au";
} else {
    cout << "différent du";
}
cout << " vecteur 2," << endl << "et est ";
if (not (vect1 == vect3)) {
    cout << "différent du";
} else {
    cout << "égal au";
}
cout << " vecteur 3." << endl;

cout << "Norme du vecteur" << vect1.norme2() << endl;

vect4.augmente(1.0); vect4.augmente(5.0);
cout << "Le produit vectoriel est égal à :";
 (vect4^vect1).affiche();
cout << endl;
 
cout << "Le produit vectoriel est égal à :";
(vect2 ^ vect1).affiche();
 

/*
// un vecteur en 3D :
Vecteur vect1(1.0, 2.0, -0.1);

// un autre vecteur en 3D
Vecteur vect2(2.6, 3.5,  4.1);

Vecteur vect3(vect1);  // copie de V1
Vecteur vect4(4);      // le vecteur nul en 4D
*/
cout << " ... " << endl;
/*cout << "Vecteur 1 : " << vect1 << endl;
cout << "Vecteur 2 : " << vect2 << endl;
cout << "Vecteur 3 : " << vect3 << endl;
cout << "Vecteur 4 : " << vect4 << endl;

cout << "Le vecteur 1 est ";
if (vect1 == vect2) {
    cout << "égal au";
} else {
    cout << "différent du";
}
cout << " vecteur 2," << endl << "et est ";
if (!(vect1 == vect3)) {
    cout << "différent du";
} else {
    cout << "égal au";
}
cout << " vecteur 3." << endl; 
*/

	
	return 0;
}
