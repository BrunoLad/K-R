#include <assert.h>
#include <limits.h>

int contains(char s[], int c);
int any(char s1[], char s2[]);

int main() {
    
    assert(any("defgabc", "abc") == 4);
    assert(any("cdefg", "abx") == -1);

    return 0;
}

int contains(char s[], int c) {
    int i = 0;

    while(s[i] != '\0')
        if (s[i++] == c)
            return i - 1;
    return -1;
}

int any(char s1[], char s2[]) {
    int i;

    int min = INT_MAX;
    for(i = 0; s2[i] != '\0'; i++) {
        int pos = contains(s1, s2[i]);
        if ((pos + 1) && pos < min)
            min = pos;
    }

    if(min != INT_MAX)
        return min;
    
    return -1;
}
