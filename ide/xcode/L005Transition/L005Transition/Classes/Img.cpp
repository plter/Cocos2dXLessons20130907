//
//  Img.cpp
//  L005Transition
//
//  Created by plter on 13-9-21.
//
//

#include "Img.h"


CCScene* Img::scene(){
    CCScene* s = CCScene::create();
    Img* l = Img::create();
    s->addChild(l);
    return s;
}


bool Img::init(){
    CCLayer::init();
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    
    CCSprite* s = CCSprite::create("img.jpg");
    s->setPosition(ccp(size.width/2, size.height/2));
    addChild(s);
    
    setTouchEnabled(true);
    return true;
}


void Img::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent){
    
//    CCDirector::sharedDirector()->popScene();
    
    CCDirector::sharedDirector()->replaceScene(CCTransitionFadeUp::create(1, HelloWorld::scene()));
}