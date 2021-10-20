#include "DataBaseFile.hpp"

std::vector<Student> DataBaseFile::load()
{
	if (filename_.empty()) {
		throw file_error("The Filename is empty.");
	}

	std::ifstream ifs(filename_);
	if (!ifs.is_open()) {
		throw file_error("Can't open File.");
	}

	std::string temp{};
	std::vector<Student> student_list{};

	while (std::getline(ifs, temp)) {
		student_list.emplace_back(temp);
	}
	ifs.close();

	return student_list;
}

void DataBaseFile::save(const std::vector<Student>& data)
{
	if (filename_.empty()) {
		throw file_error("The Filename is empty.");
	}
	std::ofstream ofs(filename_);

	if (!ofs.is_open()) {
		throw file_error("Can't open File.");
	}

	for (const auto& x : data) {
		ofs << x.to_string_cvs_format() << '\n';
	}

	ofs.close();
}

