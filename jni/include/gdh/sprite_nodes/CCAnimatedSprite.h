#ifndef __CCANIMATEDSPRITE_H__
#define __CCANIMATEDSPRITE_H__

#include "../gd.h"

	class CCAnimatedSprite : public cocos2d::CCSprite {
	protected:
		std::string m_sUnknown1;
		std::string m_sUnknown2;
		PAD(20);
		std::string m_sUnknown3;
		PAD(4);

	public:
		static CCAnimatedSprite* create(const char* file) ;

		//own vtable
		virtual void animationFinished(const char*) {}
		virtual void animationFinishedO(cocos2d::CCObject*) {}
	};

	class AnimatedSpriteDelegate {
		virtual void animationFinished(const char*);
	};

#endif