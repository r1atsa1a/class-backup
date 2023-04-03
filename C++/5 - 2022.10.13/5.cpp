#include <iostream>
#include <cstring>
using namespace std;
class Book {
public:
	Book(char *_name, char *_author, char *_publish, int _price) {
		strcpy(name, _name);
		strcpy(author, _author);
		strcpy(publish, _publish);
		price = _price;
	}
	void disp() {
		cout << name << " " << author << " " << publish << " " << price << '\n';
	}
	friend void cmp(Book t1, Book t2) {
		cout << t1.name << " vs " << t2.name << '\n';
		if (t1.price > t2.price) cout << t1.name << "价格更高！" << '\n';
		else if (t1.price < t2.price) cout << t2.name << "价格更高！" << '\n';
		else cout << "两书价格相同！" << '\n';
	}
private:
	char name[20], author[20];
	char publish[20];
	int price;
};
int main() {
	Book t1("Book1", "Mike", "0000-01", 50);
	t1.disp();
	Book t2("Book2", "Jake", "0000-02", 30);
	t2.disp();
	Book t3("Book3", "Tony", "0000-03", 50);
	t3.disp();
	cmp(t1, t2);
	cmp(t2, t3);
	cmp(t1, t3);
	return 0;
}
