#include <iostream>

unsigned int PrintFactorialPlain (unsigned int givenInt) {
    
    for (unsigned int i = givenInt - 1; i >= 1; --i) {
        givenInt *= i;
    }

    return givenInt;
}

int main () 
{
    unsigned int result;
    unsigned int inputInteger;
    std::cout << "Input an integer" << std::endl;
    std::cin >> inputInteger;
    std::cout << "You entered: " << inputInteger << std::endl;

    result = PrintFactorialPlain (inputInteger);
    
    std::cout << result << std::endl;
    
    return 0;
}


