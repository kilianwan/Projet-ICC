#pragma once
#include <vector>
#include "Vecteur.h"
#include "ObjetMobile.h"



class Balle : public ObjetMobile{
public:
//============= Constructeurs =====================
Balle(double r=0.0, Vecteur p={0.0, 0.0, 0.0}, Vecteur v={0.0, 0.0, 0.0}, Vecteur f={0.0, 0.0, 0.0}, double mv=0.0) : ObjetMobile(r, p , v, f, mv) 
{}

//=================================================

//============= Méthodes ==========================

Vecteur evolution() const override;
ostream& affiche(ostream& os) const;

//=================================================

};

std::ostream& operator<<(std::ostream& os, const Balle& b) ;
//==========
