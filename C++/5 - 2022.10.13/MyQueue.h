#ifndef _MY_QUEUE_H_
#define _MY_QUEUE_H_

const int M = 110;
class MyQueue {
public:
	MyQueue();
	MyQueue(int _x);
	int top();
	void pop();
	void push(int _x);
	bool empty();
	void disp();
private:
	int arr[M];
	int head, tail;
};
MyQueue::MyQueue() {
	head = 0;
	tail = 0;
}
MyQueue::MyQueue(int _x) {
	head = 0;
	tail = 0;
	arr[tail ++] = _x;
}
int MyQueue::top() {
	return arr[head];
}
void MyQueue::pop() {
	head ++;
}
void MyQueue::push(int _x) {
	arr[tail ++] = _x;
}
bool MyQueue::empty() {
	if (head == tail) cout << "队列为空！" << '\n';
	else cout << "队列不为空！" << '\n';
}
void MyQueue::disp() {
	for (int i = head; i < tail; i ++) cout << arr[i] << " ";
	cout << '\n';
}

#endif
