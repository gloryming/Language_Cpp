//
//  LanguageTest.h
//  Language_Cpp
//
//  Created by 郭 一鸣 on 14-1-7.
//
//

#ifndef __Language_Cpp__LanguageTest__
#define __Language_Cpp__LanguageTest__

#include <iostream>
#include "cocos2d.h"

class LanguageTest : public cocos2d::Layer
{
public:
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    
    void loopCallback(Object* pSender);
    
    void callfuncCallback(Object* pSender);
    
    void mat4Callback(Object* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(LanguageTest);
};

#endif /* defined(__Language_Cpp__LanguageTest__) */
