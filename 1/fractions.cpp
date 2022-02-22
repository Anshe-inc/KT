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
	Fraction();
    // copy-конструктор
	Fraction(Fraction& frac) : numerator_(frac.numerator_),
							   denominator_(frac.denominator_);
	// парсинг целого числа
    Fraction(int64_t num) : numerator_(num), denominator_(1);
    // создание самой дроби
	Fraction(const int64_t& numerator, const int64_t& denominator) :
			numerator_(numerator_), denominator_(denominator_);;

    // ничего не выделяем на куче по этому дефолтный деструктор
	~Fraction() = default;
	
	// сложение
	Fraction& operator+(const Fraction& first, const Fraction& second);
    Fraction& operator+(const uint64_t& first, const Fraction& second);
    Fraction& operator+(const Fraction& first, const uint64_t& second);
	
	// вычитание
    Fraction& operator-(const Fraction& first, const Fraction& second);
    Fraction& operator-(const uint64_t& first, const Fraction& second);
    Fraction& operator-(const Fraction& first, const uint64_t& second);
    
	//умножение
	Fraction& operator*(const Fraction& first, const Fraction& second);
	Fraction& operator*(const uint64_t& first, const Fraction& second);
	Fraction& operator*(const Fraction& first, const uint64_t& second);
    
	// деление
	Fraction& operator/(const Fraction& first, const Fraction& second);
	Fraction& operator/(const uint64_t& first, const Fraction& second);
	Fraction& operator/(const Fraction& first, const uint64_t& second);
};