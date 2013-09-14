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

    btn = CCMenuItemImage::create("btn.png", "btn-down.png", this, menu_selector(HelloWorld::menuItemClicked));
    CCMenu * menu = CCMenu::create(btn,NULL);
    addChild(menu);
    
    return true;
}

void HelloWorld::menuItemClicked(cocos2d::CCObject *pSender)
{
    CCMessageBox("Button Clicked", "Hello");
}
