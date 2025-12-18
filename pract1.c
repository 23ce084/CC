#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i = 0, len;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    
    len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }

    while (str[i] == 'a') {
        i++;
    }

    if (str[i] == 'b' && str[i + 1] == 'b' && str[i + 2] == '\0') {
        printf("Valid String\n");
    } else {
        printf("Invalid String\n");
    }

    return 0;
}
