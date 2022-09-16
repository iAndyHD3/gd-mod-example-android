#ifndef __BOOMLISTVIEW_H__
#define __BOOMLISTVIEW_H__

#include "../gd.h"


	class TableViewDelegate;
	class TableViewDataSource;
	class TableView;
	class TableViewCell;

	class BoomListView : public cocos2d::CCLayer, public TableViewDelegate, public TableViewDataSource {
	protected:
		TableView* m_pTableView;
		cocos2d::CCArray* m_pEntries;
		int m_eType; //? probably wrong type
		float m_fWidth;
		float m_fHeight;
		PAD(8);

	public:
		//TableViewDelegate vtable
		virtual float cellHeightForRowAtIndexPath(CCIndexPath& path, TableView* view) ;

		//TableViewDataSource vtable
		virtual unsigned int numberOfRowsInSection(unsigned int section, TableView* view);
		virtual TableViewCell* cellForRowAtIndexPath(CCIndexPath& path, TableView* view);

		//own vtable
		virtual void setupList() ;
		virtual TableViewCell* getListCell(const char* key);
		virtual void loadCell(TableViewCell* cell, unsigned int index);

		virtual void didSelectRowAtIndexPath(CCIndexPath&, TableView*) {}
	};


#endif