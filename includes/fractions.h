#ifndef FRACTIONS_FRACTIONS_H
#define FRACTIONS_FRACTIONS_H

#include <stdexcept>

typedef enum {
  Common,
  Decimal,
  Mixed
} FractionType;

// I'm using "namespace" because I think it would be better
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
        // I decided to write all functions, that inside this class in fractions.cpp (I can change my mind)

        // -------- Getters --------
        long getNumerator() const;
        long getDenominator() const;
        long getWhole() const; // Fraction.getWhole()                                                    ||||| Returns the whole part of the fraction
        Fraction getRemainder() const; // Fraction.getRemainder()                                        ||||| Returns the remainder of the fraction

        // -------- Math Functions --------
        Fraction power(long exponent) const; // Fraction.power(long)                                     ||||| Returns the powered fraction
        Fraction abs() const; // Fraction.abs()                                                          ||||| Returns the abs of the fraction
        // -------- Assignment Arithmetic Operations (arithmetic_operations.cpp) --------
        Fraction& operator += (const Fraction& f);
        Fraction& operator -= (const Fraction& f);
        Fraction& operator *= (const Fraction& f);
        Fraction& operator /= (const Fraction& f);

        // -------- Useful Functions --------
        Fraction inverse() const; // Fraction.inverse()                                                  ||||| Returns the inverted fraction
        void simplify(); // Fraction.simplify()                                                          ||||| Simplifies the fraction
        float ToNum() const; // Fraction.ToNum()                                                         ||||| Converts fraction to float and returns it

        void print(FractionType type = Common) const; // Fraction.print(FractionType)                    ||||| Prints the fraction
    };

    Fraction floatToFraction(float num); // floatToFraction(float)                                       ||||| Returns fraction

    // -------- Compare Operations --------
    bool operator == (const Fraction& f1, const Fraction& f2);
    bool operator > (const Fraction& f1, const Fraction& f2);
    bool operator < (const Fraction& f1, const Fraction& f2);
    bool operator >= (const Fraction& f1, const Fraction& f2);
    bool operator <= (const Fraction& f1, const Fraction& f2);

    // -------- Arithmetic Operations --------
    Fraction operator + (const Fraction& f1, const Fraction& f2);
    Fraction operator - (const Fraction& f1, const Fraction& f2);
    Fraction operator * (const Fraction& f1, const Fraction& f2);
    Fraction operator / (const Fraction& f1, const Fraction& f2);
}


#endif //FRACTIONS_FRACTIONS_H
