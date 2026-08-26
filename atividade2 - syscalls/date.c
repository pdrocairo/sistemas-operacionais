#include <stdio.h>
#include <time.h>


int main(){
    time_t tempo_bruto; //inicializa a variavel para suportar o date

    time(&tempo_bruto); //pega o tempo em segundos e poe dentro da variavel

    printf("%s", ctime(&tempo_bruto)); //imprime o valor convertido para a maneira como conhecemos e o imprime

    return 0;
    
}