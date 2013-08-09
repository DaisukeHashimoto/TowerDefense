//
//  MenuLayer.h
//  TowerDefense
//
//  Created by 橋本 大輔 on 8/7/13.
//
//

#ifndef __TowerDefense__MenuLayer__
#define __TowerDefense__MenuLayer__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class MenuLayer : public CCLayer, public CCBSelectorResolver
{
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject* pTarget, const char* pSelectorName);
    virtual SEL_CCControlHandler onResolveCCBCCControlSelector(CCObject* pTarget, const char* pSelectorName);
    
    void tappedBattleButton(CCObject* pSender, CCControlEvent pCCControlEvent);
    void tappedDeckButton(CCObject* pSender, CCControlEvent pCCControlEvent);
    
public:
    static void init_page();
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(MenuLayer, create);
};

#endif /* defined(__TowerDefense__MenuLayer__) */
