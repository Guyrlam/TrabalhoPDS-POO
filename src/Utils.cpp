#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "../include/Utils.hpp"

std::string Utils::readFile(const std::string& filePath) {
       
    try {
        // Abrindo o arquivo para leitura
        std::ifstream file(filePath);

        // Verifica se o arquivo foi aberto corretamente
        if (!file.is_open()) {
            throw std::runtime_error("Erro ao abrir o arquivo " + filePath);
        }

        // Variável para armazenar o conteúdo do arquivo
        std::stringstream content;

        // Variável para armazenar cada linha do arquivo
        std::string row;

        // Lendo e armazenando cada linha do arquivo
        while (std::getline(file, row)) {
            content << row << std::endl;
        }

        // Fechando o arquivo
        file.close();

        // Retornando o conteúdo do arquivo como uma string
        return content.str();
        
    }catch (const std::exception& e) {
        std::cerr << "Exceção: " << e.what() << std::endl;
        return "";
    }
}