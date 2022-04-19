#include <stdio.h>

#define MAXLINE     1000

int getline(char line[], int maxline);
void printReverse(char str[]);
void reverse(char s[]);

/* print the longest input line */
int main() {
    char line[MAXLINE];     /* current input line */

    while(getline(line, MAXLINE) > 0)
        ;

    return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim) {
    int c, i, state;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    s[i] = '\0';

    printReverse(s);
    printf("\n");
    reverse(s);
    printf("%s\n", s);

    return i;
}

void printReverse(char s[]) {
    if (*s != '\0')
        printReverse(s+1);
    printf("%c", *s);
}

// in-place replacement
void reverse(char s[]) {
    int i = 0;

    while (s[i] != '\0')
        ++i;
    
    char r[i+1];
    r[i] = '\0';

    for (int j = 0; j < i; j++)
        r[j] = s[i - j - 1];

    for (int j = 0; j < i; j++)
        s[j] = r[j];
}
