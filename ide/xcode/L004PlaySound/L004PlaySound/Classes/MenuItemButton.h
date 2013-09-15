//
//  MenuItemButton.h
//  L004PlaySound
//
//  Created by plter on 13-9-15.
//
//

#ifndef __L004PlaySound__MenuItemButton__
#define __L004PlaySound__MenuItemButton__

#include <iostream>
#include <string>
#include "cocos2d.h"

using namespace std;
USING_NS_CC;

class MenuItemButton:public CCMenuItemImage {
    
public:
    static MenuItemButton* create(string label,CCObject* target,SEL_MenuHandler selector);
    
    virtual bool initWithNormalImage(const char *normalImage, const char *selectedImage, const char *disabledImage, CCObject* target, SEL_MenuHandler selector);
    virtual string getLabel();
    virtual void setLabel(string value);
    
private:
    string _label;
    CCLabelTTF* _labelTTF;
};

#endif /* defined(__L004PlaySound__MenuItemButton__) */
