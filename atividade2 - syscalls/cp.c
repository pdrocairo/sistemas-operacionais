#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]){
//  ./meuprograma arquivo1.txt arquivo2.txt => 3 argc
// argc = somatoria de comandos por espaco no input do terminal

    if (argc != 3) {
        printf("Erro: Uso correto: ./copy <origem> <destino>\n");
        return 1;
    }

    const char *arqfonte = argv[1];
    const char *arqalvo = argv[2];

    int fonte = open(arqfonte, O_RDONLY);
    if (fonte == -1){
        perror("Erro ao abrir o arquivo de origem");
        return 1;
    }

    int alvo = open(arqalvo, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    if (alvo == -1){
        perror("Erro ao abrir o arquivo de destino");
        close(fonte);
        return 1;
    }

    char buf[1024];
    int tamanholido;

    //tamanholido = read(fonte, buf, 1024)
    //leia do arquivo fonte 1024 bytes e guarde no buf, apos isso retorne quantos bytes vc leu
    while ((tamanholido = read(fonte, buf, 1024)) != 0)
        write(alvo, buf, tamanholido);

    close(fonte);
    close(alvo);
    return 0;
}
