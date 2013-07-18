#include "Boundary.h"

Boundary::Boundary(b2World *world, float x_,float y_, float w_, float h_) {
	w = w_;
	h = h_;
	
	b2BodyDef bd;
	bd.position.Set(x_/PTM_RATIO, y_/PTM_RATIO);
	bd.type = b2_staticBody;
	b = world->CreateBody(&bd);
 
	float box2dW = (w/2) / PTM_RATIO;
	float box2dH = (h/2) / PTM_RATIO;
	b2PolygonShape *ps = new b2PolygonShape();
	ps->SetAsBox(box2dW, box2dH);

	b->CreateFixture(ps, 1);
	b->SetUserData(CCSprite::create("rect.png"));

	rect = (CCSprite*)b->GetUserData();
	rect->setScaleX(w/rect->getContentSize().width);
	rect->setScaleY(h/rect->getContentSize().height);
	addChild(rect);
}

void Boundary::display() {
	rect->setPosition( ccp( b->GetPosition().x * PTM_RATIO, b->GetPosition().y * PTM_RATIO) );
}