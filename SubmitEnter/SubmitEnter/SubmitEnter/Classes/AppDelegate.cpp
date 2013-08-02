//
//  SubmitEnterAppDelegate.cpp
//  SubmitEnter
//
//  Created by rurara on 13. 7. 21..
//  Copyright __MyCompanyName__ 2013년. All rights reserved.
//

#include "AppDelegate.h"

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
//#include "HelloWorldScene.h"
#include "MainViewController.h"

USING_NS_CC;
using namespace CocosDenshion;

AppDelegate::AppDelegate()
{

}

AppDelegate::~AppDelegate()
{
}


typedef struct tagResource
{
    cocos2d::CCSize size;
    char directory[100];
    cocos2d::CCSize designResolutionSize;
}Resource;

static Resource iphone  =  { cocos2d::CCSizeMake(320, 480), "iphone", cocos2d::CCSizeMake(320, 480)};
static Resource iphone_retina =  { cocos2d::CCSizeMake(640, 960), "iphone-retina", cocos2d::CCSizeMake(320, 480)};
static Resource iphone5 =  { cocos2d::CCSizeMake(640, 1136), "iphone5", cocos2d::CCSizeMake(320, 568)};
static Resource ipad =  { cocos2d::CCSizeMake(1024, 768), "ipad", cocos2d::CCSizeMake(512, 384)};       //현재 사용하지 않음

bool AppDelegate::applicationDidFinishLaunching()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();
    
    pDirector->setOpenGLView(pEGLView);
    
    // Set the design resolution
    pEGLView->setDesignResolutionSize(iphone.designResolutionSize.width, iphone.designResolutionSize.height, kResolutionShowAll);
    
    CCSize frameSize = pEGLView->getFrameSize();
    
    std::vector<std::string> paths;
    
    if (frameSize.height <= iphone.size.height)
    {
        CCLOG("iphone display[%f] - 3.5",frameSize.height);
        paths.push_back(iphone.directory);
        pDirector->setContentScaleFactor(iphone.size.height/iphone.designResolutionSize.height);
    }
    else if(frameSize.height == iphone5.size.height)
    {
        CCLOG("iphone display[%f] - 4",frameSize.height);
        paths.push_back(iphone5.directory);
        paths.push_back(iphone_retina.directory);
        
        pEGLView->setDesignResolutionSize(iphone5.designResolutionSize.width, iphone5.designResolutionSize.height, kResolutionShowAll);
        
        pDirector->setContentScaleFactor(iphone5.size.height / iphone5.designResolutionSize.height);
    }
    else
    {
        if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS){
            paths.push_back(iphone_retina.directory);
            //            pEGLView->setDesignResolutionSize(iphone_retina.size.width / 2, iphone_retina.size.height / 2, kResolutionExactFit);       //요걸 해제하면 아이패드에서 위아래 여백이 사라진다. 그러나 위아래로 약간 늘어남
            pDirector->setContentScaleFactor(iphone_retina.size.height/iphone_retina.designResolutionSize.height / pDirector->getContentScaleFactor());
        }
        else{
            //안드로이드는 좌우가 긴화면이 더많으므로 아이폰5 리소스를 이용한다.
            paths.push_back(iphone5.directory);
            paths.push_back(iphone_retina.directory);
            
            pEGLView->setDesignResolutionSize(iphone5.designResolutionSize.width, iphone5.designResolutionSize.height, kResolutionShowAll);
            pDirector->setContentScaleFactor(iphone5.size.height / iphone5.designResolutionSize.height);
        }
    }
    
    CCFileUtils::sharedFileUtils()->setSearchPaths(paths);
    
    // turn on display FPS
    pDirector->setDisplayStats(true);
    
    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);
    
    // create a scene. it's an autorelease object
    CCScene *pScene = MainViewController::scene();
    
    // run
    pDirector->runWithScene(pScene);
    
    return true;
}

//
//bool AppDelegate::applicationDidFinishLaunching()
//{
//    // initialize director
//    CCDirector *pDirector = CCDirector::sharedDirector();
//    pDirector->setOpenGLView(CCEGLView::sharedOpenGLView());
//    // turn on display FPS
//    pDirector->setDisplayStats(true);
//
//    // set FPS. the default value is 1.0/60 if you don't call this
//    pDirector->setAnimationInterval(1.0 / 60);
//
//    // create a scene. it's an autorelease object
//    CCScene *pScene = MainViewController::scene();
//
//    // run
//    pDirector->runWithScene(pScene);
//
//    return true;
//}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->stopAnimation();
    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->pauseAllEffects();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->startAnimation();
    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->resumeAllEffects();
}
