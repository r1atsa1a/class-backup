#include <iostream>
using namespace std;
const int M = 110;
int my_strlen(char *p) {
    int len = 0;
    for (; *(p + len); len ++);
    return len;
}
int main() {
    char s1[M] = "hello world:)";
    printf("the lenth of '%s' is %d\n", s1 ,my_strlen(s1));
    char s2[M] = "\\i love c++/";
    printf("the lenth of '%s' is %d\n", s2 ,my_strlen(s2));
    char s3[M] = "cpp yes:) python no:(";
    printf("the lenth of '%s' is %d\n", s3 ,my_strlen(s3));
    return 0;
}