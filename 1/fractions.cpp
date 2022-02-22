#include <iostream>
#include <cstdint>

class Fraction{
    int64_t numerator_;				// ���������
    uint64_t denominator_;			// �����������

	// ��� �����
    int64_t GCD_(const int64_t& first, const int64_t& second);
	// ���������� � ����������� ����
	Fraction normal();

public:
    // ����������
	Fraction();
    // copy-�����������
	Fraction(Fraction& frac) : numerator_(frac.numerator_),
							   denominator_(frac.denominator_);
	// ������� ������ �����
    Fraction(int64_t num) : numerator_(num), denominator_(1);
    // �������� ����� �����
	Fraction(const int64_t& numerator, const int64_t& denominator) :
			numerator_(numerator_), denominator_(denominator_);;

    // ������ �� �������� �� ���� �� ����� ��������� ����������
	~Fraction() = default;
	
	// ��������
	Fraction& operator+(const Fraction& first, const Fraction& second);
    Fraction& operator+(const uint64_t& first, const Fraction& second);
    Fraction& operator+(const Fraction& first, const uint64_t& second);
	
	// ���������
    Fraction& operator-(const Fraction& first, const Fraction& second);
    Fraction& operator-(const uint64_t& first, const Fraction& second);
    Fraction& operator-(const Fraction& first, const uint64_t& second);
    
	//���������
	Fraction& operator*(const Fraction& first, const Fraction& second);
	Fraction& operator*(const uint64_t& first, const Fraction& second);
	Fraction& operator*(const Fraction& first, const uint64_t& second);
    
	// �������
	Fraction& operator/(const Fraction& first, const Fraction& second);
	Fraction& operator/(const uint64_t& first, const Fraction& second);
	Fraction& operator/(const Fraction& first, const uint64_t& second);
};