#ifndef __LOADINGCIRCLE_H__
#define __LOADINGCIRCLE_H__

#include "../gd.h"

	class LoadingCircle : public cocos2d::CCLayerColor {
	protected:
		cocos2d::CCSprite* m_pSprite;
		cocos2d::CCLayer* m_pParentLayer;
		bool m_bFade;

	public:
		static LoadingCircle* create();
		void show();
		void setParentLayer(cocos2d::CCLayer* layer) { m_pParentLayer = layer; }
		void setFade(bool fade) { m_bFade = fade; }
		void fadeAndRemove() ;
	};


#endif