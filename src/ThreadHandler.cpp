#include "ThreadHandler.h"

ThreadHandler::ThreadHandler(asio::io_context * io_context)
    : m_Thread(std::thread([io_context] { io_context->run(); }))
{
}
