#include <stdio.h>


int main(int argc, char *argv[]){
    if(argc != 3){
        printf("Erro: Uso correto: ./mv <caminho-antigo> <caminho-novo>\n");
        return 1;
    }

    const char *origem = argv[1];
    const char *destino = argv[2];

    int result = rename(origem, destino);
    if (result == -1){
        perror("Erro ao tentar mover arquivo");
        return 1;
    }

    return 0;

}