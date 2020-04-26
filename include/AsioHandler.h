#pragma once

#include <asio/io_context.hpp>
#include <asio/executor_work_guard.hpp>
#include <algorithm>

#include "ThreadHandler.h"

typedef asio::executor_work_guard<asio::io_context::executor_type> WorkGuardType;

class AsioHandler {
public:
    std::unique_ptr<asio::io_context> io_Context;

    AsioHandler(size_t thread_count);
    ~AsioHandler();

    void InitializeThreadPool(size_t thread_count);
    void RunContext();
private:
    std::unique_ptr<WorkGuardType> io_WorkGuard;
    std::vector<std::unique_ptr<ThreadHandler>> m_ThreadPool;
};
