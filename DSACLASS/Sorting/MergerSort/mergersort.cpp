#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    // temp values for left and right halves
    vector<int> L(arr.begin()+left, arr.begin()+mid+1);
    vector<int> R(arr.begin()+mid+1, arr.begin()+right+1);

    int i = 0, j = 0, k = left;

    while(i < L.size() && j < R.size() ) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // copy any reamining elements from L
    while (i < L.size() ) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // copy any reamining elements from J
    while (j < R.size()) {
        arr[k] = R[j];
        j++;
        k++;
    }
};

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right); //merge the sorted halves
    }
};

void printArr(vector<int> arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
};

int main() {
    vector<int> arr = {12,11,13,5,6,7};

    cout << "Given array is: ";
    printArr(arr);

    mergeSort(arr, 0, arr.size() - 1); // sort the array

    cout << "sorted array is: ";
    printArr(arr);
    return 0;
}


// WITHOUT VECTOR 

// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int h) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = h - m;
    int L[n1], R[n2];
    
    for(i = 0; i<n1; i++) {
        L[i] = arr[l + i];
    }
    for(j = 0; j<n2; j++) {
        R[j] = arr[m+1+j];
    }
    
    i = 0, j = 0, k = l;
    
    while(i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
};


void mergeSort(int arr[], int l, int h) {
    if (l<h) {
        int m = l + (h-l) / 2;
        
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, h);
        
        merge(arr, l, m, h);    
    }
};

int main() {
    int n = 5;
    int arr[n];
    for(int i = 0; i<n; i++) {
        cin >> arr[i]; 
    }
    
    mergeSort(arr, 0, n-1);
    
    for(int i = 0; i<n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}