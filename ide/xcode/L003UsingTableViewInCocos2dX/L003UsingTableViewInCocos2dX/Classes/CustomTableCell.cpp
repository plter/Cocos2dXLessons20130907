//
//  CustomTableCell.cpp
//  L003UsingTableViewInCocos2dX
//
//  Created by plter on 13-9-14.
//
//

#include "CustomTableCell.h"

CustomTableCell::CustomTableCell():CCTableViewCell(){
    label = CCLabelTTF::create();
    label->setFontSize(36);
    label->setAnchorPoint(ccp(0, 0));
    addChild(label);
}

void CustomTableCell::setString(const char *str){
    label->setString(str);
}

const char* CustomTableCell::getString(){
    return label->getString();
}