#ifndef __EXAMPLE_3_8__
#define __EXAMPLE_3_8__

// Re-maps a number from one range to another
#define mapProc(value,start1,stop1,start2,stop2) (start2+(value-start1)*(stop2-start2)/(stop1-start1))

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "DebugDraw.h"

using namespace cocos2d;

class Example_3_8 : public CCLayer {
protected:
	float angle;
	float angleVel;
	float amplitude;
	DebugDraw *wave;
	CCLabelTTF *exLabel;
	
public:
	virtual bool init(); 
    static CCScene* scene();
	void goMainMenu(CCObject* pSender);

	CREATE_FUNC(Example_3_8);
};

#endif // __EXAMPLE_3_8__