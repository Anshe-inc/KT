#include "fraction.h"


// вывод
std::ostream& operator<<(std::ostream& out, const Fraction& frac){
	
	if (frac.denominator_ == 1) {
		out << frac.numerator_;
	}
	else {
		out << frac.numerator_ << "/" << frac.denominator_;
	}

	return out;
}

   // создание самой дроби
Fraction::Fraction(const int64_t& numerator, const int64_t& denominator) {
	if (denominator < 0) {
		this->numerator_ = -numerator;
		this->denominator_ = -denominator;
	}
	else{
		this->numerator_ = numerator;
		this->denominator_ = denominator;
	}
	normal();
}

// getter
uint64_t Fraction::get_numerator() const{
	return this->numerator_;
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

// Оператор копирования       
Fraction& Fraction::operator=(const Fraction& frac){
	this->numerator_ = frac.numerator_;
	this->denominator_ = frac.denominator_;

	return *this;
}

// сложение
Fraction Fraction::operator+(const Fraction& frac) {
	int64_t a = this->numerator_;
	int64_t b = this->denominator_;

	int64_t a1 = frac.numerator_;
	int64_t b1 = frac.denominator_;

	return Fraction(a * b1 + a1 * b, b * b1);
}
Fraction Fraction::operator+(const int64_t& num) {
	return *this + Fraction(num);
}
Fraction operator+(const uint64_t num, const Fraction& frac) {
	return Fraction(num) + frac;
}

Fraction Fraction::operator-() const{
	return Fraction(-this->numerator_, this->denominator_);
}

// вычитание
Fraction Fraction::operator-(const Fraction& frac) {
	return *this + (-frac);
}
Fraction Fraction::operator-(const int64_t& num) {
	return *this - Fraction(num);
}
Fraction operator-(const uint64_t num, const Fraction& frac) {
	return Fraction(num) - frac;
}

//умножение
Fraction Fraction::operator*(const Fraction& frac) {
	int64_t a = this->numerator_;
	int64_t b = this->denominator_;

	int64_t a1 = frac.numerator_;
	int64_t b1 = frac.denominator_;

	return Fraction(a * a1, b * b1);
} 
Fraction Fraction::operator*(const int64_t& num) {
	return *this * Fraction(num);
}
Fraction operator*(const uint64_t num, const Fraction& frac) {
	return Fraction(num) * frac;
}
// инверсия дроби
Fraction Fraction::inverce() const{
	if (this->numerator_ == 0) {
		throw std::invalid_argument("Fraction");
	}
	return Fraction(this->denominator_, this->numerator_);
}
// деление
Fraction Fraction::operator/(const Fraction& frac) {
	return *this * frac.inverce();
}
Fraction Fraction::operator/(const int64_t& num) {
	return *this / Fraction(num);
}
Fraction operator/(const uint64_t num, const Fraction& frac) {
	return Fraction(num) / frac;
}

// ------ Сравнение -------
// Равенство
bool Fraction::operator==(const Fraction& frac) {
	return (*this - frac).get_numerator() == 0;
}
bool Fraction::operator==(const int64_t& num) {
	return (*this - num).get_numerator() == 0;
}
Fraction operator==(const uint64_t num, const Fraction& frac) {
	return (num - frac).get_numerator() == 0;
}

// Неравенство
bool Fraction::operator!=(const Fraction& frac) {
	return (*this - frac).get_numerator() != 0;
}
bool Fraction::operator!=(const int64_t& num) {
	return (*this - num).get_numerator() != 0;
}
Fraction operator!=(const uint64_t num, const Fraction& frac) {
	return (num - frac).get_numerator() != 0;
}

bool Fraction::operator>(const Fraction& frac) {
	return (*this - frac).get_numerator() > 0;
}
bool Fraction::operator>(const int64_t& num) {
	return (*this - num).get_numerator() > 0;
}

bool Fraction::operator<(const Fraction& frac) {
	return (*this - frac).get_numerator() < 0;
}
bool Fraction::operator<(const int64_t& num) {
	return (*this - num).get_numerator() < 0;
}

bool Fraction::operator>=(const Fraction& frac) {
	return (*this - frac).get_numerator() >= 0;
}
bool Fraction::operator>=(const int64_t& num) {
	return (*this - num).get_numerator() >= 0;
}

bool Fraction::operator<=(const Fraction& frac) {
	return (*this - frac).get_numerator() <= 0;
}
bool Fraction::operator<=(const int64_t& num) {
	return (*this - num).get_numerator() <= 0;
}

bool operator>(const uint64_t num, const Fraction& frac) {
	return (num - frac).get_numerator() > 0;
}
bool operator>=(const uint64_t num, const Fraction& frac) {
	return (num - frac).get_numerator() >= 0;
}

bool operator<(const uint64_t num, const Fraction& frac) {
	return (num - frac).get_numerator() < 0;
}
bool operator<=(const uint64_t num, const Fraction& frac) {
	return (num - frac).get_numerator() <= 0;
}
// ------------------------
