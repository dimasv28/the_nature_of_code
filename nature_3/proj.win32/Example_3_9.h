#ifndef __EXAMPLE_3_9__
#define __EXAMPLE_3_9__

// Re-maps a number from one range to another
#define mapProc(value,start1,stop1,start2,stop2) (start2+(value-start1)*(stop2-start2)/(stop1-start1))

#include "cocos2d.h"
#include "Box2D/Box2D.h"

using namespace cocos2d;

class Example_3_9 : public CCLayer {
protected:
	vector<CCSprite*> *circles;
	vector<CCSprite*>::iterator the_iterator;
	float startAngle;
	float angle;
	float angleVel;
	int frameCount;
	CCLabelTTF *exLabel;
	
public:
	virtual bool init(); 
    static CCScene* scene();
	void goMainMenu(CCObject* pSender);
	void moveCircle(float dt);

	CREATE_FUNC(Example_3_9);
};

#endif // __EXAMPLE_3_9__