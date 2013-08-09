//
//  BattleLayer.h
//  TowerDefense
//
//  Created by 橋本 大輔 on 8/7/13.
//
//

#ifndef __TowerDefense__BattleLayer__
#define __TowerDefense__BattleLayer__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class BattleLayer : public CCLayer, public CCBSelectorResolver
{
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject* pTarget, const char* pSelectorName);
    virtual SEL_CCControlHandler onResolveCCBCCControlSelector(CCObject* pTarget, const char* pSelectorName);
    
    void tappedMenuButton(CCObject* pSender, CCControlEvent pCCControlEvent);
    
public:
    static void init_page();
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(BattleLayer, create);
};

#endif /* defined(__TowerDefense__BattleLayer__) */
