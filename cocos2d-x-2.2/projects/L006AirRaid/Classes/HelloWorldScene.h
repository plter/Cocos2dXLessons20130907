#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Gun.h"
#include "Bullet.h"
#include "Plane.h"

USING_NS_CC;

class GameLayer:public CCLayer {
    
public:
    CCSprite *bg;
    Gun * gun;
    virtual bool init();
    virtual void moveGunLeft();
    virtual void moveGunRight();
    virtual void fire();
    virtual void addPlane();
    CREATE_FUNC(GameLayer);
};


class InteracteLayer : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
    CCLabelTTF * btnLeft,*btnRight;
    virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
    // implement the "static node()" method manually
    CREATE_FUNC(InteracteLayer);
    
    virtual void setGameLayer(GameLayer* gl){
        gameLayer = gl;
    };
    
    virtual GameLayer* getGameLayer(){
        return gameLayer;
    }
    
private:
    GameLayer * gameLayer;
};


class HelloWorldScene:public CCScene {
    
public:
    virtual bool init();
    CREATE_FUNC(HelloWorldScene);
    
    GameLayer* gameLayer;
    InteracteLayer* interactLayer;
};
#endif // __HELLOWORLD_SCENE_H__
