//
//  Bullet.h
//  L006AirRaid
//
//  Created by plter on 13-10-13.
//
//

#ifndef __L006AirRaid__Bullet__
#define __L006AirRaid__Bullet__

#include <iostream>
#include <cocos2d.h>
#include "Plane.h"

USING_NS_CC;

class Bullet:public CCSprite {
    
public:
    virtual bool initWithFile(const char* fileName);
    virtual void update(float dt);
    static Bullet* create();
    
private:
    float speed;
    float maxY;
};

#endif /* defined(__L006AirRaid__Bullet__) */
