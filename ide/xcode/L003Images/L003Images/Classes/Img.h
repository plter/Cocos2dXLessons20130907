//
//  Img.h
//  L003Images
//
//  Created by plter on 13-9-14.
//
//

#ifndef __L003Images__Img__
#define __L003Images__Img__

#include <iostream>
#include "cocos2d.h"

#define MABS(a) a<0?-a:a

USING_NS_CC;

class Img:public CCSprite {
    
public:
    CREATE_FUNC(Img);
    
//    static Img* create(){
//        Img* img = new Img();
//        if(img->init()){
//            img->autorelease();
//            return img;
//        }
//        delete img;
//        return NULL;
//    };
    
    virtual void update(float dt);
    virtual bool init();
    
private:
    float speedX,speedY;
    float maxWidth,maxHeight;
    float halfWidth,halfHeight;
//    int frames;
};


#endif /* defined(__L003Images__Img__) */
