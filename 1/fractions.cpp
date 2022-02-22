#include "fraction.h"


// вывод
std::ostream& operator<<(std::ostream& out, const Fraction& frac){
	
	out << frac.numerator_ << "/" << frac.denominator_;

	return out;
}

   // создание самой дроби
Fraction::Fraction(const int64_t& numerator, const int64_t& denominator) {
	if (denominator < 0) {
		numerator_ = -numerator;
		denominator_ = -denominator;
	}
	else{
		numerator_ = -numerator;
		denominator_ = -denominator;
	}
	normal();
}


// НОД
int64_t Fraction::GCD_(const uint64_t& first, const uint64_t& second) {
	if (first % second == 0) {
		return second;
	}
	else {
		return GCD_(second, first % second);
	}
}
// приведение к нормальному виду
void Fraction::normal() {
	uint64_t a = this->numerator_;
	if (a < 0) {
		a = -a;
	}
	uint64_t b = this->denominator_;
	int64_t gcd = GCD_(a, b);
	this->numerator_ /= gcd;
	this->denominator_ /= gcd;
}

// сложение
/*Fraction& operator+(const Fraction& frac) {

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
*/