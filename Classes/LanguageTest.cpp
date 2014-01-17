//
//  LanguageTest.cpp
//  Language_Cpp
//
//  Created by 郭 一鸣 on 14-1-7.
//
//

#include "LanguageTest.h"
USING_NS_CC;

#define   N_Loop 1000
#define   N_Call 1000000
#define   N_MAT4 100000

int addFunc(int a, int b)
{
    return a + b;
}

void multiplayMatrix(int a[][4], int b[][4], int* &c)
{
    int sum = 0;
    int n = 0;
    
    for (int i = 0; i < 4; ++i) {
        while (n < 4) {
            for (int j = 0; j < 4; ++j) {
                sum += a[i][j] * b[j][n];
            }
            c[i * 4 + n] = sum;
            ++n;
            sum = 0;
        }
        n = 0;
    }
}

unsigned long getCurrentTime()
{
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

bool LanguageTest::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    auto loop = LabelTTF::create("Loop Test", "Arial", 30);
    auto call = LabelTTF::create("CallFunc Test", "Arial", 30);
    auto mat4 = LabelTTF::create("MAT4 Test", "Arial", 30);
    
    auto loopItem = MenuItemLabel::create(loop, CC_CALLBACK_1(LanguageTest::loopCallback, this));
    auto callItem = MenuItemLabel::create(call, CC_CALLBACK_1(LanguageTest::callfuncCallback, this));
    auto mat4Item = MenuItemLabel::create(mat4, CC_CALLBACK_1(LanguageTest::mat4Callback, this));
    
    loopItem->setPosition(Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 3 * 2));
    callItem->setPosition(Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
    mat4Item->setPosition(Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 3));
    
    auto menu = Menu::create(loopItem, callItem, mat4Item, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    return true;
}

void LanguageTest::loopCallback(Object* pSender)
{
    int i = 0;
    
    unsigned long start = getCurrentTime();
    
    while (i < N_Loop) {
        i++;
        CCLOG("Count: %d", i);
    }
    
    unsigned long end = getCurrentTime();
    unsigned long duration = end - start;
    
    CCLOG("Loop:start = %lu, end = %lu, duration = %lu", start, end, duration);
}

void LanguageTest::callfuncCallback(Object* pSender)
{
    int sum = 0, i = 0;
    
    unsigned long start = getCurrentTime();
    
    while (i < N_Call) {
        sum += addFunc(i, 1);
        i++;
    }
    
    unsigned long end = getCurrentTime();
    unsigned long duration = end - start;
    
    CCLOG("CallFunc:start = %lu, end = %lu, duration = %lu", start, end, duration);
}

void LanguageTest::mat4Callback(Object* pSender)
{
    int* c = new int[16];
    int i = 0;
    int a[4][4] = {{1, 2, 3, 4}, {2, 3, 4, 5}, {3, 4, 5, 6}, {4, 5, 6, 7}};
    int b[4][4] = {{5, 6, 7, 8}, {6, 7, 8, 9}, {7, 8, 9, 10}, {8, 9, 10, 11}};
    
    unsigned long start = getCurrentTime();
    
    while (i < N_MAT4) {
        multiplayMatrix(a, b, c);
        i++;
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            CCLOG("c[%d][%d] = %d", i, j, c[i * 4 + j]);
        }
    }
    unsigned long end = getCurrentTime();
    unsigned long duration = end - start;
    
    CCLOG("MAT4:start = %lu, end = %lu, duration = %lu", start, end, duration);
    
    delete[] c;
}