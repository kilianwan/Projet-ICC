#include <iostream>
#include <vector>
#include "Vecteur.h"
#include "ObjetMobile.h"
#include "Pendule.h"

using namespace std;


//================= Méthodes ==========================

	void Pendule::affiche() const { 
	cout << get_origine() << "# origine pendule" << endl;
	cout << get_direction() << "# direction pendule" << endl;
    cout << get_longueur() << "# longueur pendule" << endl;
    cout << get_frottement() << "# frottement pendule" << endl;
	cout << (get_position_bout()).get_masse() << "# masse bout pendule" << endl;
	cout << (get_position_bout()).get_rayon() << "# rayon bout pendule" << endl;
	cout << (get_position_bout()).get_masse_volumique() << "# masse volumique bout pendule" << endl;
	cout << (get_position_bout()).get_param() << "# position bout pendule" << endl;
	cout << (get_position_bout()).get_deriveeparam() << "# vitesse bout pendule" << endl;
	cout << (get_position_bout()).get_force() << "# force bout pendule " << endl;
	cout << get_theta() << "# angle pendule" << endl;
	cout << get_theta_point() << "# vitesse angulaire pendule" << endl;
	//os << p.evolution(0) << "# f() pendule" << endl;
}

	Vecteur Pendule::evolution() const{
		return (1/(get_position_bout().get_masse()*get_longueur()) *(cos(get_theta())*get_force()*(~orthogonale({0.0 ,0.0, -9.81})) - sin(get_theta())*(get_position_bout().get_force()*~(Vecteur({0.0, 0.0 ,-9.81}))) - (get_frottement()/(get_longueur())*get_theta_point())));
	}
	
	Vecteur Pendule::orthogonale(Vecteur g) const{
		return unitaire - (unitaire*~g)*~g;
	}
	
//=====================================================
	
	
//================= Accesseurs =========================	


	double Pendule::get_longueur() const{
		return longueur;
	}
	double Pendule::get_frottement() const{
		return frottement;
	}
	Vecteur Pendule::get_origine() const{
		return origine;
	}
	Vecteur Pendule::get_direction() const{
		return direction;
	}
	double Pendule::get_theta() const{
		return theta;
	}
	double Pendule::get_theta_point() const{
		return theta_point;
	}
	Balle Pendule::get_position_bout() const{
		return bout_pendule;
	}
//=====================================================


//================= Manipulateurs =====================

	
	void Pendule::set_longueur(double l) {
		longueur=l;
	}
	void Pendule::set_frottement(double f) {
		frottement = f;
	}
	void Pendule::set_origine(Vecteur o) {
		origine=o;
	}
	void Pendule::set_direction(Vecteur d) {
		direction=d;
	}
	void Pendule::set_theta(double t)  {
		theta=t;
	}
	void Pendule::set_theta_point(double t_p)  {
		theta_point=t_p;
	}
	void Pendule::set_position_bout(Balle p_b)  {
		bout_pendule=p_b;
	}

//=================================================

//=================================================
std::ostream& operator<<(std::ostream& os, const Pendule& p){
    
	os << p.get_origine() << "# origine pendule" << endl;
	os << p.get_direction() << "# direction pendule" << endl;
    os << p.get_longueur() << "# longueur pendule" << endl;
    os << p.get_frottement() << "# frottement pendule" << endl;
	os << (p.get_position_bout()).get_masse() << "# masse bout pendule" << endl;
	os << (p.get_position_bout()).get_rayon() << "# rayon bout pendule" << endl;
	os << (p.get_position_bout()).get_masse_volumique() << "# masse volumique bout pendule" << endl;
	os << (p.get_position_bout()).get_param() << "# position bout pendule" << endl;
	os << (p.get_position_bout()).get_deriveeparam() << "# vitesse bout pendule" << endl;
	os << (p.get_position_bout()).get_force() << "# force bout pendule " << endl;
	os << p.get_theta() << "# angle pendule" << endl;
	os << p.get_theta_point() << "# vitesse angulaire pendule" << endl;
	os << p.evolution() << "# f() pendule" << endl;

	
	return os;
}

//==========================================================================
