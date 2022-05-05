#pragma once
#include "ObjetMobile.h"
#include "ChampForces.h"
#include "Obstacles.h"
#include <iostream>
#include "IntegrateurEC.h"

class Systeme {

    ostream& afficher1(ostream& os) const;
    ostream& afficher2(ostream& os) const;
    ostream& afficher3(ostream& os) const;
    ostream& afficher(ostream& os) const;

    void ajouter_objet_mobile(ObjetMobile* om);
    void ajouter_obstacle(Obstacle* ob);
    void ajouter_champ_force(ChampForces* cf);
    
    void evolue();

private:
    std::vector<std::unique_ptr<ObjetMobile>> ObjetMobiles;
    std::vector<std::unique_ptr<Obstacle>> Obstacles;
    std::vector<std::unique_ptr<ChampForces>> ChampForce;
    IntegrateurEC IEC;
};
