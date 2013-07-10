#include "Example_3_11.h"
#include "HelloWorldScene.h"

using namespace cocos2d;

CCScene* Example_3_11::scene() {
    CCScene * scene = NULL;
    do {
		scene = CCScene::create();
		Example_3_11 *layer = Example_3_11::create();
		scene->addChild(layer);
    } while (0);
    return scene;
}

bool Example_3_11::init() {
    bool bRet = false;
    do {
		CCSize size = CCDirector::sharedDirector()->getWinSize();

		// background
		CCSprite *background = CCSprite::create("background.png");
		background->setPosition(ccp(size.width/2,size.height/2));
		addChild(background, 0);

		// lebel of example
		exLabel = CCLabelTTF::create("Example 3.11: A Spring connection", "Arial", 16);
		exLabel->setColor( ccc3(0,0,0));
		exLabel->setPosition(ccp(size.width/2,size.height-20));
		addChild(exLabel, 1);

		CCMenuItemImage *pMainMenuItem = CCMenuItemImage::create(
            "CloseNormal.png",
            "CloseSelected.png",
            this,
            menu_selector(Example_3_11::goMainMenu));
		CCMenu* pMenu = CCMenu::create(pMainMenuItem, NULL);
		pMenu->setPosition(CCPointZero);
		pMainMenuItem->setPosition(ccp(size.width - 20, 20));
        addChild(pMenu, 2);
		
		spring = new Spring(size.width/2, size.height, 100); 
		bob = new Bob(6, size.width/2, size.height - 150); 
		addChild(bob, 1);
		addChild(spring, 1);
		
		mouse = new PVector(size.width/2, size.height/2);

		schedule( schedule_selector(Example_3_11::moveCircle), 0.0 );

		setTouchEnabled(true);

        bRet = true;
    } while (0);

    return bRet;
}

void Example_3_11::goMainMenu(CCObject* pSender) {
    CCScene *pHelloScene = HelloWorld::scene();
	CCDirector::sharedDirector()->replaceScene(pHelloScene);
}

void Example_3_11::moveCircle(float dt) {
	PVector *gravity = new PVector(0, -3);
	bob->applyForce(gravity);

	spring->connect(bob);
	spring->constrainLength(bob, 30, 250);

	bob->update();
	bob->drag(mouse);

	spring->display(bob);
	bob->display();
}

void Example_3_11::ccTouchesMoved(CCSet* touches, CCEvent* event) {
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	CCTouch* touch = (CCTouch*)( touches->anyObject() );
	CCPoint location = touch->getLocationInView();
	location = CCDirector::sharedDirector()->convertToGL(location);

	mouse->x = location.x;
	mouse->y = location.y;

	bob->clicked(mouse);
}
void Example_3_11::ccTouchesBegan(CCSet* touches, CCEvent* event) {
	
}

void Example_3_11::ccTouchesEnded(CCSet* touches, CCEvent* event) {
	bob->stopDragging();
}