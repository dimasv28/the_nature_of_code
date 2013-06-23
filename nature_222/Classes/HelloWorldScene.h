#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "Example_1_2.h"
#include "Example_1_3.h"
#include "Example_1_7.h"

using namespace cocos2d;

class HelloWorld : public cocos2d::CCLayer
{
protected:

public:
    virtual bool init(); 
    static CCScene* scene();
    
	void startEx_1_2(CCObject* pSender);
	void startEx_1_3(CCObject* pSender);
	void startEx_1_7(CCObject* pSender);
    void menuCloseCallback(CCObject* pSender);

    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif  // __HELLOWORLD_SCENE_H__