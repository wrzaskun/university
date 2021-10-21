#pragma once
#include "IDataBase.hpp"
#include "Student.hpp"
#include <stdexcept>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>
#include <numeric>


class DataBaseFile : public IDataBase {
public:

	explicit DataBaseFile(std::string_view filename) : filename_(filename) {}

	std::vector<Student> load() override;

	void save(const std::vector<Student>& data) override;

private:
	const std::string filename_;
};
