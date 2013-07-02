#include "Example_3_4.h"
#include "HelloWorldScene.h"

using namespace cocos2d;

CCScene* Example_3_4::scene() {
    CCScene * scene = NULL;
    do {
        scene = CCScene::create();
        Example_3_4 *layer = Example_3_4::create();
        scene->addChild(layer);
    } while (0);
    return scene;
}

bool Example_3_4::init() {
    bool bRet = false;
    do {
		CCSize size = CCDirector::sharedDirector()->getWinSize();

		r = 80;
		theta = 0;

		// background
		CCSprite *background = CCSprite::create("background.png");
		background->setPosition(ccp(size.width/2,size.height/2));
		addChild(background, 0);

		// lebel of example
		exLabel = CCLabelTTF::create("Example 3.4: Polar to Cartesian", "Arial", 16);
		exLabel->setColor( ccc3(0,0,0));
		exLabel->setPosition(ccp(size.width/2,size.height-20));
		addChild(exLabel, 1);

		CCMenuItemImage *pMainMenuItem = CCMenuItemImage::create(
            "CloseNormal.png",
            "CloseSelected.png",
            this,
            menu_selector(Example_3_4::goMainMenu));
		CCMenu* pMenu = CCMenu::create(pMainMenuItem, NULL);
		pMenu->setPosition(CCPointZero);
		pMainMenuItem->setPosition(ccp(size.width - 20, 20));
        addChild(pMenu, 2);

		// "replace" coordinate system at the center of the screen
		centerPoint = new CCNode();
		centerPoint->setAnchorPoint(ccp(0,0));
		centerPoint->setPosition(size.width/2,size.height/2);
		addChild(centerPoint);

		// add circle on the Node
		line = CCSprite::create("line.png");
		line->setScaleX(5.7);
		line->setAnchorPoint( ccp(0, 0) );
		line->setPosition( ccp(0, 0) );
		centerPoint->addChild(line);

		circle = CCSprite::create("circle.png");
		circle->setScale(0.8);
		circle->setPosition( ccp(80, 0) );
		addChild(circle);

		schedule( schedule_selector(Example_3_4::moveCircle), 0.0 );

        bRet = true;
    } while (0);

    return bRet;
}

void Example_3_4::goMainMenu(CCObject* pSender) {
    CCScene *pHelloScene = HelloWorld::scene();
	CCDirector::sharedDirector()->replaceScene(pHelloScene);
}

void Example_3_4::moveCircle(float dt) {
	// rotate circle with polar coordinates and line with Cartesian coordinates
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	float x = r * cos(theta) + size.width/2;
	float y = r * sin(theta) + size.height/2;
	circle->setPosition( ccp(x, y) );
	centerPoint->setRotation(-theta*180/M_PI);
	theta += 0.01;
}