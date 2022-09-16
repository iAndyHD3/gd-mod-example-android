#ifndef __TEXTAREA_H__
#define __TEXTAREA_H__

#include "../gd.h"

	#pragma runtime_checks("s", off)
	class TextArea : public cocos2d::CCSprite {
	protected:
		PAD(0x58);

	public:
		static TextArea* create(const char* font, bool unknown,
			std::string caption, float scale, float width, float height);
	};
	#pragma runtime_checks("s", restore)


#endif