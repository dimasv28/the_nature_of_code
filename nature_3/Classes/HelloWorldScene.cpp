#include "HelloWorldScene.h"

using namespace cocos2d;

CCScene* HelloWorld::scene() {
    CCScene * scene = NULL;
    do {
        scene = CCScene::create();
        HelloWorld *layer = HelloWorld::create();
        scene->addChild(layer);
    } while (0);
    return scene;
}

bool HelloWorld::init() {
    bool bRet = false;
    do {
		CCSize size = CCDirector::sharedDirector()->getWinSize();

		CCLabelTTF* ex_3_1_label = CCLabelTTF::create("Example 3.1", "Arial", 20);
		CCLabelTTF* ex_3_2_label = CCLabelTTF::create("Example 3.2", "Arial", 20);
		CCLabelTTF* ex_3_3_label = CCLabelTTF::create("Example 3.3", "Arial", 20);
		CCLabelTTF* ex_3_4_label = CCLabelTTF::create("Example 3.4", "Arial", 20);
		CCLabelTTF* ex_3_5_label = CCLabelTTF::create("Example 3.5", "Arial", 20);
		CCLabelTTF* ex_3_7_label = CCLabelTTF::create("Example 3.7", "Arial", 20);
		CCLabelTTF* ex_3_8_label = CCLabelTTF::create("Example 3.8", "Arial", 20);
		CCLabelTTF* ex_3_9_label = CCLabelTTF::create("Example 3.9", "Arial", 20);
		CCLabelTTF* ex_3_10_label = CCLabelTTF::create("Example 3.10", "Arial", 20);

		CCMenuItemLabel *ex_3_1_item = CCMenuItemLabel::create(ex_3_1_label,this,menu_selector(HelloWorld::startEx_3_1));
		CCMenuItemLabel *ex_3_2_item = CCMenuItemLabel::create(ex_3_2_label,this,menu_selector(HelloWorld::startEx_3_2));
		CCMenuItemLabel *ex_3_3_item = CCMenuItemLabel::create(ex_3_3_label,this,menu_selector(HelloWorld::startEx_3_3));
		CCMenuItemLabel *ex_3_4_item = CCMenuItemLabel::create(ex_3_4_label,this,menu_selector(HelloWorld::startEx_3_4));
		CCMenuItemLabel *ex_3_5_item = CCMenuItemLabel::create(ex_3_5_label,this,menu_selector(HelloWorld::startEx_3_5));
		CCMenuItemLabel *ex_3_7_item = CCMenuItemLabel::create(ex_3_7_label,this,menu_selector(HelloWorld::startEx_3_7));
		CCMenuItemLabel *ex_3_8_item = CCMenuItemLabel::create(ex_3_8_label,this,menu_selector(HelloWorld::startEx_3_8));
		CCMenuItemLabel *ex_3_9_item = CCMenuItemLabel::create(ex_3_9_label,this,menu_selector(HelloWorld::startEx_3_9));
		CCMenuItemLabel *ex_3_10_item = CCMenuItemLabel::create(ex_3_10_label,this,menu_selector(HelloWorld::startEx_3_10));

		CCMenu* pMenu = CCMenu::create(ex_3_1_item, ex_3_2_item, ex_3_3_item, ex_3_4_item, ex_3_5_item, ex_3_7_item, ex_3_8_item, ex_3_9_item, ex_3_10_item, NULL);
        pMenu->setPosition(CCPointZero);
		ex_3_1_item->setPosition(ccp(size.width / 2, size.height - 20));
		ex_3_2_item->setPosition(ccp(size.width / 2, size.height - 40));
		ex_3_3_item->setPosition(ccp(size.width / 2, size.height - 60));
		ex_3_4_item->setPosition(ccp(size.width / 2, size.height - 80));
		ex_3_5_item->setPosition(ccp(size.width / 2, size.height - 100));
		ex_3_7_item->setPosition(ccp(size.width / 2, size.height - 120));
		ex_3_8_item->setPosition(ccp(size.width / 2, size.height - 140));
		ex_3_9_item->setPosition(ccp(size.width / 2, size.height - 160));
		ex_3_10_item->setPosition(ccp(size.width / 2, size.height - 180));
		addChild(pMenu, 1);

        bRet = true;
    } while (0);

    return bRet;
}

void HelloWorld::startEx_3_1(CCObject* pSender) {
	CCScene *pPlayScene = Example_3_1::scene();
	CCDirector::sharedDirector()->replaceScene(pPlayScene);
}

void HelloWorld::startEx_3_2(CCObject* pSender) {
	CCScene *pPlayScene = Example_3_2::scene();
	CCDirector::sharedDirector()->replaceScene(pPlayScene);
}

void HelloWorld::startEx_3_3(CCObject* pSender) {
	CCScene *pPlayScene = Example_3_3::scene();
	CCDirector::sharedDirector()->replaceScene(pPlayScene);
}

void HelloWorld::startEx_3_4(CCObject* pSender) {
	CCScene *pPlayScene = Example_3_4::scene();
	CCDirector::sharedDirector()->replaceScene(pPlayScene);
}

void HelloWorld::startEx_3_5(CCObject* pSender) {
	CCScene *pPlayScene = Example_3_5::scene();
	CCDirector::sharedDirector()->replaceScene(pPlayScene);
}

void HelloWorld::startEx_3_7(CCObject* pSender) {
	CCScene *pPlayScene = Example_3_7::scene();
	CCDirector::sharedDirector()->replaceScene(pPlayScene);
}

void HelloWorld::startEx_3_8(CCObject* pSender) {
	CCScene *pPlayScene = Example_3_8::scene();
	CCDirector::sharedDirector()->replaceScene(pPlayScene);
}

void HelloWorld::startEx_3_9(CCObject* pSender) {
	CCScene *pPlayScene = Example_3_9::scene();
	CCDirector::sharedDirector()->replaceScene(pPlayScene);
}

void HelloWorld::startEx_3_10(CCObject* pSender) {
	CCScene *pPlayScene = Example_3_10::scene();
	CCDirector::sharedDirector()->replaceScene(pPlayScene);
}

void HelloWorld::menuCloseCallback(CCObject* pSender) {
    CCDirector::sharedDirector()->end();
}