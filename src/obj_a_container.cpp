#include "obj_a_container.h"

obj_a_desc::obj_a_desc():
	type(0),
	ptr(nullptr) 
{}

obj_a_container::~obj_a_container()
{
	release();
}

void obj_a_container::release()
{
	while (obj_a_vec.begin() != obj_a_vec.end())
	{
        delete obj_a_vec.back().ptr;
		obj_a_vec.pop_back();
	}
}

void pup(pupper * p_, obj_a_desc & oa_d, const var_info & info)
{
	pup(p_, oa_d.type, var_info(info.name + "type"));
	if (oa_d.ptr == nullptr)
	{
		// This is a bit of a cheat because I don't feel like writing factory code
		if (oa_d.type == 1)
            oa_d.ptr = new obj_a;
		else
            oa_d.ptr = new derived_obj_a;
	}
    pup(p_, *oa_d.ptr, info);
}

void pup(pupper * p_, obj_a_container & oa, const var_info & info)
{
    pup(p_, oa.obj_a_vec, var_info("obj_a_vec"));
}
