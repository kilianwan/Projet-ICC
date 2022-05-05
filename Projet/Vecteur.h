#pragma once
#include <vector>
#include <cmath>

class Vecteur{
	
	public:
//================Constructeurs====================
	Vecteur(size_t n=0);
	Vecteur(double x, double y, double z);
	Vecteur (double x, double y);

//=================================================
	void augmente(double d);
	
	const void set_coord(unsigned int n,double c);
	
	const size_t get_dimension() const;
	
	
	bool operator==(Vecteur const& v1) const;
			
	void operator+=(Vecteur const& v1);
	
	void operator-=(Vecteur const& v1);
	
	Vecteur operator-() const;
	
	std::vector<double> get_vect()const;
	
	const double get_coord(int i) const;
	
	
	void operator ^=(Vecteur v1);
			
	double norme2() const;											
									
	double norme() const;
	
	Vecteur operator~() const;
	
	bool vect_nul();
	
	double somme_vecteurs() const;
	
	private:
	std::vector<double> vecteur;
};

std::ostream& operator<<(std::ostream& os, const Vecteur& v) ;

const Vecteur operator+(Vecteur v1, Vecteur const& v2);

const Vecteur operator-(Vecteur v1, Vecteur const& v2);

const double operator*(Vecteur v1, Vecteur const& v2); 

const Vecteur operator^(Vecteur v1, Vecteur const& v2);

const Vecteur operator*(double x, Vecteur const& v2);

const Vecteur operator*(Vecteur v1, double const& x);

Vecteur orthogonale(const Vecteur& l, const Vecteur& l2);

