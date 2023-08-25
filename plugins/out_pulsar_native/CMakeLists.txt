# Fluent Bit Pulsar Output plugin

project(flb-plugin-out_pulsar_native)
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_STANDARD 11)
set(src
  pulsar_config.h
  pulsar_config.cpp
  pulsar_native.cpp
)

include_directories("/usr/local/include")

link_directories("/usr/local/lib")

find_library(LIBPULSAR pulsar "/usr/local/lib" "")
message("the pulsar lib is ${LIBPULSAR}")
if(${LIBPULSAR} STREQUAL "")
  message(FATAL_ERROR, "the pulsar lib could not found.")
endif()

FLB_PLUGIN(out_pulsar_native "${src}" "")

link_libraries(${LIBPULSAR})

target_link_libraries(flb-plugin-out_pulsar_native ${LIBPULSAR})

target_link_libraries(flb-plugin-out_pulsar_native -lpthread)


