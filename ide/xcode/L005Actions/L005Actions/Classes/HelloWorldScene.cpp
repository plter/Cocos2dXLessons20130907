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
    
    _actionRunning = false;
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();

    _label = CCLabelTTF::create("Hello World", "Courier", 48);
    _label->setPosition(ccp(size.width/2, size.height/2));
    addChild(_label);
    
    scheduleUpdate();
    setTouchEnabled(true);
    return true;
}

void HelloWorld::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent){
    
//    CCMoveTo* move = CCMoveTo::create(1, ccp(0, 0));
//    _label->runAction(CCMoveBy::create(1, ccp(-20, -20)));
    
    //根据当前位置旋转用1秒时间360度
//    _label->runAction(CCRotateBy::create(1, 360));
    
    //使用CCRepeateForever不停的执行动作
//    if (_actionRunning) {
//        _label->stopActionByTag(100);
//        _actionRunning = false;
//    }else{
//        _label->runAction(CCRepeatForever::create(CCRotateBy::create(1, 360)))->setTag(100);
//        _actionRunning = true;
//    }
    
    //使用CCSpawn 同时执行多种动作
//    CCSpawn* sp = CCSpawn::create(CCMoveBy::create(1, ccp(-200, -200)),CCRotateBy::create(1, 360),NULL);
//    _label->runAction(sp);
    
    //使用CCSequence依次执动作
//    CCSequence* sq = CCSequence::create(CCMoveBy::create(3, ccp(-100, -100)),CCRotateBy::create(1, 360),NULL);
//    _label->runAction(CCRepeat::create(sq, 2));
}

void HelloWorld::update(float dt){
    _label->setRotation(_label->getRotation()+5);
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
