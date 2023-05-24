#pragma once

#include "../type.h"
#include <cpprest/ws_client.h>


namespace okx {


    class Channel {
    public:
        Channel(const string& uri, const string& proxy);

        bool connect();

        virtual void onMessage(const string& data) {}

    private:
        const string uri_;
        std::unique_ptr<web::websockets::client::websocket_callback_client> client_;
    };


}