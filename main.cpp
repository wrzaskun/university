#include "University.hpp"
#include <iostream>

int main()
{

    University u;
    u.addStudent(Student("11", "65122478931", "Ania", "Bida", "Wroclaw", Gender::Female));
    u.addStudent(Student("22", "88022917797", "Wiesia", "Nedza", "Poznan", Gender::Female));
    u.addStudent(Student("33", "74052464714", "Artur", "Czosnek", "Warszawa", Gender::Male));
    u.print();

    try
    {
        // u.save("my_file.txt");
        u.load("my_file.txtx");
    }
    catch (const file_error &e)
    {
        std::cout << e.what();
    }
    catch (const std::exception &e)
    {
        std::cout << e.what();
    }

    u.sortBySurname();
    u.print();
    std::cout << '\n';

    u.sortByPesel();
    u.print();

    return 0;
}