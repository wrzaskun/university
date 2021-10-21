#include "../catch2/catch_amalgamated.hpp"
#include "../Pesel.hpp"
#include <algorithm>
#include <string>

TEST_CASE("pesels valid matrix has been created", "[pesel]")
{
	std::vector<Pesel> vp{
		Pesel("65122478931"),
		Pesel("88022917797"),
		Pesel("99080739313"),
		Pesel("81121672343"),
		Pesel("75061931426"),
		Pesel("87061451611"),
		Pesel("75011112161"),
		Pesel("74052464714"),
		Pesel("92051137729"),
		Pesel("90070517744")};

	for (char i = 0; i < vp.size(); ++i)
	{
		SECTION(std::string("Looped section ") + i)
		{
			CHECK(vp[i].validate() == true);
		}
	}
}

TEST_CASE("pesels invalid crc matrix has been created", "[pesel]")
{
	std::vector<Pesel> vp{
		Pesel("65122478932"),
		Pesel("88022917798"),
		Pesel("99080739314"),
		Pesel("81121672345"),
		Pesel("75061931429"),
		Pesel("87061451610"),
		Pesel("75011112160"),
		Pesel("74052464710"),
		Pesel("92051137721"),
		Pesel("90070517742")};

	for (char i = 0; i < vp.size(); ++i)
	{
		SECTION(std::string("Looped section ") + i)
		{
			CHECK(vp[i].validate() == false);
		}
	}
}

TEST_CASE("get sex", "[pesel]")
{
	std::vector<Pesel> vp{
		Pesel("00410146985"),
		Pesel("00410146985"),
		Pesel("00410194254"),
		Pesel("00410113891")
		};

	SECTION("validate sex")
	{
		CHECK(vp[0].getSex() == 'F');
		CHECK(vp[1].getSex() == 'F');
		CHECK(vp[2].getSex() == 'M');
		CHECK(vp[3].getSex() == 'M');
	}

	auto pesel_checksum_error = Pesel("90070517742");

	SECTION("validate sex with checksum pesel error - gender None")
	{
		CHECK(pesel_checksum_error.getSex() == 'N');
	}
	
}