#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<string, int> mp;
int check(char c) {
    if (c >= 'A' && c <= 'Z') return 1;
    else if (c >= 'a' && c <= 'z') return 2;
    return 0;
}
void Cal(char *str) {
    mp.clear();
    int k = 0;
    char tmp[20];
    for (int i = 0; *(str + i); i ++) {
        int tp = check(str[i]);
        if (tp == 1) tmp[k ++] = str[i] - 'A' + 'a';
        else if (tp == 2) tmp[k ++] = str[i];
        else {
            tmp[k] = '\0';
            k = 0;
            mp[tmp] ++;
        }
    }
}
int main() {
    char str1[110] = {"Hello world,hello world hello world hello!"};
    Cal(str1);
    for (auto t : mp)
        cout << t.first << " " << t.second << endl;
    puts("");
    char str2[110] = {"I love cpp,cpp is the best programming language!"};
    Cal(str2);
    for (auto t : mp)
        cout << t.first << " " << t.second << endl;
    puts("");
    char str3[110] = {"i hate python,i hate python,i hate python!"};
    Cal(str3);
    for (auto t : mp)
        cout << t.first << " " << t.second << endl;
    puts("");
    return 0;
}