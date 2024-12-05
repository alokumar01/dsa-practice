// Odd position to descending
// Even position to ascending

// You are using GCC
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    vector<int> oddPos;
    vector<int> evenPos;
    
    for(int i = 0; i<n; i++) {
        if ((i+1) % 2 == 1) {
            oddPos.push_back(arr[i]);
        } else {
            evenPos.push_back(arr[i]);
        }
    }
    
    sort(oddPos.begin(), oddPos.end(), greater<int>());
    sort(evenPos.begin(), evenPos.end());
    
    int oddInd = 0, evenInd = 0;
    for(int i = 0; i<n; i++) {
        if ((i + 1) % 2 == 1) {
            arr[i] = oddPos[oddInd++];
        } else {
            arr[i] = evenPos[evenInd++];
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for(int i = 0; i<n; i++ ) {
        cin >> arr[i];
    }
    
    insertionSort(arr);

    for(int i = 0; i<n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
    
};

// bubble sort based on sum of digits 

#include <iostream>
using namespace std;
#include <vector>

int sumDigits(int num) {
    int sum = 0;
    while(num != 0) {
        int digit = num % 10;
        sum += digit;
        num /= 10;
    }
    return sum;
};

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    vector<int> sortDigit(n);
    
    for(int i = 0; i<n; i++) {
        sortDigit[i] = sumDigits(arr[i]);
    }
    
    for(int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (sortDigit[j] > sortDigit[j+1]) {
                swap(sortDigit[j], sortDigit[j+1]);
                swap(arr[j], arr[j+1]);
            }
        }
    }
    
    for(int i = 0; i<n; i++) {
        cout <<  arr[i] << " ";
    }
    cout << endl;
    
}

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for(int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    
    bubbleSort(arr);
    
    return 0;
    
}

