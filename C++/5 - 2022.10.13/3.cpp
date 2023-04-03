#include <iostream>
#include <cstring>
using namespace std;
class Restaurant {
public:
	Restaurant(char *_type, int _price) {
		strcpy(type, _type);
		price = _price;
		cnt ++;
		sum += price;
	}
	void disp() {
		cout << type << " " << price << '\n';
	}
	static void out() {
		cout << "当前消费均价($): " << 1.0 * sum / cnt << '\n';
	}
private:
	char type[20];
	int price;
	static int cnt, sum;
	static double aver;
};
int Restaurant::cnt = 0;
int Restaurant::sum = 0;
int main() {
	Restaurant t1("type1", 50);
	t1.disp();
	Restaurant::out();
	Restaurant t2("type2", 75);
	t2.disp();
	Restaurant::out();
	Restaurant t3("type3", 182);
	t3.disp();
	Restaurant::out();
	return 0;
}
