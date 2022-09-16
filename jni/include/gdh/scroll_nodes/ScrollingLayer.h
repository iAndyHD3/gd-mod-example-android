#ifndef __SCROLLINGLAYER_H__
#define __SCROLLINGLAYER_H__

#include "../gd.h"

	class ScrollingLayer : public cocos2d::CCLayerColor {
		public:
			PAD(0x28)
			float m_fLayerHeight;
			PAD(0x4)
			cocos2d::CCLayer * m_pScrollLayer;
			cocos2d::CCNode* m_pParent;

			static ScrollingLayer * create(cocos2d::CCSize _size, cocos2d::CCPoint _point, float _unknown);
	};


#endif