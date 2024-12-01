#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedListQueue {
    Node* front;
    Node* rear;
    int size;
    public:
        LinkedListQueue() : front(nullptr), rear(nullptr), size(0) {}

        bool isEmpty() {
            return size == 0;
        }

        void enqueue(int value) {
            Node* newNode = new Node(value);
            if (isEmpty()) {
                front = rear = newNode;
            } else {
                rear->next = newNode;
                rear = newNode;
            }
            size++;
        }

        void dequeue() {
            if (isEmpty()) {
                cout << "QUEUE UNDERFLOW!" << endl;
                return;
            }
            Node* temp = front;
            front = front->next;
            delete temp;
            size--;

            if (isEmpty()) { 
                rear = nullptr;
            }
        }

        int frontValue() {
            if (isEmpty()) {
                cout << "Queue is empty!" << endl;
                return -1;
            }
            return front->data;
        }

        int getSize() {
            return size;
        }
};

int main() {
    LinkedListQueue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    cout << "Front element: " << queue.frontValue() << endl;
    queue.dequeue();
    cout << "Front element after dequeue: " << queue.frontValue() << endl;
    cout << "Queue size: " << queue.getSize() << endl;
}
