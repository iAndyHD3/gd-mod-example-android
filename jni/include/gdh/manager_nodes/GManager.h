#ifndef __GMANAGER_H__
#define __GMANAGER_H__

#include "../gd.h"

class DS_Dictionary;


	class GManager : public cocos2d::CCNode {
	protected:
		std::string m_sFileName;
		bool m_bSetup;
		bool m_bSaved;

	public:
		std::string getSaveString();
		void save();
		virtual void setup() ;
		virtual void encodeDataTo(DS_Dictionary* data) {}
		virtual void dataLoaded(DS_Dictionary* data) {}
		virtual void firstLoad() {}
	};


#endif