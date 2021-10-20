#pragma once
#include "Student.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Pesel {
public:
	explicit Pesel(const std::string& pesel) : pesel_(pesel) {}
	bool validate() const;
	char getSex();

private:
	const std::string pesel_;
	bool validateBirth() const;
	bool checkSum() const;
	int getYearInPeselCodeYYYY(int year_yy, int month_mm) const;
	bool leapYear(int year) const;
	bool validateDigit()const;
	bool validateLength() const;
};



