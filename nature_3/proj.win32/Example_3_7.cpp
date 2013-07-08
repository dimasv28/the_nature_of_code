#include "Example_3_7.h"
#include "HelloWorldScene.h"

using namespace cocos2d;

CCScene* Example_3_7::scene() {
    CCScene * scene = NULL;
    do {
        scene = CCScene::create();
        Example_3_7 *layer = Example_3_7::create();
        scene->addChild(layer);
    } while (0);
    return scene;
}

bool Example_3_7::init() {
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
            menu_selector(Example_3_7::goMainMenu));
		CCMenu* pMenu = CCMenu::create(pMainMenuItem, NULL);
		pMenu->setPosition(CCPointZero);
		pMainMenuItem->setPosition(ccp(size.width - 20, 20));
        addChild(pMenu, 2);

		// "replace" coordinate system at the center of the screen
		centerPoint = new CCNode();
		centerPoint->setAnchorPoint(ccp(0,0));
		centerPoint->setPosition(size.width/2,size.height/2);
		addChild(centerPoint);

		arrLength = 10;
		oscillators = new vector<Oscillator*>;

		for (int i = 0; i < arrLength; i++) {
			Oscillator *oscillator = new Oscillator();
			oscillators->push_back(oscillator);
			centerPoint->addChild(oscillator);
		}

		schedule( schedule_selector(Example_3_7::moveCircle), 0.0 );

        bRet = true;
    } while (0);

    return bRet;
}

void Example_3_7::goMainMenu(CCObject* pSender) {
    CCScene *pHelloScene = HelloWorld::scene();
	CCDirector::sharedDirector()->replaceScene(pHelloScene);
}

void Example_3_7::moveCircle(float dt) {
	the_iterator = oscillators->begin();
	while (the_iterator != oscillators->end()) {
		(*the_iterator)->oscillate();
		(*the_iterator)->display();
		++the_iterator;
	}
}