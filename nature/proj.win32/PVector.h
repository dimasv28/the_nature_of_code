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
	void mult(float n) {
		x = x * n;
		y = y * n;
	}
	void div(float n) {
		x = x / n;
		y = y / n;
	}
};

#endif  __PVECTOR__