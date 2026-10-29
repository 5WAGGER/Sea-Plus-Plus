
// =====================================================
// IMPLEMENTATION FILE - FRACTION CLASS
// #include "Fraction.h" links to specification file
// =====================================================
#include "Fraction.h"
#include <cassert>
#include <iostream>

namespace cs_fraction {

// =====================================================
// CONSTRUCTOR
// Default arguments belong in Fraction.h:
// Fraction(int numeratorParameter = 0,
//          int denominatorParameter = 1);
// Handles zero, one, or two integer arguments
// =====================================================
Fraction::Fraction(int numeratorParameter,
                   int denominatorParameter)
    : top(numeratorParameter), bottom(denominatorParameter) {
    assert(denominatorParameter != 0);
    simplify();
}

// =====================================================
// CUSTOM SIMPLIFY ALGORITHM
// Keeps denominator positive and stores zero as 0/1
// Uses your original approach: check factors from 2 up
// =====================================================
void Fraction::simplify() {
    if (bottom < 0) {
        top = -top;
        bottom = -bottom;
    }

    if (top == 0) {
        bottom = 1;
        return;
    }

    long long positiveTop = top;
    if (positiveTop < 0) {
        positiveTop = -positiveTop;
    }

    int factor = 2;
    while (factor <= positiveTop && factor <= bottom) {
        while (top % factor == 0 && bottom % factor == 0) {
            top /= factor;
            bottom /= factor;
            positiveTop /= factor;
        }
        factor++;
    }
}

// =====================================================
// INSERTION OPERATOR
// Prints whole numbers, proper fractions, mixed numbers,
// and negative fractions without changing the object
// =====================================================
std::ostream& operator<<(std::ostream& out,
                         const Fraction& inputFraction) {
    long long positiveTop = inputFraction.top;

    if (positiveTop < 0) {
        out << "-";
        positiveTop = -positiveTop;
    }

    long long whole = positiveTop / inputFraction.bottom;
    int remainder = positiveTop % inputFraction.bottom;

    if (remainder == 0) {
        out << whole;
    }
    else {
        if (whole != 0) {
            out << whole << "+";
        }
        out << remainder << "/" << inputFraction.bottom;
    }

    return out;
}

// =====================================================
// EXTRACTION OPERATOR
// Reads whole numbers, proper fractions, mixed numbers,
// and negative fractions
// Does not consume characters after the fraction
// =====================================================
std::istream& operator>>(std::istream& in,
                         Fraction& inputFraction) {
    int first;
    if (!(in >> first)) {
        return in;
    }

    int numeratorParameter = first;
    int denominatorParameter = 1;

    if (in.peek() == '+') {
        in.ignore();
        int fractionalTop;

        if (!(in >> fractionalTop)) {
            return in;
        }

        in.ignore();  // Skip the '/' separator.
        if (!(in >> denominatorParameter)) {
            return in;
        }

        numeratorParameter = first * denominatorParameter;
        if (first < 0) {
            numeratorParameter -= fractionalTop;
        }
        else {
            numeratorParameter += fractionalTop;
        }
    }
    else if (in.peek() == '/') {
        in.ignore();
        if (!(in >> denominatorParameter)) {
            return in;
        }
    }

    inputFraction = Fraction(numeratorParameter,
                             denominatorParameter);
    return in;
}

// =====================================================
// ARITHMETIC OPERATORS
// Nonmember functions allow integers on either side
// Constructors automatically simplify the results
// =====================================================
Fraction operator+(const Fraction& firstFraction,
                   const Fraction& inputFraction) {
    Fraction outputFraction(
        firstFraction.top * inputFraction.bottom +
        inputFraction.top * firstFraction.bottom,
        firstFraction.bottom * inputFraction.bottom);
    return outputFraction;
}

Fraction operator-(const Fraction& firstFraction,
                   const Fraction& inputFraction) {
    Fraction outputFraction(
        firstFraction.top * inputFraction.bottom -
        inputFraction.top * firstFraction.bottom,
        firstFraction.bottom * inputFraction.bottom);
    return outputFraction;
}

Fraction operator*(const Fraction& firstFraction,
                   const Fraction& inputFraction) {
    Fraction outputFraction(
        firstFraction.top * inputFraction.top,
        firstFraction.bottom * inputFraction.bottom);
    return outputFraction;
}

Fraction operator/(const Fraction& firstFraction,
                   const Fraction& inputFraction) {
    Fraction outputFraction(
        firstFraction.top * inputFraction.bottom,
        firstFraction.bottom * inputFraction.top);
    return outputFraction;
}

// =====================================================
// RELATIONAL OPERATORS
// Compare using cross multiplication, not division
// =====================================================
bool operator<(const Fraction& firstFraction,
               const Fraction& inputFraction) {
    return firstFraction.top * inputFraction.bottom <
           inputFraction.top * firstFraction.bottom;
}

bool operator<=(const Fraction& firstFraction,
                const Fraction& inputFraction) {
    return !(inputFraction < firstFraction);
}

bool operator>(const Fraction& firstFraction,
               const Fraction& inputFraction) {
    return inputFraction < firstFraction;
}

bool operator>=(const Fraction& firstFraction,
                const Fraction& inputFraction) {
    return !(firstFraction < inputFraction);
}

bool operator==(const Fraction& firstFraction,
                const Fraction& inputFraction) {
    return firstFraction.top * inputFraction.bottom ==
           firstFraction.bottom * inputFraction.top;
}

bool operator!=(const Fraction& firstFraction,
                const Fraction& inputFraction) {
    return !(firstFraction == inputFraction);
}

// =====================================================
// COMPOUND ASSIGNMENT OPERATORS
// Update the calling object and return it by reference
// Arithmetic operators produce simplified fractions
// =====================================================
Fraction& Fraction::operator+=(const Fraction& inputFraction) {
    *this = *this + inputFraction;
    return *this;
}

Fraction& Fraction::operator-=(const Fraction& inputFraction) {
    *this = *this - inputFraction;
    return *this;
}

Fraction& Fraction::operator*=(const Fraction& inputFraction) {
    *this = *this * inputFraction;
    return *this;
}

Fraction& Fraction::operator/=(const Fraction& inputFraction) {
    *this = *this / inputFraction;
    return *this;
}

// =====================================================
// PREFIX INCREMENT AND DECREMENT
// Change the calling object and return the updated object
// =====================================================
Fraction& Fraction::operator++() {
    return *this += 1;
}

Fraction& Fraction::operator--() {
    return *this -= 1;
}

// =====================================================
// POSTFIX INCREMENT AND DECREMENT
// Save the original value, update the calling object,
// and return the original value
// =====================================================
Fraction Fraction::operator++(int) {
    Fraction outputFraction = *this;
    ++(*this);
    return outputFraction;
}

Fraction Fraction::operator--(int) {
    Fraction outputFraction = *this;
    --(*this);
    return outputFraction;
}

} // namespace cs_fraction
