#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(NULL) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(NULL) {}

    void insert(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }


    void remove(int value) {
        Node* current = head;
        Node* prev = NULL;

        if (current != NULL && current->data == value) {
            head = current->next;
            delete current;
            return;
        }


        while (current != NULL && current->data != value) {
            prev = current;
            current = current->next;
        }


        if (current == NULL) {
            cout << "Value not found in the list" << endl;
            return;
        }


        prev->next = current->next;
        delete current;
    }


    bool find(int value) {
        Node* current = head;
        while (current != NULL) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }


    void display() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList myList;

    myList.insert(33);
    myList.insert(43);
    myList.insert(55);
    myList.insert(66);


    cout << "Initial linked list:" << endl;
    myList.display();


    cout << "\nSearching for value 43: " << boolalpha << myList.find(43) << endl;

    cout << "Searching for value 70: " << boolalpha << myList.find(70) << endl;


    myList.remove(55);


    cout << "\nLinked list after deleting 55:" << endl;
    myList.display();



    return 0;
}
