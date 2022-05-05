#include "Obstacles.h"
#include "ObjetMobile.h"
#include "Plan.h"
#include "Brique.h"
#include "Balle.h"
#include <iostream>

int main(){

cout << "Nous avons:" << endl;
cout << "un mur plan" << endl;
Plan p1({0.0, 0.0, 0.0}, {0.0, 0.0, 1.0});
cout << p1 << endl;
cout << "un mur brique" << endl;
Brique b1({0.0, 0.0, 0.5}, {0, -0.6, 0}, {0.8, 0, 0}, 0.5);
cout << b1 << endl;
cout << "une balle" << endl;
Balle balle1(0.2, {1.2, -0.4, 0.3}, {0, 0, 0}, {0, 0, -0.591725259488945}, 3);
cout << balle1 << endl;
cout << "tests: " << endl;
cout << p1.point_plus_proche(balle1) << endl;
cout << p1.distance(balle1) << endl;
cout << b1.point_plus_proche(balle1) << endl;
cout << "je déplace la balle en : 1.2 -0.4 1.3" << endl;
balle1.set_position({1.2, -0.4, 1.3});
cout << balle1 << endl;
cout << p1.point_plus_proche(balle1) << endl;
    return 0;
}

