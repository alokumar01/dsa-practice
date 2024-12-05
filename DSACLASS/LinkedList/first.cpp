// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

struct LinkedList {
    Node* head;
    
    LinkedList() : head(nullptr) {}
    
    // Destructor   
    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
    // Add a new node at the end of the list;
    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node *current = head;
            while(current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    };
    
    // Print all the elements in the list
    void print() {
        Node *current = head;
        while (current != nullptr)  {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    };
    
    // Check if a node with the given value exitst in the list or not;
    bool find(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value)
            return true;
            current = current->next;
        }
        return false;
    }
    
    // Insert a node at a specific position
    void insertAt(int index, int value) {
        if (index < 0) return;
        
        Node* newNode = new Node(value);
        if (index == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }
        
        Node* current = head;
        for (in i = 0; current != nullptr && i < index - 1; i++) {
            current = current->next;
        }
        
        if (current == nullptr) return;
        
        newNode->next = current->next;
        current->next = newNode;
    }
    
    // Reverse the linked list
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
};

int main() {
    LinkedList list;
    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);
    
    cout << "List elements: " << endl;
    list.print();
    
    // Insert a value at a specific position
    list.insertAt(1, 15);
    cout << "List elements after insertion: " << endl;
    list.print();
    
    // Reverse the list;
    cout << "Reversing the list " << endl;
    list.reverse();
    list.print();
    
    
    // check if a value exists in the list
    cout << "Finding 10: " << (list.find(10) ? "Found" : "Not Found") << endl;
    cout << "Finding 1000: " << (list.find(1000) ? "Found" : "Not Found") << endl;
    
    return 0;
}