//
//  MyLayer.cpp
//  L002HelloCocos2dX
//
//  Created by plter on 13-9-8.
//
//

#include "MyLayer.h"


CCScene* MyLayer::scene(){
    CCScene* scene = CCScene::create();
    
    MyLayer* layer = MyLayer::create();
    scene->addChild(layer);
    
    return scene;
    
}


bool MyLayer::init(){
    
    CCLayer::init();
    
//    CCLog(">>>>>>>>>>>MyLayer init");
    
    CCSprite* s = CCSprite::create("img.jpg");
    addChild(s);
    
    return true;
}