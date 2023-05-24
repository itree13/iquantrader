#pragma once

#include "../type.h"
#include <cpprest/ws_client.h>

namespace okx {


    class Channel {
    public:
        Channel(const wstring& uri);



    private:
        web::websockets::client::websocket_client client_;
    };


}