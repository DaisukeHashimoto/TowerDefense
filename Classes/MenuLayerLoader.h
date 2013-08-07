//
//  MenuLayerLoader.h
//  TowerDefense
//
//  Created by 橋本 大輔 on 8/7/13.
//
//

#ifndef TowerDefense_MenuLayerLoader_h
#define TowerDefense_MenuLayerLoader_h

#include "MenuLayer.h"

class MenuLayerLoader : public cocos2d::extension::CCLayerLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(MenuLayerLoader, loader);

protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(MenuLayer);
};

#endif
