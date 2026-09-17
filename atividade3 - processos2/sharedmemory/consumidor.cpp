#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <cstdio>

int main(){
    const int SIZE = 80;
    const char* name = "OS";
    int shm_fd;
    void* ptr;
    shm_fd = open(name, O_RDWR, 0666);
    ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);
    // COPIA TODAS VARIAVEIS DO PRODUTOR
    char* s;

    for (s=static_cast<char*>(ptr); *s != static_cast<char>(0); s++)
        std::putchar(*s);
    std::putchar('\n');

    s=static_cast<char*>(ptr);
    *s='*';
    exit(0);
}
