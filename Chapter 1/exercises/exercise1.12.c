#include <stdio.h>

#define IN  1 /* inside a word */
#define OUT 0 /* outside a word */

int main() {
    int c, control;

    control = IN;
    for (c = getchar(); c != EOF; c = getchar()) {
        if (c == ' ' || c == '\t') {
            control = OUT;
            continue;
        } else if (control == OUT) {
            control = IN;
            putchar('\n');
        }
        
        putchar(c);
    }

    return 0;
}
