//
//  ColorRect.h
//  L005AddCards
//
//  Created by plter on 13-9-21.
//
//

#ifndef __L005AddCards__ColorRect__
#define __L005AddCards__ColorRect__

#include <iostream>

#include "cocos2d.h"

USING_NS_CC;

class ColorRect:public CCSprite {
    
public:
    virtual void draw();
    
    virtual bool initWithColor(ccColor4F color,const CCSize& size);
    
    static ColorRect* create(ccColor4F color,const CCSize& size);
    
private:
    ccColor4F _color;
    CCSize _size;
};

#endif /* defined(__L005AddCards__ColorRect__) */
