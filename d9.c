

#include <stdio.h>
#include <string.h>

void mirror(char str[], int index, int length) {
    if (index >= length) {
        return;
    }
    mirror(str, index + 1, length);
    printf("%c", str[index]);
}

int main() {
    char str[100];
    if (scanf("%s", str) == 1) {
        mirror(str, 0, strlen(str));
        printf("\n");
    }
    return 0;
}
