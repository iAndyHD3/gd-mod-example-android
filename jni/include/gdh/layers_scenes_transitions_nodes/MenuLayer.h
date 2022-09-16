#ifndef __MENULAYER_H__
#define __MENULAYER_H__

#include "../gd.h"

	class FLAlertLayerProtocol;

	class MenuLayer : public cocos2d::CCLayer, public FLAlertLayerProtocol, public GooglePlayDelegate {
	public:
		static MenuLayer* node();
		static cocos2d::CCScene* scene(bool options) ;
		virtual bool init();
		virtual void keyBackClicked();
		virtual void keyDown(cocos2d::enumKeyCodes key) ;
		virtual void googlePlaySignedIn();
		virtual void FLAlert_Clicked(FLAlertLayer* alert, bool btn2);
	};


#endif