#ifndef __FLALERTLAYER_H__
#define __FLALERTLAYER_H__

#include "../gd.h"


	class FLAlertLayerProtocol;
	class ButtonSprite;
	class ScrollingLayer;

	#pragma runtime_checks("s", off)
	class FLAlertLayer : public cocos2d::CCLayerColor {
	public:

		cocos2d::CCMenu* m_pButtonMenu;
		int m_nControlConnected; //?
		cocos2d::CCObject* m_pTarget;
		bool m_bReverseKeyBack;
		cocos2d::ccColor3B m_cColor;
		PAD(4);
		cocos2d::CCLayer* m_pLayer;
		int m_nZOrder2;
		bool m_bNoElasticity;
		cocos2d::ccColor3B m_cColor2; //?
		ButtonSprite* m_pButton1;
		ButtonSprite* m_pButton2;
		ScrollingLayer* m_pScrollingLayer;
		int m_nJoystickConnected;
		bool m_bBorder; //?
		bool m_bNoAction; //?


	public:
		FLAlertLayer();

		static FLAlertLayer *create(FLAlertLayerProtocol *delegate, const char *title, std::string text, const char *btn1Text, const char *btn2Text);
		static FLAlertLayer *create(FLAlertLayerProtocol *delegate, const char *title, std::string text, const char *btn1Text, const char *btn2Text, float layerHeight);
		static FLAlertLayer *create(FLAlertLayerProtocol *delegate, const char *title, std::string text, const char *btn1Text, const char *btn2Text, float layerHeight, bool scrollable, float );
		bool init(FLAlertLayerProtocol *delegate, const char *title, const char *text, std::string btn1Text, const char *btn2Text, float layerHeight);
		void onBtn2(cocos2d::CCObject *);
		void onBtn1(cocos2d::CCObject *);



		virtual void onEnter(void);
		virtual bool ccTouchBegan(cocos2d::CCTouch *,cocos2d::CCEvent *);
		virtual void ccTouchMoved(cocos2d::CCTouch *,cocos2d::CCEvent *);
		virtual void ccTouchEnded(cocos2d::CCTouch *,cocos2d::CCEvent *);
		virtual void ccTouchCancelled(cocos2d::CCTouch *,cocos2d::CCEvent *);
		virtual void registerWithTouchDispatcher(void);
		virtual void keyBackClicked(void);
		virtual void keyDown(cocos2d::enumKeyCodes);
		virtual void show(void);



		/*
        static FLAlertLayer *create(FLAlertLayerProtocol *delegate, const char *title, std::string text, const char *btn1Text, const char *btn2Text, float layerHeight);
        bool init(FLAlertLayerProtocol *delegate, const char *title, const char *text, std::string btn1Text, const char *btn2Text, float layerHeight);
        void onBtn2(cocos2d::CCObject *);
        void onBtn1(cocos2d::CCObject *);


        ~FLAlertLayer();





        virtual void registerWithTouchDispatcher();
        virtual void onEnter();
        virtual void keyBackClicked();
        //virtual void keyDown(int);
        virtual void show();


        CC_SYNTHESIZE(FLAlertLayerProtocol*, pParent_, PParent);
        CC_SYNTHESIZE(CCNode*, targetScene_, TargetScene);
        CC_SYNTHESIZE(bool, reverseKeyBack_, ReverseKeyBack);
        CC_SYNTHESIZE(CCLayer*, internalLayer_, InternalLayer);
        */
	};
	#pragma runtime_checks("s", restore)



#endif