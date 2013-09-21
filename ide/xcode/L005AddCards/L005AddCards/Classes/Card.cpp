//
//  Card.cpp
//  L005AddCards
//
//  Created by plter on 13-9-21.
//
//

#include "Card.h"

Card* Card::create(int num){
    Card* card = new Card();
    card->initWithNum(num);
    card->autorelease();
    return card;
}

bool Card::initWithNum(int num){
    init();
    
    _num = num;
    
    CCSize size = CCSizeMake(80, 80);
    setContentSize(size);
    setAnchorPoint(ccp(0, 0));
    
    _bg = ColorRect::create(ccc4f(1, 0, 0, 1), size);
    addChild(_bg);
    
    _label = CCLabelTTF::create();
    
    _label->setPosition(ccp(size.width/2, size.height/2));
    _label->setFontSize(60);
    
    char str[5];
    sprintf(str, "%d",num);
    
    _label->setString(str);
    addChild(_label);
    
    showRecto();
    
    return true;
}


bool Card::isRectoVisible(){
    return _label->isVisible();
}

void Card::showRecto(){
    _label->setVisible(true);
    _bg->setVisible(false);
}


void Card::showVerso(){
    _label->setVisible(false);
    _bg->setVisible(true);
}