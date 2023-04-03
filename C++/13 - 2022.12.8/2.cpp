#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
int main() {
    int n = 10, i, *b;
    int a[10] = {4, 7, 8, 4, 7, 6, 7, 7, 1, 2};
    ofstream ofs("2.txt",ios::out);
    ofs << n << '\n';
    for(i = 0 ; i < n; i ++)
        if(i != n - 1) ofs << a[i] << " ";
        else ofs << a[i] << '\n';
    ifstream ifs("2.txt", ios::in);
    n = 0;
    ifs >> n;
    b = new int[n];
    for (i = 0; i < n; i++) ifs >> b[i];
    for (i = 0; i < n; i++)
        if(i != n - 1) cout << b[i] << " ";
        else cout << b[i] << '\n';
    return 0;
}