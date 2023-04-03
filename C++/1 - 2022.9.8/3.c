#include <stdio.h>
#include <string.h>
void strCopy(char *s1, char *s2) {
    int i;
    for (i = 0; s1[i]; i ++) s2[i] = s1[i];
    s2[i] = '\0';
}
int main() {
    char str[1010], str_copied[1010];
    strcpy(str, "hello world");
    strCopy(str, str_copied);
    printf("copied: %s\n", str_copied);
    strcpy(str, "i love cs");
    strCopy(str, str_copied);
    printf("copied: %s\n", str_copied);
    strcpy(str, "test");
    strCopy(str, str_copied);
    printf("copied: %s\n", str_copied);
    return 0;
}