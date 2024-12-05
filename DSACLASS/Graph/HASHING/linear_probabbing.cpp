// You are using GCC
#include <iostream>
using namespace std;

void readKeys(int keys[], int numKeys) {
    for (int i = 0; i<numKeys; i++) {
        cin >> keys[i];
    }
};

void initializeHashTable(int hashTable[], int tablesize) {
    for (int i = 0; i<tablesize; i++) {
        hashTable[i] = -1;
    }
};

void insertKey(int hashTable[], int tablesize, int key) {
    int hashIndex = key % tablesize;
    int j = 0;
    while(hashTable[hashIndex] != -1) {
        j++;
        hashIndex = (hashIndex+ j*j) % tablesize;
    }
    hashTable[hashIndex] = key;
};

void printHashTable(int hashTable[], int tablesize) {
    for (int i = 0; i<tablesize; i++) {
        if (hashTable[i] != -1) {
            cout << hashTable[i] << " ";
        }
    }
}


int main() {
    const int tablesize = 10;
    int numKeys; 
    cin >> numKeys;
    
    int keys[numKeys];
    readKeys(keys, numKeys);
    
    int hashTable[tablesize];
    initializeHashTable(hashTable, tablesize);
    
    for (int i = 0; i<numKeys; i++) {
        insertKey(hashTable, tablesize, keys[i]);
    }
    
    printHashTable(hashTable, tablesize);
    
    
    return 0;
}