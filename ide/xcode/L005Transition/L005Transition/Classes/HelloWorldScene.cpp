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
    
    CCSprite* s = CCSprite::create("Hello.jpg");
    s->setPosition(ccp(size.width/2, size.height/2));
    addChild(s);
    
    
    btnShowNext = CCLabelTTF::create("Show Next Scene", "Courier", 36);
    btnShowNext->setPosition(ccp(size.width/2, size.height/2));
    addChild(btnShowNext);
    
    setTouchEnabled(true);
    
    return true;
}


void HelloWorld::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent){
    CCTouch* t = (CCTouch*)pTouches->anyObject();
    
    if (btnShowNext->boundingBox().containsPoint(t->getLocation())) {
        CCDirector::sharedDirector()->replaceScene(CCTransitionFadeDown::create(1, Img::scene()));
        
//        CCDirector::sharedDirector()->pushScene(CCTransitionSlideInB::create(1, Img::scene()));
    }
}


void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
