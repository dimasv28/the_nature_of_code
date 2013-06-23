#include "Example_1_7.h"
#include "HelloWorldScene.h"

using namespace cocos2d;

CCScene* Example_1_7::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        Example_1_7 *layer = Example_1_7::create();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Example_1_7::init()
{
    bool bRet = false;
    do 
    {
		CCSize size = CCDirector::sharedDirector()->getWinSize();

		mover = new Mover();
		addChild(mover);
		
		mouse = new PVector(size.width/2, size.height/2);

		// lebel of example
		exLabel = CCLabelTTF::create("Example 1.10: Accelerating towards the mouse", "Arial", 16);
		exLabel->setPosition(ccp(size.width/2,size.height-20));
		addChild(exLabel);

		CCMenuItemImage *pMainMenuItem = CCMenuItemImage::create(
            "CloseNormal.png",
            "CloseSelected.png",
            this,
            menu_selector(Example_1_7::goMainMenu));
		CCMenu* pMenu = CCMenu::create(pMainMenuItem, NULL);
		pMenu->setPosition(CCPointZero);
		pMainMenuItem->setPosition(ccp(size.width - 20, 20));
        addChild(pMenu, 1);

		schedule( schedule_selector(Example_1_7::moveCircle), 0.0 );

		setTouchEnabled(true);

        bRet = true;
    } while (0);

    return bRet;
}

void Example_1_7::goMainMenu(CCObject* pSender)
{
    CCScene *pHelloScene = HelloWorld::scene();
	CCDirector::sharedDirector()->replaceScene(pHelloScene);
}

void Example_1_7::moveCircle(float dt)
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	mover->update(mouse);
	mover->display();
	mover->checkEdges();
}

void Example_1_7::ccTouchesMoved(CCSet* touches, CCEvent* event)
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	CCTouch* touch = (CCTouch*)( touches->anyObject() );
	CCPoint location = touch->getLocationInView();
	location = CCDirector::sharedDirector()->convertToGL(location);

	mouse->x = location.x;
	mouse->y = location.y;
}