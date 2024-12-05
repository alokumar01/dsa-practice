// priority queue
#include <iostream>
using namespace std;

#define MAX 100

void enqueue(int queue[], int& rear, int size, int value) {
    if (rear == size - 1) {
        cout << "Queue overflow" << endl;
        return;
    }
    queue[++rear] = value;
}

int dequeue(int queue[], int& rear) {
    if (rear == -1) {
        cout << "Queue underflow" << endl;
        return -1;
    }
    
    int minIndex = 0;
    for (int i = 1; i<=rear; i++) {
        if (queue[i] < queue[minIndex]) {
            minIndex = i;
        }
    }

    int value = queue[minIndex];

    // shifts elements to fill the queue
    for (int i = minIndex; i < rear; i++) {
        queue[i] = queue[i + 1];
    }

    rear--;
    return value;
}

void displayQueue(int queue[], int rear) {
    if (rear == -1) {
        cout << "Queue is empty" << endl;
        return;
    }

    for (int i = 0; i<=rear; i++) {
        cout << queue[i] << " ";
    }
    cout << endl;
}

int main() {
    int queue[MAX], rear = -1, size, value;

    cout << "Enter the size of the queue: ";
    cin >> size;

    cout << "Enter elements to the queue: ";
    for (int i = 0; i < size; i++) {
        cin >> value;
        enqueue(queue, rear, size, value);
    }

    cout << "Original queue: ";
    displayQueue(queue, rear);


    dequeue(queue, rear);

    cout << "Queue after removing the minimum element: ";
    displayQueue(queue, rear);

    return 0;
}