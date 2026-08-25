#include <stdio.h> //metodos padroes printf, scanf...
#include <unistd.h> // close, read, write, unlink...
#include <fcntl.h> //open e constantes O_RDONLY, O_WRONLY, etc.
#include <sys/syscall.h>
#include <sys/stat.h> // Onde fica a syscall mkdir, stat
#include <dirent.h> // opendir e readdir (usado para implementar ls)
#include <time.h> // date, time, localtime, strftime

int main()
{
    printf("Hello world!\n");
    return 0;
}
