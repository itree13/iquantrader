#include "channel.h"


namespace okx {

    using namespace web::websockets::client;

    Channel::Channel(const wstring& uri)
    : uri_(uri) {
        client_.set_message_handler([this](websocket_incoming_message msg) {
            auto msg_type = msg.message_type();
            if (msg_type == websocket_message_type::ping) {
                websocket_outgoing_message msg;
                msg.set_pong_message();
                client_.send(msg);
            } else if (msg_type == websocket_message_type::text_message) {
                // handle message from server...
            } else if (msg_type == websocket_message_type::close) {

            }
        });

        client_.set_close_handler([this](websocket_close_status close_status,
            const utility::string_t& reason,
            const std::error_code& error) {

        });
    }

    void Channel::connect() {
        client_.connect(uri_);
    }

}
