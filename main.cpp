#include "src/fractions.h"
#include <iostream>

Fraction f1 = Fraction(1, 6);
Fraction f2 = Fraction(1, 8);

int main() {
    f1.print();
    f2.print();
    sumFractions(f1, f2).print();
    return 0;
}