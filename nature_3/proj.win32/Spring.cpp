#include "Spring.h"

Spring::Spring(float x, float y, int l) {
	anchor = new PVector(x, y);
	len = l;
	k = 0.1;

	line = CCSprite::create("line.png");
	line->setScaleX( l / line->getContentSize().width );
	line->setAnchorPoint( ccp(0, 0) );
	line->setPosition( ccp(x, y) );
	addChild(line);
}

void Spring::connect(Bob *b) {
	PVector *force = PVector::sub(b->getLocation(), anchor);
	float d = force->mag();
	float stretch = d - len;

	force->normalize();
	force->mult(-1 * k * stretch);
	b->applyForce(force);
}

// Constrain the distance between bob and anchor between min and max
void Spring::constrainLength(Bob *b, float minlen, float maxlen) {
	PVector *dir = PVector::sub(b->getLocation(), anchor);
	float d = dir->mag();
	// Is it too short?
	if (d < minlen) {
		dir->normalize();
		dir->mult(minlen);
		// Reset location and stop from moving (not realistic physics)
		b->setLocation(PVector::add(anchor, dir));
		b->getVelocity()->mult(0);
		// Is it too long?
	} else if (d > maxlen) {
		dir->normalize();
		dir->mult(maxlen);
		// Reset location and stop from moving (not realistic physics)
		b->setLocation(PVector::add(anchor, dir));
		b->getVelocity()->mult(0);
	}
}

void Spring::display(Bob *b) {
	PVector *dir = PVector::sub(b->getLocation(), anchor);
	float angle = atan2(dir->y, dir->x);
	line->setRotation( -angle * 180 / M_PI );
	line->setScaleX( dir->mag() / line->getContentSize().width );
}