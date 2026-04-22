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

    void Fraction::simplify() {
        long common = gcd(numerator, denominator);
        numerator /= common;
        denominator /= common;
    }

    void Fraction::print(const FractionType& type) const {
        if(type == Common) {std::cout << numerator << "/" << denominator << std::endl;}
        else if(type == Decimal) {std::cout << float(*this) << std::endl;}
        else {std::cout << this->getWhole() << " | " << this->getRemainder().getNumerator() << "/" << denominator << std::endl;}
    }
}

