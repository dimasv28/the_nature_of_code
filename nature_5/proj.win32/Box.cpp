#include "Box.h"

Box::Box(b2World *world_, CCPoint *mouse) {
	w = 16;
	h = 16;
	world = world_;
 
	b2BodyDef bd;
	bd.position.Set(mouse->x/PTM_RATIO, mouse->y/PTM_RATIO);
	bd.type = b2_dynamicBody;
	b = world->CreateBody(&bd);
 
	b2PolygonShape *ps = new b2PolygonShape();
	float box2dW = (w/2) / PTM_RATIO;
	float box2dH = (h/2) / PTM_RATIO;
	ps->SetAsBox(box2dW, box2dH);
 
	b2FixtureDef fd;
	fd.shape = ps;
	fd.density = 1;
	fd.friction = 0.3;
	fd.restitution = 0.5;

	b->CreateFixture(&fd);
	b->SetUserData(CCSprite::create("rect.png"));

	rect = (CCSprite*)b->GetUserData();
	rect->setScaleX(w/rect->getContentSize().width);
	rect->setScaleY(h/rect->getContentSize().height);
	addChild(rect);
}

void Box::display() {
	rect->setPosition( ccp( b->GetPosition().x * PTM_RATIO, b->GetPosition().y * PTM_RATIO) );
	rect->setRotation( -1 * CC_RADIANS_TO_DEGREES(b->GetAngle()) );
}

bool Box::done() {
	CCSize size = CCDirector::sharedDirector()->getWinSizeInPixels();
    b2Vec2 pos = b->GetPosition();

    if ( (pos.y * PTM_RATIO) < (-1*w*h) ) {
		world->DestroyBody(b);
		return true;
    }
    return false;
}