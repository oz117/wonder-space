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

function(check_compiler)
    if (${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
        message(FATAL_ERROR "\nVisual Studio is not supported.")
    elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
        if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS "3.6")
            message(FATAL_ERROR "\nIn order to use C++11 features, this program cannot be built using a version of Clang less than 3.2")
        endif ()
    elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
        if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS "4.8")
            message(FATAL_ERROR "\nIn order to use C++11 features, this program cannot be built using a version of GCC less than 4.7")
        endif ()
    endif ()
endfunction()
