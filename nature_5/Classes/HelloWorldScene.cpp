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

		CCLabelTTF* ex_5_2_label = CCLabelTTF::create("Example 5.2", "Arial", 20);

		CCMenuItemLabel *ex_5_2_item = CCMenuItemLabel::create(ex_5_2_label,this,menu_selector(HelloWorld::startEx_5_2));

		CCMenu* pMenu = CCMenu::create(ex_5_2_item, NULL);
        pMenu->setPosition(CCPointZero);
		ex_5_2_item->setPosition(ccp(size.width / 2, size.height - 20));

		addChild(pMenu, 1);

        bRet = true;
    } while (0);

    return bRet;
}

void HelloWorld::startEx_5_2(CCObject* pSender) {
	CCScene *pPlayScene = Example_5_2::scene();
	CCDirector::sharedDirector()->replaceScene(pPlayScene);
}

void HelloWorld::menuCloseCallback(CCObject* pSender) {
    CCDirector::sharedDirector()->end();
}