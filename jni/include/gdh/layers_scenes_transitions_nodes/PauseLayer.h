#ifndef __PAUSELAYER_H__
#define __PAUSELAYER_H__

#include "../gd.h"


	class CCBlockLayer;

	class PauseLayer : public CCBlockLayer {
	protected:
		bool m_bUnknown;
		bool m_bUnknown2;

	public:
		void createToggleButton(cocos2d::SEL_MenuHandler callback, bool on,
			cocos2d::CCMenu* menu, std::string caption, cocos2d::CCPoint pos) ;
	};


#endif