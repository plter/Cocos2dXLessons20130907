//
//  RectSprite.h
//  HelloBox2D
//
//  Created by plter on 13-10-19.
//
//

#ifndef __HelloBox2D__RectSprite__
#define __HelloBox2D__RectSprite__

#include <iostream>
#include "cocos2d.h"
#include "Box2D.h"

USING_NS_CC;

class RectSprite:public CCSprite {
    
public:
    virtual bool init();
    virtual void setB2Body(b2Body* b);
    virtual void step();
    
    CREATE_FUNC(RectSprite);
private:
    b2Body* _body;
};


#endif /* defined(__HelloBox2D__RectSprite__) */
