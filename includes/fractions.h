#ifndef FRACTIONS_FRACTIONS_H
#define FRACTIONS_FRACTIONS_H

#include <stdexcept>

typedef enum {
  Common,
  Decimal,
  Mixed
} FractionType;

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
        long getWhole() const; // Fraction.getWhole()                                                    ||||| Returns the whole part of the fraction
        Fraction getRemainder() const; // Fraction.getRemainder()                                        ||||| Returns the remainder of the fraction

        bool isEqual(const Fraction& f) const; // Fraction.isEqual(Fraction)
        bool isGreater(const Fraction& f) const; // Fraction.isGreater(Fraction)
        bool isLess(const Fraction& f) const; // Fraction.isLess(Fraction)

        Fraction power(long exponent) const; // Fraction.power(long)                                     ||||| Returns the powered fraction
        Fraction abs() const; // Fraction.abs()                                                          ||||| Returns the abs of the fraction

        Fraction inverse() const; // Fraction.inverse()                                                  ||||| Returns the inverted fraction
        void simplify(); // Fraction.simplify()                                                          ||||| Simplifies the fraction
        float ToNum() const; // Fraction.ToNum()                                                         ||||| Converts fraction to float and returns it

        void print(FractionType type = Common) const; // Fraction.print(FractionType)                    ||||| Prints the fraction
    };

    Fraction floatToFraction(float num); // floatToFraction(float)                                       ||||| Returns fraction

    // compare operations
    bool isEqual(const Fraction& f1, const Fraction& f2); // isEqual(Fraction, Fraction)
    bool isGreater(const Fraction& f1, const Fraction& f2); // isGreater(Fraction, Fraction)
    bool isLess(const Fraction& f1, const Fraction& f2); // isLess(Fraction, Fraction)

    bool isPositive(const Fraction& f);

    // arithmetic operations
    Fraction sum(const Fraction& f1, const Fraction& f2); // sumFractions(Fraction, Fraction)            ||||| Returns the sum of two fractions
    Fraction subtract(const Fraction& f1, const Fraction& f2); // subtractFractions(Fraction, Fraction)  ||||| Returns subtract of two fractions
    Fraction multiply(const Fraction& f1, const Fraction& f2); // multiplyFractions(Fraction, Fraction)  ||||| Returns multiply of two fractions
    Fraction divide(const Fraction& f1, const Fraction& f2); // divideFractions(Fraction, Fraction)      ||||| Returns divide of two fractions
}


#endif //FRACTIONS_FRACTIONS_H
