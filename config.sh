#!/bin/bash

# Script para instalar pacotes e programas no Ubuntu

# Verifica se o script está sendo executado como root
if [ "$(id -u)" != "0" ]; then
  echo "Este script precisa ser executado com privilégios de superusuário (root)." >&2
  exit 1
fi

# Atualiza a lista de pacotes
apt update

# Instalação dos pacotes e programas
apt install -y g++
apt-get install -y build-essential
snap install cmake --classic
apt-get install -y gdb
apt install libsdl2-dev libsdl2-image-dev pkg-config
mkdir build           # Cria a pasta 'build'
cd build              # Entra na pasta 'build'
cmake ..              # Executa o CMake na pasta atual
make                  # Compila o código conforme o Makefile gerado pelo CMake
cd ..
chmod -R a+rwx build  # Garante acesso de leitura, escrita e execução para todos na pasta 'build'
chmod -R a+rwx bin


# Mensagem de conclusão
echo "Instalação completa."

exit 0
