#ifndef __BUTTONSPRITE_H__
#define __BUTTONSPRITE_H__

#include "../gd.h"

	#pragma runtime_checks("s", off)
	class ButtonSprite : public cocos2d::CCSprite {
	public:
		/*PARAMS:
		* caption - the button's caption.
		* width - the width of the button. only used if absolute is TRUE.
		* absolute - whether or not to use provided width. if FALSE, game will auto-adjust.
		* font - font file for caption.
		* texture - texture file for button background.
		* height - height of button. put 0 for auto.
		* scale - scale of the caption.
		*/
		static ButtonSprite* create(const char* caption, int width, bool absolute,
			const char* font, const char* texture, float height, float scale) ;
	};
	#pragma runtime_checks("s", restore)


#endif