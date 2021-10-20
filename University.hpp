#pragma once
#include "Student.hpp"
#include "DataBaseFile.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class University
{
public:
	void addStudent(const Student& student);
	void sortBySurname();
	void sortByPesel();
	void print();
	bool removeByIndex(std::string_view index);
	size_t getAmountOfStudents() const;
	void save(std::string_view filename);
	void load(std::string_view filename);
	Student getStudentsBySurname(const std::string& surname) const;
	Student getStudentByPesel(const std::string& pesel) const;

private:
	std::vector<Student> student_list_;
	std::unique_ptr<IDataBase> db_;
};