//
//  ColorRect.cpp
//  L005AddCards
//
//  Created by plter on 13-9-21.
//
//

#include "ColorRect.h"

ColorRect* ColorRect::create(ccColor4F color,const CCSize& size){
    ColorRect* r = new ColorRect();
    r->initWithColor(color,size);
    r->autorelease();
    return r;
}


bool ColorRect::initWithColor(ccColor4F color,const CCSize& size){
    init();
    
    setAnchorPoint(ccp(0, 0));
    setContentSize(size);
    
    this->_color = color;
    this->_size = size;
    return true;
}


void ColorRect::draw(){
        
    ccDrawSolidRect(ccp(0, 0), ccp(_size.width, _size.height), _color);
    
}