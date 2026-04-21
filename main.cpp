#include "src/fractions.h"
#include <iostream>

using namespace frc;

Fraction f1 = Fraction(2, 6);
Fraction f2 = Fraction(1, 8);

int main() {
    frc::AUTO_SIMPLIFY = true;
    f1.print();
    f1.power(2);
    f1.print();

    return 0;
}