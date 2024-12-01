#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};
class LinkedListStack {
    Node* top;
    int size;
    public:
    LinkedListStack() : top(nullptr), size(0) {}
    bool isEmpty() {
        return top == nullptr;
    }
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        size++;
    }
    void pop() {
        if (isEmpty()) {
            cout << "STACK UNDERFLOW!" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
    }
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return top->data;
    }
    int getSize() {
        return size;
    }
};
int main() {
    LinkedListStack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout << "Top element: " << stack.peek() << endl;
    stack.pop();
    cout << "Top element after pop: " << stack.peek() << endl;
    cout << "Stack size: " << stack.getSize() << endl;
    return 0;
}