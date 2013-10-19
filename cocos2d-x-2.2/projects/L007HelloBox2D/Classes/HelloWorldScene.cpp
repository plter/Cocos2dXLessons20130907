#include "HelloWorldScene.h"

USING_NS_CC;

#define RATIO 80
#define BOX_WIDTH 0.1
#define BOX_HEIGHT 0.1

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
    
    setTouchEnabled(true);
    
//    rectArr = new CCArray();
    
    b2Vec2 vec(0,-10);
    world = new b2World(vec);
    world->SetAllowSleeping(true);
    world->SetContinuousPhysics(true);
    
    //创建地板
    b2BodyDef groundBodyDef;
    groundBodyDef.position.x=0;
    groundBodyDef.position.y=0;
    groundBodyDef.type = b2_staticBody;
    b2Body* groundBody = world->CreateBody(&groundBodyDef);
    
    b2PolygonShape groundShape;
    groundShape.SetAsBox(10, 0.1);
    b2FixtureDef groundDf;
    groundDf.shape=&groundShape;
    groundDf.friction = 0.1;
    groundDf.density = 0;
    groundBody->CreateFixture(&groundDf);
    
    //左边界
    b2BodyDef leftBodyDef;
    leftBodyDef.position.x=0;
    leftBodyDef.position.y=0;
    leftBodyDef.type = b2_staticBody;
    b2Body* leftBody = world->CreateBody(&leftBodyDef);
    
    b2PolygonShape leftShape;
    leftShape.SetAsBox(0.1, 5);
    b2FixtureDef leftDf;
    leftDf.shape=&leftShape;
    leftDf.friction = 0.1;
    leftDf.density = 0;
    leftBody->CreateFixture(&leftDf);
    
    //右边界
    b2BodyDef rightBodyDef;
    rightBodyDef.position.x=10;
    rightBodyDef.position.y=0;
    rightBodyDef.type = b2_staticBody;
    b2Body* rightBody = world->CreateBody(&rightBodyDef);
    
    b2PolygonShape rightShape;
    rightShape.SetAsBox(0.1, 5);
    b2FixtureDef rightDf;
    rightDf.shape=&rightShape;
    rightDf.friction = 0.1;
    rightDf.density = 0.3;
    rightBody->CreateFixture(&rightDf);
    
    scheduleUpdate();
    
    addRect(ccp(300, 400));
    
    return true;
}

void HelloWorld::addRect(const CCPoint &p){
    b2BodyDef bodyDef;
    bodyDef.position.y = p.y/RATIO;
    bodyDef.position.x = p.x/RATIO;
    bodyDef.type = b2_dynamicBody;
    body = world->CreateBody(&bodyDef);
    
    b2PolygonShape bodyShape;
    bodyShape.SetAsBox(BOX_WIDTH, BOX_HEIGHT);
    
    PSprite * rect = PSprite::create();
    rect->setContentSize(CCSize(BOX_WIDTH*RATIO, BOX_HEIGHT*RATIO));
    rect->setTextureRect(CCRect(0, 0, BOX_WIDTH*RATIO*2, BOX_HEIGHT*RATIO*2));
    rect->setColor(ccc3(255, 0, 0));
    rect->setAnchorPoint(ccp(0.5, 0.5));
    addChild(rect);
    rect->setB2Body(body);
    rect->setPTMRatio(RATIO);
    
//    rectArr->addObject(rect);
    
    b2FixtureDef bodyFd;
    bodyFd.shape=&bodyShape;
    bodyFd.density = 1;
    bodyFd.friction =0.3;
    
    body->CreateFixture(&bodyFd);
}


void HelloWorld::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent){
    CCTouch* t = (CCTouch*)pTouches->anyObject();
    
    addRect(t->getLocation());
}

void HelloWorld::update(float dt){
    world->Step(dt, 8, 3);
    
//    CCObject *obj;
//    RectSprite* rect;
//    CCARRAY_FOREACH(rectArr, obj){
//        rect = (RectSprite*)obj;
//        rect->step();
//    }
    
//    img->setPosition(ccp(body->GetPosition().x*RATIO, body->GetPosition().y*RATIO));
//    img->setRotation(body->GetAngle());
    
//    CCLog("%f",body->GetPosition().y);
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
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
