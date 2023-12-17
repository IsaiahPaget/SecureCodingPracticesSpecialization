#include <stdio.h>

int main (int argv) {
    
    char relPath[] = "../.gitignore";

    printf("hello, %d\n", dirname(argv));
    return 0;
}

char *fixpath(char* path) {
    
}