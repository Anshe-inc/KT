#include "fraction.h"


// вывод
std::ostream& operator<<(std::ostream& out, const Fraction& frac){
	
	out << frac.numerator_ << "/" << frac.denominator_;

	return out;
}