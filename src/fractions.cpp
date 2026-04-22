#include "../includes/fractions.h"
#include "helpers.h"
#include <iostream>
#include <stdexcept>

namespace frc {
    long Fraction::getNumerator() const {
        return numerator;
    }

    long Fraction::getDenominator() const {
        return denominator;
    }

    long Fraction::getWhole() const {
        return numerator / denominator;
    }

    Fraction Fraction::getRemainder() const {
        return Fraction(numerator % denominator, denominator);
    }

    bool Fraction::isEqual(const Fraction& f) const {
        long f_num = f.getNumerator();
        long f_den = f.getDenominator();

        if(numerator * f_den == f_num * denominator) {
            return true;
        }

        return false;
    }

    bool Fraction::isGreater(const Fraction& f) const {
        long f_num = f.getNumerator();
        long f_den = f.getDenominator();

        if(numerator * f_den > f_num * denominator) {
            return true;
        }

        return false;
    }

    bool Fraction::isLess(const Fraction& f) const {
        long f_num = f.getNumerator();
        long f_den = f.getDenominator();

        if(numerator * f_den < f_num * denominator) {
            return true;
        }

        return false;
    }

    Fraction Fraction::power(long exponent) const {
        Fraction f = Fraction(pow(numerator, exponent), pow(denominator, exponent));
        return simplifyIfNeeded(f);
    }

    Fraction Fraction::abs() const {
        Fraction f = Fraction(std::abs(numerator), std::abs(denominator));
        return simplifyIfNeeded(f);
    }

    Fraction Fraction::inverse() const {
        long num = numerator;
        long den = denominator;

        Fraction f = Fraction(den, num);
        return simplifyIfNeeded(f);
    }

    void Fraction::simplify() {
        long common = gcd(numerator, denominator);
        numerator /= common;
        denominator /= common;
    }

    float Fraction::ToNum() const {
        return float(numerator) / denominator;
    }

    void Fraction::print(FractionType type) const {
        if(type == Common) {std::cout << numerator << "/" << denominator << std::endl;}
        else if(type == Decimal) {std::cout << this->ToNum() << std::endl;}
        else {std::cout << this->getWhole() << " | " << this->getRemainder().getNumerator() << "/" << denominator << std::endl;}
    }
}

