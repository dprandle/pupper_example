#include "derived_obj_a.h"

void pup(pupper * p, derived_obj_a & oa, const var_info & info)
{
    pup(p, oa.health, var_info(info.name + ".health"));
    pup(p, oa.health, var_info(info.name + ".max_health"));
}
