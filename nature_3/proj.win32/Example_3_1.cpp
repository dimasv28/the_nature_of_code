#include "Example_3_1.h"
#include "HelloWorldScene.h"

using namespace cocos2d;

CCScene* Example_3_1::scene() {
    CCScene * scene = NULL;
    do {
        scene = CCScene::create();
        Example_3_1 *layer = Example_3_1::create();
        scene->addChild(layer);
    } while (0);
    return scene;
}

bool Example_3_1::init() {
    bool bRet = false;
    do {
		CCSize size = CCDirector::sharedDirector()->getWinSize();

		angle = 0;
		aVelocity = 0;
		aAcceleration = 0.001;

		// background
		CCSprite *background = CCSprite::create("background.png");
		background->setPosition(ccp(size.width/2,size.height/2));
		addChild(background, 0);

		// lebel of example
		exLabel = CCLabelTTF::create("Example 3.1: Angular motion", "Arial", 16);
		exLabel->setColor( ccc3(0,0,0));
		exLabel->setPosition(ccp(size.width/2,size.height-20));
		addChild(exLabel, 1);

		CCMenuItemImage *pMainMenuItem = CCMenuItemImage::create(
            "CloseNormal.png",
            "CloseSelected.png",
            this,
            menu_selector(Example_3_1::goMainMenu));
		CCMenu* pMenu = CCMenu::create(pMainMenuItem, NULL);
		pMenu->setPosition(CCPointZero);
		pMainMenuItem->setPosition(ccp(size.width - 20, 20));
        addChild(pMenu, 2);

		// "replace" coordinate system at the center of the screen
		centerPoint = new CCNode();
		centerPoint->setAnchorPoint(ccp(0,0));
		centerPoint->setPosition(size.width/2,size.height/2);
		addChild(centerPoint);

		// add circle and line
		circle = CCSprite::create("circle.png");
		circle_2 = CCSprite::create("circle.png");
		line = CCSprite::create("line.png");
		circle->setScale(0.5);
		circle_2->setScale(0.5);
		line->setScaleX(13);
		circle->setPosition( ccp(80, 0) );
		circle_2->setPosition( ccp(-80, 0) );
		line->setPosition( ccp(0, 0) );
		centerPoint->addChild(circle);
		centerPoint->addChild(circle_2);
		centerPoint->addChild(line);

		schedule( schedule_selector(Example_3_1::moveCircle), 0.0 );

        bRet = true;
    } while (0);

    return bRet;
}

void Example_3_1::goMainMenu(CCObject* pSender) {
    CCScene *pHelloScene = HelloWorld::scene();
	CCDirector::sharedDirector()->replaceScene(pHelloScene);
}

void Example_3_1::moveCircle(float dt) {
	centerPoint->setRotation(angle);
	aVelocity += aAcceleration;
	angle += aVelocity;
}