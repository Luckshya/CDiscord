#pragma once

#include <asio/io_context.hpp>
#include <thread>

class ThreadHandler {
private :
    std::thread m_Thread;
public :
    ThreadHandler(asio::io_context * io_Context);
};
