#include <iostream>
// #include <string>

using std::string;
typedef long Date;
struct Employee
{
	string first_name, family_name;
	char iddle_initial;
	Date hiring_date;
	short department;
};

struct Manager : public Employee
{
	int group;
	short level;
};

void g(Manager mm, Employee ee)
{
	Employee *pe = &mm;
	Manager *pm;

	// Manager *pm = &ee;
	pm->level = 2;
	pm = static_cast<Manager *>(pe);
	pm->level = 2;
}