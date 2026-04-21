#include "src/fractions.h"
#include <iostream>

Fraction f1 = Fraction(4, 16);

int main() {
    f1.print();
    f1.simplify();
    f1.print();

    f1.power(2);
    f1.print();

    std::cout << f1.ToNum() << std::endl;

    std::cout << f1.getNumerator() << std::endl;
    std::cout << f1.getDenominator() << std::endl;
    return 0;
}