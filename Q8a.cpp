#include <iostream>
using namespace std;

class ArrayStack {
    int items[100];  // Fixed-size array
    int top;

public:
    ArrayStack() : top(-1) {}

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == 99;
    }

    void push(int value) {
        if (isFull()) {
            cout << "STACK OVERFLOW!" << endl;
            return;
        }
        items[++top] = value;
    }

    void pop() {
        if (isEmpty()) {
            cout << "STACK UNDERFLOW!" << endl;
            return;
        }
        top--;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return items[top];
    }

    int getSize() {
        return top + 1;
    }
};

int main() {
    ArrayStack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element: " << stack.peek() << endl;
    stack.pop();
    cout << "Top element after pop: " << stack.peek() << endl;
    cout << "Stack size: " << stack.getSize() << endl;

    return 0;
}
