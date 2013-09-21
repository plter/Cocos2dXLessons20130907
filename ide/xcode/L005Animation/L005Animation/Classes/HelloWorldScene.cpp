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
    
    //缓存图片文件及配置
    CCSpriteFrameCache* cache = CCSpriteFrameCache::sharedSpriteFrameCache();
    cache->addSpriteFramesWithFile("L005Animation.plist", "L005Animation.png");
    
    //创建数组
    CCArray* frames = CCArray::create();
    
    char name[10];
    //根据名称获取SpriteFrame对象，并填入数组中
    for (int i=0; i<30; i++) {
        //将int类型的数据转变成字符串
        sprintf(name, "a%04d",i);
        
        //将SpriteFrame对象添加到数组中
        frames->addObject(cache->spriteFrameByName(name));
    }
    
    //根据生成的数组创建CCAnimation动画配置对象
    CCAnimation* animation = CCAnimation::createWithSpriteFrames(frames,0.02);
    //根据动画配置对象创建CCAnimate对象
    CCAnimate* animate = CCAnimate::create(animation);
    
    //创建CCSprite对象用于呈现动画
    CCSprite* anim = CCSprite::create();
    //调整位置
    anim->setPosition(ccp(size.width/2, size.height/2));
    //添加到层中
    addChild(anim);
    
    //执行动画
//    anim->runAction(CCRepeatForever::create(animate));
    
    //反向执行动画
    anim->runAction(CCRepeatForever::create(animate->reverse()));
    
    return true;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
