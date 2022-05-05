#include "Pendule.h"
#include "ChampForces.h"
#include "Integrateur.h"
#include "IntegrateurEC.h"
#include <iostream>

using namespace std;

int main(){
cout << "Nous avons:" << endl;
ChampForces c({0, 0, -9.81});
Pendule p1({0.1, {0 ,2.077883668461730 ,0.815787801199423}, {0 ,-0.0070737201667703 ,-0.0997494986604054}, {0, 0 , 0}, 1904}, {0, 2, 1}, {0, 1, 0}, 0.2, 0.005, 0.4, 0, {0.0, 0.0, 0.0});
cout << p1 << endl;
cout << "L'intégration 1 donne:" << endl;
IntegrateurEC e(0.01);
e.evolue(p1);
cout << p1 << endl;

    return 0;
}


