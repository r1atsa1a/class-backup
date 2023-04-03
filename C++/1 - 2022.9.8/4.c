#include <stdio.h>
#include <string.h>
char str1[1010], str2[1010];
int solve() {
    for (int i = 0; str1[i]; i ++) {
        if (str1[i] == str2[0]) {
            int p, q;
            for (p = i, q = 0; str1[p] && str2[q]; p ++, q ++)
                if (str1[p] != str2[q]) break;
            if (q == strlen(str2)) return 1;
        }
    }
    return 0;
}
int main() {
    // str1 = abcd, str2 = bc
    strcpy(str1, "abcd");
    strcpy(str2, "bc");
    if (solve()) printf("YES\n");
    else printf("NO\n");
    // str1 = i love cs, str2 = ilove
    strcpy(str1, "i love cs");
    strcpy(str2, "ilove");
    if (solve()) printf("YES\n");
    else printf("NO\n");
    // str1 = hello world, str2 = llo wo
    strcpy(str1, "hello world");
    strcpy(str2, "llo wo");
    if (solve()) printf("YES\n");
    else printf("NO\n");
    return 0;
}