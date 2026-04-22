#ifndef FRACTIONS_HELPERS_H
#define FRACTIONS_HELPERS_H

#include "../includes/fractions.h"
#include <cmath>

inline long gcd(long a, long b) {
    if(a == 0) {return std::abs(b);} else if(b == 0) {return std::abs(a);}
    a = std::abs(a);
    b = std::abs(b);
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

inline long lcm(long a, long b) {
    return (a * b) / gcd(a, b);
}

inline frc::Fraction simplifyIfNeeded(frc::Fraction f) {
    if(frc::AUTO_SIMPLIFY) {f.simplify();}
    return f;
}

#endif //FRACTIONS_HELPERS_H
