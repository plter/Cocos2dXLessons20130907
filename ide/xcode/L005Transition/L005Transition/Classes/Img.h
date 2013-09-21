//
//  Img.h
//  L005Transition
//
//  Created by plter on 13-9-21.
//
//

#ifndef __L005Transition__Img__
#define __L005Transition__Img__

#include <iostream>

#include "cocos2d.h"
#include "HelloWorldScene.h"

USING_NS_CC;


class Img:public CCLayer {
    
public:
    CREATE_FUNC(Img);
    
    static CCScene* scene();
    virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
    
    virtual bool init();
};

#endif /* defined(__L005Transition__Img__) */
