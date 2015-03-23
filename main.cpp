/*
   a program that prints the factorial of a given integer. 
   JD Minoong Ji
   March 23 2015
   jdmin@cmu.edu
*/

#include <iostream>

unsigned long long int PrintFactorialPlain (unsigned short const& givenInt) {
    
    unsigned long long int result;

    result = givenInt;

    for (unsigned int i = givenInt - 1; i >= 1; --i) {
        result *= i;
    }

    return result;
}

unsigned long long int PrintFactorialRecursive (unsigned short const& givenInt) {

    unsigned long long int result;

    result = givenInt;
    
    if (result >= 2)
        return result * PrintFactorialRecursive (givenInt - 1);
    else if (result == 1) // terminate condition
        return result;
    else {
        std::cout << "This can't be true" << std::endl;
        return 0;   // error
    }
}

template <unsigned long long int N> class TMPFactorial
{
    public :
        enum { GetValue = N * TMPFactorial<N - 1>::GetValue };
};

template <> class TMPFactorial<1> // base case
{
    public :
        enum { GetValue = 1 };
};

void printBigFactorial (unsigned short const& givenInt) {
    const int limit = 1000;
    const int base = 10;

    unsigned int digits[limit+1] = {0};

    int carry, d = 0;   // assistants during multiplication
    int last, j;    // indices to the big number's digits

    char text[limit+1] = {0};

    const char type_digits[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    digits[1] = 1;
    last = 1;
    
    for (int i = 1; i <= givenInt; ++i) {
        carry = 0;
        for (j = 1; j <= last; ++j) {
            d = digits[j] * i + carry;
            digits[j] = d % base;
            carry = d / base;
        }
        
        while (carry > 0) {
            if (last >= limit) {
                std::cout << "overflow" << std::endl;
            }
            last += 1;
            digits[last] = carry % base;
            carry = carry / base;
        }

        for (j = 1; j <= last; ++j) {
            text[limit - j + 1] = type_digits[digits[j]];   // reversing digits order
        }
    }
       
    std::cout << givenInt << "! = ";
    
    for (int i = 0; i < limit + 1; ++i) {
        std::cout << text[i];
    }

    std::cout << std::endl;

}


int main () 
{
    unsigned long long int result;
    unsigned short inputInteger;
    std::cout << "Input an integer" << std::endl;
    std::cin >> inputInteger;

    // 20! is the largest number can be calculated with 64bit word integer
    const unsigned long long int hardcodedInteger = 20;   // Template metaprogramming can't accept user input

    result = PrintFactorialPlain (inputInteger);
    std::cout << "Iteration with unsigned long long int (over 20! will generate overflow in 64bit system): \n" <<  inputInteger << " = " << result << std::endl;
    result = PrintFactorialRecursive (inputInteger);
    std::cout << "Recursion with unsigned long long int (over 20! will generate overflow in 64bit system): \n" << inputInteger << " = " << result << std::endl;
    result = TMPFactorial<hardcodedInteger>::GetValue;
    std::cout << "Template Metaprogramming with unsigned long long int (over 20! will generate overflow in 64bit system): \n" << "hardcoded integer " << hardcodedInteger << "! = " << result << std::endl;
    
    std::cout << "Iteration with arbitrary size integer notation (limit set to 1000 digits or 450!): \n";
    printBigFactorial (inputInteger);
    
    return 0;
}


