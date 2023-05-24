#include "channel.h"
#include "../logger.h"

namespace okx {

    using namespace web::websockets::client;

    Channel::Channel(const string& uri, const string& proxy)
    : uri_(uri) {
        websocket_client_config config;
        if (!proxy.empty())
            config.set_proxy(web::web_proxy(utility::conversions::to_string_t(proxy)));

        client_.reset(new websocket_callback_client(config));

        client_->set_message_handler([this](websocket_incoming_message msg) {
            auto msg_type = msg.message_type();
            if (msg_type == websocket_message_type::ping) {
                websocket_outgoing_message msg;
                msg.set_pong_message();
                client_->send(msg);
            } else if (msg_type == websocket_message_type::text_message) {
                // handle message from server...
            } else if (msg_type == websocket_message_type::close) {

            }
        });

        client_->set_close_handler([this](websocket_close_status close_status,
            const utility::string_t& reason,
            const std::error_code& error) {
            // TODO

        });
    }

    bool Channel::connect() {
        try {
            auto status = client_->connect(utility::conversions::to_string_t(uri_)).wait();
            if (status == Concurrency::task_status::completed) {
                LOG(info) << "connect to " << uri_ << " ok.";
                return true;
            }

            LOG(info) << "connect to " << uri_ << " failed! status=" << status;
        } catch (const websocket_exception& e) {
            LOG(error) << "connect to " << uri_ << " failed!" << e.what();
        }
        return false;
    }

}
