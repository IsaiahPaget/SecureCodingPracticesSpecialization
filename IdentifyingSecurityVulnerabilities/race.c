#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int trustfile(char *file) {
    struct stat sb;
    uid_t uid = getuid();

    if (stat(file, &sb) == -1) {
        perror("error getting file stats");
        return -1;
    }

    if (sb.st_uid != uid) {
        printf("not trustworthy\n");
        return 0;
    }

    char *path = strdup(file);
    char *dir = dirname(path);

    while (strcmp(dir, "/") != 0) {
        if (access(dir, W_OK) == 0) {
            printf("not trustworthy\n");
            free(path);
            return 0;
        }
        dir = dirname(dir);
    }

    printf("trustworthy\n");
    free(path);
    return 1;
}

int main(int argc, char *argv[]) {
    return trustfile(argv[1]);
}
