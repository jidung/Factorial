#include <iostream>

unsigned int PrintFactorialPlain (unsigned int givenInt) {
    
    for (unsigned int i = givenInt - 1; i >= 1; --i) {
        givenInt *= i;
    }

    return givenInt;
}

unsigned int PrintFactorialRecursive (unsigned int givenInt) {

    if (givenInt >= 2)
        return givenInt * PrintFactorialRecursive (givenInt - 1);
    else if (givenInt == 1) // terminate condition
        return givenInt;
    else {
        std::cout << "This can't be true" << std::endl;
        return 0;   // error
    }
}

template <unsigned int N> class TMPFactorial
{
    public :
        enum { GetValue = N * TMPFactorial<N - 1>::GetValue };
};

template <> class TMPFactorial<1> // base case
{
    public :
        enum { GetValue = 1 };
};

int main () 
{
    unsigned int result;
    unsigned int inputInteger;
    std::cout << "Input an integer" << std::endl;
    std::cin >> inputInteger;

    const unsigned int hardcodedInteger = 30;   // Template metaprogramming can't accept user input

    result = PrintFactorialPlain (inputInteger);
    std::cout << result << std::endl;
    result = PrintFactorialRecursive (inputInteger);
    std::cout << result << std::endl;
    result = TMPFactorial<hardcodedInteger>::GetValue;
    std::cout << result << std::endl;
    
    return 0;
}


