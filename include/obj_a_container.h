#ifndef OBJ_DEFS_H
#define OBJ_DEFS_H

#include "pupper.h"
#include "derived_obj_a.h"
#include <vector>

struct obj_a_desc
{
	obj_a_desc();

	int8_t type;
	obj_a * ptr;
};

struct obj_a_container
{
	~obj_a_container();

	void release();

	std::vector<obj_a_desc> obj_a_vec;
};

void pup(pupper * p_, obj_a_desc & oa_d, const var_info & info);

void pup(pupper * p_, obj_a_container & oa, const var_info & info);

template< class T>
void pup(pupper * p_, std::vector<T> & vec, const var_info & info)
{
    uint32_t size = static_cast<uint32_t>(vec.size());
    pup(p_, size, var_info(info.name + ".size"));
    vec.resize(size);
    for (uint32_t i = 0; i < size; ++i)
        pup(p_, vec[i], var_info(info.name + "[" + std::to_string(i) + "]"));
}

#endif
