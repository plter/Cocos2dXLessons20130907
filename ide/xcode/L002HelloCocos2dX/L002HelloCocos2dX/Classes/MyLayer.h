//
//  MyLayer.h
//  L002HelloCocos2dX
//
//  Created by plter on 13-9-8.
//
//

#ifndef __L002HelloCocos2dX__MyLayer__
#define __L002HelloCocos2dX__MyLayer__

#include <iostream>
#include "cocos2d.h"

using namespace cocos2d;

class MyLayer:CCLayer {
    
public:
    virtual bool init();
    static CCScene* scene();
    CREATE_FUNC(MyLayer);
};


#endif /* defined(__L002HelloCocos2dX__MyLayer__) */
