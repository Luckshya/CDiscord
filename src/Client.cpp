#include "Client.h"

#include <utility>
#include <nlohmann/json.hpp>

// for convenience
using json = nlohmann::json;

Client::Client(std::string token, size_t thread_count)
    : m_AsioHandler(std::make_unique<AsioHandler>(thread_count))
    , m_Token(std::move(token))
    , m_ThreadCount(thread_count)
{
    Setup_Websocket(m_AsioHandler->io_Context.get());
}

void Client::Setup_Websocket(asio::io_context * io_Context) {
    m_Client.clear_access_channels(websocketpp::log::alevel::all);
    m_Client.clear_error_channels(websocketpp::log::elevel::all);

    m_Client.set_tls_init_handler([](const websocketpp::connection_hdl&)
    {
        return websocketpp::lib::make_shared<asio::ssl::context>(asio::ssl::context::tlsv1);
    });

    m_Client.init_asio(io_Context);
    m_Client.start_perpetual();

    Connect();
}

void Client::SetupCallbacks(const ConnectionPtr& connection)
{
    connection->set_open_handler(std::bind(&Client::onOpen, this, std::placeholders::_1));
    connection->set_message_handler(std::bind(&Client::onMessage, this, std::placeholders::_1, std::placeholders::_2));
    connection->set_close_handler(std::bind(&Client::onClose, this, std::placeholders::_1));
}

void Client::Connect()
{
    asio::error_code ec;

    ConnectionPtr Connection = m_Client.get_connection("wss://gateway.discord.gg/?v=6&encoding=json", ec);

    if(ec)
    {
        return;
    }

    SetupCallbacks(Connection);
    m_Connection = Connection->get_handle();
    m_Client.connect(Connection);
}

void Client::onOpen(const ConnectionHdl& handle)
{

}

void Client::onMessage(const ConnectionHdl& handle, const MessagePtr& message)
{
    auto j = json::parse(message->get_payload());
    std::cout << j.dump(4) << std::endl;
}

void Client::onClose(const ConnectionHdl& handle)
{

}

