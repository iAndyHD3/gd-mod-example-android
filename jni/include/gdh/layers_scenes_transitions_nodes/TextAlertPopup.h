#ifndef __TEXTALERTPOPUP_H__
#define __TEXTALERTPOPUP_H__

#include "../gd.h"

#define __cdecl
using skip_t = char;

    class TextAlertPopup : public cocos2d::CCNode {
        public:
            static TextAlertPopup* create(std::string _text, float _time, float _scale) ;
    };
    

#endif
