#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "Example_3_1.h"
#include "Example_3_2.h"
#include "Example_3_3.h"
#include "Example_3_4.h"
#include "Example_3_5.h"
#include "Example_3_7.h"
#include "Example_3_8.h"

using namespace cocos2d;

class HelloWorld : public cocos2d::CCLayer {
protected:

public:
    virtual bool init(); 
    static CCScene* scene();

	void startEx_3_1(CCObject* pSender);
	void startEx_3_2(CCObject* pSender);
	void startEx_3_3(CCObject* pSender);
	void startEx_3_4(CCObject* pSender);
	void startEx_3_5(CCObject* pSender);
	void startEx_3_7(CCObject* pSender);
	void startEx_3_8(CCObject* pSender);

    void menuCloseCallback(CCObject* pSender);

    CREATE_FUNC(HelloWorld);
};

#endif  // __HELLOWORLD_SCENE_H__