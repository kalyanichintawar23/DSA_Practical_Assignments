#include <iostream>
#include <queue>

using namespace std;

class Stack {
    queue<int> q1, q2;

public:
    void push(int x) {
        q2.push(x);

        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1, q2);
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack Underflow! Cannot pop." << endl;
            return;
        }
        cout << "Popped: " << q1.front() << endl;
        q1.pop();
    }

    int top() {
        if (q1.empty()) {
            cout << "Stack is Empty!" << endl;
            return -1;
        }
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }

    int size() {
        return q1.size();
    }
};

int main() {
    Stack s;

    cout << "=== STACK USING TWO QUEUES DEMONSTRATION ===" << endl;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl;
    cout << "Current stack size: " << s.size() << endl;

    s.pop();
    cout << "Top element after pop: " << s.top() << endl;

    s.pop();
    s.pop();

    if (s.empty()) {
        cout << "Stack is now empty." << endl;
    }

    s.pop();

    return 0;
}
