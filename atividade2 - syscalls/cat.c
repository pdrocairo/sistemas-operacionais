#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    if (argc < 2){
        printf("Erro: Uso correto: ./cat <arquivo");
        return 1;
    }

    const char *path_arquivo = argv[1];

    int arquivo = open(path_arquivo, O_RDONLY);

    if (arquivo == -1){
        perror("Erro ao abrir");
        return 1;
    }


    char buf[1024];
    int rd;

    while ((rd = read(arquivo, buf, 1024)) !=0)
        write(1, buf, rd);

    close(arquivo);

    return 0;
}
