#ifndef __ACHIEVEMENTBAR_H__
#define __ACHIEVEMENTBAR_H__

#include "../gd.h"

	#pragma runtime_checks("s", off)
	class AchievementBar : public cocos2d::CCNodeRGBA {
	protected:
		PAD(0x24);

	public:
		static AchievementBar* create(const char* title,
			const char* desc, const char* icon, bool quest);
	};
	#pragma runtime_checks("s", restore)


#endif