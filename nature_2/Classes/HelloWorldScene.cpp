#include "HelloWorldScene.h"

using namespace cocos2d;

CCScene* HelloWorld::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        HelloWorld *layer = HelloWorld::create();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    bool bRet = false;
    do 
    {
		CCSize size = CCDirector::sharedDirector()->getWinSize();

		CCLabelTTF* ex_2_1_label = CCLabelTTF::create("Example 2.1", "Arial", 20);
		CCLabelTTF* ex_2_2_label = CCLabelTTF::create("Example 2.2", "Arial", 20);
		CCLabelTTF* ex_2_3_label = CCLabelTTF::create("Example 2.3-2.4", "Arial", 20);
		CCMenuItemLabel *ex_2_1_item = CCMenuItemLabel::create(ex_2_1_label,this,menu_selector(HelloWorld::startEx_2_1));
		CCMenuItemLabel *ex_2_2_item = CCMenuItemLabel::create(ex_2_2_label,this,menu_selector(HelloWorld::startEx_2_2));
		CCMenuItemLabel *ex_2_3_item = CCMenuItemLabel::create(ex_2_3_label,this,menu_selector(HelloWorld::startEx_2_3));

		CCMenu* pMenu = CCMenu::create(ex_2_1_item, ex_2_2_item, ex_2_3_item, NULL);
        pMenu->setPosition(CCPointZero);
		ex_2_1_item->setPosition(ccp(size.width / 2, size.height - 80));
		ex_2_2_item->setPosition(ccp(size.width / 2, size.height - 110));
		ex_2_3_item->setPosition(ccp(size.width / 2, size.height - 140));
		addChild(pMenu, 1);

        bRet = true;
    } while (0);

    return bRet;
}

void HelloWorld::startEx_2_1(CCObject* pSender)
{
	CCScene *pPlayScene = Example_2_1::scene();
	CCDirector::sharedDirector()->replaceScene(pPlayScene);
}

void HelloWorld::startEx_2_2(CCObject* pSender)
{
	CCScene *pPlayScene = Example_2_2::scene();
	CCDirector::sharedDirector()->replaceScene(pPlayScene);
}

void HelloWorld::startEx_2_3(CCObject* pSender)
{
	CCScene *pPlayScene = Example_2_3::scene();
	CCDirector::sharedDirector()->replaceScene(pPlayScene);
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    // "close" menu item clicked
    CCDirector::sharedDirector()->end();
}