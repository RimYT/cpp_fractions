#ifndef FRACTIONS_FRACTIONS_H
#define FRACTIONS_FRACTIONS_H

#include <stdexcept>
#include <any>

class Fraction {
private:
    long numerator;
    long denominator;

public:
    Fraction(long num, long den) : numerator(num), denominator(den) {
        if (den == 0) {
            throw std::runtime_error("You can't divide by zero!");
        }
    }

    long getNumerator();
    long getDenominator();

    void power(float exponent);
    void simplify(); // Fraction.simplify()                                                     ||||| Simplifies the fraction
    float ToNum();

    void print() const; // Fraction.print()                                                     ||||| Prints the fraction
};

// algebraic operations
Fraction sumFractions(Fraction f1, Fraction f2); // sumFractions(Fraction, Fraction)            ||||| sums fractions
Fraction subtractFractions(Fraction f1, Fraction f2); // subtractFractions(Fraction, Fraction)  ||||| subtracts fractions
Fraction multiplyFractions(Fraction f1, Fraction f2); // multiplyFractions(Fraction, Fraction)  ||||| multiplies fractions
Fraction divideFractions(Fraction f1, Fraction f2); // divideFractions(Fraction, Fraction)      ||||| divides fractions

#endif //FRACTIONS_FRACTIONS_H
