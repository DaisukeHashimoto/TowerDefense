//
//  BattleLayer.cpp
//  TowerDefense
//
//  Created by 橋本 大輔 on 8/7/13.
//
//

#include "BattleLayer.h"
#include "BattleLayerLoader.h"
#include "TapSprite.h"
#include "MenuLayer.h"

void BattleLayer::init_page()
{
    // cocos builder 読み込み
    CCNodeLoaderLibrary* ccNodeLoaderLibrary = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    ccNodeLoaderLibrary->registerCCNodeLoader("BattleLayer", BattleLayerLoader::loader());
    CCBReader* ccbReader = new CCBReader(ccNodeLoaderLibrary);
    CCNode* node = ccbReader->readNodeGraphFromFile("BattleLayer.ccbi");
    
    CCScene* pScene = CCScene::create();
    if (node != NULL) {
        pScene->addChild(node);
    }
    ccbReader->release();
    
    // カードストック表示
    TapSprite* sprite = (TapSprite*)TapSprite::create("1.png");
    sprite->setPosition(ccp(100, 100));
    sprite->setTag(100);
    node->addChild(sprite);
    
    // run
    CCDirector::sharedDirector()->replaceScene(pScene);
}

SEL_MenuHandler BattleLayer::onResolveCCBCCMenuItemSelector(CCObject* pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "tappedMenuButton", BattleLayer::tappedMenuButton);
    
    return NULL;
}

void BattleLayer::tappedMenuButton(CCObject* pSender, CCControlEvent pCCControlEvent)
{
    CCLOG("tappedMenuButton");
    
    // メニューページヘ
    MenuLayer::init_page();
}

SEL_CCControlHandler BattleLayer::onResolveCCBCCControlSelector(CCObject* pTarget, const char* pSelectorName)
{
    return NULL;
}