#include <iostream>
using namespace std;
#define MAX 100

void push(int stack[], int& top, int value) {
    if (top >= MAX-1) {
        cout << "Stack Overflow" << endl;
        return;
    }
    stack[++top] = value;
    // cout << "Element pushed to stack: " << value << endl;
}

int pop(int stack[], int& top) {
    if (top == -1) {
        cout << "stack underflow" << endl;
        return -1;
    }
    return stack[top--];
}


void traverse(int stack[], int& top) {
    if (top == -1) {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "stack elements: ";
    for (int i = 0; i<top; i++){
        cout << stack[i] << " ";
    }
    cout << endl;
}

void removeEvenElements(int stack[], int& top) {
    int tempStack[MAX];
    int tempTop = -1;

    while(top != -1 ) {
        int value = pop(stack, top); 
        if (value % 2 != 0) {
            push(tempStack, tempTop, value);
        }
    }

    while(tempTop != -1) {
        push(stack, top, pop(tempStack, tempTop));
    }

}

int main() {
    int stack[MAX], top = -1;

    int n;
    cout << "enter the number of elements: ";
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        push(stack, top, value);
    }

    cout << "original stack:\n";
    traverse(stack, top);

    removeEvenElements(stack, top);

    cout << "\n stack after removing elements:\n";
    traverse(stack, top);
    
    return 0;
}