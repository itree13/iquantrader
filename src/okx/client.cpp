#include "client.h"
#include "config.h"

namespace okx {


    bool Client::init() {
        auto env = Settings::instance().value<string>("okx.env", "production");
        auto proxy = Settings::instance().value<string>("okx.proxy", "");
        if (env == "demo") {
            pub_ch_.reset(new PublicChannel(OKX_DEMO_PUBLIC_WSS, proxy));
            priv_ch_.reset(new PrivateChannel(OKX_DEMO_PRIVATE_WSS, proxy));
        } else if (env == "aws") {
            pub_ch_.reset(new PublicChannel(OKX_AWS_PUBLIC_WSS, proxy));
            priv_ch_.reset(new PrivateChannel(OKX_AWS_PRIVATE_WSS, proxy));
        } else if (env == "production") {
            pub_ch_.reset(new PublicChannel(OKX_PUBLIC_WSS, proxy));
            priv_ch_.reset(new PrivateChannel(OKX_PRIVATE_WSS, proxy));
        } else
            return false;

        if (!pub_ch_->connect())
            return false;
        if (!priv_ch_->connect())
            return false;

        return true;
    }






}