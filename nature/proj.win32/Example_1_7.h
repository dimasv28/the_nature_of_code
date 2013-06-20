#ifndef __EXAMPLE_1_7__
#define __EXAMPLE_1_7__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "PVector.h"
#include "Mover.h"

using namespace cocos2d;

class Example_1_7 : public cocos2d::CCLayer
{
protected:
	Mover *mover;
	CCLabelTTF *exLabel;

public:
	virtual bool init(); 
    static CCScene* scene();

	void goMainMenu(CCObject* pSender);
	void moveCircle(float dt);

	CREATE_FUNC(Example_1_7);
};

#endif  __EXAMPLE_1_7__