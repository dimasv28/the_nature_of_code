#ifndef __EXAMPLE_3_2__
#define __EXAMPLE_3_2__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "PVector.h"
#include "Mover.h"
#include "Attractor.h"

using namespace cocos2d;
using namespace std;
class Mover;
class Attractor;

class Example_3_2 : public CCLayer {
protected:
 	vector<Mover*> *movers;
	vector<Mover*>::iterator the_iterator;
	int arrLength;
	Attractor *attractor ;
	PVector *mouse;
	CCLabelTTF *exLabel;
	
public:
	virtual bool init(); 
    static CCScene* scene();

	void goMainMenu(CCObject* pSender);
	void moveCircle(float dt);
	void ccTouchesMoved(CCSet* touches, CCEvent* event);

	CREATE_FUNC(Example_3_2);
};

#endif  __EXAMPLE_3_2__