#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Book {
    private:
        string name, author, pub;
        double price;
    public:
        Book() {}
        Book(string _name, string _author, string _pub, double _price) {
            name = _name;
            author = _author;
            pub = _pub;
            price = _price;
        }
        Book& operator= (Book t) {
            name = t.name;
            author = t.author;
            pub = t.pub;
            price = t.price;
            return *this;
        }
        bool operator== (Book t) {
            if (name == t.name && author == t.author && pub == t.pub && price == t.price) return true;
            return false;
        }
        Book& operator++ () {
            price ++;
            return *this;
        }
        Book operator++ (int) {
            Book old = *this;
            ++(*this);
            return old;
        }
        friend ostream& operator<< (ostream& os, Book& t) {
            os << t.name << '\n';
            os << t.author << '\n';
            os << t.pub << '\n';
            os << t.price << '\n';
            return os;
        }
};
int main() {
    double t1_price = 10;
    string t1_name = "一本书", t1_author = "一个作者", t1_pub = "一个出版社";
    Book t1_1, t1_2(t1_name, t1_author, t1_pub, t1_price);
    t1_1 = t1_2;
    cout << t1_1;
    if (t1_1 == t1_2) cout << "True" << '\n';
    else cout << "False" << '\n';
    t1_1 ++; cout << t1_1;

    double t2_price = 20;
    string t2_name = "一本书", t2_author = "一个作者", t2_pub = "一个出版社";
    Book t2_1, t2_2(t2_name, t2_author, t2_pub, t2_price);
    t2_1 = t2_2;
    cout << t2_1;
    if (t2_1 == t2_2) cout << "True" << '\n';
    else cout << "False" << '\n';
    t2_1 ++; cout << t2_1;

    double t3_price = 30;
    string t3_name = "一本书", t3_author = "一个作者", t3_pub = "一个出版社";
    Book t3_1, t3_2(t3_name, t3_author, t3_pub, t3_price);
    t3_1 = t3_2;
    cout << t3_1;
    if (t3_1 == t3_2) cout << "True" << '\n';
    else cout << "False" << '\n';
    t3_1 ++; cout << t3_1;

    return 0;
}