#ifndef __GJITEMICON_H__
#define __GJITEMICON_H__

#include "../gd.h"

    class GJItemIcon : public cocos2d::CCSprite {
        public:
            static GJItemIcon* create(
                UnlockType _type,
                int _id,
                cocos2d::_ccColor3B _col1,
                cocos2d::_ccColor3B _col2,
                bool _un0,
                bool _un1,
                bool _un2,
                cocos2d::_ccColor3B _col3
            );

            static GJItemIcon* createBrowserIcon(UnlockType _type, int _id) {
                return GJItemIcon::create(_type, _id,
                    { 0xaf, 0xaf, 0xaf }, { 0xff, 0xff, 0xff },
                    false, true, true,
                    { 0xff, 0xff, 0xff }
                );
            }
    };


#endif
