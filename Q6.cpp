#include <iostream>
using namespace std;

class Queue {
    int items[100];
    int size, front, rear;
    public :
        Queue() : size(0), front(0), rear(-1){};
        bool empty() {
            cout << (size==0) << endl;
        }
        void enqueue(int value) {
            if (size==100) {
                cout << "QUEUE OVERFLOW!" << endl;
                return;
            }
            rear = (rear+1)%100;
            items[rear] = value;
            size++;
        }
        void dequeue() {
            if (size==0) {
                cout << "QUEUE UNDERFLOW!" << endl;
                return;
            }
            front = (front+1)%100;
            size--;
        }
        void getsize() {
            cout << size << endl;
        }
        void show_front() {
            cout << items[front] << endl;
        }
};

int main() {
    Queue obj;
    bool not_exit = true;
    int choice, value;
    while (not_exit) {
        cout << "----------------------MENU----------------------------" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Show Front" << endl;
        cout << "4. Size" << endl;
        cout << "5. End" << endl;
        cout << "Enter the number of choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1 :
            cout << "Enter a value to insert : ";
            cin >> value;
            obj.enqueue(value);
            break;
        case 2 :
            obj.dequeue();
            break;
        case 3 :
            obj.show_front();
            break;
        case 4 :
            obj.getsize();
            break;
        case 5 :
            not_exit = false;
            break;
        default:
            cout << "INCORRECT CHOICE!";
            break;
        }
    }
}