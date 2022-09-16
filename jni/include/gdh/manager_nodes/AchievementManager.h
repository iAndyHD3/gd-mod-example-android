#ifndef __ACHIEVEMENTMANAGER_H__
#define __ACHIEVEMENTMANAGER_H__

#include "../gd.h"

	class AchievementManager : public cocos2d::CCNode {
	protected:
		PAD(16);
		cocos2d::CCDictionary* m_pAchievements;
		PAD(4);

	public:
		static AchievementManager * sharedState();
		cocos2d::CCArray * getAllAchievements();
		AchievementManager();
		bool init();
		void firstSetup();
		void notifyAchievementWithID(const char* identifier);
		void notifyAchievement(char const* title,char const* desc,char const* icon);
		bool areAchievementsEarned(cocos2d::CCArray *);
		bool isAchievementEarned(char const* identifier);
		int percentForAchievement(char const* identifier);
		int percentageForCount(int,int);                        //??
		void reportAchievementWithID(char const* identifier,int percentage,bool hidePopup);
		void reportPlatformAchievementWithID(char const*,int);  //??
		void resetAchievement(char const* identifier);
		void resetAchievements(void);
		void setReportedAchievements(cocos2d::CCDictionary *);
		void setup();
		void storeAchievementUnlocks();
		~AchievementManager();
	};


#endif