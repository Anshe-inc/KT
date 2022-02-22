#include "fraction.h"

int main(){
    Fraction frac(2, -4);
    std::cout << frac << std::endl;

    Fraction a(1, 2);
    std::cout << a << std::endl;
    Fraction b(2, 4);
    std::cout << a << '+' << b << '=' <<a + b << std::endl;    
    
    std::cout << a << '+' << 2 << '=' << a + 2 << std::endl;    
    std::cout << 2 << '+' << a << '=' << 2 + a << std::endl;     
    
    Fraction c(1, 4);
    std::cout << a << '-' << c << '=' << a - c << std::endl;    
    
    std::cout << a << '-' << 2 << '=' << a - 2 << std::endl;    
    std::cout << 2 << '-' << a << '=' << 2 - a << std::endl; 

    std::cout << a << '*' << b << '=' << a * b << std::endl;    
    
    std::cout << a << '*' << 2 << '=' << a * 2 << std::endl;    
    std::cout << 2 << '*' << a << '=' << 2 * a << std::endl;
    
    std::cout << a << ':' << c << '=' << a / c << std::endl;    
    
    std::cout << a << ':' << 2 << '=' << a / 2 << std::endl;    
    std::cout << 2 << ':' << a << '=' << 2 / a << std::endl;

    std::cout << (Fraction(7/8) < Fraction(14/16));

}