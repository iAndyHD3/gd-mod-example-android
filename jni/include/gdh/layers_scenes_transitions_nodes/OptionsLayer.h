//
// Created by marco on 30/06/2021.
//

#ifndef _OPTIONSLAYER_H
#define _OPTIONSLAYER_H




#include "../gd.h"


    class OptionsLayer :  public GJDropDownLayer, public FLAlertLayerProtocol {
    public:
        ~OptionsLayer();

        static OptionsLayer *create();


        cocos2d::CCMenu *menu_;
        void onSupport();
        void onRate();
        void onSoundtracks();
        void onHelp();
        void onMusic();
        void onFX();
        void onGC();

        bool goToSupport_;
        bool goToSongs_;
        void exitLayer();

        virtual void customSetup();
        virtual void layerHidden();
        virtual void FLAlert_Clicked(FLAlertLayer *layer, bool accept);

    };



#endif
