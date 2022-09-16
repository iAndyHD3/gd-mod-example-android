#ifndef __FMODAUDIOENGINE_H__
#define __FMODAUDIOENGINE_H__

#include "../gd.h"

	class FMODAudioEngine : public cocos2d::CCNode {
	public:
		cocos2d::CCDictionary* m_pDictionary;
		std::string m_sFilePath;
		float m_fBackgroundMusicVolume;
		float m_fEffectsVolume;
		float m_fPulse1;
		float m_fPulse2;
		float m_fPulse3;
		int m_nPulseCounter;
		bool m_bMetering;
		bool m_bFading;
		bool m_bFadeIn;
		float m_fFadeInDuration;
		FMOD::System* m_pSystem;
		FMOD::Sound* m_pSound;
		FMOD::Channel* m_pCurrentSoundChannel;
		FMOD::Channel* m_pGlobalChannel;
		FMOD::DSP* m_pDSP;
		int m_eLastResult;
		int m_nVersion;
		void* m_pExtraDriverData;
		int m_nMusicOffset;

	public:
		static FMODAudioEngine * sharedEngine();
		void playBackgroundMusic(std::string,bool,bool);
		void playEffect(std::string, bool, float, float, float);
		void stop();
		void start();
		void reloadEffects();
		void resumeAllEffects();
	};


#endif