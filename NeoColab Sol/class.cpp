// SWITCH CASE IMPLEMENTATION
// #include <iostream>
// using namespace std;
// int main() {
//     int a, b;
//     cout << "The value of A: "<<endl;
//     cin >> a;
//     cout << "The value of B: " <<endl;
//     cin >> b;
//     char op;
//     cout <<" Enter the operators to perform" <<endl;
//     cin >> op;
//     switch (op) {
//         case '+': cout << (a+b) <<endl;
//             break
//         case '-': cout << (a-b) <<endl;
//             break;  
//         case '*': cout << (a*b) <<endl;
//             break;
//         case '/': cout << (a/b) <<endl;
//             break;
//         default: cout<<"Enter the correct operators";
//             break;
//     }
//     return 0;
// }

// ARRAY IMPLEMENTATION
// #include <iostream>
// using namespace std;
// void printArray(int arr[], int size) {

//     cout << "Printing the array " << endl;

//     for(int i = 0; i<size; i++) {
//         cout << arr[i] << " ";
//     }        
//     cout << "printing DONE" << endl;
// }

// int main() {
//     int number[15];
//     cout << "Value at 14 index " << number[14] << endl;
//     int third[15] = {2, 5};
//     int n = 15;
//     printArray(third, n);

//     return 0;
// }

// MINIMUM AND MAXIMUM IN ARRAY

// #include <iostream>
// #include <climits>
// using namespace std;

// int getMin(int num[], int n) {

//     int min = INT_MAX;
//     for(int i = 0; i<n; i++) {
//         if(num[i] < min){
//             min = num[i];
//         }
//     }

//     return min;
// }

// int getMax(int num[], int n) {

//     int max = INT_MIN;
//     for(int i = 0; i<n; i++) {
//         if(num[i] > max){
//             max = num[i];
//         }
//     }

//     return max;
// }

// int main() {

//     int size;
//     cin >> size;

//     int num[100];
//     for(int i = 0; i<size; i++) {
//         cin >> num[i];
//     }
//     cout << " Maximum value is " << getMax(num, size) << endl;
//     cout << " Minimum value is " << getMin(num, size) << endl;
//     return 0;
// }


// prime numbres

// #include <iostream>
// #include <cmath>

// bool is_prime(int num) {
//     if (num <= 1) {
//         return false; // 0 and 1 are not prime
//     }
//     if (num <= 3) {
//         return true; // 2 and 3 are prime
//     }
//     if (num % 2 == 0 || num % 3 == 0) {
//         return false; // Multiples of 2 and 3 are not prime
//     }

//     int i = 5;
//     while (i * i <= num) {
//         if (num % i == 0 || num % (i + 2) == 0) {
//             return false;
//         }
//         i += 6;
//     }

//     return true;
// }

// int main() {
//     int number;
//     std::cout << "Enter a number: ";
//     std::cin >> number;

//     if (is_prime(number)) {
//         std::cout << number << " is a prime number." << std::endl;
//     } else {
//         std::cout << number << " is not a prime number." << std::endl;
//     }

//     return 0;
// }


// FIbonannci series
// #include <iostream>

// int fibonacci(int n) {
//     if (n <= 0) {
//         return 0; // Handle base case of n <= 0
//     } else if (n == 1) {
//         return 1; // Handle base case of n == 1
//     } else {
//         return fibonacci(n - 1) + fibonacci(n - 2); // Recursive call
//     }
// }

// int main() {
//     int n;
//     std::cout << "Enter the number of terms in the Fibonacci series: ";
//     std::cin >> n;

//     std::cout << "Fibonacci series up to " << n << " terms:\n";
//     for (int i = 1; i <= n; i++) {
//         std::cout << fibonacci(i) << " ";
//     }
//     std::cout << std::endl;

//     return 0;
// }


// Class to represent the details of a student
#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int rollNo;
    string className;
    int marks;

    void getStudentDetails() {
        cout << "Enter student name: ";
        cin >> name;
        cout << "Enter roll number: ";
        cin >> rollNo;
        cout << "Enter class: ";
        cin >> className;
        cout << "Enter marks: ";
        cin >> marks;
    }

    void printStudentDetails() {
        cout << "Student Name: " << name << endl;
        cout << "Roll Number: " << rollNo << endl;
        cout << "Class: " << className << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main() {
    Student student;
    student.getStudentDetails();
    student.printStudentDetails();

    return 0;
}
