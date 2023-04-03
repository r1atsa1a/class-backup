#include <iostream>
using namespace std;
template <class T>
class LinkNode {
public:
    T Data;
    LinkNode<T> *Next;
    ~LinkNode() {}
};
template <class T>
class LinkList {
    LinkNode<T> *front;
    public:
        LinkList() {
            LinkNode<T> *ptr = new LinkNode<T>();
            if (ptr) {
                ptr->Next = NULL;
                front = ptr;
            }
        }
        ~LinkList() {
            while (front) {
                LinkNode<T> *ptr = front;
                front = front->Next;
                delete (ptr);
                ptr = NULL;
            }
        }
        LinkList<T>& operator =(const LinkList<T>& s1) {
            LinkNode<T> *ptr1 = s1.front->Next;
            LinkNode<T> *ptr2 = front;
            while (ptr1) {
                LinkNode<T> *tmp = new LinkNode<T>();
                tmp->Data = ptr1->Data;
                tmp->Next = ptr1->Next;
                ptr2->Next = tmp;
                ptr1 = ptr1->Next;
            }
        }
        void Destory() {
            LinkNode<T> *ptr = front->Next;
            while (ptr) {
                LinkNode<T> *ptr1 = ptr;
                ptr = ptr->Next;
                delete ptr1;
                ptr1 = NULL;
            }
            front->Next = NULL;
        }
        void Push_Back(T elem) {
            LinkNode<T> *ptr = front;
            while (ptr->Next) {
                ptr = ptr->Next;
            }
            LinkNode<T> *ptr1 = new LinkNode<T>();
            if (ptr1) {
                ptr1->Data = elem;
                ptr->Next = ptr1;
            }
        }
        void Push_Front(T elem) {
            LinkNode<T> *ptr1 = new LinkNode<T>();
            if (ptr1) {
                ptr1->Data = elem;
                ptr1->Next = front->Next;
                front->Next = ptr1;
            }
        }
        void Push_Front(LinkNode<T> *nodes) {
            if (nodes) {
                nodes->Next = front->Next;
                front->Next = nodes;
            }
        }
        T Pop_Front() {
            LinkNode<T> *ptr = front->Next;
            if (ptr) {
                T elem = ptr->Data;
                front->Next = ptr->Next;
                delete ptr;
                ptr = NULL;
                return elem;
            }
            return -1;
        }
        T Pop_Back() {
            LinkNode<T> *ptr = front;
            LinkNode<T> *tmp = ptr;
            while (ptr->Next) {
                tmp = ptr;
                ptr = ptr->Next;
            }
            T elem = ptr->Data;
            tmp->Next = NULL;
            delete ptr;
            ptr = NULL;
            return elem;
        }
        T Remove(LinkNode<T> *node) {
            if (node->Next) {
                LinkNode<T> *ptr = node->Next;
                T elem = ptr->Data;
                node->Next = ptr->Next;
                delete ptr;
                ptr = NULL;
                return elem;
            }
            return -1;
        }
        void Remove(T elem) {
            LinkNode<T> *ptr = front;
            while (ptr->Next) {
                if (ptr->Next->Data == elem) {
                    LinkNode<T> *tmp = ptr->Next;
                    ptr->Next = tmp->Next;
                    delete tmp;
                    tmp = NULL;
                    break;
                }
                else ptr = ptr->Next;
            }
        }
        void Reverse() {
            LinkNode<T> *ptr = front->Next;
            LinkNode<T> *n = ptr->Next;
            while (n) {
                ptr->Next = n->Next;
                Push_Front(n);
                n = ptr->Next;
            }
        }
        LinkNode<T> *find(T elem) {
            LinkNode<T> *ptr = front->Next;
            while (ptr) {
                if (ptr->Data == elem) return ptr;
                else ptr = ptr->Next;
            }
            return NULL;
        }
        void Show() {
            LinkNode<T> *ptr = front->Next;
            if (!ptr) cout << "NO ELEMENT!";
            while (ptr) {
                cout << ptr->Data << " ";
                ptr = ptr->Next;
            }
            cout << '\n';
        }
};
int main() {
    LinkList<int> *ilist = new LinkList<int>();
    ilist->Push_Front(1);
    ilist->Push_Front(2);
    ilist->Push_Front(3);
    ilist->Push_Front(4);
    ilist->Push_Front(5);
    ilist->Push_Front(6);
    ilist->Show();

    ilist->Destory();
    ilist->Show();
    
    ilist->Push_Back(1);
    ilist->Push_Back(2);
    ilist->Push_Back(3);
    ilist->Push_Back(4);
    ilist->Push_Back(5);
    ilist->Push_Back(6);
    ilist->Show();

    ilist->Reverse();
    ilist->Show();

    ilist->Remove(3);
    ilist->Show();

    ilist->Remove(ilist->find(4));
    ilist->Show();

    ilist->Pop_Back();
    ilist->Show();

    ilist->Pop_Front();
    ilist->Show();

    LinkList<int> *list1 = ilist;
    list1->Show();

    return 0;
}
