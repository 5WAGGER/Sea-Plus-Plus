#include <iostream>
using namespace std;

// Class declaration
class Fraction {
private:
    int top;    // the top number (numerator)
    int bottom; // the bottom number (denominator)

public:
    void set(int n, int d);
    Fraction addedTo(Fraction f);
    Fraction subtract(Fraction f);
    Fraction multipliedBy(Fraction f);
    Fraction dividedBy(Fraction f);
    bool isEqualTo(Fraction f);
    void print();
};  // <-- End of class Fraction


// Implementation of member functions

void Fraction::set(int n, int d) {
    top = n;
    bottom = d;
}

Fraction Fraction::addedTo(Fraction f) {
    Fraction outputFraction;
    outputFraction.top = top * f.bottom + f.top * bottom;
    outputFraction.bottom = bottom * f.bottom;
    return outputFraction;
}

Fraction Fraction::subtract(Fraction f) {
    Fraction outputFraction;
    outputFraction.top = top * f.bottom - f.top * bottom;
    outputFraction.bottom = bottom * f.bottom;
    return outputFraction;
}

Fraction Fraction::multipliedBy(Fraction f) {
    Fraction outputFraction;
    outputFraction.top = top * f.top;
    outputFraction.bottom = bottom * f.bottom;
    return outputFraction;
}

Fraction Fraction::dividedBy(Fraction f) {
    Fraction outputFraction;
    outputFraction.top = top * f.bottom;
    outputFraction.bottom = bottom * f.top;
    return outputFraction;
}

bool Fraction::isEqualTo(Fraction f) {
    return (top * f.bottom == bottom * f.top);
}

void Fraction::print() {
    cout << top << "/" << bottom;
}


// Client program (must not be modified)
int main()
{
    Fraction f1;
    Fraction f2;
    Fraction result;

    f1.set(9, 8);
    f2.set(2, 3);

    cout << "The product of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.multipliedBy(f2);
    result.print();
    cout << endl;

    cout << "The quotient of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.dividedBy(f2);
    result.print();
    cout << endl;

    cout << "The sum of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.addedTo(f2);
    result.print();
    cout << endl;

    cout << "The difference of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.subtract(f2);
    result.print();
    cout << endl;

    if (f1.isEqualTo(f2)){
        cout << "The two Fractions are equal." << endl;
    } else {
        cout << "The two Fractions are not equal." << endl;
    }
}
