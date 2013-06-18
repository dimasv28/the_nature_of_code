#ifndef __PVECTOR__
#define __PVECTOR__

class PVector {
protected:

public:
	float x;
	float y;

	PVector();
	PVector(float x_, float y_)	{
		x = x_;
		y = y_;
	}
	void add(PVector *v) {
		y = y + v->y;
		x = x + v->x;
	}
	void sub(PVector *v) {
		x = x - v->x;
		y = y - v->y;
	}
};

#endif  __PVECTOR__