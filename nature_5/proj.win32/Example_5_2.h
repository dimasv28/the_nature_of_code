#ifndef __EXAMPLE_5_2__
#define __EXAMPLE_5_2__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "Boundary.h"
#include "Box.h"

using namespace cocos2d;

class Example_5_2 : public CCLayer {
protected:
	CCLabelTTF *exLabel;
	b2World *world;
	Boundary *boundary;
	Boundary *boundary_2;
	vector<Box*> *boxes;
	vector<Box*>::iterator the_iterator;
	CCPoint *mouse;
	
public:
	virtual bool init(); 
    static CCScene* scene();

	void goMainMenu(CCObject* pSender);
	void draw(float dt);
	void addBoxes(float dt);
	void ccTouchesBegan(CCSet* touches, CCEvent* event);
	void ccTouchesEnded(CCSet* touches, CCEvent* event);
	void ccTouchesMoved(CCSet* touches, CCEvent* event);

	CREATE_FUNC(Example_5_2);
};

#endif