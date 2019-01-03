#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

/*

int convertCharToNumber(char c) {
    return c - '0';
}
 //-------------------------- 2-6
 // convert a binary number to decimal and vice versa
void convertToDecimal() {
    std::cout << "Enter a binary number to convert to decimal." << std::endl;
    char input;
    int sum = 0;
    while(true) {
        input = std::cin.get();
        if (static_cast<int>(input) == 10) break; // exit if enter key
        int in = convertCharToNumber(input);
        if (in == 1) {// turn the first bit on
            sum |= 1;
        }
        sum <<= 1; // makes the bit mask ready for the next number on the first bit
    }
    sum >>= 1; // redo the shift
    std::cout << "Number is : " << sum << std::endl;
}

void convertToBinary() {
    std::cout << "Enter a number to convert to binary." << std::endl;
    char input;
    int number = 0;
    // get number from the user
    while (true) {
        input = std::cin.get();
        if (static_cast<int>(input) == 10) break;
        int in = convertCharToNumber(input);
        number *= 10;
        number += in;

    }
    std::vector<short> bits;
    // keep dividing by 2, and store the remainder, which is the bit number.
    while(number >= 1) {
        short remainder = number % 2;
        number /= 2;
        bits.push_back(remainder);
    }
    // The correct orientation is in reverse
    std::cout << "The Binary number is : ";
    for (auto rIter = bits.crbegin(); rIter != bits.crend(); rIter++) {
        std::cout << *rIter;
    }
    std::cout << std::endl;
}

//------------------------- 2-7
// Convert to hexadecimal, the same ideas of 2-6, but 9-16 must be represented by letters
static const std::vector<char> hexadecimalCharacters = {'A','B','C','D','E','F'};

void convertToHexadecimal() {
    std::cout << "Enter a number to convert to hexadecimal" << std::endl;
    char input;
    int number = 0;
    while(true) {
        input = std::cin.get();
        if (static_cast<int>(input) == 10) break;
        int in = convertCharToNumber(input);
        number *= 10;
        number += in;
    }
    std::vector<char> hex;
    // divide by the base number
    while (number > 0) {
        int remainder = number % 16;
        number /= 16;
        hex.push_back(remainder >= 10 ? hexadecimalCharacters[remainder % 10] : remainder + '0');
    }
    std::cout << "The Hexadecimal number is : ";
    for (auto rIter = hex.crbegin(); rIter != hex.crend(); rIter++) {
        std::cout << *rIter;
    }
    std::cout << std::endl;
}

// ------------------------ 2-8
// Allow the user to specify the base of the conversion
void converToMenu() {
    while (true) {
        std::cout << "Enter (b) to convert a number to binary\n";
        std::cout << "Enter (h) to convert a number to hexadecimal\n";
        std::cout << "Any other character to quit.";
        char input = std::cin.get();
        if (input == 'b')
            convertToDecimal();
        else if (input == 'h')
            convertToHexadecimal();
        else
            break;
    }
}

void convertTo() {
    int baseNumber1, baseNumber2;
    std::string number1, number2;
    std::cout << "Enter the baseNumber of the first number" << std::endl;
    std::cin >> baseNumber1;
    std::cout << "Enter the number" << std::endl;
    std::cin >> number1;
    std::cout << "Enter the baseNumber to convert to" << std::endl;
    std::cin >> baseNumber2;

    int decimalNum = convertToDecimal(baseNumber1, number1);
    number2 = convertToBase(baseNumber2, decimalNum);
    std::cout << "The converted number is : " << number2;

}

//------------------------ 2-9
// Have an all base function to convert from n base to m base.





*/
static const std::vector<char> alphabet = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
// convert a base 10 integer to m base

// convert n base to a base 10 integer
int convertToDecimal(int baseNumber, std::string number) {
    if (baseNumber < 1 || baseNumber > 36)
        throw new std::runtime_error("Base cannot be bigger than 36 or less than 1");

    if (baseNumber == 1) return number.size(); // Base one is similarly as to sticks, which is the size
    int sum = 0;
    // Summing works by getting the value of the number at the specific number place
    // then multiplies by the basenumber to the power of the place's position
    for (auto rIter = number.crbegin(); rIter != number.crend(); rIter++) {
        int pos = rIter - number.crbegin();
        char place = *rIter;
        if (place - '0' > 10) // It uses a letter
            sum += std::pow(baseNumber, pos) *
                    (std::find(alphabet.begin(), alphabet.end(), place) - alphabet.begin() + 10);
        else // it uses a number
            sum += std::pow(baseNumber, pos) * convertCharToNumber(place);
    }


    if (sum < 0) { // the number went around
        throw new std::runtime_error("Number exceeds limit of 2^31");
    }
    return sum;
}

std::string convertToBase(int baseNumber, int number) {
    if (baseNumber < 1 || baseNumber > 36)
        throw new std::runtime_error("Base cannot be bigger than 36 or less than 1");
    if (baseNumber == 1) return std::string(number, '1');

    std::string sum;
    // keep divinding by the base number and the result is the remainder in reverse order
    while (number > 0) {
        int remainder = number % baseNumber;
        number /= baseNumber;
        sum.push_back(remainder >= 10 ? alphabet[remainder % 10] : remainder + '0');
    }
    std::reverse(sum.begin(), sum.end());
    return sum;
}

