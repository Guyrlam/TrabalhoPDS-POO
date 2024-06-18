cmake_minimum_required(VERSION 3.10)

project(main)

# Definir o diretório de saída para o executável final
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

# Configurar flags de compilação usando propriedades modernas do CMake
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Encontrar pacotes necessários (SDL2, SDL2_image e SDL2_ttf)
find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
pkg_check_modules(SDL2TTF REQUIRED SDL2_ttf>=2.0.0)

# Mensagens de erro personalizadas para pacotes não encontrados
if(NOT SDL2_FOUND)
    message(FATAL_ERROR "SDL2 não encontrado!")
endif()

if(NOT SDL2IMAGE_FOUND)
    message(FATAL_ERROR "SDL2_image não encontrado!")
endif()

if(NOT SDL2TTF_FOUND)
    message(FATAL_ERROR "SDL2_ttf não encontrado!")
endif()

# Localizar todos os arquivos fonte na pasta src
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

# Criar o executável com base nos arquivos fonte encontrados
add_executable(${PROJECT_NAME} ${SOURCES})

# Incluir diretórios de cabeçalho das bibliotecas encontradas
target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${SDL2TTF_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/include)

# Linkar as bibliotecas necessárias
target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${SDL2TTF_LIBRARIES})

# Configuração para os testes
# Localizar todos os arquivos de teste na pasta tests
file(GLOB TEST_SOURCES "${PROJECT_SOURCE_DIR}/tests/*.cpp")

# Adicionar executável de teste
add_executable(tests ${TEST_SOURCES})

# Incluir diretórios de cabeçalho necessários para os testes
target_include_directories(tests PRIVATE ${PROJECT_SOURCE_DIR}/include)

# Linkar as bibliotecas necessárias para o executável de teste
target_link_libraries(tests PRIVATE ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${SDL2TTF_LIBRARIES})

# Adicionar o executável de teste ao CTest
enable_testing()
add_test(NAME tests COMMAND tests)
