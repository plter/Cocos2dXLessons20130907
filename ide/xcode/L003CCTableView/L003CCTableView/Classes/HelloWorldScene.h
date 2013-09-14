#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class HelloWorld : public cocos2d::CCLayer,public CCTableViewDataSource
{
    
public:
    /**
     * cell height for a given table.
     *
     * @param table table to hold the instances of Class
     * @return cell size
     */
    virtual CCSize cellSizeForTable(CCTableView *table) {
        return CCSizeMake(300, 40);
    };
    /**
     * a cell instance at a given index
     *
     * @param idx index to search for a cell
     * @return cell found at idx
     */
    virtual CCTableViewCell* tableCellAtIndex(CCTableView *table, unsigned int idx){
        
        CCTableViewCell * cell = table->dequeueCell();
        CCLabelTTF * label;
        
        if (cell==NULL) {
            cell = new CCTableViewCell();
            cell->autorelease();
            
            label = CCLabelTTF::create();
            label ->setFontSize(36);
            label ->setTag(1);
            label->setAnchorPoint(ccp(0, 0));
            cell->addChild(label);
        }else{
            label = (CCLabelTTF*) cell->getChildByTag(1);
        }
        
        char str[10];
        sprintf(str, "Item %d",idx);
        
        label->setString(str);
        
        return cell;
    };
    /**
     * Returns number of cells in a given table view.
     *
     * @return number of cells
     */
    virtual unsigned int numberOfCellsInTableView(CCTableView *table){
        return 100;
    };
    
public:
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    virtual bool init();

    // there's no 'id' in cpp, so we recommend to return the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);

    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(HelloWorld);
    
private:
    CCTableView * _table;
};

#endif // __HELLOWORLD_SCENE_H__
