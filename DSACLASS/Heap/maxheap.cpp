#include <iostream>
using namespace std;

// Function to swap two elements
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to maintain the max-heap property
void maxHeapify(int heap[], int size, int i) {
    int left = 2 * i + 1;  // Left child index
    int right = 2 * i + 2; // Right child index
    int largest = i;       // Assume current node is the largest

    // Check if left child exists and is greater than root
    if (left < size && heap[left] > heap[largest]) {
        largest = left;
    }

    // Check if right child exists and is greater than current largest
    if (right < size && heap[right] > heap[largest]) {
        largest = right;
    }

    // If the largest is not the current node, swap and continue heapifying
    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        maxHeapify(heap, size, largest);
    }
}

// Function to insert a new element into the max heap
void insertElement(int heap[], int *size, int value) {
    // Increase the size of the heap and add the new value at the end
    (*size)++;
    heap[*size - 1] = value;

    // Heapify up: Move the new element to its correct position
    int i = *size - 1;
    while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
        // Swap with the parent if the current node is larger
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to display the heap
void displayMaxHeap(int heap[], int size) {
    for (int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main() {
    int heap[100];  // Array to hold the heap
    int size = 0;   // Current size of the heap
    int n, value;

    // Take input for number of elements
    cout << "Enter the number of elements to insert into the heap: ";
    cin >> n;

    // Take input for each element and insert into the max heap
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        insertElement(heap, &size, value);
    }

    // Display the heap after all insertions
    cout << "Max Heap: ";
    displayMaxHeap(heap, size);

    return 0;
}
