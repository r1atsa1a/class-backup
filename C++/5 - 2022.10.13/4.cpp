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
	friend void out(Book t) {
		if (t.price >= 50) {
			cout << "该书价格大于50($): ";
			cout << t.name << " " << t.author << " " << t.publish << " " << t.price << '\n';
		}
	}
private:
	char name[20], author[20];
	char publish[20];
	int price;
};
int main() {
	Book t1("Book1", "Mike", "0000-01", 49);
	t1.disp();
	out(t1);
	Book t2("Book2", "Jake", "0000-02", 51);
	t2.disp();
	out(t2);
	Book t3("Book3", "Tony", "0000-03", 88);
	t3.disp();
	out(t3);
	return 0;
}
