cmake_minimum_required(VERSION 3.16)
project(CDiscord)

set(CMAKE_CXX_STANDARD 17)

include(ExternalProject)
include(buildtools/cmake/DownloadProject.cmake)

download_project(
        PROJ           asio
        GIT_REPOSITORY https://github.com/chriskohlhoff/asio.git
        GIT_TAG        22afb86
        SOURCE_DIR     ${PROJECT_SOURCE_DIR}/deps/asio
        UPDATE_DISCONNECTED 1
)

download_project(
        PROJ           websocketpp
        GIT_REPOSITORY https://github.com/zaphoyd/websocketpp.git
        GIT_TAG        master
        SOURCE_DIR     ${PROJECT_SOURCE_DIR}/deps/websocketpp
        UPDATE_DISCONNECTED 1
)

download_project(
        PROJ           nlohmann_json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG        develop
        SOURCE_DIR     ${PROJECT_SOURCE_DIR}/deps/nlohmann_json
        UPDATE_DISCONNECTED 1
)

set(asio_SOURCE_DIR ${PROJECT_SOURCE_DIR}/deps/asio)
set(websocketpp_SOURCE_DIR ${PROJECT_SOURCE_DIR}/deps/websocketpp)
set(nlohmann_json_SOURCE_DIR ${PROJECT_SOURCE_DIR}/deps/nlohmann_json)

add_subdirectory(src)

add_subdirectory(test)