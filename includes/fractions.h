#ifndef FRACTIONS_FRACTIONS_H
#define FRACTIONS_FRACTIONS_H

#include <stdexcept>
#include <string>

// I'm using "namespace" because I think it would be better
namespace frc {
    typedef enum {
      Common,
      Decimal,
      Mixed
    } FractionType;

    inline bool AUTO_SIMPLIFY = false;
    inline FractionType STREAM_TYPE = Common; // Used in << operator

    class Fraction {
    private:
        long numerator;
        long denominator;

    public:
        Fraction(long num, long den = 1) : numerator(den < 0 ? -num : num), denominator(den < 0 ? -den : den) {
            if (den == 0) {
                throw std::runtime_error("You can't divide by zero!");
            }
            if(AUTO_SIMPLIFY) {this->simplify();}
        }
        // I decided to write all functions, that inside this class in fractions.cpp (I can change my mind)

        // -------- Getters --------
        long getNumerator() const;
        long getDenominator() const;
        long getWhole() const; // Fraction.getWhole()                                        ||||| Returns the whole part of the fraction
        Fraction getRemainder() const; // Fraction.getRemainder()                            ||||| Returns the remainder of the fraction

        // -------- Assignment Arithmetic Operations (arithmetic_operations.cpp) --------
        Fraction& operator += (const Fraction& f);
        Fraction& operator -= (const Fraction& f);
        Fraction& operator *= (const Fraction& f);
        Fraction& operator /= (const Fraction& f);
        Fraction operator - () const;
        // -------- Prefix Operators --------
        Fraction& operator ++ ();
        Fraction& operator -- ();
        // -------- Postfix Operators --------
        Fraction operator ++ (int);
        Fraction operator -- (int);

        // -------- Useful Functions --------
        explicit operator float() const {return float(numerator) / denominator;} // Overloaded float() operator
        explicit operator double() const {return double(numerator) / denominator;} // Overloaded double() operator
        std::string str(const FractionType& type = Common) const; // utils.cpp

        void simplify(); // Fraction.simplify()                                              ||||| Simplifies the fraction

        void print(const FractionType& type = Common) const; // Fraction.print(FractionType) ||||| Prints the fraction
    };

    // -------- Utils --------
    Fraction from_float(float num); // from_float(float)                                     ||||| Returns fraction
    std::string to_string(const Fraction& f, const FractionType& type = Common);
    Fraction inverse(const Fraction& f); // inverse(Fraction)                                ||||| Returns the inverted fraction

    std::ostream& operator << (std::ostream& stream, const Fraction& f);

    // -------- Comparison --------
    bool operator == (const Fraction& f1, const Fraction& f2);
    bool operator > (const Fraction& f1, const Fraction& f2);
    bool operator < (const Fraction& f1, const Fraction& f2);
    bool operator >= (const Fraction& f1, const Fraction& f2);
    bool operator <= (const Fraction& f1, const Fraction& f2);
    bool operator != (const Fraction& f1, const Fraction& f2);

    // -------- Arithmetic Operations --------
    Fraction operator + (const Fraction& f1, const Fraction& f2);
    Fraction operator - (const Fraction& f1, const Fraction& f2);
    Fraction operator * (const Fraction& f1, const Fraction& f2);
    Fraction operator / (const Fraction& f1, const Fraction& f2);
    // -------- Math Functions --------
    Fraction pow(const Fraction& base, long exponent);
    Fraction abs(const Fraction& f);
    long floor(const Fraction& f);
    long ceil(const Fraction& f);
    long round(const Fraction& f);
}


#endif //FRACTIONS_FRACTIONS_H
