/*
   a program that prints the factorial of a given integer. 
   JD Minoong Ji
   March 23 2015
   jdmin@cmu.edu
*/

#include <iostream>

void PrintFactorialPlain (unsigned short const& givenInt) {

    unsigned long long int result = givenInt;
    
    for (unsigned int i = givenInt - 1; i >= 1; --i) {
        result *= i;
    }

    std::cout << "Iteration with unsigned long long int (over 20! will generate overflow in 64bit system): " << givenInt << "! = " << result << std::endl;
}

unsigned long long int PrintFactorialRecursive (unsigned short const& givenInt) {

    unsigned long long int result = givenInt;
    
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
    const int limit = 10000;    // limit of number of digits
    const int base = 10;        // using decimal system

    unsigned int digits[limit] = {0};
    unsigned int carry, d = 0;  // assistants during multiplication
    unsigned int last = 0;      // indice to the big number's last (highest) digit

    char text[limit+1] = {0};
    const char type_digits[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    digits[0] = 1;  // init value
    
    for (unsigned int i = 1; i <= givenInt; ++i) {
        carry = 0;

        // multiply by digits by digits. add carry from the multiplication right before
        for (unsigned int j = 0; j <= last; ++j) {
            d = digits[j] * i + carry;
            digits[j] = d % base;       
            carry = d / base;
        }
        
        // if carry remained, add more digits to the number out of carry
        while (carry > 0) {
            if (last >= limit)
                std::cout << "overflow" << std::endl;
            last += 1;
            digits[last] = carry % base;
            carry = carry / base;
        }

        // reversing digits to correct order
        for (unsigned int j = 0; j <= last; ++j) {
            text[limit - j] = type_digits[digits[j]];   
        }
    }
    
    // print the number digit by digit
    std::cout << "Iteration with arbitrary size integer notation (limit set to 10000 digits): " << givenInt << "! = ";
    for (unsigned int i = 0; i < limit; ++i) {
        std::cout << text[i];
    }
    std::cout << std::endl;
}


int main () 
{
    unsigned long long int result;
    unsigned short inputInteger;
    std::cout << "Input an integer: " << std::endl;
    std::cin >> inputInteger;

    // 20! is the largest number can be calculated with 64bit word unsigned long long integer
    const unsigned long long int hardcodedInteger = 20;   // Template metaprogramming can't accept user input

    // Iteration
    PrintFactorialPlain (inputInteger);

    // Recursion
    result = PrintFactorialRecursive (inputInteger);
    std::cout << "Recursion with unsigned long long int (over 20! will generate overflow in 64bit system): " << inputInteger << "! = " << result << std::endl;
   
    // Template Metaprogramming
    result = TMPFactorial<hardcodedInteger>::GetValue;
    std::cout << "Template Metaprogramming with unsigned long long int (over 20! will generate overflow in 64bit system): (hardcoded integer) " 
              << hardcodedInteger << "! = " << result << std::endl;    

    // Iteration with Big Integer
    printBigFactorial (inputInteger);
    
    return 0;
}


