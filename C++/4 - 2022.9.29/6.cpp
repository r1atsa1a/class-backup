#include <iostream>
using namespace std;
const int N = 10;
class Num {
    public:
        Num();
        Num(int t[]);
        Num(const Num &t);
        ~Num();
        void Show();
    private:
        int arr[N];
        int sum, max, min, mid;
        double aver;
};
Num::Num() {
    for (int i = 0; i < N; i ++) arr[i] = 0;
    sum = 0; max = 0; min = 0; mid = 0; aver = 0;
}
Num::Num(int t[]) {
    sum = 0;
    for (int i = 0; i < N; i ++) {
        arr[i] = t[i];
        sum += arr[i];
        if (!i || arr[i] > max) max = arr[i];
        if (!i || arr[i] < min) min = arr[i];
    }
    mid = arr[4];
    aver = sum / 10.0;
}
Num::Num(const Num &t) {
    for (int i = 0; i < N; i ++) arr[i] = t.arr[i];
    sum = t.sum; max = t.max; min = t.min; mid = t.mid; aver = t.aver;
}
Num::~Num() {
    
}
void Num::Show() {
    printf("arr:");
    for (int i = 0; i < N; i ++) printf("%d ", arr[i]);
    printf("\nsum = %d max = %d min = %d\n", sum, max, min);
    printf("mid = %d average = %.2lf\n\n", mid, aver);
}
int main() {
    Num t1;
    t1.Show();
    int tarr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Num t2(tarr);
    t2.Show();
    Num t3(t2);
    t3.Show();
    return 0;
}