#ifndef __EXAMPLE_2_8__
#define __EXAMPLE_2_8__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "PVector.h"
#include "Mover.h"

using namespace cocos2d;
using namespace std;
class Mover;

class Example_2_8 : public CCLayer
{
protected:
 	vector<Mover*> *movers;
	vector<Mover*>::iterator i_iterator;
	vector<Mover*>::iterator j_iterator;
	int arrLength;
	PVector *mouse;
	CCLabelTTF *exLabel;
	
public:
	virtual bool init(); 
    static CCScene* scene();

	void goMainMenu(CCObject* pSender);
	void moveCircle(float dt);
	void ccTouchesMoved(CCSet* touches, CCEvent* event);

	CREATE_FUNC(Example_2_8);
};

#endif  __EXAMPLE_2_8__