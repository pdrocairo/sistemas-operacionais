#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){

    if (argc != 2){
        printf("Erro: Uso correto: ./rm <arquivo> \n");
        return 1;
    }

    int result = unlink(argv[1]);

    if (result == -1){
        printf("Erro ao tentar apagar o arquivo");
        return 1;
    }

    return 0;


}
