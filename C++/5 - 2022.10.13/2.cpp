#include <iostream>
#include <cstring>
using namespace std;
class Tea {
public:
	Tea(char *_type, int _price) {
		strcpy(type, _type);
		price = _price;
		sum += _price;
	}
	void disp() {
		cout << type << " " << price << '\n';
	}
	static void out() {
		cout << "当前营业额($): " << sum << '\n';
	}
private:
	char type[20];
	int price;
	static int sum;
};
int Tea::sum = 0;
int main() {
	Tea t1("type1", 10);
	t1.disp();
	Tea::out();
	Tea t2("type2", 15);
	t2.disp();
	Tea::out();
	Tea t3("type3", 20);
	t3.disp();
	Tea::out();
	return 0;
}
