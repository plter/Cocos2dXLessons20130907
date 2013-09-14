#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();

    tf = CCTextFieldTTF::textFieldWithPlaceHolder("Please input", "Courier", 36);
    tf->cocos2d::CCNode::setPosition(size.width/2, size.height);
    tf->setAnchorPoint(ccp(0.5, 1));
    addChild(tf);
    
//    tf->attachWithIME();
    
    setTouchEnabled(true);
    return true;
}


void HelloWorld::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent){
    
    CCTouch* touch = (CCTouch*) pTouches->anyObject();
    
//    CCSize size = tf->getContentSize();
    
//    CCLog("current tf size(width:%d,height:%f)",size.width,size.height);
    
    if (tf->boundingBox().containsPoint(touch->getLocation())) {
        tf->attachWithIME();
    }else{
        tf->detachWithIME();
    }
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
