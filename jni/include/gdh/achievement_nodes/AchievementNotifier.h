#ifndef __ACHIEVEMENTNOTIFIER_H__
#define __ACHIEVEMENTNOTIFIER_H__

#include "../gd.h"


	class AchievementBar;

	class AchievementNotifier : public cocos2d::CCNode {
	protected:
		cocos2d::CCScene* m_pCurrentScene;
		cocos2d::CCArray* m_pQueue;
		AchievementBar* m_pCurrentAchievement;

	public:
		static AchievementNotifier* sharedState();
		void showNextAchievement();
		//this is inlined on win32 so let's reconstruct it
		void notifyAchievement(const char* title, const char* desc, const char* icon, bool quest);
	};


#endif