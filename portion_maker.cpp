#include <iostream>
using namespace std;

// Class declaration
class Fraction {
private:
    int top;    // the top number (numerator)
    int bottom; // the bottom number (denominator)

public:
    void set(int numerator, int denominator);
    Fraction addedTo(Fraction inputFraction);
    Fraction subtract(Fraction inputFraction);
    Fraction multipliedBy(Fraction inputFraction);
    Fraction dividedBy(Fraction inputFraction);
    bool isEqualTo(Fraction inputFraction);
    void print();
};  // <-- End of class Fraction


// Implementation of member functions

void Fraction::set(int numerator, int denominator) {
    top = numerator;
    bottom = denominator;
}

Fraction Fraction::addedTo(Fraction inputFraction) {
    Fraction outputFraction;
    outputFraction.top = top * inputFraction.bottom + inputFraction.top * bottom;
    outputFraction.bottom = bottom * inputFraction.bottom;
    return outputFraction;
}

Fraction Fraction::subtract(Fraction inputFraction) {
    Fraction outputFraction;
    outputFraction.top = top * inputFraction.bottom - inputFraction.top * bottom;
    outputFraction.bottom = bottom * inputFraction.bottom;
    return outputFraction;
}

Fraction Fraction::multipliedBy(Fraction inputFraction) {
    Fraction outputFraction;
    outputFraction.top = top * inputFraction.top;
    outputFraction.bottom = bottom * inputFraction.bottom;
    return outputFraction;
}

Fraction Fraction::dividedBy(Fraction inputFraction) {
    Fraction outputFraction;
    outputFraction.top = top * inputFraction.bottom;
    outputFraction.bottom = bottom * inputFraction.top;
    return outputFraction;
}

bool Fraction::isEqualTo(Fraction inputFraction) {
    return (top * inputFraction.bottom == bottom * inputFraction.top);
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
