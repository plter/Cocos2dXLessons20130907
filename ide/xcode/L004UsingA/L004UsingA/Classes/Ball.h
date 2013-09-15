//
//  Ball.h
//  L004UsingA
//
//  Created by plter on 13-9-15.
//
//

#ifndef __L004UsingA__Ball__
#define __L004UsingA__Ball__

#include <iostream>

#include "cocos2d.h"

USING_NS_CC;

class Ball :public CCSprite{
    
public:
    float maxX,maxY;
    
public:
    virtual void draw();
    CREATE_FUNC(Ball);
    
    virtual bool init();
    virtual void update(float dt);
    
    virtual void setAX(float value){
        aX = value;
    };
    virtual float getAX(){
        return aX;
    };
    virtual void setAY(float value){
        aY = value;
    };
    virtual float getAY(){
        return aY;
    };
    
private:
    float speedX,speedY,aX,aY,ball_r;
};

#endif /* defined(__L004UsingA__Ball__) */
