#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class QueueLinkedList {
    Node* front;
    Node* rear;

public:
    QueueLinkedList() {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int val) {
        Node* temp = new Node();
        temp->data = val;
        temp->next = NULL;

        if (rear == NULL) {
            front = rear = temp;
            return;
        }

        rear->next = temp;
        rear = temp;
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow" << endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        delete temp;
    }

    int peek() {
        if (front == NULL) {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return front->data;
    }

    bool empty() {
        return front == NULL;
    }
};

int main() {
    QueueLinkedList q;

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
