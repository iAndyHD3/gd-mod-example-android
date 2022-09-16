#ifndef __SIMPLEPLAYER_H__
#define __SIMPLEPLAYER_H__

#include "../gd.h"


	enum IconType;

	class GJRobotSprite;
	class GJSpiderSprite;

	class SimplePlayer : public cocos2d::CCSprite {
	protected:
		cocos2d::CCSprite* m_pFirstLayer; // idk a good name for these, theyre not even layers
		cocos2d::CCSprite* m_pSecondLayer;
		cocos2d::CCSprite* m_pBirdDome; // the glass thingy on the ufo
		cocos2d::CCSprite* m_pOutlineSprite;
		cocos2d::CCSprite* m_pDetailSprite;
		GJRobotSprite* m_pRobotSprite;
		GJSpiderSprite* m_pSpiderSprite;
		PAD(4); // seems to be unused
		bool m_bHasGlowOutline;

		virtual bool init(int iconID);
	public:
		static SimplePlayer* create(int iconID);

		void updatePlayerFrame(int iconID, IconType iconType);

		void updateColors() ;

		void setFrames(const char* firstLayer, const char* secondLayer, const char* birdDome, const char* outlineSprite, const char* detailSprite);

		virtual void setColor(const cocos2d::ccColor3B& color);

		void setSecondColor(const cocos2d::ccColor3B& color) {
			// this function is inlined on windows
			m_pSecondLayer->setColor(color);
			updateColors();
		}

		virtual void setOpacity(unsigned char opacity) ;

		// custom functions

		bool hasGlowOutline() { return m_bHasGlowOutline; }
		void setGlowOutline(bool value) {
			m_bHasGlowOutline = value;
			updateColors();
		}

		inline bool getPlayerGlow() const
		{
			return *reinterpret_cast<bool*>(reinterpret_cast<uintptr_t>(this) + 0x204);
		}
		inline void setPlayerGlow(bool n_glow)
		{
			auto glow_ptr = reinterpret_cast<bool*>(reinterpret_cast<uintptr_t>(this) + 0x204);
			*glow_ptr = n_glow;
		};
	};


#endif
