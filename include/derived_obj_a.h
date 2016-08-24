#ifndef DERIVED_OBJ_A
#define DERIVED_OBJ_A

#include "obj_a.h"

class derived_obj_a : public puppable_obj_a<derived_obj_a>
{
public:
	derived_obj_a(float health_=100.0f, float max_health_=100.0f):
        puppable_obj_a<derived_obj_a>(*this),
		health(health_),
		max_health(max_health_)
	{}

	float health;
	float max_health;
};

void pup(pupper * p, derived_obj_a & oa, const var_info & info);

#endif
