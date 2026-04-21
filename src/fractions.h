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

        Fraction power(long exponent); // Fraction.power(long)                                           ||||| Returns the powered fraction
        Fraction abs(); // Fraction.abs()                                                                ||||| Returns the abs of the fraction
        long getWhole(); // Fraction.getWhole()                                                          ||||| Returns the whole part of the fraction
        Fraction getRemainder(); // Fraction.getRemainder()                                              ||||| Returns the remainder of the fraction


        Fraction inverse(); // Fraction.inverse()                                                        ||||| Returns the inverted fraction
        void simplify(); // Fraction.simplify()                                                          ||||| Simplifies the fraction
        float ToNum(); // Fraction.ToNum()                                                               ||||| Converts fraction to float and returns it

        void print() const; // Fraction.print()                                                          ||||| Prints the fraction
    };

    Fraction floatToFraction(float num); // floatToFraction(float)                                       ||||| Return fraction

    // arithmetic operations
    Fraction sum(const Fraction& f1, const Fraction& f2); // sumFractions(Fraction, Fraction)            ||||| Returns the sum of two fractions
    Fraction subtract(const Fraction& f1, const Fraction& f2); // subtractFractions(Fraction, Fraction)  ||||| Returns subtract of two fractions
    Fraction multiply(const Fraction& f1, const Fraction& f2); // multiplyFractions(Fraction, Fraction)  ||||| Returns multiply of two fractions
    Fraction divide(const Fraction& f1, const Fraction& f2); // divideFractions(Fraction, Fraction)      ||||| Returns divide of two fractions
}


#endif //FRACTIONS_FRACTIONS_H
