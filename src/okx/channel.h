#pragma once

#include "../type.h"
#include <cpprest/http_client.h>

namespace okx {


    class Channel {
    public:
        Channel(const wstring& uri);



    private:
        web::http::client::http_client client_;
    };


}