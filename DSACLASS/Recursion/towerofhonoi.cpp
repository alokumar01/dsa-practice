// #include <iostream>
using namespace std;
#include <bits/stdc++.h>

void towerOfHanoi(int n, char source, char target, char auxilliary) {
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << target << endl;
        return;
    }
    towerOfHanoi(n-1, source, auxilliary, target);
    cout << "Move disk " << n << " from  " << source << " to  " << target << endl;

    towerOfHanoi(n - 1, auxilliary, target, source);
};


int main() {
    int N = 3;
    towerOfHanoi(N, 'A', 'B', 'C');
    return 0;
}