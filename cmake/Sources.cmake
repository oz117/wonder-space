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


# Resource files
set(ResourceFiles ${CONFIG_FILE_SOURCE})

# Main source file
set(MAIN_SOURCE_FILE ${PROJECT_SOURCE_DIR}/${SRC_DIR}/main.cpp)

# SOURCE_FILES
set(SOURCES
        ${PROJECT_SOURCE_DIR}/${SRC_DIR}/Utils/Settings.cpp
        ${PROJECT_SOURCE_DIR}/${SRC_DIR}/Window/Window.cpp
        ${PROJECT_SOURCE_DIR}/${SRC_DIR}/Actors/Player.cpp
        ${PROJECT_SOURCE_DIR}/${SRC_DIR}/Actors/Enemy.cpp
        ${PROJECT_SOURCE_DIR}/${SRC_DIR}/Actors/Model.cpp
        ${PROJECT_SOURCE_DIR}/${SRC_DIR}/Actors/Model.cpp
        ${PROJECT_SOURCE_DIR}/${SRC_DIR}/Commands/Commands.cpp
        ${PROJECT_SOURCE_DIR}/${SRC_DIR}/Commands/NullCommand.cpp
        ${PROJECT_SOURCE_DIR}/${SRC_DIR}/InputHandler.cpp
        ${PROJECT_SOURCE_DIR}/${INC_DIR}/Settings.hpp
        ${PROJECT_SOURCE_DIR}/${INC_DIR}/Window.hpp
        ${PROJECT_SOURCE_DIR}/${INC_DIR}/Actors/Actor.hpp
        ${PROJECT_SOURCE_DIR}/${INC_DIR}/Actors/Player.hpp
        ${PROJECT_SOURCE_DIR}/${INC_DIR}/Actors/Enemy.hpp
        ${PROJECT_SOURCE_DIR}/${INC_DIR}/Actors/Model.hpp
        ${PROJECT_SOURCE_DIR}/${INC_DIR}/Commands/Command.hpp
        ${PROJECT_SOURCE_DIR}/${INC_DIR}/Commands/Commands.hpp
        ${PROJECT_SOURCE_DIR}/${INC_DIR}/Commands/NullCommand.hpp
        ${PROJECT_SOURCE_DIR}/${INC_DIR}/InputHandler.hpp
)
