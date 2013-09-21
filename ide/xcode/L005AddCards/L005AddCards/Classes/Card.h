//
//  Card.h
//  L005AddCards
//
//  Created by plter on 13-9-21.
//
//

#ifndef __L005AddCards__Card__
#define __L005AddCards__Card__

#include <iostream>
#include "cocos2d.h"
#include "ColorRect.h"

USING_NS_CC;

class Card:public CCSprite {
    
public:
    
    virtual bool initWithNum(int num);
    
    static Card* create(int num);
    virtual void showRecto();
    virtual void showVerso();
    virtual bool isRectoVisible();
    virtual int getNum(){
        return _num;
    };
    
private:
    int _num;
    CCLabelTTF* _label;
    ColorRect* _bg;
};


#endif /* defined(__L005AddCards__Card__) */
