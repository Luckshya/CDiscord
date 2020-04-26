add_library(CDiscord STATIC AsioHandler.cpp Client.cpp ThreadHandler.cpp)

find_package(OpenSSL REQUIRED)

target_include_directories(CDiscord
        PUBLIC
            ${PROJECT_SOURCE_DIR}/include
            ${asio_SOURCE_DIR}/asio/include
            ${websocketpp_SOURCE_DIR}
            ${nlohmann_json_SOURCE_DIR}/include
        )

target_compile_definitions(CDiscord
        PUBLIC
            ASIO_STANDALONE
            _WEBSOCKETPP_CPP11_STL_
        )

target_link_libraries(CDiscord
        PUBLIC
            "OpenSSL::SSL"
            "OpenSSL::Crypto"
        )