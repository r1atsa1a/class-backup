#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
class String {
    public:
        // 构造函数的重载
        String(const char* = 0) {
            _size = 0;
            _string = NULL;
        }
        String(const String& t) {
            _size = t._size;
            _string = new char[_size + 1];
        }
        // 析构函数
        ~String() {

        }
        // 赋值操作符+的重载
        String operator+ (const String& t) {
            String tmp;
            tmp._size = _size + t._size;
            tmp._string = new char[tmp._size + 1];
            strcpy(tmp._string, _string);
            strcat(tmp._string, t._string);
            return tmp;
        }
        String operator+ (const char *t) {
            String tmp;
            tmp._size = _size + strlen(t);
            tmp._string = new char[tmp._size + 1];
            strcpy(tmp._string, _string);
            strcat(tmp._string, t);
            return tmp;
        }
        // 赋值操作符=的重载
        String& operator= ( const String& t) {
            delete[] _string;
            _size = t._size;
            _string = new char[_size + 1];
            strcpy(_string, t._string);
            return *this;
        }
        String& operator= ( const char *t) {
            delete[] _string;
            _size = strlen(t);
            _string = new char[_size + 1];
            strcpy(_string, t);
            return *this;
        }
        // 重载的下标[]操作符
        char& operator[] (int idx) const {
            return _string[idx];
        }
        // 等于操作符==的重载集合
        bool operator== (const char *t) const {
            if (!strcmp(_string, t)) return true;
            else return false;
        }
        bool operator== (const String& t) const {
            if (!strcmp(_string, t._string)) return true;
            else return false;
        }
        // 重载<< ，>>
        friend ostream& operator<< (ostream& os, const String& t) {
            os << t._string;
            return os;
        }
        friend istream& operator>> (istream& is, String& t) {
            is >> t._string;
            return is;
        }
        // 接口
        int size() {
            return _size;
        }
        char* c_str() {
            return _string;
        }
    private:
        int _size;
        char *_string;
};
int main() {
    char t1_char[10] = "ABCDEF";
    String t1_1, t1_2;
    t1_2 = "abcd";
    t1_1 = t1_2;
    cout << t1_1 << '\n';
    t1_1 = t1_1 + t1_2;
    cout << t1_1 << '\n';
    t1_2 = t1_2 + t1_char;
    cout << t1_2 << '\n';
    t1_2[0] = 'A';
    cout << t1_2 << '\n';
    if (t1_1 == t1_2) cout << "True" << '\n';
    else cout << "False" << '\n';
    if (t1_1 == t1_char) cout << "True" << '\n';
    else cout << "False" << '\n';

    char t2_char[10] = "awdasd";
    String t2_1, t2_2;
    t2_2 = "xxxxx";
    t2_1 = t2_2;
    cout << t2_1 << '\n';
    t2_1 = t2_1 + t2_2;
    cout << t2_1 << '\n';
    t2_2 = t2_2 + t2_char;
    cout << t2_2 << '\n';
    t2_2[7] = 'b';
    cout << t2_2 << '\n';
    if (t2_1 == t2_2) cout << "True" << '\n';
    else cout << "False" << '\n';
    if (t2_1 == t2_char) cout << "True" << '\n';
    else cout << "False" << '\n';

    char t3_char[10] = "dwaawd";
    String t3_1, t3_2;
    t3_2 = "asdda";
    t3_1 = t3_2;
    cout << t3_1 << '\n';
    t3_1 = t3_1 + t3_2;
    cout << t3_1 << '\n';
    t3_2 = t3_2 + t3_char;
    cout << t3_2 << '\n';
    t3_2[2] = 'x';
    cout << t3_2 << '\n';
    if (t3_1 == t3_2) cout << "True" << '\n';
    else cout << "False" << '\n';
    if (t3_1 == t3_char) cout << "True" << '\n';
    else cout << "False" << '\n';

    return 0;
}