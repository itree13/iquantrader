#pragma once

#include "../settings.h"
#include "public_channel.h"
#include "private_channel.h"

namespace okx {


    class Client {
    public:
        bool init();


    private:
        std::unique_ptr<PublicChannel> pub_ch_;
        std::unique_ptr<PrivateChannel> priv_ch_;
    };


}