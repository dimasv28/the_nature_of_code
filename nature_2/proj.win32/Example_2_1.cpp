#include "Example_2_1.h"
#include "HelloWorldScene.h"

using namespace cocos2d;

CCScene* Example_2_1::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        Example_2_1 *layer = Example_2_1::create();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Example_2_1::init()
{
    bool bRet = false;
    do 
    {
		CCSize size = CCDirector::sharedDirector()->getWinSize();

		// background
		CCSprite *background = CCSprite::create("background.png");
		background->setPosition(ccp(size.width/2,size.height/2));
		addChild(background, 0);

		// lebel of example
		exLabel = CCLabelTTF::create("Example 2.1: Forces", "Arial", 16);
		exLabel->setColor( ccc3(0,0,0));
		exLabel->setPosition(ccp(size.width/2,size.height-20));
		addChild(exLabel, 1);

		CCMenuItemImage *pMainMenuItem = CCMenuItemImage::create(
            "CloseNormal.png",
            "CloseSelected.png",
            this,
            menu_selector(Example_2_1::goMainMenu));
		CCMenu* pMenu = CCMenu::create(pMainMenuItem, NULL);
		pMenu->setPosition(CCPointZero);
		pMainMenuItem->setPosition(ccp(size.width - 20, 20));
        addChild(pMenu, 2);

		mover = new Mover(3,50,150);
		addChild(mover, 1);
		
		mouse = new PVector(size.width/2, size.height/2);

		schedule( schedule_selector(Example_2_1::moveCircle), 0.0 );

		setTouchEnabled(true);
		CCDirector::sharedDirector()->getKeyboardDispatcher()->addDelegate(this);

        bRet = true;
    } while (0);

    return bRet;
}

void Example_2_1::goMainMenu(CCObject* pSender)
{
    CCScene *pHelloScene = HelloWorld::scene();
	CCDirector::sharedDirector()->replaceScene(pHelloScene);
}

void Example_2_1::moveCircle(float dt)
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	PVector *wind = new PVector(0.01,0);
	PVector *gravity = new PVector(0,-0.1);
	mover->applyForce(wind);
	mover->applyForce(gravity);

	mover->update(mouse);
	mover->display();
	mover->checkEdges();
}

void Example_2_1::ccTouchesMoved(CCSet* touches, CCEvent* event)
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	CCTouch* touch = (CCTouch*)( touches->anyObject() );
	CCPoint location = touch->getLocationInView();
	location = CCDirector::sharedDirector()->convertToGL(location);

	mouse->x = location.x;
	mouse->y = location.y;
}

void Example_2_1::keyDown(int keyCode)
{
	if(keyCode == W_KEY)
	{// w key

	}
}