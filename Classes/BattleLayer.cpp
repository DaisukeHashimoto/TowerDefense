//
//  BattleLayer.cpp
//  TowerDefense
//
//  Created by 橋本 大輔 on 8/7/13.
//
//

#include "BattleLayer.h"
#include "MenuLayerLoader.h"

SEL_MenuHandler BattleLayer::onResolveCCBCCMenuItemSelector(CCObject* pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "tappedMenuButton", BattleLayer::tappedMenuButton);
    
    return NULL;
}

void BattleLayer::tappedMenuButton(CCObject* pSender, CCControlEvent pCCControlEvent)
{
    CCLOG("tappedMenuButton");
    
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

SEL_CCControlHandler BattleLayer::onResolveCCBCCControlSelector(CCObject* pTarget, const char* pSelectorName)
{
    return NULL;
}