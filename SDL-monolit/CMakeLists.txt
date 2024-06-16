cmake_minimum_required(VERSION 3.0)
project(SDL2_Test)

# Encontrar o pacote SDL2 com pkg-config
find_package(PkgConfig REQUIRED)
pkg_search_module(SDL2 REQUIRED sdl2)

# Incluir diretórios de cabeçalho da SDL2
include_directories(${SDL2_INCLUDE_DIRS})

# Configurar o executável
add_executable(main main.cpp)

# Incluir as flags retornadas pelo pkg-config
target_compile_options(main PRIVATE ${SDL2_CFLAGS_OTHER})

# Linkar com as bibliotecas da SDL2
target_link_libraries(main PRIVATE ${SDL2_LIBRARIES})