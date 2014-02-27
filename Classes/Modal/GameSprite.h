//
//  GameSprite.h
//  BattleDuty
//
//  Created by dinh-q on 2014/02/12.
//
//

#ifndef __BattleDuty__GameSprite__
#define __BattleDuty__GameSprite__

#include "cocos2d.h"

using namespace cocos2d;

class GameSprite : public CCSprite {

public:
    CC_SYNTHESIZE(CCPoint, _nextPosition, NextPosition);
    
    CC_SYNTHESIZE(CCTouch *, _touch, Touch);
    
    CC_SYNTHESIZE(CCPoint, _vector, Vector);
    
    GameSprite(void);
    ~GameSprite(void);
    
    static GameSprite* gameSpriteWithFile(const char *pszFileName);
    
    virtual void setPosition(const CCPoint& pos);
    
    float radius();
};

#endif /* defined(__BattleDuty__GameSprite__) */
