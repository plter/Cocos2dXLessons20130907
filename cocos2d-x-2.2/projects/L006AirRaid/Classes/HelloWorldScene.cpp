#include "HelloWorldScene.h"

USING_NS_CC;

//Scene>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
bool HelloWorldScene::init(){
    CCScene::init();
    
    gameLayer = GameLayer::create();
    addChild(gameLayer);
    interactLayer = InteracteLayer::create();
    interactLayer->setGameLayer(gameLayer);
    addChild(interactLayer);
    
    return true;
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//GameLayer>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


bool GameLayer::init(){
    CCLayer::init();
    
    CCSize size = CCDirector::sharedDirector()->getVisibleSize();
    
    bg = CCSprite::create("bg.jpg");
    bg->setAnchorPoint(ccp(0, 0));
    addChild(bg);
    
    //create gun
    gun = Gun::create();
    gun->setPositionX(size.width/2);
    addChild(gun);
    
    schedule(schedule_selector(GameLayer::addPlane), 2);
    
    return true;
}

void GameLayer::addPlane(){
    addChild(Plane::create());
}

void GameLayer::moveGunLeft(){
//    gun->setPositionX(gun->getPositionX()-5);
    gun->runAction(CCMoveBy::create(0.5, ccp(-30, 0)));
}

void GameLayer::moveGunRight(){
    
    gun->runAction(CCMoveBy::create(0.5, ccp(30, 0)));
//    gun->setPositionX(gun->getPositionX()+5);
}

void GameLayer::fire(){
    Bullet* b = Bullet::create();
    addChild(b);
    b->setPosition(gun->getPosition()+ccp(0,gun->getContentSize().height));
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//InteractLayer>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


// on "init" you need to initialize your instance
bool InteracteLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize size = CCDirector::sharedDirector()->getVisibleSize();
    
    setTouchEnabled(true);
    
    //create buttons
    btnLeft = CCLabelTTF::create();
    btnLeft->setString("<");
    btnLeft->setFontSize(50);
    btnLeft->setAnchorPoint(ccp(0, 0));
    btnLeft->setPositionX(10);
    addChild(btnLeft);
    
    btnRight = CCLabelTTF::create();
    btnRight->setAnchorPoint(ccp(1, 0));
    btnRight->setString(">");
    btnRight->setFontSize(50);
    btnRight->setPositionX(size.width-10);
    addChild(btnRight);
    
    
    return true;
}

void InteracteLayer::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent){
    
    CCTouch * t = (CCTouch*)pTouches->anyObject();
    CCPoint p = t->getLocation();
    
    if (btnLeft->boundingBox().containsPoint(p)) {
        getGameLayer()->moveGunLeft();
    }else if(btnRight->boundingBox().containsPoint(p)){
        getGameLayer()->moveGunRight();
    }else{
        getGameLayer()->fire();
    }
}


void InteracteLayer::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
