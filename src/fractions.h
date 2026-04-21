#ifndef FRACTIONS_FRACTIONS_H
#define FRACTIONS_FRACTIONS_H

#include <stdexcept>

// im using "namespace" because i think it would be better
namespace frc {
    inline bool AUTO_SIMPLIFY = false;

    class Fraction {
    private:
        long numerator;
        long denominator;

    public:
        Fraction(long num, long den = 1) : numerator(den < 0 ? -num : num), denominator(den < 0 ? -den : den) {
            if (den == 0) {
                throw std::runtime_error("You can't divide by zero!");
            }
        }

        long getNumerator() const;
        long getDenominator() const;

        void power(long exponent); // Fraction.power(long)                                          ||||| Powers the fraction
        long getWhole();

        void inverse(); //Fraction.inverse()                                                        ||||| Inverses the fraction
        void simplify(); // Fraction.simplify()                                                     ||||| Simplifies the fraction
        float ToNum(); // Fraction.ToNum()                                                          ||||| Converts fraction to float

        void print() const; // Fraction.print()                                                     ||||| Prints the fraction
    };

    // arithmetic operations (with Fractions)
    Fraction sum(Fraction& f1, Fraction& f2); // sumFractions(Fraction, Fraction)            ||||| sums fractions
    Fraction subtract(Fraction& f1, Fraction& f2); // subtractFractions(Fraction, Fraction)  ||||| subtracts fractions
    Fraction multiply(Fraction& f1, Fraction& f2); // multiplyFractions(Fraction, Fraction)  ||||| multiplies fractions
    Fraction divide(Fraction& f1, Fraction& f2); // divideFractions(Fraction, Fraction)      ||||| divides fractions

    // arithmetic operations (with Fractions)
}


#endif //FRACTIONS_FRACTIONS_H
