#include <string.h>

void reverse(char arr[]);

int main() {

    return 0;
}

/* reverse: reverse string s in place */
void reverse(char s[]) {
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        // c = s[i], s[i] = s[j], s[j] = c;
    }
}