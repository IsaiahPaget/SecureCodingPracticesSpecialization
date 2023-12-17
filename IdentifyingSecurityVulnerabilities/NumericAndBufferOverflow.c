#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    // char *large = malloc(-2048);
    // char *zero = malloc(0);
    char *string1 = "aaaaavvvvvaaaaafffffdddddAAAAAVVVVVAAAAAFFFFFDDDDDdf";
    char *string2[52];
    
    strncpy(*string2 + 5, string1, 26);

    return 0;
}