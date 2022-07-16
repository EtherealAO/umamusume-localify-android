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
