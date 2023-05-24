#pragma once

#include "../type.h"
#include <cpprest/ws_client.h>


namespace okx {


    class Channel {
    public:
        Channel(const wstring& uri);

        void connect();

        virtual void onMessage(const string& data) {}

    private:
        const wstring uri_;
        web::websockets::client::websocket_callback_client client_;
    };


}