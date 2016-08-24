#ifndef OBJ_A_H
#define OBJ_A_H

#include "pupper.h"
#include "math_structs.h"

class obj_a
{
public:
	friend void pup(pupper * p_, obj_a & oa, const var_info & info);

	void set_transform(const fmat4 & tform);

	void set_velocity(const fvec4 & vel);

	const fvec4 & get_velocity() const;

	const fmat4 & get_transform() const;

protected:

	virtual void pack_unpack(pupper * p, const var_info & info);

private:

	fmat4 transform;
	fvec4 velocity;

};

template<class T>
class puppable_obj_a : public obj_a
{
public:

    puppable_obj_a(T & derived_):
        derived(derived_)
    {}

protected:
	void pack_unpack(pupper * p, const var_info & info)
	{
        pup(p, derived, info);
    }

private:

    T & derived;
};

void pup(pupper * p_, obj_a & oa, const var_info & info);

#endif
