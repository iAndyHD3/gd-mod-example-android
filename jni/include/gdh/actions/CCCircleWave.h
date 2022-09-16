#ifndef __CCCIRCLEWAVE_H__
#define __CCCIRCLEWAVE_H__

#include "../gd.h"

	#pragma runtime_checks("s", off)
	class CCCircleWave : public cocos2d::CCNode {
	protected:
		cocos2d::CCArray* m_pArray; //idk what this is tho
		PAD(4);
		float m_fFrom1; //?
		float m_fFrom2; //?
		cocos2d::ccColor3B m_cColor;
		cocos2d::CCPoint m_obUnknown;
		//more that im too lazy to figure out lol

	public:
		static CCCircleWave* create(bool fade1, bool fade2, float from, float to, float duration);
		void setColor(cocos2d::ccColor3B color) { m_cColor = color; }
	};
	#pragma runtime_checks("s", restore)


#endif