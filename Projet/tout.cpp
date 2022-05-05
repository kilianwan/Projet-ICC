/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <cmath>
#include <memory>

using namespace std;

class Vecteur{

public:

    Vecteur(int n=0): vecteur(std::vector<double>(n)){ }
    Vecteur(double x, double y, double z): vecteur(std::vector<double>({x, y, z})) {}
    Vecteur (double x, double y) : vecteur(std::vector< double> ({x, y})) {}

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

//==========================================================================

class ObjetMobile{

public:

//============= Constructeurs =====================
    ObjetMobile(double r=0.0, Vecteur p={0.0,0.0,0.0}, Vecteur v={0.0,0.0,0.0}, Vecteur f={0.0,0.0,0.0}, double mv=0.0) :rayon(r), P(p), P_prime(v), force(f), masse_volumique(mv)
    {}
//=================================================

//================== Méthodes =====================
    virtual Vecteur evolution() const = 0;
    void agit_sur();
    void dessine_sur();
    void point_plus_proche();
    double distance(const ObjetMobile& v) const;
    void affiche() const;
//=================================================

//================== Accesseurs ===================
    Vecteur get_param() const;
    Vecteur get_deriveeparam() const;
    double get_rayon() const;
    Vecteur get_force() const;
    double get_masse_volumique() const;
    double get_masse() const;
//=================================================

//============== Manipulateurs ====================
    void set_position(Vecteur);
    void set_vitesse(Vecteur);
    void set_rayon(double);
    void set_force(Vecteur);
    void set_masse_volumique(double);
    void ajoute_force(Vecteur const& df) ;
//=================================================


protected:
    double rayon;
    Vecteur P;
    Vecteur P_prime;
    Vecteur force;
    double masse_volumique;

};


std::ostream& operator<<(std::ostream& os, const Vecteur& o);

void ObjetMobile::affiche() const{
    cout << "Position : " << get_param() << ", " << "Vitesse : " << get_deriveeparam();

}

// ================== Méthodes ===================

/*void ObjetMobile::agit_sur(){
	}

void ObjetMobile::dessine_sur(){
}

void ObjetMobile::point_plus_proche(){
}
*/

double ObjetMobile::distance(const ObjetMobile& v) const{
    return (get_param() - v.get_param()).norme();
}
//=================================================

//================== Accesseurs ===================
Vecteur ObjetMobile::get_param() const{
    return P;
}

Vecteur ObjetMobile::get_deriveeparam() const{
    return P_prime;
}

double ObjetMobile::get_rayon() const{
    return rayon;
}
Vecteur ObjetMobile::get_force() const{
    return force;
}
double ObjetMobile::get_masse_volumique() const{
    return masse_volumique;
}

double ObjetMobile::get_masse() const {
    return (get_masse_volumique()*(4.0/3.0)*(M_PI*(get_rayon()*get_rayon()*get_rayon())));
}
//=================================================


//==================== Manipulateurs ==============
void ObjetMobile::set_position(Vecteur p)
{
    P = p;
}
void ObjetMobile::set_vitesse(Vecteur v)
{
    P_prime = v;
}
void ObjetMobile::set_rayon(double r)
{
    rayon= r;

}
void ObjetMobile::set_force(Vecteur f)
{
    force = f;
}
void ObjetMobile::set_masse_volumique(double mv)
{
    masse_volumique = mv;
}
//=================================================


void ObjetMobile::ajoute_force(Vecteur const& df) {
    for (size_t i(0); i < df.get_dimension(); ++i) {
        force.set_coord(i, force.get_coord(i) + df.get_coord(i)) ;
    }
}

//==================== Affiche =====================
std::ostream& operator<<(std::ostream& os, const ObjetMobile& o){
    os <<  "Position : " << o.get_param() << ", " << "Vitesse : " << o.get_deriveeparam();
    return os;
}
//==================================================

//==========================================================================

class Balle : public ObjetMobile{
public:
//============= Constructeurs =====================
    Balle(double r=0.0, Vecteur p={0.0, 0.0, 0.0}, Vecteur v={0.0, 0.0, 0.0}, Vecteur f={0.0, 0.0, 0.0}, double mv=0.0) : ObjetMobile(r, p , v, f, mv)
    {}

//=================================================

//============= Méthodes ==========================

