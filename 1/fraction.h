#include <iostream>
#include <cstdint>

class Fraction{
    int64_t numerator_ = 0;				// числитель
    uint64_t denominator_ = 1;			// знаменатель

	// НОД числа
    int64_t GCD_(const uint64_t& first, const uint64_t& second);
	// приведение к нормальному виду
	void normal();

public:
    // конструтор
	Fraction() = default;
    // copy-конструктор
	Fraction(const Fraction& frac) : numerator_(frac.numerator_),
                               denominator_(frac.denominator_) {}
	// парсинг целого числа
    //Fraction(int64_t num) : numerator_(num), denominator_(1) {}
    // создание самой дроби и парсинг целого числа
	Fraction(const int64_t& numerator, const int64_t& denominator = 1);

    // ничего не выделяем на куче по этому дефолтный деструктор
	~Fraction() = default;
	
	// сложение
	Fraction operator+(const Fraction& frac);
	Fraction operator+(const int64_t& num);
    friend Fraction operator+(const uint64_t num, const Fraction& frac);
	
    // унарный минус
    Fraction operator-() const;

	// вычитание
	Fraction operator-(const Fraction& frac);
	Fraction operator-(const int64_t& num);
    friend Fraction operator-(const uint64_t num, const Fraction& frac);   
    
	//умножение
	Fraction operator*(const Fraction& frac);  
	Fraction operator*(const int64_t& num);
    friend Fraction operator*(const uint64_t num, const Fraction& frac);
	
    // деление
	Fraction operator/(const Fraction& frac);
	Fraction operator/(const int64_t& num);
    friend Fraction operator/(const uint64_t num, const Fraction& frac);

	// Оператор копирования       
    Fraction& operator=(const Fraction& frac);
    // вывод
	friend std::ostream& operator<<(std::ostream& out, const Fraction& frac);
	
};