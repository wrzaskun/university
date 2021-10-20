#include "Student.hpp"

Student::Student() : Student("-1", "00410251218", "-1", "-1", "-1", Gender::None){}

Student::Student(const std::string& index, const std::string& pesel, const std::string& name, const std::string& surname, const std::string& address, Gender gender)
	: index_(index)
	, name_(name)
	, surname_(surname)
	, address_(address)
	, gender_(gender) {
	setPesel(pesel);
}

Student::Student(const std::string& line)
{
	auto result = split(line, ",");

	if (result[5] == "Male") {
		gender_ = Gender::Male;
	}
	else if (result[5] == "Female") {
		gender_ = Gender::Female;
	}
	else {
		gender_ = Gender::None;
	}

	index_ = result.at(0);
	setPesel(result.at(1));
	name_ = result.at(2);
	surname_ = result.at(3);
	address_ = result.at(4);
}

const std::string& Student::getName() const {
	return name_;
}

const std::string& Student::getSurname() const {
	return surname_;
}

const std::string& Student::getAddress() const {
	return address_;
}

const std::string& Student::getIndex() const {
	return index_;
}

const std::string& Student::getPesel() const {
	return pesel_;
}

void Student::setName(const std::string& name) {
	name_ = name;
}

void Student::setSurname(const std::string& surname) {
	surname_ = surname;
}

void Student::setAddress(const std::string& address) {
	address_ = address;
}

void Student::setIndex(int index) {
	index_ = std::to_string(index);
}

void Student::setPesel(const std::string& pesel) {

	Pesel p{ pesel };
	if (!p.validate()) {
		throw std::logic_error(std::string("Pesel is wrong."));
	};
	pesel_ = pesel;
}

std::string Student::to_string() const {
	std::string temp =
		index_ +
		" | " + pesel_ +
		" | " + name_ + " " + surname_ +
		" | " + address_ +
		" | " + getGender() + '\n';
	return temp;
}

std::string Student::to_string_cvs_format() const
{
	std::string temp
		= index_ + ','
		+ pesel_ + ','
		+ name_ + ','
		+ surname_ + ','
		+ address_ + ','
		+ getGender();
	return temp;
}

std::string Student::getGender() const
{
	if (Gender::Female == gender_) {
		return "Female";
	}
	else if (Gender::Male == gender_) {
		return "Male";
	}
	else {
		return "None";
	}
}