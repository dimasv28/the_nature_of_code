#include "Example_1_8.h"
#include "HelloWorldScene.h"

using namespace cocos2d;

CCScene* Example_1_8::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        Example_1_8 *layer = Example_1_8::create();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Example_1_8::init()
{
    bool bRet = false;
    do 
    {
		CCSize size = CCDirector::sharedDirector()->getWinSize();

		mover = new Mover();
		addChild(mover);
		
		// lebel of example
		exLabel = CCLabelTTF::create("Example 1.8: Motion 101 (velocity and constant acceleration)", "Arial", 16);
		exLabel->setPosition(ccp(size.width/2,size.height-20));
		addChild(exLabel);

		CCMenuItemImage *pMainMenuItem = CCMenuItemImage::create(
            "CloseNormal.png",
            "CloseSelected.png",
            this,
            menu_selector(Example_1_8::goMainMenu));
		CCMenu* pMenu = CCMenu::create(pMainMenuItem, NULL);
		pMenu->setPosition(CCPointZero);
		pMainMenuItem->setPosition(ccp(size.width - 20, 20));
        addChild(pMenu, 1);

		schedule( schedule_selector(Example_1_8::moveCircle), 0.0 );

        bRet = true;
    } while (0);

    return bRet;
}

void Example_1_8::goMainMenu(CCObject* pSender)
{
    CCScene *pHelloScene = HelloWorld::scene();
	CCDirector::sharedDirector()->replaceScene(pHelloScene);
}

void Example_1_8::moveCircle(float dt)
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	// Example 1.8: Motion 101 (velocity and constant acceleration)
	mover->update();
	mover->display();
	mover->checkEdges();
}