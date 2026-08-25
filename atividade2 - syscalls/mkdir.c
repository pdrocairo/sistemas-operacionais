#include <stdio.h>
#include <sys/stat.h>


int main(int argc, char *argv[]){
    if (argc != 2){
        printf("Erro: Uso correto: ./mkdir <nome-da-pasta>\n");
        return 1;
    }

    int result = mkdir(argv[1], 0777); //nome da pasta, codigo permissao para qqlr usuario edite e mexa na pasta

    if (result == -1){
        perror("Erro ao criar o diretorio");
        return 1;
    }

    return 0;
}
