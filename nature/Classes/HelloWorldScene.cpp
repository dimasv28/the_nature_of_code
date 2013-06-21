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

		CCLabelTTF* ex_1_2_label = CCLabelTTF::create("Example 1.2", "Arial", 20);
		CCLabelTTF* ex_1_3_label = CCLabelTTF::create("Example 1.3-1.6", "Arial", 20);
		CCLabelTTF* ex_1_7_label = CCLabelTTF::create("Example 1.7-1.10", "Arial", 20);
		CCMenuItemLabel *ex_1_2_item = CCMenuItemLabel::create(ex_1_2_label,this,menu_selector(HelloWorld::startEx_1_2));
		CCMenuItemLabel *ex_1_3_item = CCMenuItemLabel::create(ex_1_3_label,this,menu_selector(HelloWorld::startEx_1_3));
		CCMenuItemLabel *ex_1_7_item = CCMenuItemLabel::create(ex_1_7_label,this,menu_selector(HelloWorld::startEx_1_7));

		CCMenu* pMenu = CCMenu::create(ex_1_2_item, ex_1_3_item, ex_1_7_item, NULL);
        pMenu->setPosition(CCPointZero);
		ex_1_2_item->setPosition(ccp(size.width / 2, size.height - 50));
		ex_1_3_item->setPosition(ccp(size.width / 2, size.height - 80));
		ex_1_7_item->setPosition(ccp(size.width / 2, size.height - 110));
		addChild(pMenu, 1);

        bRet = true;
    } while (0);

    return bRet;
}

void HelloWorld::startEx_1_2(CCObject* pSender)
{
	CCScene *pPlayScene = Example_1_2::scene();
	CCDirector::sharedDirector()->replaceScene(pPlayScene);
}

void HelloWorld::startEx_1_3(CCObject* pSender)
{
    CCScene *pPlayScene = Example_1_3::scene();
	CCDirector::sharedDirector()->replaceScene(pPlayScene);
}

void HelloWorld::startEx_1_7(CCObject* pSender)
{
    CCScene *pPlayScene = Example_1_7::scene();
	CCDirector::sharedDirector()->replaceScene(pPlayScene);
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    // "close" menu item clicked
    CCDirector::sharedDirector()->end();
}