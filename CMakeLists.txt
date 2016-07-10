# COPYRIGHT (c) 2016 Andre Paulos
#
# BSD ISC License
#
# Permission to use, copy, modify, and/or distribute this software for any
# purpose with or without fee is hereby granted, provided that the above
# copyright notice and this permission notice appear in all copies.
#
# THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
# WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
# MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
# ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
# WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
# ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
# OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

cmake_minimum_required(VERSION 3.0.2)

# Disable in-source build
set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

set(PROJECT_NAME wonder-space)

project(${PROJECT_NAME})

# Build type
# Configure through -D
if (NOT CMAKE_BUILD_TYPE)
  if (NOT BUILD_TYPE)
    set(CMAKE_BUILD_TYPE debug)
  else ()
    set(CMAKE_BUILD_TYPE ${BUILD_TYPE})
  endif ()
endif ()

message(STATUS "Building ${CMAKE_BUILD_TYPE} ${PROJECT_NAME}\n")

# Binary filename
set(BIN_NAME wonder-space)
set(LIB_NAME ${BIN_NAME}_lib)

# Directories
set(SRC_DIR src)
set(INC_DIR include)
set(RES_DIR ressources)
set(LIB_DIR lib)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_INCLUDE_DIRECTORIES_PROJECT_BEFORE ON)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)
set(PREDEFINED_TARGETS_FOLDER "CMake")

include(CMakeDependentOption)

include(Utils)
check_compiler()

include(ThirdPartyLibraries)

include_directories(
  ${PROJECT_SOURCE_DIR}/${INC_DIR}
)

include(Sources)

include(CxxFlags)

include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_BINARY_DIR}/${INC_DIR}")

# Add targets
add_library(${LIB_NAME} ${SOURCE_FILES})
add_executable(${BIN_NAME} ${MAIN_SOURCE_FILE})

# Libraries links
target_link_libraries(${LIB_NAME} ${EXTRA_LIBS})
target_link_libraries(${BIN_NAME} ${LIB_NAME})

if (DEPENDENCIES)
    add_dependencies(${LIB_NAME} ${DEPENDENCIES})
endif ()

include(CPackConfig)
include(CPack)
