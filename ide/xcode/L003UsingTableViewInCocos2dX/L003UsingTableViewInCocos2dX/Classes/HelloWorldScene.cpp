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
    
    dataArr = CCArray::create(CCString::create("Hello"),CCString::create("World"),CCString::create("World"),CCString::create("World"),CCString::create("World"),CCString::create("World"),CCString::create("World"),CCString::create("World"),CCString::create("World"),CCString::create("World"),CCString::create("World"),CCString::create("World"),CCString::create("World"),CCString::create("World"),CCString::create("World"),CCString::create("World"),CCString::create("World"),CCString::create("World"),CCString::create("World"),CCString::create("Hello"),CCString::create("World"),CCString::create("World"),CCString::create("World"),CCString::create("World"),CCString::create("World"),CCString::create("World"),CCString::create("World"),CCString::create("World"),CCString::create("World"),CCString::create("World"),CCString::create("World"),CCString::create("World"),CCString::create("World"),CCString::create("World"),CCString::create("World"),CCString::create("World"),CCString::create("World"),CCString::create("World"),NULL);
    dataArr->retain();

    _table = CCTableView::create(this, CCSizeMake(300, 300));
    _table->setAnchorPoint(ccp(0, 0));
    _table->setPosition(100, 10);
    _table->setDelegate(this);
    addChild(_table);
    
    return true;
}

CCTableViewCell* HelloWorld::tableCellAtIndex(cocos2d::extension::CCTableView *table, unsigned int idx){
    
    CustomTableCell * cell = (CustomTableCell*) table->dequeueCell();
    
    if (cell==NULL) {
        cell = new CustomTableCell();
        cell->autorelease();
    }
    
    //init data
    cell->setString(((CCString*)dataArr->objectAtIndex(idx))->getCString());
    
    return cell;
}

unsigned int HelloWorld::numberOfCellsInTableView(cocos2d::extension::CCTableView *table){
    return dataArr->count();
}


CCSize HelloWorld::cellSizeForTable(cocos2d::extension::CCTableView *table){
    return CCSizeMake(300, 40);
}

void HelloWorld::tableCellTouched(cocos2d::extension::CCTableView *table, cocos2d::extension::CCTableViewCell *cell){
    
    CustomTableCell * _cell = (CustomTableCell*)cell;
    
    CCLog("Cell value : %s",_cell->getString());
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

HelloWorld::~HelloWorld(){
    dataArr->release();
}