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
   
    int displayInclaseValue = 0;
    
    if(isRetinaDisplay()){
        CCLOG("retina!");
    } else {
        CCLOG("no retina!");
    }
    
    if (is4InchDisplay()) {
        CCLOG("4inch");
        displayInclaseValue = 88;
    } else {
        CCLOG("3.5 inch");
    }
    
    //상단 숫자 표시 출력 부분
    CCSprite *numberDisplaySprite = CCSprite::create();
    numberDisplaySprite->setTextureRect(CCRectMake(160, 200, 320, 100));
    numberDisplaySprite->setPosition(CCPointMake(160, 430 + displayInclaseValue));
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
    
    
    //button layer
    CCLayerColor *buttonLayer = CCLayerColor::create(ccc4(255, 0, 0, 255),320,380);
    buttonLayer->setPosition(ccp(0,0));

    CCMenu *buttonMenu = CCMenu::create();

    for (int i=1; i<=9; i++) {

        CCSprite *backgroundSprite = CCSprite::create();
        backgroundSprite->setTextureRect(CCRectMake(0+i*10, 0+i*10, 200, 200));
        backgroundSprite->setColor(ccBLUE);
        
        
        CCString *text = CCString::createWithFormat("%d",i);
        
        CCMenuItemFont *numberButton = CCMenuItemFont::create(text->getCString(), this,menu_selector(MainViewController::tapNumberButtonAction));
        numberButton->setColor(ccc3(0, 0, 0));
        numberButton->setTag(i);


//        backgroundSprite->addChild(numberButton);
//        buttonLayer->addChild(backgroundSprite);
        buttonMenu->addChild(numberButton);
    }
    


    
    buttonMenu->alignItemsInColumns(3,3,3,NULL);
    
    buttonLayer -> addChild(buttonMenu);
    
    this->addChild(buttonLayer);
    
    
    
    //하단 숫자 입력 키패드 부분
    
}


void MainViewController::tapNumberButtonAction(CCObject* sender){
    CCMenuItem *button = (CCMenuItem *)sender;
    int buttonTag = button->getTag();
    CCLOG("tap number - %d",buttonTag);
    
}

