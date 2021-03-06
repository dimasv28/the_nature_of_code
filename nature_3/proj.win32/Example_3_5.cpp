#include "Example_3_5.h"
#include "HelloWorldScene.h"

using namespace cocos2d;

CCScene* Example_3_5::scene() {
    CCScene * scene = NULL;
    do {
        scene = CCScene::create();
        Example_3_5 *layer = Example_3_5::create();
        scene->addChild(layer);
    } while (0);
    return scene;
}

bool Example_3_5::init() {
    bool bRet = false;
    do {
		CCSize size = CCDirector::sharedDirector()->getWinSize();

		// background
		CCSprite *background = CCSprite::create("background.png");
		background->setPosition(ccp(size.width/2,size.height/2));
		addChild(background, 0);

		// lebel of example
		exLabel = CCLabelTTF::create("Example 3.5: Simple Harmonic Motion", "Arial", 16);
		exLabel->setColor( ccc3(0,0,0));
		exLabel->setPosition(ccp(size.width/2,size.height-20));
		addChild(exLabel, 1);

		CCMenuItemImage *pMainMenuItem = CCMenuItemImage::create(
            "CloseNormal.png",
            "CloseSelected.png",
            this,
            menu_selector(Example_3_5::goMainMenu));
		CCMenu* pMenu = CCMenu::create(pMainMenuItem, NULL);
		pMenu->setPosition(CCPointZero);
		pMainMenuItem->setPosition(ccp(size.width - 20, 20));
        addChild(pMenu, 2);
		
		frameCount = 0;
		period = 120;
		amplitude = 200;

		// add circle and line
		circle = CCSprite::create("circle.png");
		addChild(circle);

		line = CCSprite::create("line.png");
		line->setAnchorPoint( ccp(0, 0) );
		line->setPosition( ccp(size.width/2, size.height/2) );
		addChild(line);

		schedule( schedule_selector(Example_3_5::moveCircle), 0.0 );

        bRet = true;
    } while (0);

    return bRet;
}

void Example_3_5::goMainMenu(CCObject* pSender) {
    CCScene *pHelloScene = HelloWorld::scene();
	CCDirector::sharedDirector()->replaceScene(pHelloScene);
}

void Example_3_5::moveCircle(float dt) {
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	float x = amplitude * cos(2*M_PI * frameCount / period);
	circle->setPosition( ccp(x + size.width/2, size.height/2) );
	line->setScaleX( x / line->getContentSize().width );
	frameCount++;
}