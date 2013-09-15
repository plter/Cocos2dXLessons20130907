//
//  Ball.cpp
//  L004UsingA
//
//  Created by plter on 13-9-15.
//
//

#include "Ball.h"


bool Ball::init(){
    CCSprite::init();
    
    speedX = 0;
    speedY = 0;
    aX = 0;
    aY = 0;
    ball_r = 30;
    
    scheduleUpdate();
    
    return true;
}

void Ball::update(float dt){
    speedX+=aX;
    speedY+=aY;
    
    setPositionX(getPositionX()+speedX);
    setPositionY(getPositionY()+speedY);
    
    if (getPositionX()>maxX-ball_r) {
        setPositionX(maxX-ball_r);
        
        speedX = -fabsf(speedX)/2;
    }
    if (getPositionX()<ball_r) {
        setPositionX(ball_r);
        
        speedX = fabsf(speedX)/2;
    }
    if (getPositionY()>maxY-ball_r) {
        setPositionY(maxY-ball_r);
        
        speedY = -fabsf(speedY)/2;
    }
    if (getPositionY()<ball_r) {
        setPositionY(ball_r);
        
        speedY = fabsf(speedY)/2;
    }
}

void Ball::draw(){
    ccDrawCircle(ccp(0, 0), ball_r, 360, 20, true);
}