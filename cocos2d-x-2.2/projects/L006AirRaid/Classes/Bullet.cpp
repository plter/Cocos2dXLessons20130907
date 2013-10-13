//
//  Bullet.cpp
//  L006AirRaid
//
//  Created by plter on 13-10-13.
//
//

#include "Bullet.h"

Bullet* Bullet::create(){
    Bullet* b = new Bullet();
    b->initWithFile("bullet.png");
    b->autorelease();
    return b;
}

bool Bullet::initWithFile(const char *fileName){
    CCSprite::initWithFile(fileName);
    
    maxY = CCDirector::sharedDirector()->getVisibleSize().height;
    speed = 8;
    setAnchorPoint(ccp(0.5, 0));
    scheduleUpdate();
    return true;
}

void Bullet::update(float dt){
    setPositionY(getPositionY()+speed);
    
    CCObject* obj;
    Plane* p;
    CCARRAY_FOREACH(Plane::planes, obj){
        p = (Plane*)obj;
        if (p->boundingBox().intersectsRect(boundingBox())) {
            unscheduleUpdate();
            getParent()->removeChild(this);
            
            Plane::planes->removeObject(p);
            p->getParent()->removeChild(p);
            
            break;
        }
    };
    
    if (getPositionY()>maxY) {
        unscheduleUpdate();
        getParent()->removeChild(this);
    }
}

