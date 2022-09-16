#ifndef __OBJECTTOOLBOX_H__
#define __OBJECTTOOLBOX_H__

#include "../gd.h"

    class ObjectToolbox : public cocos2d::CCNode {
    public:
        cocos2d::CCDictionary* m_frameToKey;
        cocos2d::CCDictionary* m_keyToFrame;
        PAD(4);

        static auto sharedState() ;

        cocos2d::CCArray* allKeys() ;

        const char* frameToKey(const char* frame);

        const char* intKeyToFrame(int key);

        const char* keyToFrame(const char* key) {
            return intKeyToFrame(atoi(key));
        }

        static float gridNodeSizeForKey(int key) ;

        static const char* perspectiveBlockFrame(int key) ;

        // custom funcs

        void addObject(int id, const char* frame) {
            m_frameToKey->setObject(cocos2d::CCString::createWithFormat("%i", id), frame);
            m_keyToFrame->setObject(cocos2d::CCString::create(frame), id);
        }
    };

#endif
