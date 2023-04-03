#include  <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
const int M = 110;
string info;
string name, tel, address;
int vis[M];
void Extract() {
    memset(vis, 0, sizeof vis);
    name.clear(); tel.clear(); address.clear();
    int idx = -1;
    for (int i = 0; i < info.size(); i ++)
        if (isdigit(info[i])) {
            tel.push_back(info[i]);
            vis[i] = 1;
            if (idx == -1) idx = i;
        }
    if (tel.front() == '1') {
        for (int i = info.size() - 1, k = 0; i >= 0 && k < 5; i --)
            if (isdigit(info[i])) vis[i] = 0, k ++;
        tel.erase(tel.end() - 5, tel.end());
    } else {
        for (int i = 0, k = 0; i < info.size() && k < 5; i ++)
            if (isdigit(info[i])) vis[i] = 0, k ++;
        tel.erase(tel.begin(), tel.begin() + 5);
    }
    int left = 1;
    for (int i = 0; i < info.size(); i ++) {
        if (info[i] < 0) {
            if (name.size() > 6) {
                name.clear();
                left = 0;
                for (int o = 0; o < 7; o ++) vis[o] = 0;
                break;
            }
            name.push_back(info[i]);
            vis[i] = 1;
        } else break;
    }
    if (!left) {
        for (int i = info.size() - 1; i >= 0; i --) {
            if (info[i] < 0) {
                name.push_back(info[i]);
                vis[i] = 1;
                if (name.size() > 6) {vis[i] = 0; break;}
            }
        }
        name.pop_back();
        reverse(name.begin(), name.end());
    }
    for (int i = 0; i < info.size(); i ++)
        if (!vis[i] && info[i] != ' ' && info[i] != ',')
            address.push_back(info[i]);
}
void Disp() {
    cout << "提取后：" << '\n';
    cout << "姓名：" << name << '\n';
    cout << "电话：" << tel << '\n';
    cout << "地址：" << address << '\n';
    cout << '\n';
}
int main() {
    info = "张伟,13899886633,杭州市西湖区天目山路天欣苑3幢1单元501室";
    Extract(); Disp();
    info = "张伟 13899886633 杭州市西湖区天目山路天欣苑3幢1单元501室";
    Extract(); Disp();
    info = "杭州市西湖区天目山路天欣苑3幢1单元501室,张伟,13899886633";
    Extract(); Disp();
    info = "张伟13899886633杭州市西湖区天目山路天欣苑3幢1单元501室";
    Extract(); Disp();
    info = "张伟 13899886633 杭州市 西湖区 天目山路 天欣苑 3幢1单元501室";
    Extract(); Disp();
    info = "杭州市西湖区天目山路天欣苑3幢1单元501室张伟13899886633";
    Extract(); Disp();
    info = "杭州市西湖区天目山路天欣苑3幢1单元50113899886633张伟";
    Extract(); Disp();
}
