#ifndef __GJACCOUNTMANAGER_H__
#define __GJACCOUNTMANAGER_H__

#include "../gd.h"

    class GJAccountManager : public cocos2d::CCNode {
        protected:
            PAD(0x4)
            std::string m_sPassword;
            std::string m_sUsername;

        public:
            static GJAccountManager* sharedState();

            const char* getPassword();
            const char* getUsername() ;
    };


#endif
