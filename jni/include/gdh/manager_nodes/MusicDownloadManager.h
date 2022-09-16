#ifndef __MUSICDOWNLOADMANAGER_H__
#define __MUSICDOWNLOADMANAGER_H__

#include "../gd.h"

    class MusicDownloadManager : public cocos2d::CCNode {
    public:
        PAD(4);
        cocos2d::CCDictionary* m_unknownDict;
        cocos2d::CCArray* m_unknownArr; // list of MusicDelegateHandler s
        cocos2d::CCDictionary* m_songsDict;

        static MusicDownloadManager* sharedState();
        static std::string pathForSong(int id) ;

        cocos2d::CCArray* getDownloadedSongs();
        void songStateChanged() ;
    };

#endif
