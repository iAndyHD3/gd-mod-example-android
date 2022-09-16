//
// Created by marco on 30/06/2021.
//

#ifndef _GAMESTATSMANAGER_H
#define _GAMESTATSMANAGER_H

#include "../gd.h"

class GJRewardItem;


enum GJRewardType{

};

    class GameStatsManager : public cocos2d::CCNode {
    public:
        cocos2d::CCDictionary *value_0;


        static GameStatsManager * sharedState();
        GameStatsManager * setStat(const char *,int);
        int getBaseCurrency(int,bool,int);
        int checkAchievement(const char*);

        void collectReward(GJRewardType,GJRewardItem *);

        void storeRewardState(GJRewardType,int,int,std::string);

        void registerRewardsFromItem(GJRewardItem*);
        inline cocos2d::CCDictionary* getDict(){ return value_0;}



    };


#endif
