#include "../catch2/catch_amalgamated.hpp"
#include "../Student.hpp"
#include <string>

TEST_CASE("student has been created", "[student]")
{
	Student student{};

	SECTION("student class values are default")
	{
		REQUIRE("-1" == student.getAddress());
		REQUIRE("None" == student.getGender());
		REQUIRE("-1" == student.getIndex());
		REQUIRE("-1" == student.getName());
		REQUIRE("-1" == student.getSurname());
		REQUIRE("00410251218" == student.getPesel());
	}

	student.setName("Kasia");
	student.setSurname("Kowalska");
	student.setAddress("Warszawa");
	student.setIndex(1);
	student.setPesel("57101281951");

	SECTION("student class values are changed by setters")
	{
		REQUIRE("Warszawa" == student.getAddress());
		REQUIRE("None" == student.getGender());
		REQUIRE("1" == student.getIndex());
		REQUIRE("Kasia" == student.getName());
		REQUIRE("Kowalska" == student.getSurname());
		REQUIRE("57101281951" == student.getPesel());
	}

	SECTION("student class values throw exception")
	{
		REQUIRE_THROWS_WITH(student.setPesel("57101281952"), "Pesel is wrong.");	
	}
}