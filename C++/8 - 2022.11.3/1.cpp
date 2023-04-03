#include <iostream>
#include <string>
using namespace std;
class Book {
	public:
		Book(char *_name, char *_pub, char *_price) {
			name = _name;
			pub = _pub;
			price = _price;
		}
		void Disp() {
			cout << ">> 书本类" << '\n';
			cout << "书名: " << name << '\n';
			cout << "出版社: " << pub << '\n';
			cout << "价格: " << price << '\n' << '\n';
		}
		string name, pub, price;
};
class ChildBook : public Book {
	public:
		ChildBook(char *_name, char *_pub, char *_price, char *_age) : Book(_name, _pub, _price) {
			age = _age;
		}
		void Disp() {
			cout << ">> 儿童图书类" << '\n';
			cout << "书名: " << name << '\n';
			cout << "出版社: " << pub << '\n';
			cout << "价格: " << price << '\n';
			cout << "设用年龄: " << age << '\n' << '\n';
		}
		string age;
};
class TeachBook : public Book {
	public:
		TeachBook(char *_name, char *_pub, char *_price, char *_age, char *_type) : Book(_name, _pub, _price) {
			age = _age;
			type = _type;
		}
		void Disp() {
			cout << ">> 教科书类" << '\n';
			cout << "书名: " << name << '\n';
			cout << "出版社: " << pub << '\n';
			cout << "价格: " << price << '\n';
			cout << "设用年龄: " << age << '\n';
			cout << "类别: " << type << '\n' << '\n';
		}
		string age, type;
};
int main() {
	char t1_name[20] = "一本书", t1_pub[20] = "一个出版社", t1_price[20] = "一个价格";
	Book t1(t1_name, t1_pub, t1_price);
	t1.Disp();
	char t2_name[20] = "一本儿童图书", t2_pub[20] = "一个儿童图书出版社", t2_price[20] = "一个儿童图书价格", t2_age[20] = "一个儿童图书年龄";
	ChildBook t2(t2_name, t2_pub, t2_price, t2_age);
	t2.Disp();
	char t3_name[20] = "一本教科书", t3_pub[20] = "一个教科书出版社", t3_price[20] = "一个教科书价格", t3_age[20] = "一个教科书年龄", t3_type[20] = "教科书";
	TeachBook t3(t3_name, t3_pub, t3_price, t3_age, t3_type);
	t3.Disp();
	return 0;
}
