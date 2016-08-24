#include "math_structs.h"

fvec4::fvec4(float x_, float y_, float z_, float w_):
        x(x_),
        y(y_),
        z(z_),
        w(w_)
{}

fvec4 fvec4::operator+(const fvec4 & rhs)
{
        return fvec4(x+rhs.x,y+rhs.y,z+rhs.z,w+rhs.w);
}

fvec4 fvec4::operator-(const fvec4 & rhs)
{
        return fvec4(x-rhs.x,y-rhs.y,z-rhs.z,w-rhs.w);
}

fvec4 & fvec4::operator+=(const fvec4 & rhs)
{
        x+=rhs.x; y+=rhs.y;z+=rhs.z;w+=rhs.w;
        return *this;
}

fvec4 & fvec4::operator-=(const fvec4 & rhs)
{
        x-=rhs.x; y-=rhs.y;z-=rhs.z;w-=rhs.w;
        return *this;
}

void pup(pupper * p_, fvec4 & vc, const var_info & info)
{
        pup(p_, vc.data[0], var_info(info.name + ".x"));
        pup(p_, vc.data[1], var_info(info.name + ".y"));
        pup(p_, vc.data[2], var_info(info.name + ".z"));
        pup(p_, vc.data[3], var_info(info.name + ".w"));
}

fmat4::fmat4(fvec4 row1_, fvec4 row2_, fvec4 row3_, fvec4 row4_)
{
    rows[0] = row1_;
    rows[1] = row2_;
    rows[2] = row3_;
    rows[3] = row4_;
}


void pup(pupper * p_, fmat4 & tf, const var_info & info)
{
        pup(p_, tf.rows[0], var_info(info.name + ".row1"));
        pup(p_, tf.rows[1], var_info(info.name + ".row2"));
        pup(p_, tf.rows[2], var_info(info.name + ".row3"));
        pup(p_, tf.rows[3], var_info(info.name + ".row4"));
}
