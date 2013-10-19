//
//  RectSprite.cpp
//  HelloBox2D
//
//  Created by plter on 13-10-19.
//
//

#include "RectSprite.h"


bool RectSprite::init(){
    CCSprite::init();
    return true;
}


void RectSprite::setB2Body(b2Body *b)  {
    _body = b;
}

void RectSprite::step(){
    setPosition(ccp(_body->GetPosition().x*80, _body->GetPosition().y*80));
    setRotation(-_body->GetAngle()*180/3.14);
}

