cmake_minimum_required(VERSION 3.10)
project(chem2json)

set(SOURCE_FILES, "main.cpp")
add_executable(chem2json main.cpp include/CLI11.hpp chemParser.cpp chemParser.hpp stringUtils.hpp jsonWriter.cpp jsonWriter.hpp)

target_link_libraries(chem2json stdc++fs)

install(TARGETS chem2json
        RUNTIME DESTINATION bin )