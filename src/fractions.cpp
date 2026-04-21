#include "fractions.h"
#include <iostream>
#include <numeric>
#include <string>
#include <stdexcept>
#include <cmath>

// handlers
long gcd(long a, long b) {
    long mx = std::max(a, b);
    long mn = std::min(a, b);

    while(true) {
        long t = mx % mn;

        if(t == 0) {
            break;
        } else {
            mx = std::max(t, mn);
            mn = std::min(t, mn);
        }
    }

    return mn;
}

// "class" funcs
long Fraction::getNumerator() {
    return numerator;
}

long Fraction::getDenominator() {
    return denominator;
}

void Fraction::power(float exponent) {
    numerator = pow(numerator, exponent);
    denominator = pow(denominator, exponent);
}

void Fraction::simplify() {
    long common = gcd(numerator, denominator);
    numerator /= common;
    denominator /= common;
}

float Fraction::ToNum() {
    return float(numerator) / denominator;
}

void Fraction::print() const {
    std::cout << numerator << "/" << denominator << std::endl;
}

// other funcs

