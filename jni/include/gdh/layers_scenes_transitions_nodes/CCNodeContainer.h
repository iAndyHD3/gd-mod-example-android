#ifndef __CCNODECONTAINER_H__
#define __CCNODECONTAINER_H__

#include "../gd.h"

    class CCNodeContainer : public cocos2d::CCNode {
        protected:
            // literally no extra fields or anything, just
            // these 3 methods

            bool init();

        public:
            void visit();

            static CCNodeContainer* create();
    };


#endif
