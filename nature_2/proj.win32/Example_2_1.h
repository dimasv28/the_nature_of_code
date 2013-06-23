#ifndef __EXAMPLE_2_1__
#define __EXAMPLE_2_1__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "PVector.h"
#include "Mover.h"
#include "keyboard_dispatcher\CCKeyboardDispatcher.h"

#define W_KEY 87

using namespace cocos2d;
class Mover;

class Example_2_1 : public CCLayer, public cocos2d::CCKeyboardDelegate
{
protected:
	Mover *mover;
	PVector *mouse;
	CCLabelTTF *exLabel;
	
public:
	virtual bool init(); 
    static CCScene* scene();

	//void keyUp(int keyCode);
	void keyDown(int keyCode);

	void goMainMenu(CCObject* pSender);
	void moveCircle(float dt);
	void ccTouchesMoved(CCSet* touches, CCEvent* event);

	CREATE_FUNC(Example_2_1);
};

#endif  __EXAMPLE_2_1__