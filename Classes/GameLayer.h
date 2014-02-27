#ifndef __GAME_LAYER_H__
#define __GAME_LAYER_H__

#define GOAL_WIDTH 400

#include "cocos2d.h"
#include "GameSprite.h"

using namespace cocos2d;

class GameLayer : public cocos2d::CCLayer
{
public:
    
    GameSprite * _player1;
    GameSprite * _player2;
    GameSprite * _ball;
    CCArray * _players;
    CCLabelTTF * _player1ScoreLabel;
    CCLabelTTF * _player2ScoreLabel;
    
    CCSize _screenSize;
    
    int _player1Score;
    int _player2Score;
    void playerScore (int player);
    
    ~GameLayer();
    
    virtual bool init();
    
    static CCScene* scene();
    
    CREATE_FUNC(GameLayer);
	
	void update (float dt);
    
    virtual void onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event);
    virtual void onTouchesMoved(const std::vector<Touch*>& touches, Event *unused_event);
    virtual void onTouchesEnded(const std::vector<Touch*>& touches, Event *unused_event);
};

#endif // __GAME_LAYER_H__
