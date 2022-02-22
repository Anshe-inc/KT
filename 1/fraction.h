#include <iostream>
#include <cstdint>

class Fraction{
    int64_t numerator_;				// числитель
    uint64_t denominator_;			// знаменатель

	// НОД числа
    int64_t GCD_(const int64_t& first, const int64_t& second);
	// приведение к нормальному виду
	Fraction normal();

public:
    // конструтор
	Fraction() : numerator_(0), denominator_(1) {}
    // copy-конструктор
	Fraction(Fraction& frac) : numerator_(frac.numerator_),
							   denominator_(frac.denominator_) {}
	// парсинг целого числа
    Fraction(int64_t num) : numerator_(num), denominator_(1) {}
    // создание самой дроби
	Fraction(const int64_t& numerator, const uint64_t& denominator) :
			numerator_(numerator), denominator_(denominator) {}

    // ничего не выделяем на куче по этому дефолтный деструктор
	~Fraction() = default;
	
	// сложение
	Fraction& operator+(const Fraction& frac);
	Fraction& operator+(const uint64_t& numb);
	
	// вычитание
	Fraction& operator-(const Fraction& frac);
	Fraction& operator-(const uint64_t& numb);
   
    
	//умножение
	Fraction& operator*(const Fraction& frac);  
	Fraction& operator*(const uint64_t& numb);
	
    
	// деление
	Fraction& operator/(const Fraction& frac);
	Fraction& operator/(const uint64_t& numb);

	// вывод
	friend std::ostream& operator<<(std::ostream& out, const Fraction& frac);
	
};