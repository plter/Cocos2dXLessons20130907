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


void HelloWorld::didAccelerate(cocos2d::CCAcceleration *pAccelerationValue){
    
//    CCLog("x:%f,y:%f,z:%f",pAccelerationValue->x,pAccelerationValue->y,pAccelerationValue->z);
    
    ball->setAX(pAccelerationValue->x);
    ball->setAY(pAccelerationValue->y);
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
    
    ball = Ball::create();
    ball->maxX = size.width;
    ball->maxY = size.height;
    ball->cocos2d::CCNode::setPosition(200, 200);
    addChild(ball);
    
    setAccelerometerEnabled(true);
    
    return true;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
