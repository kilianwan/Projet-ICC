#include "Systeme.h"
#include <iostream>

using namespace std;


ostream& Systeme::afficher1(ostream& os) const {
    for (auto const& om : ObjetMobiles){
        om->affiche(os);
    }
}

ostream& Systeme::afficher2(ostream& os) const {
    for (auto const& obs : Obstacles) {
        obs->affiche(os);
    }
}

ostream& Systeme::afficher3(ostream& os) const {
    for (auto const& cf : ChampForce){
        cf->affiche(os);
    }
}

ostream& Systeme::afficher(ostream& os) const{
    afficher1(os);
    afficher2(os);
    afficher3(os);
}

void Systeme::ajouter_objet_mobile(ObjetMobile* om){
    if(om != nullptr){
        ObjetMobiles.push_back(std::unique_ptr<ObjetMobile>(om));
    }
}
void Systeme::ajouter_obstacle(Obstacle* ob){
	if(ob != nullptr) Obstacles.push_back(std::unique_ptr<Obstacle>(ob));
}
void Systeme::ajouter_champ_force(ChampForces* cf){
	if(cf != nullptr) ChampForce.push_back(std::unique_ptr<ChampForces>(cf));
}

void Systeme::evolue() {
	for (auto const& o: ObjetMobiles){
		IEC.evolue(*o);
	}
}	
