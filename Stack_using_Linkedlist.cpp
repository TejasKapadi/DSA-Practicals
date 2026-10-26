#include <iostream>
using namespace std;

class node {
public:
    int data;
    node *next;

    node(int x) {
        data = x;
        next = NULL;
    }
};

class stack {
private:
    node *top;

public:
    stack() {
        top = NULL;
    }

    int empty() {
        if (top == NULL) {
            return 1;
        } else {
            return 0;
        }
    }

    void push(int x) {
        node *p = new node(x);
        p->next = top;
        top = p;
    }

    int pop(void) {
        int x = top->data;
        node *p = top;
        top = top->next;
        delete p;
        return x;
    }

    int peek() {
        return top->data;
    }

    void display() {
        node *q = top;
        while (q != NULL) {
            cout << endl << q->data;
            q = q->next;
        }
    }
};

int main() {
    int x;
    stack s;

    s.push(999);
    s.push(878);
    s.push(707);
    s.push(500);
    s.push(333);
    s.push(100);
    
    s.display();

    if (!s.empty()) {
        x = s.pop();
        cout << endl << "Removed" << x;
    }
    
    s.display();

    x = s.peek();
    cout << endl << "Top Element is:" << x;

    return 0;
}

//Output:
PS D:\Tejas> cd "d:\Tejas\" ; if ($?) { g++ Stack_using_Linkedlist.cpp -o Stack_using_Linkedlist } ; if ($?) { .\Stack_using_Linkedlist }

100
333
500
707
878
999
Removed100
333
500
707
878
999
Top Element is:333