#include "obj_a.h"

void obj_a::set_transform(const fmat4 & tform)
{
	transform = tform;
}

void obj_a::set_velocity(const fvec4 & vel)
{
	velocity = vel;
}

const fvec4 & obj_a::get_velocity() const
{
	return velocity;
}

const fmat4 & obj_a::get_transform() const
{
	return transform;
}

void obj_a::pack_unpack(pupper * p, const var_info & info)
{}


void pup(pupper * p_, obj_a & oa, const var_info & info)
{
    oa.pack_unpack(p_,info);
	pup(p_, oa.transform, var_info(info.name + ".transform"));
	pup(p_, oa.velocity, var_info(info.name + ".velocity"));
}
