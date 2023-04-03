#include <iostream>
#include <cstring>
using namespace std;
class BookSale {
public:
	BookSale(char *_no, char *_name, int _price) {
		strcpy(no, _no);
		strcpy(name, _name);
		price = _price;
		num ++;
		sumP += price;
	}
	void disp() {
		printf("%s %s %d\n", no, name, price);
	}
	static void sum() {
		cout << "总金额: " << sumP << '\n';
	}
private:
	static int num, sumP;
	char no[15], name[20];
	int price;
};
int BookSale::num = 0;
int BookSale::sumP = 0;
int main() {
	cout << "no  name  price" << '\n';
	BookSale t1("001", "Book1", 10);
	t1.disp();
	BookSale t2("002", "Book2", 20);
	t2.disp();
	BookSale t3("003", "Book3", 30);
	t3.disp();
	BookSale::sum();
	return 0;
}
