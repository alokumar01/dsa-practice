#include <iostream>
using namespace std;

class Node {
public:
    int licensePlate;
    Node* next;

    Node(int licensePlate) : licensePlate(licensePlate), next(nullptr) {}
};

Node* createNode(int licensePlate) {
    return new Node(licensePlate);
}

Node* deleteByPlate(Node* head, int plateToRemove) {
    if (head == nullptr) {
        return nullptr;
    }
    
    Node* temp = head;
    if (head->licensePlate == plateToRemove) {
        head = head->next;
        delete temp;
        return head;
    }
    
    Node* prev = nullptr;
    while (temp != nullptr && temp->licensePlate != plateToRemove) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == nullptr) {
        return head; // Plate not found
    }
    
    prev->next = temp->next;
    delete temp;
    return head;
}

Node* deleteByPosition(Node* head, int position) {
    if (head == nullptr || position < 0) {
        return head; // Position out of bounds or empty list
    }
    
    Node* temp = head;
    if (position == 0) {
        head = head->next;
        delete temp;
        return head;
    }
    
    for (int i = 0; i < position - 1 && temp != nullptr; ++i) {
        temp = temp->next;
    }
    
    if (temp == nullptr || temp->next == nullptr) {
        return head; // Position out of bounds
    }
    
    Node* del = temp->next;
    temp->next = del->next;
    delete del;
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->licensePlate << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int N;
    cin >> N;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < N; ++i) {
        int licensePlate;
        cin >> licensePlate;
        Node* newNode = createNode(licensePlate);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int plateToRemove, positionToRemove;
    cin >> plateToRemove;
    cin >> positionToRemove;

    head = deleteByPlate(head, plateToRemove);
    head = deleteByPosition(head, positionToRemove);

    printList(head);

    return 0;
}
