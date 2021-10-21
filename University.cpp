#include "University.hpp"

void University::sortBySurname()
{
	std::sort(student_list_.begin(), student_list_.end(), [](const Student& a, const Student& b)
		{ return a.getSurname() < b.getSurname(); });
}

void University::sortByPesel()
{
	std::sort(student_list_.begin(), student_list_.end(), [](const Student& a, const Student& b)
		{ return a.getPesel() < b.getPesel(); });
}

void University::print()
{
	for (const auto& x : student_list_)
	{
		std::cout << x.to_string();
	}
}

bool University::removeByIndex(std::string_view index)
{
	bool result = false;
	auto it = std::remove_if(std::begin(student_list_), std::end(student_list_), [&index, &result](const Student& x){
		if(index == x.getIndex()){
			result = true;
			return true;
		}
		return false;
	});

	student_list_.erase(it, student_list_.end());

	return result;
}

size_t University::getAmountOfStudents() const
{
	return student_list_.size();
}

void University::save(std::string_view filename)
{
	db_ = std::make_unique<DataBaseFile>(filename);
	db_->save(student_list_);

}

void University::load(std::string_view filename)
{
	db_ = std::make_unique<DataBaseFile>(filename);
	student_list_ = db_->load();
}

Student University::getStudentsBySurname(const std::string& surname) const
{
	for (const auto& el : student_list_)
	{
		if (surname == el.getSurname())
		{
			return el;
		}
	}
	return {};
}

Student University::getStudentByPesel(const std::string& pesel) const
{
	for (const auto& el : student_list_)
	{
		if (pesel == el.getPesel())
		{
			return el;
		}
	}
	return {};
}

void University::addStudent(const Student &student) {
    student_list_.push_back(student);
}

