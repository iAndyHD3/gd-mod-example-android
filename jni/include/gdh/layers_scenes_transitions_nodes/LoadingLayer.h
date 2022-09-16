#ifndef __LOADINGLAYER_H__
#define __LOADINGLAYER_H__

#include "../gd.h"

	class LoadingLayer : public cocos2d::CCLayer {
	protected:
		PAD(4);
		int m_nLoadIndex;
		cocos2d::CCLabelBMFont* m_pCaption;
		PAD(4);
		//artifacts of rob debugging something
		cocos2d::CCSprite* m_pSliderBar;
		float m_fSliderGrooveXPos;
		PAD(4);
		bool m_bFromRefresh;

	public:
		static LoadingLayer* create(bool fromReload) ;
		void setFromRefresh(bool value) {
			m_bFromRefresh = value;
		}

		void setWillFadeIn(bool willFadeIn) {
			*reinterpret_cast<bool*>(
					reinterpret_cast<char*>(this) + 0x138
			) = willFadeIn;
		}
	};

#endif