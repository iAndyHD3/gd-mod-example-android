#ifndef __POINTNODE_H__
#define __POINTNODE_H__

#include "../gd.h"

    class PointNode : public cocos2d::CCObject {
    public:
        cocos2d::CCPoint m_point;

        static PointNode* create(cocos2d::CCPoint point);
    };


#endif