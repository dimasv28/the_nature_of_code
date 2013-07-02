#ifndef __EXAMPLE_3_4__
#define __EXAMPLE_3_4__

#include "cocos2d.h"
#include "Box2D/Box2D.h"

using namespace cocos2d;

class Example_3_4 : public CCLayer {
protected:
	CCNode *centerPoint;
	CCSprite *circle;
	CCSprite *line;

	CCLabelTTF *exLabel;

	float r;
	float theta;
	
public:
	virtual bool init(); 
    static CCScene* scene();

	void goMainMenu(CCObject* pSender);
	void moveCircle(float dt);

	CREATE_FUNC(Example_3_4);
};

#endif // __EXAMPLE_3_4__