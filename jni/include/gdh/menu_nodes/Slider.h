#ifndef SLIDER_H
#define SLIDER_H

#include "../gd.h"


    class Slider;

    class SliderThumb : public cocos2d::CCMenuItemImage {
        protected:
            float m_fLength;
            bool m_bVertical;

        public:
            void setValue(float val);

            float getValue() {
                float pos = this->m_bVertical ?
                    this->getPositionY() : 
                    this->getPositionX();
                
                float scale = this->getScale();
                
                return (scale * this->m_fLength * .5f + pos) / (scale * this->m_fLength);
            }
    };

    class SliderTouchLogic : public cocos2d::CCMenu {
        protected:
            PAD(0x4)
            float m_fLength;
            SliderThumb* m_pThumb;
            Slider* m_pSlider;
            bool m_bUnknown;
            PAD(0x8)
            bool m_bVertical;

        public:
            SliderThumb* getThumb() const { return m_pThumb; }
    };

    class Slider : public cocos2d::CCLayer {
        protected:
            SliderTouchLogic* m_pTouchLogic;
            cocos2d::CCSprite* m_pSliderBar;
            cocos2d::CCSprite* m_pGroove;
            float m_fUnknown;
            float m_fHeight;

        public:
            void setValue(float val) {
                this->m_pTouchLogic->getThumb()->setValue(val);
            }

            float getValue() {
                return this->m_pTouchLogic->getThumb()->getValue();
            }

            void setBarVisibility(bool v) {
                this->m_pSliderBar->setVisible(v);
            }

            static Slider* create(
                cocos2d::CCNode* target,
                cocos2d::SEL_MenuHandler click,
                const char* grooveSpr,
                const char* thumbSpr,
                const char* thumbSprSel,
                float scale
            );

            static Slider* create(
                cocos2d::CCNode* target,
                cocos2d::SEL_MenuHandler click,
                float scale
            ) ;

        // todo
    };



#endif
