#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"
#include <vector>
#include <string>


using namespace std;
USING_NS_CC;
USING_NS_CC_EXT;

class HelloWorld : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
    virtual void reqComplete(CCHttpClient * client,CCHttpResponse* req);
    
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);
    
    CCHttpClient * hc;
};

#endif // __HELLOWORLD_SCENE_H__