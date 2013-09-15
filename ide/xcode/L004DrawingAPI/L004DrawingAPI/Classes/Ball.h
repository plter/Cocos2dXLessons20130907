//
//  Ball.h
//  L004DrawingAPI
//
//  Created by plter on 13-9-15.
//
//

#ifndef __L004DrawingAPI__Ball__
#define __L004DrawingAPI__Ball__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class Ball:public CCSprite {
    
public:
    CREATE_FUNC(Ball);
    
    virtual void draw();
};


#endif /* defined(__L004DrawingAPI__Ball__) */
