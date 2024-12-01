#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

class DLL {
    Node *head;
    public:
        DLL(){head=NULL;}
        void InsertBeginning(int val) {
            Node *x = new Node();
            x->data = val;
            x->next = head;
            x->prev = NULL;
            if (head!=NULL) {head->prev = x;}
            head = x;
        }
        void InsertEnd(int val) {
            Node *x = new Node();
            Node *temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            x->data = val;
            x->next = NULL;
            x->prev = temp;
            temp->next = x;
        }
        void display() {
            Node *x = head;
            while (x) {
                cout << "( ";
                if (x->prev) cout << x->prev->data;
                else cout << "NULL";
                cout << " <- " << x->data << " -> ";

                if (x->next) cout << x->next->data;
                else cout << "NULL";
                cout << " ) ";
                
                if (x->next) cout << "<=> ";
                
                x = x->next;
            }
            cout << endl;
        }

        void deleteNodeBeginning() {
            if (head == NULL) {cout << "Insert elements first!" << endl;}
            else {
                head = head->next;
                head->prev = NULL;
            }
        }
        void deleteNodeEnd() {
            if (head == NULL) {cout << "Insert elements first!" << endl;}
            else {
                Node *temp = head;
                while (temp->next) {
                    temp = temp->next;
                }
                temp = temp->prev;
                temp->next = NULL;
            }
        }
};

int main() {
    DLL obj;
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