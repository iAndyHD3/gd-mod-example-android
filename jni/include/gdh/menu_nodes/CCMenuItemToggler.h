#ifndef __CCMENUITEMTOGGLER_H__
#define __CCMENUITEMTOGGLER_H__

#include "../gd.h"


	class CCMenuItemSpriteExtra;

	#pragma runtime_checks("s", off)
	class CCMenuItemToggler : public cocos2d::CCMenuItem {
	protected:
		CCMenuItemSpriteExtra* m_pOnButton;
		CCMenuItemSpriteExtra* m_pOffButton;
		bool m_bOn;
		bool m_bUnknown;

	public:
		static CCMenuItemToggler* create(cocos2d::CCNode* off, cocos2d::CCNode* on,
			cocos2d::CCObject* target, cocos2d::SEL_MenuHandler callback);
		void setSizeMult(float mult);
		//my own function
		inline bool isOn() { return m_bOn; }
		void toggle(bool on);
	};
	#pragma runtime_checks("s", restore)


#endif