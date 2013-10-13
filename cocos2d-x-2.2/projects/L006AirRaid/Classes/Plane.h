//
//  Plane.h
//  L006AirRaid
//
//  Created by plter on 13-10-13.
//
//

#ifndef __L006AirRaid__Plane__
#define __L006AirRaid__Plane__

#include <iostream>
#include <cocos2d.h>

using namespace std;

USING_NS_CC;

class Plane:public CCSprite {
    
public:
    virtual bool initWithFile(const char* fileName);
    virtual void update(float dt);
    
    static Plane* create();
    static CCArray* planes;
    static CCArray* planeImgFiles;
    
private:
    float speedX;
    CCSize visibleSize;
};


#endif /* defined(__L006AirRaid__Plane__) */
