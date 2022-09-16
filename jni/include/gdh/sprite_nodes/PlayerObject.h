#ifndef __PLAYEROBJECT_H__
#define __PLAYEROBJECT_H__

#include "../gd.h"

	class GameObject;
	class AnimatedSpriteDelegate;
	class GJRobotSprite;
	class GJSpiderSprite;
	class HardStreak;

	class PlayerObject : public GameObject, public AnimatedSpriteDelegate {
	public:
		PAD(24);
		PAD(12);
		PAD(40);
		PAD(36);
		PAD(12);
		PAD(40);
		PAD(8);
		PAD(188);
		PAD(104);
		cocos2d::CCPoint position; //0x067C
		PAD(4);
		double unk_0688;
		PAD(12);
		float yVelMaybeCantChangeItThough; //0x069C
		PAD(4);
		float last200YPositions[200]; //0x06A4
		PAD(28);


		virtual void setVisible(bool visible) ;
		void pushButton(int button);
		void releaseButton(int button) ;
		bool playerIsFalling() ;
		void runRotateAction();
		void playBurstEffect() ;
		void spiderTestJump(bool param1) ;
		void incrementJumps();
		void flipGravity(bool param1, bool param2) ;
		bool isFlying();

		bool isShipMode(){
			return *((bool*)((long)this + 1528));
		}

	};


#endif