#pragma once
#include "Pesel.hpp"
#include "Helper.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

class file_error : public std::runtime_error{
public:
	file_error(const std::string& msg) : std::runtime_error(msg){}
};


enum class Gender : const char
{
	None = 'N',
	Male = 'M',
	Female = 'F'
};


class Student
{
public:
	Student();
	explicit Student(const std::string& line);
	Student(const std::string& index, const std::string& pesel, const std::string& name, const std::string& surname, const std::string& address, Gender gender);

	const std::string& getName() const;

	const std::string& getSurname() const;

	const std::string& getAddress() const;

	const std::string& getIndex() const;

	const std::string& getPesel() const;

	void setName(const std::string& name);

	void setSurname(const std::string& surname);

	void setAddress(const std::string& address);

	void setIndex(int index);

	void setPesel(const std::string& pesel);

	std::string to_string() const;
	std::string to_string_cvs_format() const;
	std::string getGender() const;
private:
	std::string index_;
	std::string pesel_;
	std::string name_;
	std::string surname_;
	std::string address_;
	Gender gender_;
};
