#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "DebugDraw.h"
#include "PVector.h"
#include "Example_1_2.h"
#include "Example_1_3.h"

using namespace cocos2d;

class HelloWorld : public cocos2d::CCLayer
{
protected:
	Example_1_2 *ex_1_2;
	Example_1_3 *ex_1_3;

	void moveCircle(float dt);

public:
	void ccTouchesMoved(CCSet* touches, CCEvent* event);

    virtual bool init();  
    static CCScene* scene();
    
    void menuCloseCallback(CCObject* pSender);

    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif  // __HELLOWORLD_SCENE_H__