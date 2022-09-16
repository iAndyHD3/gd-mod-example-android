#ifndef __GAMETOOLBOX_H__
#define __GAMETOOLBOX_H__

#include "../gd.h"
#include <cocos-ext.h>


class GameToolbox
{
public:
	static std::string getResponse(cocos2d::extension::CCHttpResponse * response);

};

#endif
