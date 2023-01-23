#include <string>
#include "httplib.h"
#include "../stdinclude.hpp"

namespace notifier
{
    httplib::Client* client = nullptr;

    void init()
    {
        client = new httplib::Client(g_packet_notifier_host);
        client->set_connection_timeout(0, 50000);
    }

    void ping() {

        if (client == nullptr) {
            init();
        }

        auto res = client->Get("/notify/ping");
        auto error = res.error();
        if (error != httplib::Error::Success) {
            std::ostringstream oss;
            oss << "无法连接到URA: " << httplib::to_string(error);
        }
        else if (res.value().body != "pong") {
            std::ostringstream oss;
            oss << "URA返回值异常: " << res.value().body;
        }
    }

    void notify_response(const std::string& data)
    {
        if (client == nullptr) {
            init();
        }

        auto res = client->Post("/notify/response", data, "application/x-msgpack");
        httplib::Error error = res.error();
        if (error != httplib::Error::Success)
        {
            LOGE("Unexpected error from notifier: %s\n",httplib::to_string(error).c_str());
        }
    }
    void notify_request(const std::string& data)
    {
        if (client == nullptr) {
            init();
        }

        auto res = client->Post("/notify/request", data, "application/x-msgpack");
        httplib::Error error = res.error();
        if (error != httplib::Error::Success)
        {
            LOGE("Unexpected error from notifier: %s\n",httplib::to_string(error).c_str());
        }
    }
}