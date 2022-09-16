#ifndef __LEVELEDITORLAYER_H__
#define __LEVELEDITORLAYER_H__

#include "../gd.h"

    class GJBaseGameLayer;
    class EditorUI;
    class GameObject;

    class LevelEditorLayer : public GJBaseGameLayer {
    public:
        PAD(0x84)
        int m_currentLayer;
        PAD(0x2c)
        EditorUI* m_editorUI;

        void removeObject(GameObject * obj, bool idk);

        int getNextFreeGroupID(cocos2d::CCArray* objs);

        GameObject* addObjectFromString(std::string const& str) ;
    };


#endif
