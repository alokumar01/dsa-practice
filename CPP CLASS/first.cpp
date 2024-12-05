// #include <iostream>
// using namespace std;

// Class A {
// public:
//     void func() {
//         cout << "I am in class A \n";
//     }    
// };
// Class B {
// public:
//     void func() {
//         cout << "I am in class B\n";
//     }
// };
// Class C {
    
// };

// class B: public virtual A {
// };
// class C: public virtual A {
// };
// class D: public B, public C {
// };

// int main() {
//     D object;
//     cout << "a= " << object.a;
//     return 0;
// }


// #include <iostream>
// using namespace std;

// class B {
// protected:
//     int x;
// public:
//     void get_dataB() {
//         cout << "\nEnter value of X: ";
//         cin >> x;
//     }
// };

// class DB1:public virtual B {
// protected:
//     int y;
// public:
//     void get_dataDB1() {
//         cout << "\n Enter the value of Y: ";
//         cin >> y;
//     }
// };


// class DB2: public virtual B {
// protected:
//     int z;
// public:
//     void get_dataDB2() {
//         cout << "\n Enter value of Z: ";
//         cin >> z;
//     }
// };

// class D:public DB1, public DB2 {
// public:
//     void sum(){
//         int result;
//         result = x+y+z;
//         cout << "\n Result is : " << result;
//     }
// };


// int main() {
//     D obj1;
//     obj1.get_dataB();  
//     obj1.get_dataDB1();  
//     obj1.get_dataDB2();
//     obj1.sum();  
//     return 0;
// }


                                    // funtion overiding

// #include <iostream>
// using namespace std;

// class A {
// public:
//     void show() {
//         cout << "\n Base class A ";
//     }
// };

// class B:public A {
// public:
//     void show() {
//         cout << "\n Derived Class B: ";
//     }
// };

// int main() {
//     B obj1;
//     obj1.show();
//     obj1.A::show();    
//     return 0;
// }


// Program for Hybrid inheritence

// #include <iostream>
// using namespace std;

// class Animal {
// public:
//     void eat() {
//         cout << "eating... " << endl;
//     }
// };

// class Bird: public Animal {
// public:
//     void fly() {
//         cout << "flying... " << endl;
//     }
// };

// class Sparrow: public Bird, public Animal {
// public:
//     void fff() {
//         cout << "all is well..." << endl;
//     }
// };

// int main() {
    
//     return 0;
// }



// #include <iostream>
// using namespace std;

// class A {
// protected:
//     int a;
// public:
//     A(int x) {
//         a = x;
//     }

//     void display() {
//         cout << " A " << a;
//     }
// };

// class B {
// protected:
//     int b;
// public:
//     A(int y) {
//         b = y;
//     }

//     void private(){
//         cout << " B " << b;
//     }
// }

// class C: public A, public B {
//     int c;
// public:
//     A(int p, int q, int r) : A(p), B(q) {
//         c = r;
//     }
// };




// int main() {
//     A obj;
//     cout << obj.display() << endl;

//     cout << endl;

//     B obj1;
//     obj1.private();

//     return 0;
// }

// question

#include <iostream>
using namespace std;

class A {
public:
    A() {
        cout << "\n Calling default base class constructor";
    }
    ~A() {
        cout << "\n Calling base class destructor ";
    }
};

class B: public A {
public:
    B() {
        cout << "\n Calling default derived constructor ";
    }
    ~B() {
        cout << "\n Calling derived class destructor ";

    }
};

int main() {
    B obj1;  
    return 0;
}


