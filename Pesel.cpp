#include "Pesel.hpp"
#include <numeric>

bool Pesel::validate() const
{
	if (!validateLength())return false;
	if (!validateDigit())return false;
	if (!validateBirth())return false;
	if (!checkSum())return false;
	return true;
}


bool Pesel::validateBirth() const
{
	auto year = std::stoi(pesel_.substr(0, 2));
	auto month = std::stoi(pesel_.substr(2, 2));
	auto day = std::stoi(pesel_.substr(4, 2));

	if (day < 1)return false;

	year = getYearInPeselCodeYYYY(year, month);


	if ((day < 32) && (month == 1 || month == 3 || month == 5 || month == 7 ||
		month == 8 || month == 10 || month == 12)) {
		return true;
	}
	else if ((day < 31) &&
		(month == 4 || month == 6 || month == 9 || month == 11)) {
		return true;
	}
	else if ((day < 30 && leapYear(year)) ||
		(day > 0 && day < 29 && !leapYear(year))) {
		return true;
	}
	else {
		return false;
	}
}

char Pesel::getSex()
{
	if(!validate())return static_cast<char>(Gender::None);

	auto gender = pesel_.at(9) - '0';

	if (gender % 2 == 1) {
		return static_cast<char>(Gender::Male);
	}
	else {
		return static_cast<char>(Gender::Female);
	}
}

bool Pesel::checkSum() const
{
	const std::vector<int> vags{ 1,3,7,9,1,3,7,9,1,3 };
	std::vector<int> pesel_digit;
	pesel_digit.reserve(12);

	for (const auto& x : pesel_)
	{
		pesel_digit.push_back(x - '0');
	}

	auto result = std::transform_reduce(std::begin(vags), std::end(vags), std::begin(pesel_digit), 0);
	result %= 10;
	result = 10 - result;
	result %= 10;

	auto crc = pesel_digit.at(10);

	if (result == crc)return true;

	return false;
}

int Pesel::getYearInPeselCodeYYYY(int year_yy, int month_mm) const
{
	if (month_mm > 80 && month_mm < 93) {
		year_yy += 1800;
	}
	else if (month_mm > 0 && month_mm < 13) {
		year_yy += 1900;
	}
	else if (month_mm > 20 && month_mm < 33) {
		year_yy += 2000;
	}
	else if (month_mm > 40 && month_mm < 53) {
		year_yy += 2100;
	}
	else if (month_mm > 60 && month_mm < 73) {
		year_yy += 2200;
	}

	return year_yy;
}

bool Pesel::leapYear(int year) const
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool Pesel::validateDigit() const
{
	for_each(pesel_.begin(), pesel_.end(), [](auto x) {
		if (std::isdigit(x) && x >= 0)
		{
			return true;
		}
		return false;
		});

	return true;

}

bool Pesel::validateLength() const
{
	if (pesel_.size() != 11) return false;
	return true;
}
