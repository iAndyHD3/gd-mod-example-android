#ifndef __CCCONTENTLAYER_H__
#define __CCCONTENTLAYER_H__

#include "../gd.h"

	class CCContentLayer : public cocos2d::CCLayerColor {
		//no members
	public:
		static CCContentLayer* create(const cocos2d::ccColor4B& color, float width, float height);
	};


#endif