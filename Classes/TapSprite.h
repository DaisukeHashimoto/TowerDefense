//
//  TapSprite.h
//  TowerDefense
//
//  Created by 橋本 大輔 on 8/8/13.
//
//

#ifndef __TowerDefense__TapSprite__
#define __TowerDefense__TapSprite__

#include <iostream>
#include "cocos2d.h"

NS_CC_BEGIN

class TapSprite : public CCSprite, public CCTargetedTouchDelegate
{
public:
    static TapSprite* create(const char *pszFileName);
    virtual void onEnter();
    virtual void onExit();
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);
};

NS_CC_END


#endif /* defined(__TowerDefense__TapSprite__) */
