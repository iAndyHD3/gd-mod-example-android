//
// Created by marco on 30/06/2021.
//

#ifndef _GJGARAGELAYER_H
#define _GJGARAGELAYER_H

#pragma runtime_checks("s", off)
    class GJGarageLayer : public cocos2d::CCLayer, TextInputDelegate, FLAlertLayerProtocol /*, GameRateDelegate, ListButtonBarDelegate, DialogDelegate */ {
    public:
        static cocos2d::CCScene *scene();
        static GJGarageLayer *node();
        void updatePlayerSelect(cocos2d::CCNode* pushedBtn);
        void updateColorSelect(cocos2d::CCNode* pushedBtn, bool);
        void updatePlayerColors();
    };
#pragma runtime_checks("s", restore)

#endif
