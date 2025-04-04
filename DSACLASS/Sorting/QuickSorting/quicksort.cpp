// You are using GCC

// Quick sorting for integer

#include <iostream>
#include <string>
using namespace std;

int partition(int arr[], int low, int high) {
    //Type your code here
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j<high; j++) {
        if ( arr[j] <= pivot ) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
};

void quickSort(int arr[], int low, int high) {
    //Type your code here
    if (low<high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
};

int main() {
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}