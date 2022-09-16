//
// Created by marco on 30/06/2021.
//

#ifndef _UPLOADACTIONPOPUP_H
#define _UPLOADACTIONPOPUP_H

#pragma runtime_checks("s", off)
    class UploadActionPopup : public FLAlertLayer {
    public:
        static UploadActionPopup* create(UploadPopupDelegate*,std::string);
        bool init(UploadPopupDelegate*,std::string);

        void showSuccessMessage(std::string);
        void showFailMessage(std::string);
        void closePopup();

    };
#pragma runtime_checks("s", restore)

#endif
