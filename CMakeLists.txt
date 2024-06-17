cmake_minimum_required(VERSION 3.5)

project(main)

# Definir o diretório de saída para o executável final
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

# Configurar flags de compilação
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

# Encontrar pacotes necessários (SDL2 e SDL2_image)
find_package(PkgConfig REQUIRED)
pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

# Localizar todos os arquivos fonte na pasta src
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

# Criar o executável com base nos arquivos fonte encontrados
add_executable(${PROJECT_NAME} ${SOURCES})

# Incluir diretórios de cabeçalho das bibliotecas encontradas
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/include)

# Linkar as bibliotecas necessárias
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})

