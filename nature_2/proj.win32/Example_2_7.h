#ifndef __EXAMPLE_2_7__
#define __EXAMPLE_2_7__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "PVector.h"
#include "Mover.h"
#include "Attractor.h"

using namespace cocos2d;
using namespace std;
class Mover;
class Attractor;

class Example_2_7 : public CCLayer
{
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

	CREATE_FUNC(Example_2_7);
};

#endif  __EXAMPLE_2_7__