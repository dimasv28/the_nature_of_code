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

		CCMenuItemLabel *ex_3_1_item = CCMenuItemLabel::create(ex_3_1_label,this,menu_selector(HelloWorld::startEx_3_1));

		CCMenu* pMenu = CCMenu::create(ex_3_1_item, NULL);
        pMenu->setPosition(CCPointZero);
		ex_3_1_item->setPosition(ccp(size.width / 2, size.height - 50));
		addChild(pMenu, 1);

        bRet = true;
    } while (0);

    return bRet;
}

void HelloWorld::startEx_3_1(CCObject* pSender) {
	CCScene *pPlayScene = Example_3_1::scene();
	CCDirector::sharedDirector()->replaceScene(pPlayScene);
}

void HelloWorld::menuCloseCallback(CCObject* pSender) {
    CCDirector::sharedDirector()->end();
}