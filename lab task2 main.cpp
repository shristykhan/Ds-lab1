#include <iostream>
using namespace std;

class Node {

public:

    int data;

    Node* next;

    Node* prev;

};

void addFront(Node** head_ref, int new_data) {

    Node* new_node = new Node();

    new_node->data = new_data;

    new_node->next = (*head_ref);

    new_node->prev = NULL;

    if ((*head_ref) != NULL)

        (*head_ref)->prev = new_node;

    (*head_ref) = new_node;

}

void addAfter(Node* prev_node, int new_data) {

    if (prev_node == NULL) {

        cout << "The given previous node cannot be NULL";

        return;

    }

    Node* new_node = new Node();

    new_node->data = new_data;

    new_node->next = prev_node->next;

    prev_node->next = new_node;

    new_node->prev = prev_node;

    if (new_node->next != NULL)

        new_node->next->prev = new_node;

}

void addEnd(Node** head_ref, int new_data) {

    Node* new_node = new Node();

    Node* last = *head_ref;

    new_node->data = new_data;

    new_node->next = NULL;

    if (*head_ref == NULL) {

        *head_ref = new_node;

        new_node->prev = NULL;

        return;

    }

    while (last->next != NULL) {

        last = last->next;

    }

    last->next = new_node;

    new_node->prev = last;

}

void printList(Node* node) {

    while (node != NULL) {

        cout << node->data << " ";

        node = node->next;

    }

    cout << endl;

}


void deleteHead(Node** head_ref) {

    if (*head_ref == NULL) {

        cout << "Linked list is empty. Cannot delete head node.\n";

        return;

    }

    Node* temp = *head_ref;

    *head_ref = (*head_ref)->next;

    if (*head_ref != NULL)

        (*head_ref)->prev = NULL;

    delete temp;

}


void deleteEnd(Node** head_ref) {

    if (*head_ref == NULL) {

        cout << "Linked list is empty. Cannot delete last node.\n";

        return;

    }

    Node* last = *head_ref;

    while (last->next != NULL) {

        last = last->next;

    }

    if (last->prev != NULL)

        last->prev->next = NULL;

    else

        *head_ref = NULL;

    delete last;

}


void deleteNode(Node** head_ref, Node* del_node) {

    if (*head_ref == NULL || del_node == NULL) {

        cout << "Invalid input. Cannot delete node.\n";

        return;

    }

    if (del_node->prev != NULL)

        del_node->prev->next = del_node->next;

    else

        *head_ref = del_node->next;

    if (del_node->next != NULL)

        del_node->next->prev = del_node->prev;

    delete del_node;

}

int main() {

    Node* head = NULL;

    addEnd(&head, 20);

    addFront(&head, 8);

    addEnd(&head, 40);

    addAfter(head->next, 25);

    cout << "Linked list: ";

    printList(head);


    deleteHead(&head);

    cout << "Linked list after deleting head: ";

    printList(head);


    deleteEnd(&head);

    cout << "Linked list after deleting last node: ";

    printList(head);


    if (head != NULL && head->next != NULL)

        deleteNode(&head, head->next);

    cout << "Linked list after deleting node in the middle: ";

    printList(head);


    return 0;

}
