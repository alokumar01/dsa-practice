#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void insertAtEnd(Node* &head, int val) {
    Node* newNode = new Node(val);
    if (head== nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while(temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}



void insertAtBeginning(Node* &head, int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void insertAtPos(Node* &head, int value, int pos) {
    Node* newNode = new Node(value);
    if (pos == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* temp = head;
        for(int i = 0; i < pos-1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}



void traverseList(Node* head) {
    Node* crnt = head;
    while(crnt != nullptr) {
        cout << crnt->data << " ";
        crnt = crnt->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int n;
    cin >> n;
    for (int i = 0; i<n; i++) {
        int val;
        cin >> val;
        insertAtEnd(head, val);
    }
    cout << "Inserted at end of list" << endl;
    traverseList(head);

    int value, pos;
    cout << "Enter value and position to insert: ";
    cin >> value >> pos;
    insertAtPos(head, value, pos);
    cout << "List after insertion: " << endl;
    traverseList(head);

    return 0;
}