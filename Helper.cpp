#include "Helper.hpp"

std::vector<std::string> split(const std::string& text, const std::string& del)
{
	std::vector<std::string> string_array;
	size_t begin = 0;
	size_t end = text.find(del);


	while (end != std::string::npos)
	{
		string_array.push_back(text.substr(begin, end - begin));
		begin = end + del.length();
		end = text.find(del, begin);
	}

	string_array.push_back(text.substr(begin, end));
	return string_array;
}
