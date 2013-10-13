//
//  Plane.cpp
//  L006AirRaid
//
//  Created by plter on 13-10-13.
//
//

#include "Plane.h"

CCArray* Plane::planes = new CCArray();
CCArray* Plane::planeImgFiles = new CCArray();

Plane* Plane::create(){
    
    if (planeImgFiles->count()<=0) {
        planeImgFiles->addObject(CCString::create("p1.png"));
        planeImgFiles->addObject(CCString::create("p2.png"));
        planeImgFiles->addObject(CCString::create("p3.png"));
        planeImgFiles->addObject(CCString::create("p4.png"));
        planeImgFiles->addObject(CCString::create("p5.png"));
    }
    
    Plane* p = new Plane();
    planes->addObject(p);
    p->initWithFile(((CCString*)planeImgFiles->objectAtIndex(rand()%5))->getCString());
    p->autorelease();
    return p;
}


bool Plane::initWithFile(const char *fileName){
    CCSprite::initWithFile(fileName);
    
    visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    if (rand()%2) {
        setPosition(ccp(visibleSize.width, visibleSize.height-30));
        speedX = -(rand()%3+2);
        setAnchorPoint(ccp(0, 1));
    }else{
        speedX = rand()%3+2;
        setScaleX(-1);
        setPosition(ccp(-50, visibleSize.height-30));
    }
    
    scheduleUpdate();
    return true;
}

void Plane::update(float dt){
    
    setPositionX(getPositionX()+speedX);
    if (getScaleX()>0) {
        if (getPositionX()<-getContentSize().width) {
            unscheduleUpdate();
            planes->removeObject(this);
            getParent()->removeChild(this);
        }
    }else{
        if (getPositionX()>visibleSize.width+getContentSize().width) {
            unscheduleUpdate();
            planes->removeObject(this);
            getParent()->removeChild(this);
        }
    }
}