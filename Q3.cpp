#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

class CLL {
    Node *head;
    public:
        CLL(){head=NULL;}
        void InsertBeginning(int val) {
            Node *x = new Node();
            x->data = val;
            if (head == NULL) {
                head = x;
                head->next = head;
            }
            else {
                Node *temp = head;
                while (temp->next != head) {
                    temp = temp->next;
                }
                x->next = head;
                head = x;
                temp->next = head;
            }
            
        }
        void InsertEnd(int val) {
            Node *x = new Node();
            Node *temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            x->data = val;
            x->next = head;
            temp->next = x;
        }
        void display() {
            Node *x = head;
            do {
                cout << x->data << " -> ";
                x = x->next;
            }
            while (x != head);
            cout << endl;
        }
        void deleteNodeBeginning() {
            if (head == NULL) {cout << "Insert elements first!" << endl;}
            else {
                Node *temp = head;
                while (temp->next != head) {
                    temp = temp->next;
                }
                head = head->next;
                temp->next = head;
            }
        }
        void deleteNodeEnd() {
            if (head == NULL) {cout << "Insert elements first!" << endl;}
            else {
                Node *temp = head;
                while (temp->next->next != head) {
                    temp = temp->next;
                }
                temp->next = head;
            }
        }
};

int main() {
    CLL obj;
    bool not_exit = true;
    int choice, value;
    while (not_exit) {
        cout << "----------------------MENU----------------------------" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Delete at Beginning" << endl;
        cout << "4. Delete at End" << endl;
        cout << "5. Display" << endl;
        cout << "6. End" << endl;
        cout << "Enter the number of choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1 :
            cout << "Enter a value to insert : ";
            cin >> value;
            obj.InsertBeginning(value);
            break;
        case 2 :
            cout << "Enter a value to insert : ";
            cin >> value;
            obj.InsertEnd(value);
            break;
        case 3 :
            obj.deleteNodeBeginning();
            break;
        case 4 :
            obj.deleteNodeEnd();
            break;
        case 5 :
            obj.display();
            break;
        case 6 :
            not_exit = false;
            break;
        default:
            cout << "INCORRECT CHOICE!";
            break;
        }
    }
}