cmake_minimum_required(VERSION 3.5)

project(JS LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(JS
    main.cpp
    tokenizer.cpp
    token.cpp
)
