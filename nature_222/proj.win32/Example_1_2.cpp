#include "Example_1_2.h"
#include "HelloWorldScene.h"

using namespace cocos2d;

CCScene* Example_1_2::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        Example_1_2 *layer = Example_1_2::create();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Example_1_2::init()
{
    bool bRet = false;
    do 
    {
		CCSize size = CCDirector::sharedDirector()->getWinSize();

		location  = new PVector(50,50);
		velocity = new PVector(2,2);
		circle = DebugDraw::create();
		addChild(circle);

		CCMenuItemImage *pMainMenuItem = CCMenuItemImage::create(
            "CloseNormal.png",
            "CloseSelected.png",
            this,
            menu_selector(Example_1_2::goMainMenu));
		CCMenu* pMenu = CCMenu::create(pMainMenuItem, NULL);
		pMenu->setPosition(CCPointZero);
		pMainMenuItem->setPosition(ccp(size.width - 20, 20));
        addChild(pMenu, 1);

		schedule( schedule_selector(Example_1_2::moveCircle), 0.0 );

        bRet = true;
    } while (0);

    return bRet;
}

void Example_1_2::goMainMenu(CCObject* pSender)
{
    CCScene *pHelloScene = HelloWorld::scene();
	CCDirector::sharedDirector()->replaceScene(pHelloScene);
}

void Example_1_2::moveCircle(float dt)
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	location->add(velocity);

	if ((location->x > size.width) || (location->x < 0)) {
		velocity->x = velocity->x * -1;
	}
	if ((location->y > size.height) || (location->y < 0)) {
		velocity->y = velocity->y * -1;
	}
}

void Example_1_2::draw()
{
	circle->clear();
	float r = 30;
	for(int alfa=0; alfa<360; alfa++)
	{
		circle->appendPoint(ccp(location->x+r*sin(alfa*M_PI/180),location->y+r*cos(alfa*M_PI/180)),125,255,0);
	}
}