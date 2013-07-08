#include "Example_3_8.h"
#include "HelloWorldScene.h"

using namespace cocos2d;

CCScene* Example_3_8::scene() {
    CCScene * scene = NULL;
    do {
        scene = CCScene::create();
        Example_3_8 *layer = Example_3_8::create();
        scene->addChild(layer);
    } while (0);
    return scene;
}

bool Example_3_8::init() {
    bool bRet = false;
    do {
		CCSize size = CCDirector::sharedDirector()->getWinSize();

		// background
		CCSprite *background = CCSprite::create("background.png");
		background->setPosition(ccp(size.width/2,size.height/2));
		addChild(background, 0);

		// lebel of example
		exLabel = CCLabelTTF::create("Example 3.7: Oscillator objects", "Arial", 16);
		exLabel->setColor( ccc3(0,0,0));
		exLabel->setPosition(ccp(size.width/2,size.height-20));
		addChild(exLabel, 1);

		CCMenuItemImage *pMainMenuItem = CCMenuItemImage::create(
            "CloseNormal.png",
            "CloseSelected.png",
            this,
            menu_selector(Example_3_8::goMainMenu));
		CCMenu* pMenu = CCMenu::create(pMainMenuItem, NULL);
		pMenu->setPosition(CCPointZero);
		pMainMenuItem->setPosition(ccp(size.width - 20, 20));
        addChild(pMenu, 2);

		angle = 0;
		angleVel = 0.2;
		amplitude = 100;

		wave = DebugDraw::create();
		addChild(wave, 1);

		for(int x = 0; x <= size.width; x+=10) {
			float y1 = mapProc(sin(angle),(-1),1,0,size.height);
			float y2 = mapProc(sin(angle + angleVel),(-1),1,0,size.height);
			wave->appendLine(ccp(x, y1), ccp(x+10, y2), 0, 0, 0, 2);
			angle +=angleVel;
		}

		bRet = true;
    } while (0);

    return bRet;
}

void Example_3_8::goMainMenu(CCObject* pSender) {
    CCScene *pHelloScene = HelloWorld::scene();
	CCDirector::sharedDirector()->replaceScene(pHelloScene);
}