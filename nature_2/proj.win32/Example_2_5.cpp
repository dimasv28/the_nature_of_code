#include "Example_2_5.h"
#include "HelloWorldScene.h"

using namespace cocos2d;

CCScene* Example_2_5::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        Example_2_5 *layer = Example_2_5::create();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Example_2_5::init()
{
    bool bRet = false;
    do 
    {
		CCSize size = CCDirector::sharedDirector()->getWinSize();
		arrLength = 5;
		movers = new vector<Mover*>;

		for (int i = 0; i < arrLength; i++) {
			Mover *mover = new Mover(rand() % 5 + 1, rand() % (int)(size.width), 300);
			movers->push_back(mover);
			addChild(mover);
		}
		
		c = 0.1;
		liquid = new Liquid(0,0,size.width, size.height/2, c);

		mouse = new PVector(size.width/2, size.height/2);

		// lebel of example
		exLabel = CCLabelTTF::create("Example 2.5: Fluid Resistance", "Arial", 16);
		exLabel->setPosition(ccp(size.width/2,size.height-20));
		addChild(exLabel);

		CCMenuItemImage *pMainMenuItem = CCMenuItemImage::create(
            "CloseNormal.png",
            "CloseSelected.png",
            this,
            menu_selector(Example_2_5::goMainMenu));
		CCMenu* pMenu = CCMenu::create(pMainMenuItem, NULL);
		pMenu->setPosition(CCPointZero);
		pMainMenuItem->setPosition(ccp(size.width - 20, 20));
        addChild(pMenu, 1);

		schedule( schedule_selector(Example_2_5::moveCircle), 0.0 );

		setTouchEnabled(true);

        bRet = true;
    } while (0);

    return bRet;
}

void Example_2_5::goMainMenu(CCObject* pSender)
{
    CCScene *pHelloScene = HelloWorld::scene();
	CCDirector::sharedDirector()->replaceScene(pHelloScene);
}

void Example_2_5::moveCircle(float dt)
{
	the_iterator = movers->begin();
	while (the_iterator != movers->end()) {
		float m = (*the_iterator)->getMass();
		PVector *gravity = new PVector(0,-0.1*m);

		(*the_iterator)->applyForce(gravity);

		if ((*the_iterator)->isInside(liquid)) {
			(*the_iterator)->drag(liquid);
		}

		(*the_iterator)->update(mouse);
		(*the_iterator)->display();
		(*the_iterator)->checkEdges();

		++the_iterator;
	}
}

void Example_2_5::ccTouchesMoved(CCSet* touches, CCEvent* event)
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	CCTouch* touch = (CCTouch*)( touches->anyObject() );
	CCPoint location = touch->getLocationInView();
	location = CCDirector::sharedDirector()->convertToGL(location);

	mouse->x = location.x;
	mouse->y = location.y;
}