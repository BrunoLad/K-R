#include <stdio.h>

#define COLUMNS 8   /* number of columns per tab */

int main() {
    int c, count;
    
    count = 0;
    for (c = getchar(); c != EOF; c = getchar())
        if (c == '\t') {
            for (int i = 0; i < COLUMNS - count; ++i)
                    putchar(' ');
            count = 0;
        } else {
            putchar(c);
            count = (c == '\n') ? 0 : (++count) % COLUMNS;
        }

    return 0;
}
