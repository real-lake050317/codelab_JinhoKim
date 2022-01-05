#include <iostream>
using std::string;

class Employee {
public:
	string Name;
	string Company;
	int Age;
	
	void IntroduceYourself() {
		std::cout << "Name - " << Name << std::endl;
		std::cout << "Company - " << Company << std::endl;
		std::cout << "Age - " << Age << std::endl;
	}
};

int main()
{
	int number;
	Employee employee1;
	employee1.Name = "Jinho";
	employee1.Company = "Kaspersky";
	//employee1.Age = 18;
	employee1.IntroduceYourself();
	
}
