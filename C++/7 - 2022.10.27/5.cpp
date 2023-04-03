#include <iostream>
#include <cstring>
using namespace std;
class MyString {
    public:
        MyString() {
            size = 0;
            ptr = NULL;
        }
        MyString(char *_str) {
            size = strlen(_str);
            ptr = new char[size + 1];
            strcpy(ptr, _str);
        }
        MyString(MyString &_str) {
            size = _str.size;
            strcpy(ptr, _str.ptr);
        }
        ~MyString() {
            size = 0;
            delete ptr;
            ptr = NULL;
        }
        void Show() {
            cout << ptr << '\n';
        }
        void Reset(char *_str) {
            size = strlen(_str);
            delete ptr;
            ptr = new char[size + 1];
            strcpy(ptr, _str);
        }
        void Append(char *_str) {
            char *tmp;
            tmp = new char[strlen(ptr) + 1];
            strcpy(tmp, ptr);
            size = strlen(ptr) + strlen(_str);
            delete ptr;
            ptr = new char[size + 1];
            strcat(tmp, _str);
            ptr = tmp;
        }
        int Length() {
            return size;
        }
    private:
        char *ptr;
        int size;
};
int main() {
    MyString S1;
    char t1_1[50] = "This is a test - 1";
    char t1_2[50] = "(~Append Info - 1)";
    S1.Reset(t1_1); S1.Show();
    S1.Append(t1_2); S1.Show();
    cout << "The length of the string: " << S1.Length() << '\n';
    MyString S2;
    char t2_1[50] = "This is a test - 2";
    char t2_2[50] = "(~Append Info - 2)";
    S2.Reset(t2_1); S2.Show();
    S2.Append(t2_2); S2.Show();
    cout << "The length of the string: " << S2.Length() << '\n';
    MyString S3;
    char t3_1[50] = "This is a test - 3";
    char t3_2[50] = "(~Append Info - 3)";
    S3.Reset(t3_1); S3.Show();
    S3.Append(t3_2); S3.Show();
    cout << "The length of the string: " << S3.Length() << '\n';
    return 0;
}