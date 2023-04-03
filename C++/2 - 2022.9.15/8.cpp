#include <iostream>
#include <algorithm>
using namespace std;
const int M = 110;
struct node {
    int ascii_no;
    int f;
}ascii[128];
bool cmp(struct node a, struct node b) {
    return a.f > b.f;
}
void solve(char *str) {
    for (int i = 0; *(str + i); i ++) ascii[*(str + i)].f ++;
    sort(ascii, ascii + 128, cmp);
}
int main() {
    for (int i = 0; i <= 127; i ++) ascii[i].ascii_no = i;
    for (int i = 0; i <= 127; i ++) ascii[i].f = 0;
    char s1[M] = "hello world:)";
    solve(s1);
    for (int i = 0; i <= 127 ; i++)
        if (ascii[i].f) printf("%c's frequency is %d\n", ascii[i].ascii_no, ascii[i].f);
    puts("");
    for (int i = 0; i <= 127; i ++) ascii[i].f = 0;
    char s2[M] = "i love c++!";
    solve(s2);
    for (int i = 0; i <= 127 ; i++)
        if (ascii[i].f) printf("%c's frequency is %d\n", ascii[i].ascii_no, ascii[i].f);
    puts("");
    for (int i = 0; i <= 127; i ++) ascii[i].f = 0;
    char s3[M] = "cpp yes:) python no:(";
    solve(s3);
    for (int i = 0; i <= 127 ; i++)
        if (ascii[i].f) printf("%c's frequency is %d\n", ascii[i].ascii_no, ascii[i].f);
    return 0;
}