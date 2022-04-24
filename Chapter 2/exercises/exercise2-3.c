#include <stdio.h>
#include <assert.h>

int lower(char character);
int local_htoi(char str[]);
int local_strlen(char str[]);

int main() {

    assert(local_htoi("0xA") == 10);
    assert(local_htoi("0Xabc") == 0xabc);
    assert(local_htoi("abc") == 0Xabc);
    assert(local_htoi("f") == 15);

    return 0;
}

int lower(char c) {
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';

    return c;
}

int local_htoi(char s[]) {
    int n = 0;

    for (int i = 0; (s[i] >= '0' && s[i] <= '9') ||
            (lower(s[i]) >= 'a' && lower(s[i]) <= 'f') ||
            (lower(s[i]) == 'x'); i++) {
        if ((s[i] == '0' && i == 0) || lower(s[i]) == 'x')
            continue;
        // n = n * 16 + ((lower(s[i]) - '0') % 39);
        if (s[i] >= '0' && s[i] <= '9')
            n = n * 16 + (s[i] - '0');
        else if (lower(s[i]) >= 'a' && lower(s[i]) <= 'f')
            n = n * 16 + (lower(s[i]) - 'a' + 10);

    }

    return n;
}
