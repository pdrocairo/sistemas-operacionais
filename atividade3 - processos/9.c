#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
int valor = 5;
int main(int argc, char* argv[]){
    pid_t pid; - // id do filho 12312321
    valor = valor + 1;
    pid = fork();
    valor = valor + 1;
    if (pid == 0) {
        valor = valor + 3;
    }
    if (pid > 0) {
        valor = valor + 5;
        wait(NULL);
        printf("Processo pai: valor = %d\n",valor); //linha A
    }
    return 0;
    }