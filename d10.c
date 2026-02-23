#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(char str[], int left, int right) {
    if (left >= right) {
        return true;
    }
    if (str[left] != str[right]) {
        return false;
    }
    return isPalindrome(str, left + 1, right - 1);
}

int main() {
    char str[100];
    if (scanf("%s", str) == 1) {
        if (isPalindrome(str, 0, strlen(str) - 1)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
