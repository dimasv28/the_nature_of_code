#ifndef __EXAMPLE_2_6__
#define __EXAMPLE_2_6__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "PVector.h"
#include "Mover.h"
#include "Attractor.h"

using namespace cocos2d;
using namespace std;
class Mover;
class Attractor;

class Example_2_6 : public CCLayer
{
protected:
 	Mover *mover;
	Attractor *attractor ;
	PVector *mouse;
	CCLabelTTF *exLabel;
	
public:
	virtual bool init(); 
    static CCScene* scene();

	void goMainMenu(CCObject* pSender);
	void moveCircle(float dt);
	void ccTouchesMoved(CCSet* touches, CCEvent* event);

	CREATE_FUNC(Example_2_6);
};

#endif  __EXAMPLE_2_6__