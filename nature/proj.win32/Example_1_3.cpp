#include "Example_1_3.h"
#include "HelloWorldScene.h"

using namespace cocos2d;

CCScene* Example_1_3::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        Example_1_3 *layer = Example_1_3::create();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Example_1_3::init()
{
    bool bRet = false;
    do 
    {
		CCSize size = CCDirector::sharedDirector()->getWinSize();

		mouse  = new PVector(50,50);
		center = new PVector(size.width/2,size.height/2);

		// "replace" coordinate system at the center of the screen
		centerPoint = new CCNode();
		centerPoint->setAnchorPoint(ccp(0,0));
		centerPoint->setPosition(size.width/2,size.height/2);
		addChild(centerPoint);

		// add line on the new coordinate system
		line = DebugDraw::create();
		centerPoint->addChild(line);

		// main menu button
		CCMenuItemImage *pMainMenuItem = CCMenuItemImage::create(
            "CloseNormal.png",
            "CloseSelected.png",
            this,
            menu_selector(Example_1_3::goMainMenu));
		CCMenu* pMenu = CCMenu::create(pMainMenuItem, NULL);
		pMenu->setPosition(CCPointZero);
		pMainMenuItem->setPosition(ccp(size.width - 20, 20));
        addChild(pMenu, 1);

		this->setTouchEnabled(true);

        bRet = true;
    } while (0);

    return bRet;
}

void Example_1_3::goMainMenu(CCObject* pSender)
{
    CCScene *pHelloScene = HelloWorld::scene();
	CCDirector::sharedDirector()->replaceScene(pHelloScene);
}

void Example_1_3::ccTouchesMoved(cocos2d::CCSet* touches, cocos2d::CCEvent* event)
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	CCTouch* touch = (CCTouch*)( touches->anyObject() );
	CCPoint location = touch->getLocationInView();
	location = CCDirector::sharedDirector()->convertToGL(location);
	
	//Example 1.4: Multiplying a vector
	mouse->x = location.x;
	mouse->y = location.y;
	mouse->sub(center);
	mouse->mult(0.5);
	drawLine();
}

void Example_1_3::drawLine()
{
	line->clear();
	line->appendLine(ccp(0,0),ccp(mouse->x,mouse->y),100,250,2,1);
}