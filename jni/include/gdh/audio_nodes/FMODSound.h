#ifndef __FMODSOUND_H__
#define __FMODSOUND_H__

#include "../gd.h"

	class FMODSound : public cocos2d::CCNode {
	public:
		FMOD::Sound* m_pSound;
	};


#endif