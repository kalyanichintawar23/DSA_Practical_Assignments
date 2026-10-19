#include <iostream>

using namespace std;

class Stack {
    int arr[100];
    int topIndex;

public:
    Stack() {
        topIndex = -1;
    }

    void push(int val) {
        if (topIndex >= 99) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++topIndex] = val;
    }

    void pop() {
        if (topIndex < 0) {
            cout << "Stack Underflow" << endl;
            return;
        }
        topIndex--;
    }

    int top() {
        if (topIndex < 0) {
            return -1;
        }
        return arr[topIndex];
    }

    bool empty() {
        return topIndex == -1;
    }
};

class QueueTwoStacks {
    Stack s1, s2;

public:
    void enqueue(int val) {
        s1.push(val);
    }

    void dequeue() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue Underflow" << endl;
            return;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        s2.pop();
    }

    int peek() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is Empty" << endl;
            return -1;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    QueueTwoStacks q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.peek() << endl;

    q.dequeue();
    cout << "Front element after dequeue: " << q.peek() << endl;

    q.dequeue();
    q.dequeue();

    if (q.empty()) {
        cout << "Queue is empty" << endl;
    }

    return 0;
}