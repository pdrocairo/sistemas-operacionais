#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>

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
    int alvo = open(arqalvo, O_WRONLY | O_CREAT, S_IRUSR, S_IWUSR);

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
