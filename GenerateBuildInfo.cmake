# Minimal GenerateBuildInfo.cmake for Solstice
# This script generates a build_info.h header with basic build information

set(BUILD_INFO_HEADER "${CMAKE_BINARY_DIR}/build_info.h")

file(WRITE ${BUILD_INFO_HEADER} "/**\n")
file(APPEND ${BUILD_INFO_HEADER} " * Auto-generated build info header\n")
file(APPEND ${BUILD_INFO_HEADER} " */\n\n")
file(APPEND ${BUILD_INFO_HEADER} "#pragma once\n")
file(APPEND ${BUILD_INFO_HEADER} "#define BUILD_TIMESTAMP \"${CMAKE_TIMESTAMP}\"\n")
file(APPEND ${BUILD_INFO_HEADER} "#define BUILD_TYPE \"${CMAKE_BUILD_TYPE}\"\n")
