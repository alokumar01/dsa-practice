#include <iostream>
using namespace std;

// Function to swap two elements
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to maintain the min-heap property
void minHeapify(int heap[], int size, int i) {
    int left = 2 * i + 1;  // Left child index
    int right = 2 * i + 2; // Right child index
    int smallest = i;      // Assume current node is the smallest

    // Check if left child exists and is smaller than the root
    if (left < size && heap[left] < heap[smallest]) {
        smallest = left;
    }

    // Check if right child exists and is smaller than the current smallest
    if (right < size && heap[right] < heap[smallest]) {
        smallest = right;
    }

    // If the smallest is not the current node, swap and continue heapifying
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, size, smallest);
    }
}

// Function to build the min heap from an unordered array
void buildMinHeap(int heap[], int size) {
    // Start from the last non-leaf node and heapify each node
    for (int i = size / 2 - 1; i >= 0; i--) {
        minHeapify(heap, size, i);
    }
}

// Function to insert a new element into the min heap
void insertElement(int heap[], int *size, int value) {
    // Increase the size of the heap and add the new value at the end
    (*size)++;
    heap[*size - 1] = value;

    // Heapify up: Move the new element to its correct position
    int i = *size - 1;
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        // Swap with the parent if the current node is smaller
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to display the heap
void displayMinHeap(int heap[], int size) {
    for (int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

// Driver code
int main() {
    int heap[100];  // Array to hold the heap
    int size = 0;   // Current size of the heap

    // Insert elements into the heap
    insertElement(heap, &size, 10);
    insertElement(heap, &size, 20);
    insertElement(heap, &size, 5);
    insertElement(heap, &size, 15);
    insertElement(heap, &size, 30);

    cout << "Heap after insertion: ";
    displayMinHeap(heap, size);  // Display the heap after insertion

    // Build a min heap from an unsorted array
    int unsortedArray[] = {15, 20, 10, 30, 5};
    int unsortedSize = 5;
    buildMinHeap(unsortedArray, unsortedSize);

    cout << "Min Heap after buildMinHeap: ";
    displayMinHeap(unsortedArray, unsortedSize);  // Display the built min-heap

    return 0;
}
