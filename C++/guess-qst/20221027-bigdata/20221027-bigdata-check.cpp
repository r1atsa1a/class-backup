#include <iostream>
#include <vector>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int M = 1e4 + 10;
int main() {
    IOS
    int o = 9856;
    vector<vector<int>> v(M);
    FILE *fp;
    fp = fopen("bigdata-10w.txt", "rb");
    while (!feof(fp)) {
        int idx, x;
        fscanf(fp, "%d %d", &idx, &x);
        v[x].push_back(idx);
    }
    for (auto xi : v[o]) cout << xi << " ";
    fclose(fp);
    return 0;
}
