#ifndef __CUSTOMLISTVIEW_H__
#define __CUSTOMLISTVIEW_H__

#include "../gd.h"


	class BoomListView;

	#pragma runtime_checks("s", off)
	class CustomListView : public BoomListView {
		//no members
	protected:
		CustomListView();
		virtual bool init(cocos2d::CCArray* entries, int type, float width, float height);

	public:
		static CustomListView* create(cocos2d::CCArray* entries, int type, float width, float height);

		virtual void setupList() ;
		virtual TableViewCell* getListCell(const char* key) ;
		virtual void loadCell(TableViewCell* cell, unsigned int index) ;
	};
	#pragma runtime_checks("s", restore)


#endif