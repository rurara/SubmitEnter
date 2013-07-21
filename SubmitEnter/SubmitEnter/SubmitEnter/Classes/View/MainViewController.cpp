//
//  MainViewController.cpp
//  SubmitEnter
//
//  Created by rurara on 13. 7. 21..
//
//

#include "MainViewController.h"

using namespace cocos2d;

CCScene *MainViewController::scene(){
    CCScene *scene = CCScene::create();
    
    MainViewController *layer = MainViewController::create();
    scene->addChild(layer);
    return scene;
}

bool MainViewController::init(){
    if (!CCLayerColor::initWithColor(ccc4(255, 255, 255, 255))) {
        return false;
    }
    MainViewController::createLayout();

    return true;
}

void MainViewController::createLayout(){
    CCLog("create main view");
    
    //상단 숫자 표시 출력 부분
    CCSprite *numberDisplaySprite = CCSprite::create();
    numberDisplaySprite->setTextureRect(CCRectMake(160, 200, 320, 100));
    numberDisplaySprite->setPosition(ccp(160, 430));
    numberDisplaySprite->setColor(ccc3(120, 229, 80));

    
    
    CCLabelTTF *numberLabel = CCLabelTTF::create("label",
                                                 "Thonburi",
                                                 20,
                                                 CCSize(320,50),
                                                 kCCTextAlignmentCenter,
                                                 kCCVerticalTextAlignmentCenter);
    
    numberLabel -> setPosition(ccp(160, 50));
    numberLabel->setColor(ccc3(100, 100, 87));

    
    numberDisplaySprite->addChild(numberLabel);
    this->addChild(numberDisplaySprite);
    
    //하단 숫자 입력 키패드 부분
    
}