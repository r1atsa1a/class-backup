#include <iostream>
using namespace std;
template<class T>
class Sample {
    public:
        T n;
        Sample(T _n = 0) : n(_n) {}
        void show() {
            cout << "The Value is : " << n << '\n';
        }
        bool operator ==(Sample _t) {
            if (n == _t.n) return true;
            return false;
        }
        Sample operator -(Sample _t) {
            return Sample(n - _t.n);
        }
        Sample& operator --() {
            -- n;
            return *this;
        }
};
int main() {
	Sample<int> s1(5), s2(8), s3;
	if (s1 == s2) cout << "s1和s2相等。" << '\n';
    else cout << "s1和s2不相等。" << '\n';
	s3 = s1 - s2;
	-- s3;
	s3.show();
	return 0;
}