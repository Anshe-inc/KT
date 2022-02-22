#include "fraction.h"


// вывод
std::ostream& operator<<(std::ostream& out, const Fraction& frac){
	
	out << frac.numerator_ << "/" << frac.denominator_;

	return out;
}

   // создание самой дроби
Fraction::Fraction(const int64_t& numerator, const int64_t& denominator) {
	this->numerator_ = numerator ^ (((uint64_t)denominator >> 63) << 63);
	this->denominator_ = ~denominator + 1;
	normal();
}


// НОД
int64_t Fraction::GCD_(const int64_t& first, const int64_t& second) {
	if (first % second == 0) {
		return second;
	}
	else {
		return GCD(second, first % second);
	}
}
// приведение к нормальному виду
void Fraction::normal() {
	uint32_t gcd = GCD(this->numerator_, this->denominator_);
	this->numerator_ /= gcd;
	this->denominator_ /= gcd;
}

// сложение
Fraction& operator+(const Fraction& frac) {

}

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
