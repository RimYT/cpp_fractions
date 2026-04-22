# Fractions

My "project". The code was written entirely by me. AI and other resources were used only for information, not for writing the code itself

## Table of Contents
* [Project Rules](#project-rules)
  * [Strictly Prohibited](#strictly-prohibited)
  * [Preferred Approach](#preferred-approach-self-reliance)
  * [Permitted Uses](#permitted-uses)
* [Documentation](#documentation)
  * [Configuration & Enums](#configuration--enums)
    * [FractionType (enum)](#fractiontype-enum)
    * [Global Settings](#global-settings)
  * [Class: frc::Fraction](#class-frcfraction)
    * [Constructor](#constructor)
    * [Methods](#methods)
    * [Operators](#operators)
  * [Global Functions (namespace frc)](#global-functions-namespace-frc)
    * [Mathematical Operations](#mathematical-operations)
    * [Utility Functions](#utility-functions)
    * [Comparison Operators](#comparison-operators)
    * [Stream Output](#stream-output)

## Project Rules

To maximize learning and skill development, this project follows a strict set of personal guidelines:

### STRICTLY PROHIBITED
* **No AI-generated code:** Using AI (like ChatGPT, Copilot, etc.) to write or complete any part of the source code is forbidden
* **No Copy-Pasting:** Searching for and using ready-made code solutions from the internet for project tasks is not allowed

### PREFERRED APPROACH (Self-Reliance)
* **Independent Debugging:** Analyzing and fixing errors on my own before seeking external help
* **Algorithmic Thinking:** Designing logic and algorithms independently (e.g., calculating GCD/LCM, etc.)
* **Mathematical Research:** Manually figuring out the mathematical rules and logic required for the project

### PERMITTED USES
* **Syntax & Language Reference:** Using the internet or AI to understand language syntax, OOP principles, or standard library functions (e.g., `std::max()`)
* **Error Analysis:** Using external tools to help understand a specific error message (though self-analysis is preferred)
* **Algorithm Concepts:** Researching the *theory* behind algorithms (not the code) when necessary (e.g., the logic behind finding GCD/LCM)
* **Mathematical Assistance:** Using resources to clarify mathematical rules (e.g., the process of adding fractions) if stuck

*This project serves as a testament to my personal coding journey and commitment to fundamental learning* </br>
*This file was written by AI, cuz idk how to write .md files xd*

## Documentation

## Configuration & Enums

### `FractionType` (Enum)
Determines the formatting style for string conversion and printing
* `Common`: Represented as `n/d` (e.g., `3/2`)
* `Decimal`: Represented as a floating-point string (e.g., `1.5`)
* `Mixed`: Represented as a whole number and a remainder (e.g., `1 | 1/2`)

### Global Settings
| Variable | Type | Description                                                                                                                            |
| :--- | :--- |:---------------------------------------------------------------------------------------------------------------------------------------|
| `frc::AUTO_SIMPLIFY` | `bool` | If `true`, fraction automatically simplifies after every operation, the constructor automatically calls `simplify()`. Default: `false` |
| `frc::STREAM_TYPE` | `FractionType` | Sets the format used by the `<<` stream operator. Default: `Common`                                                                    |

---

## Class: `frc::Fraction`

### Constructor
`Fraction(long num, long den = 1)`
* Creates a fraction with a numerator and denominator
* **Note:** If the denominator is negative, the sign is automatically moved to the numerator
* **Throws:** `std::runtime_error` if `den` is 0

### Methods
| Method | Return Type | Description                                                        |
| :--- | :--- |:-------------------------------------------------------------------|
| `getNumerator()` | `long` | Returns the numerator                                              |
| `getDenominator()` | `long` | Returns the denominator                                            |
| `getWhole()` | `long` | Returns the integer (whole) part of the fraction                   |
| `getRemainder()` | `Fraction` | Returns the fractional remainder (the part left after `getWhole`). |
| `simplify()` | `void` | Reduces the fraction to its simplest form in-place                 |
| `str(FractionType)` | `std::string` | Returns a string representation based on the type provided         |
| `print(FractionType)` | `void` | Prints the fraction to the standard output                         |

### Operators
* **Arithmetic (Assignment):** `+=`, `-=`, `*=`, `/=`
* **Unary:** `-` (negation)
* **Increment/Decrement:** `++`, `--` (both prefix and postfix supported)
* **Type Casting:** `explicit operator float()`, `explicit operator double()`

---

## Global Functions (Namespace `frc`)

### Mathematical Operations
| Function | Return Type | Description                                   |
| :--- | :--- |:----------------------------------------------|
| `operator +` | `Fraction` | Returns the sum of two fractions              |
| `operator -` | `Fraction` | Returns the difference between two fractions  |
| `operator *` | `Fraction` | Returns the product of two fractions          |
| `operator /` | `Fraction` | Returns the quotient of two fractions         |
| `pow(base, exp)` | `Fraction` | Returns the fraction raised to a `long` power |
| `abs(f)` | `Fraction` | Returns the absolute value of the fraction    |

### Utility Functions
| Function | Return Type | Description                                                        |
| :--- | :--- |:-------------------------------------------------------------------|
| `from_float(float)` | `Fraction` | Converts a float value into a `Fraction` object                    |
| `to_string(f, type)` | `std::string` | Utility to convert a fraction to a string                          |
| `inverse(f)` | `Fraction` | Returns a new fraction with swapped numerator and denominator      |
| `floor(f)` | `long` | Returns the largest integer less than or equal to the fraction     |
| `ceil(f)` | `long` | Returns the smallest integer greater than or equal to the fraction |
| `round(f)` | `long` | Returns the fraction rounded to the nearest integer                |

### Comparison Operators
All standard comparison operators are overloaded to compare the mathematical value of two fractions:
`==`, `!=`, `>`, `<`, `>=`, `<=`

### Stream Output
`std::ostream& operator << (std::ostream& stream, const Fraction& f)`
Outputs the fraction to a stream using the format defined in `frc::STREAM_TYPE`