#include <iostream>
#include "fractions.h"

int main() {
    // Creating fractions
    frc::Fraction f1(3, 4);    // 3/4
    frc::Fraction f2(5);       // 5/1
    frc::Fraction f3 = 10;     // 10/1

    // Using different output types via print()
    std::cout << "Standard print:" << std::endl;
    f1.print(frc::Common);    // Output: 3/4
    f2.print(frc::Common);    // Output: 5/1
    f3.print(frc::Common);    // Output: 10/1

    frc::Fraction f4(10, 3);
    std::cout << "Mixed fraction print:" << std::endl;
    f4.print(frc::Mixed);     // Output: 3 | 1/3

    // Global settings for stream operator <<
    frc::STREAM_TYPE = frc::Decimal;
    std::cout << "Global Decimal mode: " << f1 << std::endl; // Output: 0.75

    frc::STREAM_TYPE = frc::Common;
    std::cout << "Global Common mode: " << f1 << std::endl; // Output: 0.75

    frc::STREAM_TYPE = frc::Mixed;
    std::cout << "Global Mixed mode: " << f1 << std::endl; // Output: 0.75

    return 0;
}