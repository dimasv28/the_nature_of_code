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
	float mag() {
		return sqrt(x*x + y*y);
	}
	void normalize() {
		float m = mag();
		if (m != 0) {
			div(m);
		}
	}
	void limit(float max) {
		if ( mag() > max ) {
			normalize();
			mult(max);
		}
	}
	void random2D() {
	// rand -1 / 1
		int r1 = rand() % 2;
		int r2 = rand() % 2;
		if(!r1)	{ r1 = -1; }
		if(!r2)	{ r2 = -1; }
		x = r1;
		y = r2;
	}
};

#endif  __PVECTOR__