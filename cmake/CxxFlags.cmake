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

INCLUDE(CheckCompilerFlags)

# C++ compiler flags
if (CMAKE_COMPILER_IS_GNUC OR CMAKE_COMPILER_IS_GNUCXX OR MINGW)
    message(STATUS "Setting GCC flags\n--------------------")
else()
    message(STATUS "Setting Clang/LLVM flags\n---------------------------")
endif ()

COMPILER_FLAGS(
          FLAGS

          "-std=c++11"
          "-Wall" "-pedantic" "-Wextra"
          "-pedantic-errors" "-Wcast-align"
          "-Wcast-qual" "-Wconversion"
          "-Wdisabled-optimization"
          "-Wdocumentation"
          "-Wformat=2"
          "-Wformat-nonliteral" "-Wformat-security"
          "-Wformat-y2k"
          "-Wimplicit" "-Wimport" "-Winit-self" "-Winline"
          "-Wlong-long"
          "-Wmissing-field-initializers" "-Wmissing-format-attribute"
          "-Wmissing-include-dirs" "-Wmissing-noreturn"
          "-Wpacked" "-Wpointer-arith"
          "-Wredundant-decls"
          "-Wstack-protector"
          "-Wstrict-aliasing=2" "-Wswitch-default"
          "-Wswitch-enum"
          "-Wunreachable-code" "-Wunused"
          "-Wunused-parameter"
          "-Wvariadic-macros"
          "-Wno-builtin-macro-redefined"
          "-Wwrite-strings"
          "-Wno-unknown-pragmas"
          "-fsanitize=address"
          "-pipe"
          "-DQT_NO_KEYWORDS"

          FLAGS_RELEASE

          "-Wno-inline"
)

message(STATUS "CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")