    Vecteur evolution() const override;
    void affiche() const;

//=================================================



};

std::ostream& operator<<(std::ostream& os, const Balle& b) ;
//==========

Vecteur Balle::evolution() const{
    return get_force()*(1/get_masse());
}

void Balle::affiche() const{
    cout << get_masse() << " # masse balle" << endl;
    cout << get_rayon() << " # rayon balle" << endl;
    cout << get_masse_volumique() << " # masse volumique balle" << endl;
    cout << get_param() << " # position balle" << endl;
    cout << get_deriveeparam() << " # vitesse balle" << endl;
    cout << get_force() << " # force balle" << endl;
}
//=================================================

std::ostream& operator<<(std::ostream& os, const Balle& b) {
    os << b.get_masse() << " # masse balle" << endl;
    os << b.get_rayon() << " # rayon balle" << endl;
    os << b.get_masse_volumique() << " # masse volumique balle" << endl;
    os << b.get_param() << " # position balle" << endl;
    os << b.get_deriveeparam() << " # vitesse balle" << endl;
    os << b.get_force() << " # force balle" << endl;

    return os;
}

class Pendule : public ObjetMobile {

public:
    Pendule(Balle bp, Vecteur o={0.0, 0.0, 0.0}, Vecteur d={0.0, 0.0, 0.0}, double l=0.0, double f=0.0, double th=0.0, double thp=0.0, Vecteur u={0.0, 0.0, 0.0} )
            : bout_pendule(bp), origine(o), direction(d), longueur(l), frottement(f), theta(th), theta_point(thp), unitaire(u)
    {}


//================= Méthodes ==========================

    Vecteur evolution() const override;
    Vecteur orthogonale(Vecteur g) const;
    void affiche() const;

//=====================================================

//================= Accesseurs =========================


    double get_longueur() const;
    double get_frottement() const;
    Vecteur get_origine() const;
    Vecteur get_direction() const;
    double get_theta() const;
    double get_theta_point() const;
    Balle get_position_bout() const;

//=====================================================

//================= Manipulateurs =====================

    void set_longueur(double l) ;
    void set_frottement(double f);
    void set_origine(Vecteur o) ;
    void set_direction(Vecteur d) ;
    void set_theta(double t) ;
    void set_theta_point(double t_p) ;
    void set_position_bout(Balle p_b) ;


//=====================================================

protected:
    Balle bout_pendule;
    Vecteur origine;
    Vecteur direction;
    double longueur;
    double frottement;
    double theta;
    double theta_point;
    Vecteur unitaire;
};

//=====================================================



std::ostream& operator<<(std::ostream& os, const Pendule& p);


//=====================================================

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
    //os << p.evolution(0) << "# f() pendule" << endl;


    return os;
}

//==========================================================================

class Obstacle{

public:
    Obstacle(Vecteur p={0.0, 0.0, 0.0}) : position(p) {}

//================ Méthodes =======================
    void affiche() const;
    virtual Vecteur point_plus_proche(const ObjetMobile& o) = 0;
    void agit_sur(const ObjetMobile& o);
    virtual double distance (const ObjetMobile& o) = 0;

//=================================================


//================= Accesseurs ====================

    Vecteur get_position() const;

//=================================================

//=================== Manipulateurs ===============

    void set_position(double p);

//=================================================

protected:
    Vecteur position;


};
std::ostream& operator<<(std::ostream& os, const Obstacle& p) ;

void Obstacle::affiche() const{
    cout << get_position() << endl;
}

