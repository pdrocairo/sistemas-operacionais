#define _XOPEN_SOURCE 500
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <unistd.h>
#include <cstdlib>


int main(){
    const int SIZE = 80; // tamanho espaco de memoria em bytes

    const char* name = "OS"; //nome da area de memoria

    int shm_fd; //file descriptor

    void* ptr; // aponta para "OS"

    shm_fd = open(name, O_CREAT | O_RDWR, 0666); //abre o arquivo e define permissoes

    ftruncate(shm_fd, SIZE); //define tamanho da area de memoria usada

    ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);

    char *s = static_cast<char *>(ptr);

    char c;

    for (c = 'a'; c<='z';c++)
        *s++ = c;
    *s = (char)0;
    s = static_cast<char*>(ptr);
    while (*s != '*') sleep(1);

    shm_unlink(name);
    exit(0);

}
