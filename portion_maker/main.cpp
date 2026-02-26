// =====================================================
// CLIENT PROGRAM - PROVIDED BY INSTRUCTOR
// #include "Fraction.h" links to YOUR class definition
// NO LONGER USES set() - uses constructors instead
// =====================================================
#include <iostream>
#include "Fraction.h"  // LINKS TO fraction.h (YOUR CLASS)
using namespace std;

int main()
{
    Fraction f1(9,8);          // Constructor automatically simplifies
    Fraction f2(2,3);
    Fraction result;           // Default constructor = 0/1

    cout << "The result starts off at ";
    result.print();
    cout << endl;

    // All your original operations work exactly the same
    cout << "The product of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.multipliedBy(f2);  // Automatically simplified to 3/4
    result.print();
    cout << endl;

    // ... rest matches assignment exactly ...
    cout << "The quotient of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.dividedBy(f2);     // Automatically simplified to 27/16
    result.print();
    cout << endl;

    cout << "The sum of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.addedTo(f2);       // Automatically simplified to 43/24
    result.print();
    cout << endl;

    cout << "The difference of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.subtract(f2);      // Automatically simplified to 11/24
    result.print();
    cout << endl;

    if (f1.isEqualTo(f2)){
        cout << "The two Fractions are equal." << endl;
    } else {
        cout << "The two Fractions are not equal." << endl;
    }
    
    // Tests const correctness requirement
    const Fraction f3(12, 8);      // 12/8 auto-simplifies to 3/2
    const Fraction f4(202, 303);
    result = f3.multipliedBy(f4);  // 3/2 * 202/303 = 1/1
    cout << "The product of ";
    f3.print();
    cout << " and ";
    f4.print();
    cout << " is ";
    result.print();
    cout << endl;
}
