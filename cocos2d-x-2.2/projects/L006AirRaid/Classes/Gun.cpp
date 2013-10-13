//
//  Gun.cpp
//  L006AirRaid
//
//  Created by plter on 13-10-13.
//
//

#include "Gun.h"

Gun* Gun::create(){
    
    Gun * g = new Gun();
    g->initWithFile("gun.png");
    g->setAnchorPoint(ccp(0.5, 0));
    g->autorelease();
    
    return g;
}