#include "AsioHandler.h"

AsioHandler::AsioHandler(size_t thread_count)
    : io_Context(std::make_unique<asio::io_context>())
    , io_WorkGuard(std::make_unique<WorkGuardType>(asio::make_work_guard(*io_Context)))
{
    InitializeThreadPool(thread_count);
}

AsioHandler::~AsioHandler()
{
}

void AsioHandler::InitializeThreadPool(size_t thread_count)
{
    for(size_t idx = 0; idx < thread_count; ++idx)
    {
        m_ThreadPool.emplace_back(std::make_unique<ThreadHandler>(io_Context.get()));
    }
}

void AsioHandler::RunContext() {
    io_Context->run();
}
