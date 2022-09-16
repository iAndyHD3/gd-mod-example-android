#ifndef __EDITORUI_H__
#define __EDITORUI_H__

#include "../gd.h"


class EditButtonBar : public cocos2d::CCNode {};
class GJRotationControl : public cocos2d::CCLayer {};
class GJScaleControl : public cocos2d::CCLayer {};

class CCMenuItemSpriteExtra;
class CCMenuItemToggler;
class Slider;
class GameObject;

class EditorUI : public cocos2d::CCLayer,
    public FLAlertLayerProtocol,
    public ColorSelectDelegate,
    public GJRotationControlDelegate,
    public GJScaleControlDelegate,
    public MusicDownloadDelegate {

    public:
        EditButtonBar* m_pEditButtonBar;
        PAD(0x4)
        cocos2d::CCArray* m_pUnknownArray;
        PAD(0x28)
        cocos2d::CCLabelBMFont* m_pUnknownLabel;
        GJRotationControl* m_pRotationControl;
        PAD(0x10)
        GJScaleControl* m_pScaleControl;
        cocos2d::CCDictionary* m_pUnknownDict;
        EditButtonBar* m_pEditButtonBar2;
        EditButtonBar* m_pEditButtonBar3;
        Slider* m_pPositionSlider;
        PAD(0x20)
        cocos2d::CCArray* m_pUnknownArray2;
        PAD(0x8)
        cocos2d::CCArray* m_pUnknownArray3;
        cocos2d::CCMenu* m_pUnknownMenu;
        cocos2d::CCArray* m_pUnknownArray4;
        CCMenuItemSpriteExtra* m_pButton0;
        CCMenuItemSpriteExtra* m_pButton1;
        CCMenuItemSpriteExtra* m_pButton2;
        CCMenuItemSpriteExtra* m_pButton3;
        CCMenuItemSpriteExtra* m_pButton4;
        CCMenuItemSpriteExtra* m_pButton5;
        CCMenuItemSpriteExtra* m_pButton6;
        CCMenuItemSpriteExtra* m_pButton7;
        CCMenuItemSpriteExtra* m_pButton8;
        CCMenuItemSpriteExtra* m_pButton9;
        CCMenuItemSpriteExtra* m_pButton10;
        CCMenuItemSpriteExtra* m_pButton11;
        CCMenuItemSpriteExtra* m_pButton12;
        CCMenuItemSpriteExtra* m_pButton13;
        CCMenuItemSpriteExtra* m_pButton14;
        CCMenuItemSpriteExtra* m_pButton15;
        CCMenuItemSpriteExtra* m_pButton16;
        CCMenuItemSpriteExtra* m_pButton17;
        CCMenuItemSpriteExtra* m_pButton18;
        CCMenuItemSpriteExtra* m_pButton19;
        CCMenuItemSpriteExtra* m_pButton20;
        CCMenuItemSpriteExtra* m_pButton21;
        CCMenuItemSpriteExtra* m_pButton22;
        CCMenuItemSpriteExtra* m_pButton23;
        CCMenuItemSpriteExtra* m_pButton24;
        CCMenuItemSpriteExtra* m_pButton25;
        CCMenuItemSpriteExtra* m_pButton26;
        CCMenuItemToggler* m_pUnknownToggler;
        cocos2d::CCArray* m_pUnknownArray5;
        cocos2d::CCMenu* m_pUnknownMenu2;
        cocos2d::CCArray* m_pUnknownArray6;
        cocos2d::CCSprite* m_pIdkSprite0;
        cocos2d::CCSprite* m_pIdkSprite1;
        CCMenuItemSpriteExtra* m_pButton27;
        CCMenuItemSpriteExtra* m_pButton28;
        CCMenuItemSpriteExtra* m_pButton29;
        CCMenuItemSpriteExtra* m_pButton30;
        CCMenuItemSpriteExtra* m_pButton31;
        CCMenuItemSpriteExtra* m_pButton32;
        cocos2d::CCLabelBMFont* m_pCurrentLayerLabel;
        CCMenuItemSpriteExtra* m_pButton33;
        CCMenuItemSpriteExtra* m_pButton34;
        CCMenuItemSpriteExtra* m_pButton35;
        PAD(0xc)
        cocos2d::CCArray* m_pUnknownArray7;
        cocos2d::CCArray* m_pUnknownArray8;
        cocos2d::CCArray* m_pUnknownArray9;
        PAD(0x4)
        LevelEditorLayer* m_pEditorLayer;
        PAD(60)
        std::string m_clipBoard;
    
    public:
        cocos2d::CCArray* pasteObjects(std::string const& _str) ;

        void deselectAll() ;
        void updateButtons() ;

        void selectObjects(cocos2d::CCArray* objs, bool idk) ;
        cocos2d::CCArray* getSelectedObjects() ;

        void moveObject(GameObject* obj, cocos2d::CCPoint position) ;

        void updateZoom(float amt) ;

        cocos2d::CCPoint getGroupCenter(cocos2d::CCArray* objects, bool idk);

        void scaleObjects(cocos2d::CCArray* objects, float scale, cocos2d::CCPoint center);
    };


#endif
