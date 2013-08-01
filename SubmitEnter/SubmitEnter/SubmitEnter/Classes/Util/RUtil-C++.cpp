//
//  RUtil-C++.cpp
//  SubmitEnter
//
//  Created by As one on 13. 8. 1..
//
//

#include "RUtil-C++.h"

bool isRetinaDisplay()
{
#if (ANDROID_BUILD_LEVEL_1 == 1)
    return true;
#endif
    CCDirector* pDirector = CCDirector::sharedDirector();
    float nScaleFactor = pDirector->getContentScaleFactor();
    
    bool nIsRetinaDisplay = false;
    if (nScaleFactor >= 2)
    {
        nIsRetinaDisplay = true;
    }
    
    return nIsRetinaDisplay;
    
}

bool is4InchDisplay(){
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();
    CCSize frameSize = pEGLView->getFrameSize();
    
    if (frameSize.height == 1136) {
        return true;
    } else {
        return false;
    }
    
}