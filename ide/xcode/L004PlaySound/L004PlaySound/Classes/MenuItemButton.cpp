//
//  MenuItemButton.cpp
//  L004PlaySound
//
//  Created by plter on 13-9-15.
//
//

#include "MenuItemButton.h"

MenuItemButton* MenuItemButton::create(string label,cocos2d::CCObject *target, SEL_MenuHandler selector){
    
    MenuItemButton* btn = new MenuItemButton();
    btn->initWithNormalImage("btn-normal.png", "btn-down.png", NULL, target, selector);
    btn->setLabel(label);
    btn->autorelease();
    return btn;
}


bool MenuItemButton::initWithNormalImage(const char *normalImage, const char *selectedImage, const char *disabledImage, cocos2d::CCObject *target, SEL_MenuHandler selector){
    
    CCMenuItemImage::initWithNormalImage(normalImage, selectedImage, disabledImage, target, selector);
    
    //custom code
    
    CCSize contentSize = getContentSize();
    
    _labelTTF = CCLabelTTF::create("Button", "Courier", 36);
    _labelTTF->setPosition(ccp(contentSize.width/2, contentSize.height/2));
    addChild(_labelTTF);
    
    return true;
}


string MenuItemButton::getLabel(){
    return _label;
}

void MenuItemButton::setLabel(string value){
    _label = value;
    _labelTTF->setString(value.c_str());
}