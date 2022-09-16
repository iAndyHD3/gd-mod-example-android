#ifndef __GJDROPDOWNLAYER_H__
#define __GJDROPDOWNLAYER_H__

#include "../gd.h"


	class GJListLayer;

	#pragma runtime_checks("s", off)
	class GJDropDownLayer : public cocos2d::CCLayerColor {
	public:
		cocos2d::CCPoint m_obEndPosition;
		cocos2d::CCPoint m_obStartPosition;
		cocos2d::CCMenu* m_pButtonMenu;
		GJListLayer* m_pListLayer;
		bool m_bControllerEnabled; //?
		cocos2d::CCLayer* m_pLayer;
		bool m_bHidden; //?
		PAD(7);

	public:
		//CCNode vtable
		virtual void registerWithTouchDispatcher() ;
		virtual void draw() ;

		//CCTouchDelegate vtable
		virtual bool ccTouchBegan(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent) { return true; }
		virtual void ccTouchMoved(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent) {}
		virtual void ccTouchEnded(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent) {}
		virtual void ccTouchCancelled(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent) {}

		//CCKeypadDelegate vtable
		virtual void keyBackClicked();

		//vtable
		virtual void customSetup() {}
		virtual void enterLayer() ;
		virtual void exitLayer(cocos2d::CCObject* btn);
		virtual void showLayer(bool noTransition) ;
		virtual void hideLayer(bool noTransition) ;
		virtual void layerVisible() ;
		virtual void layerHidden();
		virtual void enterAnimFinished() {}
		virtual void disableUI() ;
		virtual void enableUI() ;
		GJDropDownLayer();
		bool init(const char* title, float height);

		static GJDropDownLayer* create(const char* title, float height) ;
	};
	#pragma runtime_checks("s", restore)


#endif