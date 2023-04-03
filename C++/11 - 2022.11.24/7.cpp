#include <iostream>
using namespace std;
const int M = 10;
template<class T>
class MyStack {
	T list[M];
	int top;
    public:
        MyStack() : top(0) {}
        void Push(const T& t1) {
            if (isFull()) cout << "Stack is Full!" << '\n';
            else list[top++] = t1;
        }
        void clear() {
            top = 0;
        }
        T Pop() {
            if (isEmpty()) {
                cout << "Stack is Empty!" << '\n';
                return -1;
            } else {
                top--;
                return list[top];
            }
        }
        T Top() {
            if (isEmpty()) cout << "Stack is Empty!" << '\n';
            else return list[top - 1];
        }
        bool isEmpty() {
            return top == 0;
        }
        bool isFull() {
            return top == M;
        }
};
int main(){
	MyStack<int> T1;
	T1.Pop();
	for (int i = 1; i <= 10; i ++) T1.Push(i);
	for (int i = 0; i < 10; i ++) cout << T1.Pop() << ' ';
	cout << '\n';
    
	MyStack<double> T2;
	for (double i = 0; i <= 1; i+= 0.1) T2.Push(i);
	int cnt = 0;
	for (double i = 0; i <= 10; i++) {
		cout << T2.Pop() << ' ';
		cnt ++;
		if (cnt == 10){
			cnt = 0;
			cout << '\n';
		}
	}
	return 0;
}
