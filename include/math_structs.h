#ifndef MATH_STRUCTS_H
#define MATH_STRUCTS_H

#include "pupper.h"

struct fvec4
{
    fvec4(float x_=0.0f, float y_=0.0f, float z_=0.0f, float w_=0.0f);

	union
	{
		struct
		{
			float x;
			float y;
			float z;
			float w;
		};
		
		struct
		{
			float r;
			float g;
			float b;
			float a;
		};

		float data[4];
	};

    fvec4 operator+(const fvec4 & rhs);
    fvec4 operator-(const fvec4 & rhs);
    fvec4 & operator+=(const fvec4 & rhs);
    fvec4 & operator-=(const fvec4 & rhs);
};

void pup(pupper * p_, fvec4 & vc, const var_info & info);

struct fmat4
{	
	fmat4(fvec4 row1_ = fvec4(1.0f,0.0f,0.0f,0.0f), 
	      fvec4 row2_ = fvec4(0.0f,1.0f,0.0f,0.0f),
	      fvec4 row3_ = fvec4(0.0f,0.0f,1.0f,0.0f),
          fvec4 row4_ = fvec4(0.0f,0.0f,0.0f,1.0f));

	union
	{
		struct
		{
			fvec4 rows[4];
		};
		float data[16];
	};
};

void pup(pupper * p_, fmat4 & tf, const var_info & info);

#endif
