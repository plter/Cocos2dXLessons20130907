#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

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
    
    //init ui
    btnPlay = MenuItemButton::create("Play", this, menu_selector(HelloWorld::buttonClickHandler));
    btnPlay->setPositionY(120);
    
    btnPause = MenuItemButton::create("Pause", this, menu_selector(HelloWorld::buttonClickHandler));
    btnPause->setPositionY(60);
    
    btnStop = MenuItemButton::create("Stop", this, menu_selector(HelloWorld::buttonClickHandler));
    
    btnResume = MenuItemButton::create("Resume", this, menu_selector(HelloWorld::buttonClickHandler));
    btnResume->setPositionY(-60);
    
    btnTurnUp = MenuItemButton::create("放大音量", this, menu_selector(HelloWorld::buttonClickHandler));
    btnTurnUp->setPositionY(-120);
    btnTurnUp->setPositionX(-120);
    
    btnTurnDown = MenuItemButton::create("放小音量", this, menu_selector(HelloWorld::buttonClickHandler));
    btnTurnDown->setPositionY(-120);
    btnTurnDown->setPositionX(120);
    
    CCMenu* menu = CCMenu::create(btnPlay,btnPause,btnStop,btnResume,btnTurnUp,btnTurnDown,NULL);
    addChild(menu);
    
    return true;
}

void HelloWorld::buttonClickHandler(CCObject* pSender)
{
    SimpleAudioEngine * sae = SimpleAudioEngine::sharedEngine();
    
    sae->playEffect("click.wav");
    
    if (pSender==btnPlay) {
        sae->playBackgroundMusic("sound.mp3");
    }else if(pSender==btnStop){
        sae->stopBackgroundMusic();
    }else if(pSender==btnPause){
        sae->pauseBackgroundMusic();
    }else if(pSender==btnResume){
        sae->resumeBackgroundMusic();
    }else if (pSender==btnTurnDown){
        sae->setBackgroundMusicVolume(sae->getBackgroundMusicVolume()-0.1);
    }else if (pSender==btnTurnUp){
        sae->setBackgroundMusicVolume(sae->getBackgroundMusicVolume()+0.1);
    }
}
