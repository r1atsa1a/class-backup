#include <iostream>
using namespace std;
const int M = 10;
template<class T>
class MyQueue {
	int front, tail, length;
	T list[M];
    public:
        MyQueue() : front(0), tail(0), length(0) {}
        void Push(const T& t1) {
            if (length != M){
                length ++;
                list[tail] = t1;
                tail = (tail + 1) % M;
            } else cout << "Queue is Full!" << '\n';
        }
        T Pop() {
            if (length != 0) {
                length --;
                int t = front;
                front = (front + 1) % 10;
                return list[t];
            } else cout << "Queue is Empty!" << '\n';
            return 0;
        }
        void clear() {
            front = 0;
            tail = 0;
            length = 0;
        }
        T Fout() {
            return list[front];
        }
        int Getlength() {
            return length;
        }
        bool Iempty() {
            return length == 0;
        }
        bool Ifull() {
            return length == M;
        }
        void Show() {
            if (length == M){
                for (int i = 0; i < M; i++)
                    cout << list[i] << " ";
                cout << '\n';
            } else {
                int tFront = front;
                int tTail = tail;
                while (tFront != tTail){
                    cout << list[tFront] << " ";
                    tFront = (tFront + 1) % M;
                }
                cout << '\n';
            }
        }
        int GetFront() {
            return front;
        }
        int GetTail() {
            return tail;
        }
};
int main(){
	MyQueue<int> t;
	for (int i = 1; i <= 10; i++) t.Push(i);
	cout << "Head Element is POP! " << t.Pop() << '\n';
	t.Show();
	return 0;
}
