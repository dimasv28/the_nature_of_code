#include "Example_3_9.h"
#include "HelloWorldScene.h"

using namespace cocos2d;

CCScene* Example_3_9::scene() {
    CCScene * scene = NULL;
    do {
        scene = CCScene::create();
        Example_3_9 *layer = Example_3_9::create();
        scene->addChild(layer);
    } while (0);
    return scene;
}

bool Example_3_9::init() {
    bool bRet = false;
    do {
		CCSize size = CCDirector::sharedDirector()->getWinSize();

		// background
		CCSprite *background = CCSprite::create("background.png");
		background->setPosition(ccp(size.width/2,size.height/2));
		addChild(background, 0);

		// lebel of example
		exLabel = CCLabelTTF::create("Example 3.9: The Wave", "Arial", 16);
		exLabel->setColor( ccc3(0,0,0));
		exLabel->setPosition(ccp(size.width/2,size.height-20));
		addChild(exLabel, 1);

		CCMenuItemImage *pMainMenuItem = CCMenuItemImage::create(
            "CloseNormal.png",
            "CloseSelected.png",
            this,
            menu_selector(Example_3_9::goMainMenu));
		CCMenu* pMenu = CCMenu::create(pMainMenuItem, NULL);
		pMenu->setPosition(CCPointZero);
		pMainMenuItem->setPosition(ccp(size.width - 20, 20));
        addChild(pMenu, 2);

		startAngle = 0;
		angle = 0;
		angleVel = 0.2;
		frameCount = 0;

		circles = new vector<CCSprite*>;
		for(int x = 0; x <= size.width; x+=24) {
			CCSprite *circle = CCSprite::create("circle.png");
			circle->setPositionX(x);
			addChild(circle, 1);
			circles->push_back(circle);
		}

		schedule( schedule_selector(Example_3_9::moveCircle), 0.0 );

		bRet = true;
    } while (0);

    return bRet;
}

void Example_3_9::goMainMenu(CCObject* pSender) {
    CCScene *pHelloScene = HelloWorld::scene();
	CCDirector::sharedDirector()->replaceScene(pHelloScene);
}

void Example_3_9::moveCircle(float dt) {
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	angle = startAngle;
	the_iterator = circles->begin();
	while (the_iterator != circles->end()) {
		float y = mapProc(sin(angle),(-1),1,0,size.height);
		(*the_iterator)->setPositionY(y);
		angle +=angleVel;

		++the_iterator;
	}
	startAngle += 0.02;
}
