//
//  MainViewController.h
//  SubmitEnter
//
//  Created by rurara on 13. 7. 21..
//
//

#ifndef __SubmitEnter__MainViewController__
#define __SubmitEnter__MainViewController__

#include <iostream>
#include "cocos2d.h"

class MainViewController : public cocos2d::CCLayerColor {
    
public:
    virtual bool init();
    static cocos2d::CCScene *scene();
    
    CREATE_FUNC(MainViewController);
    void createLayout();
};
#endif



