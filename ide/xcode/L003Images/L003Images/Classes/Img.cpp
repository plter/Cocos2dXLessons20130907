//
//  Img.cpp
//  L003Images
//
//  Created by plter on 13-9-14.
//
//

#include "Img.h"


bool Img::init(){
    if (!initWithFile("img.jpg")) {
        return false;
    }
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    maxHeight = size.height;
    maxWidth = size.width;
    
    CCSize contentSize = getContentSize();
    
    halfWidth = contentSize.width/2;
    halfHeight = contentSize.height/2;
    
//    CCLog("maxWidth:%f,maxHeight:%f",maxWidth,maxHeight);
    
    speedX = 1+CCRANDOM_0_1()*5;
    speedY = 1+CCRANDOM_0_1()*5;
    
//    CCLog("speedX:%f,speedY:%f",speedX,speedY);
    
    scheduleUpdate();
    
//    frames=0;
    
    return true;
}


void Img::update(float dt){
//    frames++;
//    
//    if (frames>60) {
//        unscheduleUpdate();
//    }
//    CCLog(">>>>>>>>");
    
    setPositionY(getPositionY()+speedY);
    setPositionX(getPositionX()+speedX);
    
    if (getPositionX()<halfWidth) {
        speedX = fabsf(speedX);
    }
    if (getPositionX()>maxWidth-halfWidth) {
        speedX = -fabsf(speedX);
    }
    if (getPositionY()<halfHeight) {
        speedY = fabsf(speedY);
    }
    if (getPositionY()>maxHeight-halfHeight) {
        speedY = -fabsf(speedY);
    }
}