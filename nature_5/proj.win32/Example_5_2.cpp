#include "Example_5_2.h"
#include "HelloWorldScene.h"

using namespace cocos2d;

CCScene* Example_5_2::scene() {
    CCScene * scene = NULL;
    do {
        scene = CCScene::create();
        Example_5_2 *layer = Example_5_2::create();
        scene->addChild(layer);
    } while (0);
    return scene;
}

bool Example_5_2::init() {
    bool bRet = false;
    do {
		CCSize size = CCDirector::sharedDirector()->getWinSize();

		// background
		CCSprite *background = CCSprite::create("background.png");
		background->setPosition(ccp(size.width/2,size.height/2));
		addChild(background, 0);

		// lebel of example
		exLabel = CCLabelTTF::create("Example 5.2: Falling boxes hitting boundaries", "Arial", 16);
		exLabel->setColor( ccc3(0,0,0));
		exLabel->setPosition(ccp(size.width/2,size.height-20));
		addChild(exLabel, 1);

		CCMenuItemImage *pMainMenuItem = CCMenuItemImage::create(
            "CloseNormal.png",
            "CloseSelected.png",
            this,
            menu_selector(Example_5_2::goMainMenu));
		CCMenu* pMenu = CCMenu::create(pMainMenuItem, NULL);
		pMenu->setPosition(CCPointZero);
		pMainMenuItem->setPosition(ccp(size.width - 20, 20));
        addChild(pMenu, 2);

		b2Vec2 gravity;
		gravity.Set(0, -10);

		world = new b2World(gravity);
		boundary = new Boundary(world, 200, 5, 300, 10);
		addChild(boundary, 1);
		boundary_2 = new Boundary(world, 600, 50, 300, 10);
		addChild(boundary_2, 1);

		boxes = new vector<Box*>;
		mouse = new CCPoint( ccp(size.width/2, size.height/2) );

		schedule( schedule_selector(Example_5_2::draw), 0.0 );

		setTouchEnabled(true);

        bRet = true;
    } while (0);

    return bRet;
}

void Example_5_2::goMainMenu(CCObject* pSender) {
    CCScene *pHelloScene = HelloWorld::scene();
	CCDirector::sharedDirector()->replaceScene(pHelloScene);
}

void Example_5_2::draw(float dt) {
	boundary->display();
	boundary_2->display();

	the_iterator = boxes->begin();
	while ( the_iterator != boxes->end() ) {
		(*the_iterator)->display();
		++the_iterator;
	}

	world->Step(dt, 1, 1);
}

void Example_5_2::addBoxes(float dt) {
	Box *box = new Box(world, mouse);
	boxes->push_back(box);
	addChild(box, 1);
}

void Example_5_2::ccTouchesBegan(CCSet* touches, CCEvent* event)
{
	CCTouch* touch = (CCTouch*)( touches->anyObject() );
	CCPoint location = touch->getLocationInView();
	location = CCDirector::sharedDirector()->convertToGL(location);

	mouse->setPoint(location.x, location.y);

	addBoxes(0);
	schedule( schedule_selector(Example_5_2::addBoxes), 0.1 );
}

void Example_5_2::ccTouchesMoved(CCSet* touches, CCEvent* event)
{
	CCTouch* touch = (CCTouch*)( touches->anyObject() );
	CCPoint location = touch->getLocationInView();
	location = CCDirector::sharedDirector()->convertToGL(location);

	mouse->setPoint(location.x, location.y);
}

void Example_5_2::ccTouchesEnded(CCSet* touches, CCEvent* event)
{
	unschedule( schedule_selector(Example_5_2::addBoxes) );
}