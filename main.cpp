#include "src/fractions.h"
#include <iostream>

using namespace frc;

Fraction f1 = Fraction(5, -10);
Fraction f2 = Fraction(1, 8);
Fraction f3 = 10;
Fraction f4 = Fraction(1, 2);

int main() {
    //AUTO_SIMPLIFY = true
    f2.inverse();
    f2.print();
    return 0;
}