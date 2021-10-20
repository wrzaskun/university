#include "../catch2/catch.hpp"
#include "../University.hpp"
#include <string>

TEST_CASE("Operation on University", "[university]")
{
	University university;
	university.addStudent({ "1", "81121672343", "Ania", "Bida", "Poznan", Gender::Female });
	university.addStudent({ "2", "75061931426", "Asia", "Nedza", "Wroclaw",  Gender::Female });
	university.addStudent({ "3", "75011112161", "Arek", "Lipa", "Lodz",  Gender::Male });
	university.addStudent({ "4", "90070517744", "Artur", "Czosnek", "Warszawa",  Gender::Female });

	SECTION("find student on list by pesel")
	{
		std::string pesel("81121672343");
		std::string other_pesel("75011112161");
		REQUIRE(university.getAmountOfStudents() == 4);
		CHECK(pesel == university.getStudentByPesel(pesel).getPesel());
		CHECK_FALSE(pesel == university.getStudentByPesel(other_pesel).getPesel());
	}

	SECTION("find student on list by surname")
	{
		std::string surname_on_list("Lipa");
		std::string surname_not_on_list("Dzieciol");
		REQUIRE(university.getAmountOfStudents() == 4);
		CHECK(surname_on_list == university.getStudentsBySurname(surname_on_list).getSurname());
		CHECK_FALSE(surname_on_list == university.getStudentsBySurname(surname_not_on_list).getSurname());
	}

	SECTION("remove student from list by index")
	{
		std::string valid_index = "1";
		REQUIRE(university.getAmountOfStudents() == 4);
		CHECK(university.removeByIndex(valid_index));
		CHECK(university.getAmountOfStudents() == 3);

		std::string invalid_index = "123";
		CHECK(university.getAmountOfStudents() == 3);
		CHECK_FALSE(university.removeByIndex(invalid_index));
		CHECK(university.getAmountOfStudents() == 3);
	}

	SECTION("write / read student's list from file")
	{
		std::string file_name = "test_write.txt";
		university.save(file_name);

		University university_load;
		university_load.load(file_name);

		SECTION("is file properly load ") {

			CHECK(university_load.getAmountOfStudents() == 4);
		}

		SECTION("check if loaded person exist on list") {

			std::string surname_on_list = "Bida";
			std::string surname_not_on_list = "Kutek";
			CHECK(surname_on_list == university_load.getStudentsBySurname(surname_on_list).getSurname());
			CHECK_FALSE(surname_on_list == university_load.getStudentsBySurname(surname_not_on_list).getSurname());
		}

		SECTION("check if loaded pesels exist on list") {

			std::string pesel_on_list("81121672343");
			std::string pesel_not_on_list("65122478931");
			CHECK(pesel_on_list == university_load.getStudentByPesel(pesel_on_list).getPesel());
			CHECK_FALSE(pesel_on_list == university_load.getStudentByPesel(pesel_not_on_list).getPesel());
		}
	}
}