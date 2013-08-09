//
//  MenuLayer.cpp
//  TowerDefense
//
//  Created by 橋本 大輔 on 8/7/13.
//
//

#include "MenuLayer.h"
#include "BattleLayer.h"
#include "MenuLayerLoader.h"

void MenuLayer::init_page()
{
    // cocos builder 読み込み
    CCNodeLoaderLibrary* ccNodeLoaderLibrary = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    ccNodeLoaderLibrary->registerCCNodeLoader("MenuLayer", MenuLayerLoader::loader());
    CCBReader* ccbReader = new CCBReader(ccNodeLoaderLibrary);
    CCNode* node = ccbReader->readNodeGraphFromFile("MenuLayer.ccbi");
    
    CCScene* pScene = CCScene::create();
    if (node != NULL) {
        pScene->addChild(node);
    }
    ccbReader->release();
    
    // run
    CCDirector::sharedDirector()->replaceScene(pScene);
}

SEL_MenuHandler MenuLayer::onResolveCCBCCMenuItemSelector(CCObject* pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "tappedBattleButton", MenuLayer::tappedBattleButton);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "tappedDeckButton", MenuLayer::tappedDeckButton);
    
    return NULL;
}

void MenuLayer::tappedBattleButton(CCObject* pSender, CCControlEvent pCCControlEvent)
{
    CCLOG("tappedBattleButton");
    
    // バトルページヘ
    BattleLayer::init_page();
}

void MenuLayer::tappedDeckButton(CCObject* pSender, CCControlEvent pCCControlEvent)
{
    CCLOG("tappedDeckButton");
}

SEL_CCControlHandler MenuLayer::onResolveCCBCCControlSelector(CCObject* pTarget, const char* pSelectorName)
{
    return NULL;
}