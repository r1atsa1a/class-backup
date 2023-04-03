#include <iostream>
using namespace std;
const int N = 1e3 + 10;
class Stackk {
    public:
        Stackk();
        Stackk(int _x);
        ~Stackk();
        void Push(int _x);
        void Pop();
        void Show();
        bool Empty();
    private:
        int arr[N];
        int tt;
};
Stackk::Stackk() {
    tt = 0;
}
Stackk::Stackk(int _x) {
    tt = 0;
    arr[tt ++] = _x;
}
Stackk::~Stackk() {
    
}
void Stackk::Push(int _x) {
    arr[tt ++] = _x;
    cout << arr[tt - 1] << " Pushed!" << endl;
}
void Stackk::Pop() {
    tt --;
    cout << arr[tt] << " Poped!" << endl;
}
void Stackk::Show() {
    for (int i = 0; i < tt; i ++) cout << arr[i] << " ";
    cout << endl;
}
bool Stackk::Empty() {
    return tt > 0;
}
int main() {
    Stackk s1;
    for (int i = 1; i <= 3; i ++) s1.Push(i);
    s1.Show();
    if (!s1.Empty()) cout << "Stack is empty!" << endl;
    else cout << "Stack is not empty!" << endl;
    s1.Pop();
    s1.Show();
    Stackk s2;
    for (int i = 1; i <= 2; i ++) s2.Push(i);
    s2.Show();
    s2.Pop(); s2.Pop();
    if (!s2.Empty()) cout << "Stack is empty!" << endl;
    else cout << "Stack is not empty!" << endl;
    s2.Show();
    return 0;
}