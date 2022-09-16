#ifndef __ANIMATEDSHOPKEEPER_H__
#define __ANIMATEDSHOPKEEPER_H__

#include "../gd.h"


	class CCAnimatedSprite;

	typedef enum {
		kShopTypeNormal,
		kShopTypeSecret,
		kShopTypeCommunity
	} ShopType;

	class AnimatedShopKeeper : public CCAnimatedSprite {
	protected:
		float m_fUnknown1;
		float m_fUnknown2;
		bool m_bUnknown;

	public:
		static AnimatedShopKeeper* create(ShopType type) ;
		void startAnimating() ;
		//own vtable
		virtual void animationFinished(const char*) {}
	};


#endif