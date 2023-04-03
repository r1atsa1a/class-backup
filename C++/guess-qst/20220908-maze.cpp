#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef pair<int, int> PII;
const int M = 20, row = 7, col = 13;
int tx[4] = {0, 0, -1, 1}, ty[4] = {1, -1, 0, 0};
int startx = 2, starty = 3;
char Gph[M][M] = {
    {"              "},
    {" AAIAAAAAAAAAA"},
    {" AA AA     AAA"},
    {" A     A A   A"},
    {" AAA AA   AA A"},
    {" AA      AA  A"},
    {" A  AAAA    AA"},
    {" AAAAAAAAAAOAA"}
};
bool vis[M][M];
vector<vector<PII>> res;
void DFS(int x, int y, vector<PII> sav) {
    if (Gph[x][y] == 'O') {
        sav.push_back({x, y});
        res.push_back(sav);
        return;
    }
    if (vis[x][y] || Gph[x][y] != ' ') return;
    vis[x][y] = true;
    sav.push_back({x, y});
    for (int i = 0; i < 4; i ++) {
        int xx = x + tx[i], yy = y + ty[i];
        if (xx > 0 && xx <= row && yy > 0 && yy <= col)
            DFS(xx, yy, sav);
    }
    vis[x][y] = false;
}
int cmp(vector<PII> a, vector<PII> b) {
    return a.size() < b.size();
}
int main() {
    memset(vis, false, sizeof(vis));
    vector<PII> sav;
    DFS(startx, starty, sav);
    sort(res.begin(), res.end(), cmp);
    for (int i = 0; i < res.size(); i ++) {
        int x = 1, y = 3;
        printf("step<%d>:", res[i].size());
        for (int j = 0; j < res[i].size(); j ++) {
            int xx = res[i][j].first - x;
            int yy = res[i][j].second - y;
            if (xx == 1 && yy == 0) cout << 's';
            else if (xx == 0 && yy == 1) cout << 'd';
            else if (xx == -1 && yy == 0) cout << 'w';
            else cout << 'a';
            x = res[i][j].first, y = res[i][j].second;
        }
        cout << endl;
    }
    for (int i = 0; i < res[0].size(); i ++)
        Gph[res[0][i].first][res[0][i].second] = '*';
    for (int i = 1; i <= row; i ++) {
        for (int j = 1; j <= col; j ++) cout << Gph[i][j];
        cout << endl;
    }  
    return 0;
}