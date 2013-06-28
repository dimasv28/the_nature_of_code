#include "Example_2_3.h"
#include "HelloWorldScene.h"

using namespace cocos2d;

CCScene* Example_2_3::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        Example_2_3 *layer = Example_2_3::create();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Example_2_3::init()
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
		exLabel = CCLabelTTF::create("Example 2.3: Gravity scaled by mass\n(Uncomment required lines in code to see other Example)", "Arial", 16);
		exLabel->setColor( ccc3(0,0,0));
		exLabel->setPosition(ccp(size.width/2,size.height-20));
		exLabel2 = CCLabelTTF::create("Example 2.4: Including friction\n(Uncomment required lines in code to see other Example)", "Arial", 16);
		exLabel2->setColor( ccc3(0,0,0));
		exLabel2->setPosition(ccp(size.width/2,size.height-20));
		//addChild(exLabel, 1);	// example 2.3
		addChild(exLabel2, 1);	// example 2.4

		CCMenuItemImage *pMainMenuItem = CCMenuItemImage::create(
            "CloseNormal.png",
            "CloseSelected.png",
            this,
            menu_selector(Example_2_3::goMainMenu));
		CCMenu* pMenu = CCMenu::create(pMainMenuItem, NULL);
		pMenu->setPosition(CCPointZero);
		pMainMenuItem->setPosition(ccp(size.width - 20, 20));
        addChild(pMenu, 2);

		arrLength = 5;
		movers = new vector<Mover*>;

		for (int i = 0; i < arrLength; i++) {
			Mover *mover = new Mover(rand() % 5 + 1, rand() % (int)(size.width), 150);
			movers->push_back(mover);
			addChild(mover, 1);
		}
		
		mouse = new PVector(size.width/2, size.height/2);

		schedule( schedule_selector(Example_2_3::moveCircle), 0.0 );

		setTouchEnabled(true);

        bRet = true;
    } while (0);

    return bRet;
}

void Example_2_3::goMainMenu(CCObject* pSender)
{
    CCScene *pHelloScene = HelloWorld::scene();
	CCDirector::sharedDirector()->replaceScene(pHelloScene);
}

void Example_2_3::moveCircle(float dt)
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	PVector *wind = new PVector(0.02,0);

	the_iterator = movers->begin();
	while (the_iterator != movers->end()) {
		float m = (*the_iterator)->getMass();
		PVector *gravity = new PVector(0,-0.1*m);

		float c = 0.1;
		PVector *friction = new PVector((*the_iterator)->getVelocity()->x,(*the_iterator)->getVelocity()->y);
		friction->mult(-1);
		friction->normalize();
		friction->mult(c);

		(*the_iterator)->applyForce(friction);	//Example 2.4: Including friction
		(*the_iterator)->applyForce(wind);
		(*the_iterator)->applyForce(gravity);

		(*the_iterator)->update(mouse);
		(*the_iterator)->display();
		(*the_iterator)->checkEdges();

		++the_iterator;
	}
}

void Example_2_3::ccTouchesMoved(CCSet* touches, CCEvent* event)
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	CCTouch* touch = (CCTouch*)( touches->anyObject() );
	CCPoint location = touch->getLocationInView();
	location = CCDirector::sharedDirector()->convertToGL(location);

	mouse->x = location.x;
	mouse->y = location.y;
}