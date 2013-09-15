//
//  Ball.cpp
//  L004DrawingAPI
//
//  Created by plter on 13-9-15.
//
//

#include "Ball.h"

void Ball::draw(){
    ccDrawCircle(ccp(0, 0), 30, 360, 10, true);
}