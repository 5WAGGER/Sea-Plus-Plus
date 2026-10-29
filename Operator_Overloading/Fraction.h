
/*
 * Quentin Jeriko
 * COMS 215
 * [Submission date]
 * Project 19.1
 * Fraction class with operator overloading and simplification
 */

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
using std::ostream;
using std::istream;

namespace cs_fraction {

class Fraction {
private:
    int top;
    int bottom;

    // =====================================================
    // PRIVATE SIMPLIFY FUNCTION
    // Called automatically by constructors
    // Arithmetic results are simplified through construction
    // Precondition: bottom != 0
    // Postcondition: fraction is reduced, bottom is positive,
    // and a zero fraction is stored as 0/1
    // =====================================================
    void simplify();

public:
    // =====================================================
    // CONSTRUCTOR WITH DEFAULT PARAMETERS
    // Supports zero, one, or two integer arguments
    // Precondition: denominatorParameter != 0
    // Postcondition: fraction stores the given value in
    // reduced form with a positive denominator
    // No arguments creates 0/1; one creates a whole number
    // =====================================================
    Fraction(int numeratorParameter = 0,
             int denominatorParameter = 1);

    // =====================================================
    // STREAM OPERATORS
    // =====================================================

    // Precondition: out is a usable output stream
    // Postcondition: writes the fraction as a whole number,
    // proper fraction, or mixed number, with a leading
    // minus sign if negative; returns out
    // The fraction is unchanged
    friend ostream& operator<<(
        ostream& out,
        const Fraction& inputFraction);

    // Precondition: input has valid formatting with no
    // internal spaces and no zero denominator
    // Postcondition: on successful input, inputFraction
    // stores the value in reduced form with a positive
    // denominator; characters after the value are not
    // consumed; returns in
    friend istream& operator>>(
        istream& in,
        Fraction& inputFraction);

    // =====================================================
    // ARITHMETIC OPERATORS
    // Fractions or integers may appear on either side
    // =====================================================

    // Precondition: none
    // Postcondition: returns the reduced sum
    // Neither operand is changed
    friend Fraction operator+(
        const Fraction& firstFraction,
        const Fraction& inputFraction);

    // Precondition: none
    // Postcondition: returns the reduced difference:
    // firstFraction minus inputFraction
    // Neither operand is changed
    friend Fraction operator-(
        const Fraction& firstFraction,
        const Fraction& inputFraction);

    // Precondition: none
    // Postcondition: returns the reduced product
    // Neither operand is changed
    friend Fraction operator*(
        const Fraction& firstFraction,
        const Fraction& inputFraction);

    // Precondition: inputFraction is not zero
    // Postcondition: returns the reduced quotient:
    // firstFraction divided by inputFraction
    // Neither operand is changed
    friend Fraction operator/(
        const Fraction& firstFraction,
        const Fraction& inputFraction);

    // =====================================================
    // RELATIONAL OPERATORS
    // Fractions or integers may appear on either side
    // =====================================================

    // Precondition: none
    // Postcondition: returns whether firstFraction is
    // less than inputFraction; neither operand is changed
    friend bool operator<(
        const Fraction& firstFraction,
        const Fraction& inputFraction);

    // Precondition: none
    // Postcondition: returns whether firstFraction is
    // less than or equal to inputFraction
    // Neither operand is changed
    friend bool operator<=(
        const Fraction& firstFraction,
        const Fraction& inputFraction);

    // Precondition: none
    // Postcondition: returns whether firstFraction is
    // greater than inputFraction; neither operand is changed
    friend bool operator>(
        const Fraction& firstFraction,
        const Fraction& inputFraction);

    // Precondition: none
    // Postcondition: returns whether firstFraction is
    // greater than or equal to inputFraction
    // Neither operand is changed
    friend bool operator>=(
        const Fraction& firstFraction,
        const Fraction& inputFraction);

    // Precondition: none
    // Postcondition: returns whether the fractions have
    // equal values; neither operand is changed
    friend bool operator==(
        const Fraction& firstFraction,
        const Fraction& inputFraction);

    // Precondition: none
    // Postcondition: returns whether the fractions have
    // different values; neither operand is changed
    friend bool operator!=(
        const Fraction& firstFraction,
        const Fraction& inputFraction);

    // =====================================================
    // COMPOUND ASSIGNMENT OPERATORS
    // Left operand is a Fraction
    // Right operand may be a Fraction or integer
    // =====================================================

    // Precondition: none
    // Postcondition: adds inputFraction to this fraction,
    // leaves it reduced, and returns *this by reference
    Fraction& operator+=(const Fraction& inputFraction);

    // Precondition: none
    // Postcondition: subtracts inputFraction from this
    // fraction, leaves it reduced, and returns *this
    // by reference
    Fraction& operator-=(const Fraction& inputFraction);

    // Precondition: none
    // Postcondition: multiplies this fraction by
    // inputFraction, leaves it reduced, and returns
    // *this by reference
    Fraction& operator*=(const Fraction& inputFraction);

    // Precondition: inputFraction is not zero
    // Postcondition: divides this fraction by
    // inputFraction, leaves it reduced, and returns
    // *this by reference
    Fraction& operator/=(const Fraction& inputFraction);

    // =====================================================
    // PREFIX INCREMENT AND DECREMENT
    // =====================================================

    // Precondition: none
    // Postcondition: adds one to this fraction, leaves
    // it reduced, and returns *this by reference
    Fraction& operator++();

    // Precondition: none
    // Postcondition: subtracts one from this fraction,
    // leaves it reduced, and returns *this by reference
    Fraction& operator--();

    // =====================================================
    // POSTFIX INCREMENT AND DECREMENT
    // =====================================================

    // Precondition: none
    // Postcondition: adds one to this fraction, leaves
    // it reduced, and returns its original value
    Fraction operator++(int);

    // Precondition: none
    // Postcondition: subtracts one from this fraction,
    // leaves it reduced, and returns its original value
    Fraction operator--(int);
};

} // namespace cs_fraction

#endif
