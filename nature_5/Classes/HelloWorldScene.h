#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "Example_5_2.h"

using namespace cocos2d;

class HelloWorld : public cocos2d::CCLayer {
protected:

public:
    virtual bool init(); 
    static CCScene* scene();

	void startEx_5_2(CCObject* pSender);

    void menuCloseCallback(CCObject* pSender);

    CREATE_FUNC(HelloWorld);
};

#endif  // __HELLOWORLD_SCENE_H__