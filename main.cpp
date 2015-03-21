#include <iostream>

unsigned int PrintFactorialPlain (unsigned int givenInt) {
    
    for (unsigned int i = givenInt - 1; i >= 1; --i) {
        givenInt *= i;
    }

    return givenInt;
}

unsigned int PrintFactorialRecursive (unsigned int givenInt) {

    if (givenInt >= 2)
        givenInt *= PrintFactorialRecursive (givenInt - 1);
    else if (givenInt == 1) // terminate condition
        return givenInt;
    else {
        std::cout << "This can't be true" << std::endl;
        return 0;   // error
    }
    
    return givenInt;
}

int main () 
{
    unsigned int result;
    unsigned int inputInteger;
    std::cout << "Input an integer" << std::endl;
    std::cin >> inputInteger;

    result = PrintFactorialPlain (inputInteger);
    result = PrintFactorialRecursive (inputInteger);
    
    std::cout << result << std::endl;
    
    return 0;
}


