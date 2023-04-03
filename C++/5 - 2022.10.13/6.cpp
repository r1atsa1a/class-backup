#include <iostream>
using namespace std;
#include "MyQueue.h"
int main() {
	MyQueue queue(1);
	queue.push(2);
	queue.push(3);
	queue.push(4);
	queue.push(5);
	queue.disp();
	queue.empty();
	cout << "队首元素为: " << queue.top() << '\n';
	queue.pop();
	queue.disp();
	cout << "队首元素为: " << queue.top() << '\n';
	queue.pop();
	queue.disp();
	cout << "队首元素为: " << queue.top() << '\n';
	return 0;
}
