/*
 * Quentin Jeriko
 * COMS 215
 * Project 19.1
 * Fraction class specification.
 *
 * Fractions are stored in reduced form with a positive
 * denominator. A zero fraction is stored as 0/1.
 */

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

namespace cs_fraction {

class Fraction {
private:
    int top;
    int bottom;

    // Precondition: bottom != 0.
    // Postcondition: The calling fraction is reduced, its
    // denominator is positive, and zero is stored as 0/1.
    void simplify();

public:
    // Precondition: denominatorParameter != 0.
    // Postcondition: Constructs a reduced fraction from the
    // arguments. One argument represents a whole number;
    // no arguments create zero.
    Fraction(int numeratorParameter = 0,
             int denominatorParameter = 1);

    // Precondition: out is an output stream ready for writing.
    // Postcondition: Writes the fraction as a whole number,
    // proper fraction, or mixed number, with a leading minus
    // sign when negative. Returns out; the fraction is unchanged.
    friend std::ostream& operator<<(
        std::ostream& out,
        const Fraction& inputFraction);

    // Precondition: in contains a correctly formatted whole
    // number, fraction, or mixed number without internal spaces.
    // Any denominator is positive and nonzero.
    // Postcondition: On successful extraction, inputFraction
    // stores the value in reduced form. Characters following
    // the fraction remain unread. Returns in.
    friend std::istream& operator>>(
        std::istream& in,
        Fraction& inputFraction);

    // Postcondition: Returns the reduced sum of the operands.
    // Neither operand is changed.
    friend Fraction operator+(
        const Fraction& firstFraction,
        const Fraction& inputFraction);

    // Postcondition: Returns the reduced difference of the
    // first operand minus the second. Neither operand changes.
    friend Fraction operator-(
        const Fraction& firstFraction,
        const Fraction& inputFraction);

    // Postcondition: Returns the reduced product of the operands.
    // Neither operand is changed.
    friend Fraction operator*(
        const Fraction& firstFraction,
        const Fraction& inputFraction);

    // Precondition: inputFraction is not zero.
    // Postcondition: Returns the reduced quotient of the first
    // operand divided by the second. Neither operand changes.
    friend Fraction operator/(
        const Fraction& firstFraction,
        const Fraction& inputFraction);

    // Postcondition: Returns whether the first operand is less
    // than the second.
