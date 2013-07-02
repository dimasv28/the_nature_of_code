#ifndef __EXAMPLE_3_5__
#define __EXAMPLE_3_5__

#include "cocos2d.h"
#include "Box2D/Box2D.h"

using namespace cocos2d;

class Example_3_5 : public CCLayer {
protected:
	CCSprite *circle;
	CCSprite *line;

	CCLabelTTF *exLabel;

	float frameCount;
	float period;
	float amplitude;
	
public:
	virtual bool init(); 
    static CCScene* scene();

	void goMainMenu(CCObject* pSender);
	void moveCircle(float dt);

	CREATE_FUNC(Example_3_5);
};

#endif // __EXAMPLE_3_5__