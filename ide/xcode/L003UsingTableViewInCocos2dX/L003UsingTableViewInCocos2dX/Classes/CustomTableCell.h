//
//  CustomTableCell.h
//  L003UsingTableViewInCocos2dX
//
//  Created by plter on 13-9-14.
//
//

#ifndef __L003UsingTableViewInCocos2dX__CustomTableCell__
#define __L003UsingTableViewInCocos2dX__CustomTableCell__

#include <iostream>

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class CustomTableCell :public CCTableViewCell{
    
public:
    CustomTableCell();
    virtual void setString(const char* str);
    virtual const char* getString();
    
private:
    CCLabelTTF * label;
};

#endif /* defined(__L003UsingTableViewInCocos2dX__CustomTableCell__) */
