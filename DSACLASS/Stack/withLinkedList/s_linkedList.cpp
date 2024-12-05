#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void push(Node*& top, int value) {
    Node* newNode = new Node(value);
    // newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int pop(Node*& top) {
    if (top == nullptr) {
        cout << "stack underflow" << endl;
        return -1;
    }

    int value = top->data;
    Node* temp = top;
    top = top->next;

    delete temp;
    return value;
}

void display(Node*& top) {
    if (top == nullptr) {
        cout << "stack is empty" << endl;
        return;
    }
    Node* current = top;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void removeEvenElements(Node*& node) {
    Node* tempStack = nullptr;
    while (node != nullptr) {
        int value = pop(node);
        if (value % 2 != 0) {
            push(tempStack, value);
        }
    }

    while (tempStack != nullptr) {
        push(node, pop(tempStack));
    }
}

int main() {
    Node* stack = nullptr;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter elements: \n";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        push(stack, value);
    }

    cout << "\nOriginal stack:\n";
    display(stack);

    removeEvenElements(stack);

    cout << "\nStack after removing even elements:\n";
    display(stack);

    return 0;
}
