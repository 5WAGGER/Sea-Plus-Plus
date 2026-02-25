#include <iostream>
using namespace std;

// Class declaration
class Fraction {
private:
    int numerator;
    int denominator;

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
    numerator = n;
    denominator = d;
}

Fraction Fraction::addedTo(Fraction f) {
    Fraction outputFraction;
    outputFraction.numerator = numerator * f.denominator + f.numerator * denominator;
    outputFraction.denominator = denominator * f.denominator;
    return outputFraction;
}

Fraction Fraction::subtract(Fraction f) {
    Fraction outputFraction;
    outputFraction.numerator = numerator * f.denominator - f.numerator * denominator;
    outputFraction.denominator = denominator * f.denominator;
    return outputFraction;
}

Fraction Fraction::multipliedBy(Fraction f) {
    Fraction outputFraction;
    outputFraction.numerator = numerator * f.numerator;
    outputFraction.denominator = denominator * f.denominator;
    return outputFraction;
}

Fraction Fraction::dividedBy(Fraction f) {
    Fraction outputFraction;
    outputFraction.numerator = numerator * f.denominator;
    outputFraction.denominator = denominator * f.numerator;
    return outputFraction;
}

bool Fraction::isEqualTo(Fraction f) {
    return (numerator * f.denominator == denominator * f.numerator);
}

void Fraction::print() {
    cout << numerator << "/" << denominator;
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
