#include "Example_2_8.h"
#include "HelloWorldScene.h"

using namespace cocos2d;

CCScene* Example_2_8::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        Example_2_8 *layer = Example_2_8::create();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Example_2_8::init()
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
		exLabel = CCLabelTTF::create("Example 2.8: Mutual attraction", "Arial", 16);
		exLabel->setColor( ccc3(0,0,0));
		exLabel->setPosition(ccp(size.width/2,size.height-20));
		addChild(exLabel, 1);

		CCMenuItemImage *pMainMenuItem = CCMenuItemImage::create(
            "CloseNormal.png",
            "CloseSelected.png",
            this,
            menu_selector(Example_2_8::goMainMenu));
		CCMenu* pMenu = CCMenu::create(pMainMenuItem, NULL);
		pMenu->setPosition(CCPointZero);
		pMainMenuItem->setPosition(ccp(size.width - 20, 20));
        addChild(pMenu, 2);

		arrLength = 10;
		movers = new vector<Mover*>;

		for (int i = 0; i < arrLength; i++) {
			Mover *mover = new Mover(rand() % 5 + 1, rand() % (int)(size.width), rand() % (int)(size.height));
			PVector *v = new PVector(0, 0);
			mover->setVelocity(v);
			movers->push_back(mover);
			addChild(mover, 1);
		}
		
		mouse = new PVector(size.width/2, size.height/2);

		schedule( schedule_selector(Example_2_8::moveCircle), 0.0 );

		setTouchEnabled(true);

        bRet = true;
    } while (0);

    return bRet;
}

void Example_2_8::goMainMenu(CCObject* pSender)
{
    CCScene *pHelloScene = HelloWorld::scene();
	CCDirector::sharedDirector()->replaceScene(pHelloScene);
}

void Example_2_8::moveCircle(float dt)
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	i_iterator = movers->begin();
	while (i_iterator != movers->end()) {
		j_iterator = movers->begin();
		while (j_iterator != movers->end()) {
			if(i_iterator != j_iterator) {
				PVector *force = (*j_iterator)->attract(*i_iterator);
				(*i_iterator)->applyForce(force);
			}
			++j_iterator;
		}
		(*i_iterator)->update(mouse);
		(*i_iterator)->display();
		++i_iterator;
	}
}

void Example_2_8::ccTouchesMoved(CCSet* touches, CCEvent* event)
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	CCTouch* touch = (CCTouch*)( touches->anyObject() );
	CCPoint location = touch->getLocationInView();
	location = CCDirector::sharedDirector()->convertToGL(location);

	mouse->x = location.x;
	mouse->y = location.y;
}