void Obstacle::agit_sur(const ObjetMobile& o){
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

class Plan : public Obstacle {

public:
    Plan(Vecteur p = {0.0 ,0.0, 0.0}, Vecteur n = {0.0, 0.0, 0.0}) : Obstacle(p), normale(n) {}

// ================== Méthodes ===================

    void affiche() const;
    double distance(const ObjetMobile& p) override;
    Vecteur point_plus_proche(const ObjetMobile& p) override;

//=================================================


//================== Accesseurs ===================

    Vecteur get_normale() const;

//=================================================


//============== Manipulateurs ====================

    void set_normale(Vecteur u);

//=================================================




private:
    Vecteur normale;

};


std::ostream& operator<<(std::ostream& os, const Plan& p) ;

// ================== Méthodes ===================

void Plan::affiche() const{
    cout << get_position() << "#origine plan" << endl;
    cout << get_normale() << "#normale plan" << endl;
}

Vecteur Plan::point_plus_proche(const ObjetMobile& p){
    return p.get_param() + normale*((normale*(position - p.get_param())));
}

double Plan::distance(const ObjetMobile& p) {
    return (p.get_param() - point_plus_proche(p)).norme() - p.get_rayon();
}

//=================================================

//================== Accesseurs ===================

Vecteur Plan::get_normale() const{
    return normale;
}

//=================================================


//============== Manipulateurs ====================

void Plan::set_normale(Vecteur n){
    normale = n;
}

//=================================================

std::ostream& operator<<(std::ostream& os, const Plan& p){
    os << p.get_position() << "#origine plan" << endl;
    os << p.get_normale() << "#normale plan" << endl;

    return os;

}


//==================================================================================================





//==================================================================================================


class Brique : public Obstacle{

public:
    Brique(Vecteur p= {0.0, 0.0, 0.0}, Vecteur l={0.0, 0.0, 0.0}, Vecteur la= {0.0, 0.0, 0.0}, double h=0.0) :Obstacle(p), longueur(l), largeur(orthogonale(l, la)), hauteur(h*(~(longueur^largeur)).norme()) {}

// ================== Méthodes ===================

    void affiche() const;
    Vecteur o_hauteur();
    Vecteur point_plus_proche(const ObjetMobile& o) override;
    double distance(const ObjetMobile& o) override;
    Vecteur coordonnes(const ObjetMobile& o, Vecteur x);

//=================================================


//================== Accesseurs ===================

    Vecteur get_longueur() const;
    Vecteur get_largeur() const;
    double get_hauteur() const;
    Vecteur normale() const;

//=================================================


//============== Manipulateurs ====================

    void set_longueur(Vecteur);
    void set_largeur(Vecteur);
    void set_hauteur(double);

//=================================================


private:
    Vecteur longueur;
    Vecteur largeur;
    double hauteur;


};

std::ostream& operator<<(std::ostream& os, const Brique& b) ;


// ================== Méthodes ===================

void Brique::affiche() const {
    cout << get_position() << " #origine brique" << endl;
    cout << get_longueur() << " #longueur brique" << endl;
    cout << get_largeur() << " #largeur brique" << endl;
    cout << get_hauteur() << " #hauteur brique" << endl;
}


Vecteur Brique::o_hauteur(){
    Vecteur eh = (longueur^largeur);
    return hauteur*(~eh);
}


double Brique::distance(const ObjetMobile& p) {
    return (p.get_param() - point_plus_proche(p)).norme() - p.get_rayon();
}

Vecteur Brique::point_plus_proche(const ObjetMobile& o){

    Vecteur eL = ~(orthogonale(normale(), get_longueur()));
    Vecteur el = ~(normale() ^ eL);
    Vecteur n = ~normale();
    Plan p1(get_position(), n);
    Plan p2(get_position(), -el);
    Plan p3(get_position(), -eL);
    Plan p4(get_position() + (get_longueur()).norme()*eL, eL);
    Plan p5(get_position() + ((get_largeur()).norme())*el, el);
    Plan p6(get_position() - (get_hauteur())*n, -n);


    vector<Vecteur> plans={p1.point_plus_proche(o),p2.point_plus_proche(o),p3.point_plus_proche(o),p4.point_plus_proche(o),p5.point_plus_proche(o),p6.point_plus_proche(o)};
    Vecteur point_opti=coordonnes(o, (plans[0]));


    for(size_t i(0) ; i < plans.size() -1; i++){
        if ((((plans[i+1]) - o.get_param()).norme()) < (((plans[i]) - o.get_param()).norme()) ){
            point_opti =coordonnes(o, (plans[i+1]));
        }
    }

    return point_opti;
}
//=================================================


//================== Accesseurs ===================

Vecteur Brique::get_longueur() const{
    return longueur;
}
Vecteur Brique::get_largeur() const{
    return largeur;
}
double Brique::get_hauteur() const{
    return hauteur*((~(longueur^largeur)).norme());
}
Vecteur Brique::normale() const{
    return orthogonale(get_longueur(), get_largeur());
}
//=================================================


//============== Manipulateurs ====================

void Brique::set_longueur(Vecteur lo){
    longueur = lo;
}
void Brique::set_largeur(Vecteur la){
    largeur = la;
}
void Brique::set_hauteur(double h){
    hauteur = h;
}

//=================================================

//==================================================================================================

Vecteur Brique::coordonnes(const ObjetMobile& o, Vecteur x){
    Vecteur eL = ~(orthogonale(normale(), get_longueur()));
    Vecteur el = ~(normale() ^ eL);
    double xL = (x - get_position())*eL;
    if (xL > get_longueur().norme()) x = x - (xL - get_longueur())*eL;
    else if (xL < 0) x = x - xL*eL;
    double xl = (x - get_position())*el;
    if (xl > get_largeur().norme()) x = x - (xl - get_largeur())*el;
    else if (xl < 0) x = x - xl*el;

    return x;
}

//==================================================================================================




std::ostream& operator<<(std::ostream& os, const Brique& b){

    os << b.get_position() << " #origine brique" << endl;
    os << b.get_longueur() << " #longueur brique" << endl;
    os << b.get_largeur() << " #largeur brique" << endl;
    os << b.get_hauteur() << " #hauteur brique" << endl;

    return os;


}



//==================================================================================================


class ChampForces {

public:
    ChampForces(Vecteur i={0.0, 0.0, 0.0}) : intensite(i) {}

    void affiche() const;
    void agit_sur(ObjetMobile& b);

    Vecteur get_intensite() const;

private:
    Vecteur intensite;

};


std::ostream& operator<<(std::ostream& os, const ChampForces& cf) ;

double distance(ChampForces c, ObjetMobile const& b);

void ChampForces::affiche() const {
    cout << get_intensite() << "# intensite ";
}

void ChampForces::agit_sur(ObjetMobile& b) {
    Vecteur f(0, 0, (b.get_masse() - 4*M_PI*1.2*pow(b.get_rayon(),3)/3)*(-9.81));
    b.set_force(b.get_force() + f);
}

double distance(ChampForces c, ObjetMobile const& b){
    return (c.get_intensite() -b.get_param()).norme();

}

Vecteur ChampForces::get_intensite() const{
    return intensite;
}


std::ostream& operator<<(std::ostream& os, const ChampForces& cf){

    os << cf.get_intensite() << "# intensite ";
    return os;

}

//==================================================================================================


class Integrateur {

public:
    Integrateur(double t=0.0) : dt(t)
    {}

    virtual void evolue(ObjetMobile& o) const = 0;

    double get_dt() const;



protected:
    double dt;

};


double Integrateur::get_dt() const{
    return dt;
}

class IntegrateurEC : public Integrateur {

public:
    IntegrateurEC(double dt) : Integrateur(dt)
    {}

    void evolue(ObjetMobile& o) const override;

protected:


};


//======================================================

void IntegrateurEC::evolue(ObjetMobile& o) const {

    cout << o.get_deriveeparam() + get_dt()*o.evolution() << endl;
    cout << o.get_param()+ get_dt()*o.get_deriveeparam() << endl;

    o.set_vitesse(o.get_deriveeparam() + get_dt()*o.evolution());
    o.set_position(o.get_param()+ get_dt()*o.get_deriveeparam());




}


class SupportADessin {

public:
    virtual ~SupportADessin() = default;

    //virtual void dessine(Systeme  const&) = 0;
    //virtual void dessine(Balle const&) = 0;


};




class Dessinable{

    virtual void dessine_sur(SupportADessin& support);


};

void Dessinable::dessine_sur(SupportADessin& support) {
    //support.dessine(*this);
}

class Systeme {

    void afficher1() const;
    void afficher2() const;
    void afficher3() const;

    void ajouter_objet_mobile(ObjetMobile* om);
    void ajouter_obstacle(Obstacle* ob);
    void ajouter_champ_force(ObjetMobile* cf);

private:
    std::vector<std::unique_ptr<ObjetMobile>> ObjetMobiles;
    std::vector<std::unique_ptr<Obstacle>> Obstacles;
    std::vector<std::unique_ptr<ChampForces>> ChampForce;


};

void Systeme::afficher1() const {

    for (auto const& om : ObjetMobiles){
        om->affiche();
    }
}

void Systeme::afficher2() const {
    for (auto const& obs : Obstacles) {
        obs->affiche();
    }
}

void Systeme::afficher3() const {
    for (auto const& cf : ChampForce){
        cf->affiche();
    }
}


void Systeme::ajouter_objet_mobile(ObjetMobile* om){
    if(om != nullptr){
        ObjetMobiles.push_back(std::unique_ptr<ObjetMobile>(om));
    }
}

/*
	void ajouter_obstacle(Obstacle* ob){
	if(ob != nullptr) Obstacles.push_back(std::unique_ptr<Obstacle>(ob));
}
	void ajouter_champ_force(ObjetMobile* cf){
	if(cf != nullptr) ChampForce.push_back(std::unique_ptr<ChampForces>(cf));
}

*/


//==================================================================================================


int main(){

    Pendule p1({0.1, {0 ,1.599498997320811 ,0.435852559666459}, {0 ,-0.0070737201667703 ,-0.0997494986604054}, {0, -0.073322623865539 , -0.963268946241630}, 190.985931710274}, {0, 1.4, 0.45}, {0, 1, 0}, 0.2, 0.005, 1.5, -0.5, {0.0, 0.0, 0.0});

    ChampForces c1({0, 0, -9.81});
    cout << "Nous avons: " << endl;
    cout << "un champ de force : " << endl;
    cout << c1 << endl;
    cout << "un pendule " << endl;
    cout << p1 << endl;

    Plan p2({0, 0, 0}, {0, 0, 1});
    Brique b1({0, 0, 0.5}, {0, -0.6, 0}, {0.8, 0, 0}, 0.5);

    Balle b(0.2, {1.2, -0.4, 0.3}, {0, 0, 0}, {0, 0, -0.591725259488945}, 3);

    cout << "Nous avons :" << endl;
    cout << "un mur brique" << endl;
    cout << b1 << endl;

    cout << "une balle" << endl;
    cout << b << endl;

    cout << "tests" << endl;
    cout << p2.point_plus_proche(b) << endl;
    cout << p2.distance(b) << endl;
    cout << b1.point_plus_proche(b) << endl;
    cout << b1.distance(b) << endl;
//
//
/*
cout << "Je déplace la balle en 0.2 ... " << endl;
b.set_position({0.2, -0.4, 1.3});
cout << "tests pour la balle déplacée" << endl;
cout << p2.point_plus_proche(b) << endl;
cout << p2.distance(b) << endl;
*/
/*cout << "tests" << endl;
cout << b1.point_plus_proche(b) << endl;
cout << b1.distance(b) << endl;

c1.agit_sur(b);
cout << b.get_force() << endl;


cout << " Nouvelle Balle " << endl;
Balle balle(0.2, {0.0, 0.0, 0.0}, {0.0, 0.1, 0.2}, {0.0, 0.0, -0.591725259488945}, 3);
cout << balle << endl;
IntegrateurEC ec(0.01);
ec.evolue(balle);
cout << balle << endl;
ec.evolue(balle);
cout << balle << endl;
*/
    return 0;
}




