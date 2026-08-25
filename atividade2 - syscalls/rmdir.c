#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){

    if (argc !=2){
        printf("Erro: Uso correto: ./rmdir <nome-da-pasta>\n");
        return 1;
    }

    int result = rmdir(argv[1]);

    if (result == -1){
        printf("Erro ao tentar remover pasta");
    }

    return 0;
}
