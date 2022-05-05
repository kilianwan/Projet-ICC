
#include "IntegrateurEC.h"

void IntegrateurEC::evolue(ObjetMobile& o) const {
	o.set_vitesse(o.get_deriveeparam() + get_dt()*o.evolution());
	o.set_position(o.get_param()+ get_dt()*o.get_deriveeparam());
	
}
