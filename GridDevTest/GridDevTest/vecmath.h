/*------------------------------------------------------------------------
Header for Some Vector Classes
------------------------------------------------------------------------*/
#ifndef vecmat_h_included
#define vecmat_h_included

#include <math.h>

/*------------------------------------------------------------------------
vec2 : 2d Vector
------------------------------------------------------------------------*/

//Vec2 class was externally imported from Uni of Lincoln; School Computer Science Department
class vec2
{
public:
	double 	elem[2];

public:
	vec2() {}
	vec2(double x, double y) { elem[0] = x; elem[1] = y; }
	vec2(double x) { elem[0] = elem[1] = x; }

	double operator()(int x) const { return elem[x]; }
	double &operator()(int x) { return elem[x]; }

	vec2 operator *(const double x) const { vec2 res(*this); res.elem[0] *= x; res.elem[1] *= x; return res; }
	vec2 operator /(const double x) const { vec2 res(*this); res.elem[0] /= x; res.elem[1] /= x; return res; }
	vec2 operator +(const vec2 &x) const { vec2 res(*this); res.elem[0] += x.elem[0]; res.elem[1] += x.elem[1]; return res; }
	vec2 operator -(const vec2 &x) const { vec2 res(*this); res.elem[0] -= x.elem[0]; res.elem[1] -= x.elem[1]; return res; }
	vec2 operator -() const { vec2 res(*this); res.elem[0] = -res.elem[0]; res.elem[1] = -res.elem[1]; return res; }
	vec2 &operator *=(const double x) { elem[0] *= x; elem[1] *= x; return (*this); }
	vec2 &operator /=(const double x) { elem[0] /= x; elem[1] /= x; return (*this); }
	vec2 &operator +=(const vec2 &x) { elem[0] += x.elem[0]; elem[1] += x.elem[1]; return (*this); }
	vec2 &operator -=(const vec2 &x) { elem[0] -= x.elem[0]; elem[1] -= x.elem[1]; return (*this); }
	bool operator ==(const vec2 &x) const { return((elem[0] == x.elem[0]) && (elem[1] == x.elem[1])); }

	double Magnitude(void) const { return(sqrt((elem[0] * elem[0]) + (elem[1] * elem[1]))); }
	double Magnitude2(void) const { return((elem[0] * elem[0]) + (elem[1] * elem[1])); }
	double Normalise(void) { double x = Magnitude(); elem[0] /= x; elem[1] /= x; return x; }
	vec2 Normalised(void) const { vec2 res(*this); res.Normalise(); return res; }

	double Dot(const vec2 &x) const { return ((elem[0] * x.elem[0]) + (elem[1] * x.elem[1])); }
};

#endif
