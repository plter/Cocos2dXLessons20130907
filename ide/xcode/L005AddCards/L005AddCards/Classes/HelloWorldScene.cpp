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
    
//    ColorRect* r = ColorRect::create(ccc4f(1, 0, 0, 1), CCSizeMake(100, 100));
//    addChild(r);
    
    c = Card::create(10);
    c->setPosition(ccp(200, 200));
    addChild(c);
    
    setTouchEnabled(true);
    
    return true;
}


void HelloWorld::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent){
    
    CCTouch* t = (CCTouch*) pTouches->anyObject();
    
    if (c->boundingBox().containsPoint(t->getLocation())) {
//        if (c->isRectoVisible()) {
//            c->showVerso();
//        }else{
//            c->showRecto();
//        }
        
        CCLog("Clicked %d",c->getNum());
    }
    
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
