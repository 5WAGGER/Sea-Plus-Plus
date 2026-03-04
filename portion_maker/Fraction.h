/*
 * Quentin Jeriko
 * COMS 215  
 * 2/25/2026
 * Project 15.1
 * Fraction class with constructors, const correctness, and simplification
 */

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
using std::ostream;

class Fraction {
private:
    int top;
    int bottom;
    
    // =====================================================
    // NEW PRIVATE FUNCTION REQUIRED BY ASSIGNMENT
    // Called automatically by constructors and arithmetic ops
    // Reduces fraction to lowest terms using custom algorithm
    // Precondition: bottom != 0
    // Postcondition: fraction is reduced (GCF removed)
    // =====================================================
    void simplify();
    
public:
    // =====================================================
    // NEW CONSTRUCTORS - REPLACED set() FUNCTION
    // Default constructor - creates 0/1 automatically
    // Postcondition: top=0, bottom=1  
    // =====================================================
    Fraction();
    
    // =====================================================
    // Parameterized constructor
    // Precondition: denominatorParameter != 0 (checked by assert)
    // Postcondition: fraction = given values (already reduced)
    // =====================================================
    Fraction(int numeratorParameter, int denominatorParameter);
    
    // =====================================================
    // YOUR EXISTING FUNCTIONS - NOW WITH CONST CORRECTNESS
    // All methods marked const, parameters passed by const reference
    // =====================================================
    void print() const;
    Fraction multipliedBy(const Fraction& inputFraction) const;
    Fraction dividedBy(const Fraction& inputFraction) const;
    Fraction addedTo(const Fraction& inputFraction) const;
    Fraction subtract(const Fraction& inputFraction) const;
    bool isEqualTo(const Fraction& inputFraction) const;
};

#endif
