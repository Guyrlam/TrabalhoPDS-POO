# TrabalhoPDS-POO
![Static Badge](https://img.shields.io/badge/Linguagem-C%2B%2B-%23fcf403)
![Static Badge](https://img.shields.io/badge/UFMG-PDSII-%23fc4503)
![Static Badge](https://img.shields.io/badge/RPG-Futebol-%2303a1fc)

# Soccer Duo

## O que é o projeto?

Nosso jogo se baseia em um RPG de futebol, em que 2 times de 4 jogadores se confrontam para chegar a 3 gols marcados.
***Como rodar o projeto está no fim do arquivo**

## Regras 

- Turnos alternados
- Todos atacam todos (de menos os goleiros)
- Quem faz 3 jogos vence
- Jogadores após os ataques ficam cansados, o que diminui seus ataques e defesas
- É possível realizar substituições ilimitdas
- Os times tem 7 jogadores, sendo 3 jogadores de linha no banco de reservas,  3 jogadores de linha titulares e um goleiro
- Ao ganhar 2 confrontos, o time poderá tentar atacar o goleiro com o resto das somas dos ataques ganhos
  -  Se o resto das somas dos ataques ganhos for maior que a defesa do goleiro, o time pode jogar dois dados, se tirar 6 ou 5 em um deles, o gol é marcado
  -  Se o resto das somas dos ataques ganhos for menor que a defesa do goleiro, o time pode jogar um dado, se tirar 6 ou 5, o gol é marcado
- Após o gol a resistência dos jogadores e restaurada
- Se um jogador vai para o banco, sua resistência é restaurada

# Libs utilizadas
- SDL2
- SDL2 Image
- SDL2 fonts

## Configurações de ambiente

Antes de utilizar o nosso sistema se atente as seguintes configurações basicas de ambiente utilizada:
- WSL 1 ou 2.0
- Ubuntu 22.04
- Visual Studio Code
- Extenções: WSL, C/C++, C/C++ Extension Pack

## Como rodar?

Existem duas formas, entretanto:

Primeiro clone o projeto para uma pasta dentro do ambiente Ubuntu (No WSL), lembre-se de entrar no WSL pela funcionalidade da extensão WSL do VScode.

### Primeira forma

Com o projeto clonado, execute na raiz do projeto o seguinte o comando abaixo, ele irá instalar todas as dependencias necessárias para utilizar o projeto:
```
  sudo sh config.sh 
```

Após a instalação, entre dentro da pasta build com o comando abaixo:

```
 cd build
```
Dentro da pasta **buid** execute o comando abaixo para realizar o build do projeto:

```
cmake ..
```

Logo após a realização do build, execute o comando abaixo para realizar a compilação dos arquivos:

```
make
```

Agora saia da pasta build e volte para raiz do projeto:

```
cd ..
```

Por fim rode o arquivo executável **main** gerado na raiz do projeto:

```
./main
```

### Segunda forma

Para rodar dessa forma, certifique-se que já executou o arquivo ***config.sh***. 
No nosso ambiente de desenvolvimento configuramos o build e o debug para ocorrerem de forma mais simples, utilizando atalhos. Para executá-lo, aperte em seu teclado Ctrl+shift+B, e selecione na parte superior central a opção "Meu Projeto", o projeto irá realizar o build. Logo após vá para a área de run e debug e clique no botão de play.

