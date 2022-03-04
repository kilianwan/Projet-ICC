# Projet-ICC

#include <iostream>
#include <vector>

using namespace std;


class Vecteur{
	
	public:
	

	void augmente(double d) {
		vecteur.push_back(d);
	}
	
	void set_coord(unsigned int n,double c) {
		vecteur[n]=c;
	}
	
	double get_coord(unsigned int n) const {
		return vecteur[n];
	}
	
	size_t get_dimension() const{
		return vecteur.size();
	}
	
	void affiche() const {
		cout << "Vecteur ";
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
				if (vecteur[i]!= v1.get_coord(i)) {
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
			v2.set_coord(i, vecteur[i] + v1.get_coord(i));
		}
		return v2;
			
	}
	
	Vecteur soustraction(Vecteur v1) {
		int n(vecteur.size());
		Vecteur v2;
		for (int i(0); i < n; ++i){
			v2.set_coord(i, vecteur[i] - v1.get_coord(i));
		}
		return v2;
		
	}
	
	Vecteur mult(double x) const {
		int n(vecteur.size());
		Vecteur v2;
		for (int i(0); i < n; ++i) {
			v2.set_coord(i, x*get_coord(i));
		}
		return v2;
	}
	
		
	Vecteur oppose() {
		return this->mult(-1.0);	
	}

	
	private:
	vector<double> vecteur;
	
	
};



int main(){
	
	Vecteur v1, v2;
	
	
	
	return 0;
}
