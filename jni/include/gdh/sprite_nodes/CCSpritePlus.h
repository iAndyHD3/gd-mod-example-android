#ifndef __CCSPRITEPLUS_H__
#define __CCSPRITEPLUS_H__

#include "../gd.h"

	//credit to zmx (https://github.com/kyurime)
	class CCSpritePlus : public cocos2d::CCSprite {
	protected:
		cocos2d::CCArray* m_pFollowers;
		CCSpritePlus* m_pFollowing;
		bool m_bHasFollowers;
		bool m_bScaleFollowers;
		bool m_bFlipFollowers;

	public:
		//CCNode vtable
		virtual void setScaleX(float scale);
		virtual void setScaleY(float scale) ;
		virtual void setScale(float scale) ;
		virtual void setPosition(const cocos2d::CCPoint& pos) ;
		virtual void setRotation(float rotation);
		virtual bool initWithTexture(cocos2d::CCTexture2D* texture);
		virtual bool initWithSpriteFrameName(const char* name) ;

		//own vtable
		virtual void setFlipX(bool flip);
		virtual void setFlipY(bool flip);
		CCSpritePlus* getFollowingSprite() { return m_pFollowing; }

		// note: this is not an actual gd function.
		// this should really not be used. it's just
		// because camden314 has it.
		void setFollowingSprite(CCSpritePlus* spr) { this->m_pFollowing = spr; }

		static CCSpritePlus* createWithSpriteFrame(cocos2d::CCSpriteFrame* frame) ;
	};


#endif