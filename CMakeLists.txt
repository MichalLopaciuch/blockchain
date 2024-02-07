cmake_minimum_required(VERSION 3.25..3.28)

project(BLOCKCHAIN VERSION 1.0 LANGUAGES CXX)

set(CMAKE_GENERATOR "Unix Makefiles")
set(CC_FILES
    src/main.cc
    src/block.cc
    src/blockchain.cc)

add_executable(${PROJECT_NAME} ${CC_FILES})

find_package(OpenSSL REQUIRED)
target_link_libraries(${PROJECT_NAME} openssl::openssl)
