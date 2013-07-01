#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "Example_3_1.h"
#include "Example_3_2.h"

using namespace cocos2d;

class HelloWorld : public cocos2d::CCLayer {
protected:

public:
    virtual bool init(); 
    static CCScene* scene();

	void startEx_3_1(CCObject* pSender);
	void startEx_3_2(CCObject* pSender);

    void menuCloseCallback(CCObject* pSender);

    CREATE_FUNC(HelloWorld);
};

#endif  // __HELLOWORLD_SCENE_H__