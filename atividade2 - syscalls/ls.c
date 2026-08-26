#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]){

    if (argc != 2){
        printf("Erro: Uso correto: ./ls <caminho>\n");
        return 1;
    }

    char *path_arquivo = argv[1];

    DIR *result = opendir(path_arquivo);

    if(result == NULL){
        perror("Erro ao tentar abrir o caminho especificado");
        return 1;
    }

    struct dirent *rd;

    while ((rd = readdir(result)) != NULL)
        printf("%s\n", rd->d_name);
    
    closedir(result);
    
    return 0;
}







