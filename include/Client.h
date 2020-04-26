#pragma once

#include "AsioHandler.h"

#include <websocketpp/config/asio_client.hpp>
#include <websocketpp/client.hpp>
#include <websocketpp/common/thread.hpp>
#include <websocketpp/common/connection_hdl.hpp>

typedef websocketpp::client<websocketpp::config::asio_tls_client> WebsocketClient;
typedef websocketpp::client<websocketpp::config::asio_tls_client>::connection_ptr ConnectionPtr;
typedef websocketpp::connection_hdl ConnectionHdl;
typedef websocketpp::config::asio_client::message_type::ptr MessagePtr;

class Client {
public :
    Client(std::string token, size_t thread_count);

    void Setup_Websocket(asio::io_context * io_Context);
    void SetupCallbacks(const ConnectionPtr& connection);
    void Connect();

    void onOpen(const ConnectionHdl& handle);
    void onMessage(const ConnectionHdl& handle, const MessagePtr& message);
    void onClose(const ConnectionHdl& handle);

private:
    WebsocketClient m_Client;
    std::unique_ptr<AsioHandler> m_AsioHandler;
    ConnectionHdl m_Connection;
    std::string m_Token;
    size_t m_ThreadCount;
};
