#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

class LinkedList {
    Node* head;
    public :
        LinkedList() {
            head = NULL;
        }
        void insert_Beginning(int value) {
            Node *newnode = new Node();
            newnode->data = value;
            newnode->next = head;
            head = newnode;
        }
        void insert_End(int value) {
            Node *newnode = new Node();
            newnode->data = value;
            newnode->next = NULL;
            
            Node *temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
        void insert_position(int value, int pos) {
            Node* temp = head; 
            int count = 1;
            while (temp->next && count<pos) {
                temp = temp->next;
                count++;
            }

            Node *newnode = new Node();
            newnode->data = value;
            newnode->next = temp->next;
            temp->next = newnode;
        }
        void delete_pos(int pos) {
            Node *temp = head;
            int count = 1;
            while(temp->next && count<pos) {
                temp = temp->next;
                count++;
            }
            Node* delete_node = temp->next;
            temp->next = temp->next->next; 
            delete delete_node;
        }

        void display() {
            Node *temp = head;
            while(temp) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << endl;
        }

        void reverse() {
            Node *current = head;
            Node *next, *prev = NULL;
            while (current != NULL) {
                    next = current->next;
                    current->next = prev;
                    prev = current;
                    current = next;
            }
            head = prev;
        }
};

int main() {
    int choice, num1, num2;
    LinkedList obj;
    while(true) {
        cout << "----------MENU----------" << endl;
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n4. Delete at Position\n5. Display\n6. Exit\nEnter number of choice : ";
        cin >> choice;
        switch(choice) {
            case 1 :
                cout << "Enter the data : ";
                cin >> num1;
                obj.insert_Beginning(num1);
                break;
            case 2 :
                cout << "Enter the data : ";
                cin >> num1;
                obj.insert_End(num1);
                break;
            case 3 :
                cout << "Enter the data : ";
                cin >> num1;
                cout << "Enter the position number (from index 0) : ";
                cin >> num2;
                obj.insert_position(num1, num2);
                break;
            case 4 :
                cout << "Enter the position number (from index 0) : ";
                cin >> num1;
                obj.delete_pos(num1);
                break;
            case 5 :
                obj.display();
                break;
            case 6 :
                obj.reverse();
                break;
        }
    }
}