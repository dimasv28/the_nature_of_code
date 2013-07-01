#include "Example_3_2.h"
#include "HelloWorldScene.h"

using namespace cocos2d;

CCScene* Example_3_2::scene() {
    CCScene * scene = NULL;
    do {
		scene = CCScene::create();
		Example_3_2 *layer = Example_3_2::create();
        scene->addChild(layer);
    } while (0);
    return scene;
}

bool Example_3_2::init() {
    bool bRet = false;
    do {
		CCSize size = CCDirector::sharedDirector()->getWinSize();

		// background
		CCSprite *background = CCSprite::create("background.png");
		background->setPosition(ccp(size.width/2,size.height/2));
		addChild(background, 0);

		// lebel of example
		exLabel = CCLabelTTF::create("Example 3.2: Forces with (arbitrary) angular motion", "Arial", 16);
		exLabel->setColor( ccc3(0,0,0));
		exLabel->setPosition(ccp(size.width/2,size.height-20));
		addChild(exLabel, 1);

		CCMenuItemImage *pMainMenuItem = CCMenuItemImage::create(
            "CloseNormal.png",
            "CloseSelected.png",
            this,
            menu_selector(Example_3_2::goMainMenu));
		CCMenu* pMenu = CCMenu::create(pMainMenuItem, NULL);
		pMenu->setPosition(CCPointZero);
		pMainMenuItem->setPosition(ccp(size.width - 20, 20));
        addChild(pMenu, 2);

		arrLength = 10;
		movers = new vector<Mover*>;

		for (int i = 0; i < arrLength; i++) {
			Mover *mover = new Mover(rand() % 5 + 1, rand() % (int)(size.width - 200) + 100, rand() % (int)(size.height));
			movers->push_back(mover);
			addChild(mover, 1);
		}

		attractor = new Attractor();
		addChild(attractor, 1);
		
		mouse = new PVector(size.width/2, size.height/2);

		schedule( schedule_selector(Example_3_2::moveCircle), 0.0 );

		setTouchEnabled(true);

        bRet = true;
    } while (0);

    return bRet;
}

void Example_3_2::goMainMenu(CCObject* pSender)
{
    CCScene *pHelloScene = HelloWorld::scene();
	CCDirector::sharedDirector()->replaceScene(pHelloScene);
}

void Example_3_2::moveCircle(float dt)
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	
	attractor->update(mouse);
	attractor->display();

	the_iterator = movers->begin();
	while (the_iterator != movers->end()) {
		PVector *force = attractor->attract(*the_iterator);
		(*the_iterator)->applyForce(force);
		(*the_iterator)->update(mouse);
		(*the_iterator)->display();

		++the_iterator;
	}
}

void Example_3_2::ccTouchesMoved(CCSet* touches, CCEvent* event)
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	CCTouch* touch = (CCTouch*)( touches->anyObject() );
	CCPoint location = touch->getLocationInView();
	location = CCDirector::sharedDirector()->convertToGL(location);

	mouse->x = location.x;
	mouse->y = location.y;
}