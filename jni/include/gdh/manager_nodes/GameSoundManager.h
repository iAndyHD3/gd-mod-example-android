#ifndef __GAMESOUNDMANAGER_H__
#define __GAMESOUNDMANAGER_H__

#include "../gd.h"

	class GameSoundManager : public cocos2d::CCNode {
	protected:
		cocos2d::CCDictionary* m_pDictionary1;
		cocos2d::CCDictionary* m_pDictionary2;
		PAD(12);
		bool m_bPreloaded;
		PAD(4);
		std::string m_sFilePath;

	public:
		static GameSoundManager* sharedState() ;
		static void playSound(std::string sName) ;
		void playBackgroundMusic(std::string path, bool idk, bool idk2) ;
		void playBackgroundMusic(bool idk, std::string path);
		void stopBackgroundMusic() ;
	};


#endif