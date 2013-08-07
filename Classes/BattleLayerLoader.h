//
//  BattleLayerLoader.h
//  TowerDefense
//
//  Created by 橋本 大輔 on 8/7/13.
//
//

#ifndef TowerDefense_BattleLayerLoader_h
#define TowerDefense_BattleLayerLoader_h

#include "BattleLayer.h"

class BattleLayerLoader : public cocos2d::extension::CCLayerLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(BattleLayerLoader, loader);
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(BattleLayer);
};

#endif
