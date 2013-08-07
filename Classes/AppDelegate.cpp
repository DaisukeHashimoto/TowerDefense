#include "AppDelegate.h"

// マルチレゾリューション対応
#include "AppMacros.h"
#include "cocos-ext.h"

#include "MenuLayerLoader.h"
#include "BattleLayerLoader.h"

USING_NS_CC;
USING_NS_CC_EXT;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();

    pDirector->setOpenGLView(pEGLView);
	

    // マルチレゾリューション対応 START
    // Set the design resolution
    pEGLView->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, kResolutionShowAll);
    
	CCSize frameSize = pEGLView->getFrameSize();
    
    std::vector<std::string> searchPath;
    
    // In this demo, we select resource according to the frame's height.
    // If the resource size is different from design resolution size, you need to set contentScaleFactor.
    // We use the ratio of resource's height to the height of design resolution,
    // this can make sure that the resource's height could fit for the height of design resolution.
    
    
    cocos2d::CCLog("-------");
    cocos2d::CCLog("height:%f", frameSize.height);
    cocos2d::CCLog("width:%f", frameSize.width);
	if (frameSize.height > largeResource.size.height)
	{
        cocos2d::CCLog("xlargeResource");
        searchPath.push_back(xlargeResource.directory);
        pDirector->setContentScaleFactor(MIN(xlargeResource.size.height/designResolutionSize.height, xlargeResource.size.width/designResolutionSize.width));
	}
    else if (frameSize.height > smallResource.size.height)
    {
        cocos2d::CCLog("largeResource");
        searchPath.push_back(largeResource.directory);
        pDirector->setContentScaleFactor(MIN(largeResource.size.height/designResolutionSize.height, largeResource.size.width/designResolutionSize.width));
    }
	else
    {
        cocos2d::CCLog("smallResource");
        searchPath.push_back(smallResource.directory);
        pDirector->setContentScaleFactor(MIN(smallResource.size.height/designResolutionSize.height, smallResource.size.width/designResolutionSize.width));
    }
    
    
    // デバッグログ
    for (std::vector<std::string>::iterator itiElement = searchPath.begin(); itiElement != searchPath.end(); ++itiElement) {
        std::string iElement = *itiElement;      // itiElement を使って繰り返し、配列要素を扱う。
        cocos2d::CCLog("searchPath:%s", iElement.c_str());
    }
    float scale = pDirector->getContentScaleFactor();
    cocos2d::CCLog("scale:%f", scale);

    
    // set searching path
    CCFileUtils::sharedFileUtils()->setSearchPaths(searchPath);
    // マルチレゾリューション対応 END
    
    
    // turn on display FPS
    pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);
    
    
    // create a scene. it's an autorelease object
    //CCScene *pScene = Menu::scene();
    
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
    pDirector->runWithScene(pScene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    CCDirector::sharedDirector()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    CCDirector::sharedDirector()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
