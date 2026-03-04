// =====================================================
// IMPLEMENTATION FILE - ALL YOUR FUNCTIONS LIVE HERE NOW
// #include "Fraction.h" links to specification file above
// =====================================================
#include "Fraction.h"
#include <cassert>

// =====================================================
// DEFAULT CONSTRUCTOR (NEW)
// Automatically creates Fraction = 0/1
// Called when you write: Fraction result;  
// =====================================================
Fraction::Fraction() : top(0), bottom(1) {
}

// =====================================================
// PARAMETERIZED CONSTRUCTOR (NEW)
// Automatically creates Fraction with given values
// Called when you write: Fraction f1(9,8);
// assert() crashes program if denominator = 0
// simplify() called automatically to reduce fraction
// =====================================================
Fraction::Fraction(int numeratorParameter, int denominatorParameter) 
    : top(numeratorParameter), bottom(denominatorParameter) {
    assert(denominatorParameter != 0);
    simplify();
}

// =====================================================
// CUSTOM SIMPLIFY ALGORITHM (NEW REQUIREMENT)
// Finds all common factors from 2 up, divides them out
// Called automatically after constructors and arithmetic
// Example: 12/8 becomes 3/2, 18/6 becomes 3/1
// =====================================================
void Fraction::simplify() {
    int factor = 2;
    while (factor <= top && factor <= bottom) {
        while (top % factor == 0 && bottom % factor == 0) {
            top /= factor;
            bottom /= factor;
        }
        factor++;
    }
}

// =====================================================
// YOUR ORIGINAL FUNCTIONS - MINOR CHANGES ONLY
// 1) Now const methods  
// 2) Parameters passed by const reference (&)
// 3) Arithmetic ops now call simplify() automatically
// =====================================================
void Fraction::print() const {
    std::cout << top << "/" << bottom;
}

Fraction Fraction::multipliedBy(const Fraction& inputFraction) const {
    // Creates new fraction, simplify() called automatically by constructor
    Fraction outputFraction(top * inputFraction.top, 
                           bottom * inputFraction.bottom);
    return outputFraction;
}

Fraction Fraction::dividedBy(const Fraction& inputFraction) const {
    Fraction outputFraction(top * inputFraction.bottom, 
                           bottom * inputFraction.top);
    return outputFraction;
}

Fraction Fraction::addedTo(const Fraction& inputFraction) const {
    Fraction outputFraction(top * inputFraction.bottom + 
                           inputFraction.top * bottom,
                           bottom * inputFraction.bottom);
    return outputFraction;
}

Fraction Fraction::subtract(const Fraction& inputFraction) const {
    Fraction outputFraction(top * inputFraction.bottom - 
                           inputFraction.top * bottom,
                           bottom * inputFraction.bottom);
    return outputFraction;
}

bool Fraction::isEqualTo(const Fraction& inputFraction) const {
    // Cross-multiplication comparison (works with unreduced fractions)
    return (top * inputFraction.bottom == bottom * inputFraction.top);
}
