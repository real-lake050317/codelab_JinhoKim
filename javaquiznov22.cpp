#include <iostream>
int main(void){
	short a = 32768;
    short b = -32769;
    short c = 40000;
	std::cout << "양수 32768은 " << a << "로 표현된다." << "\n";
	std::cout << "음수 -32769은 " << b << "로 표현된다." << "\n";
	std::cout << "양수 40000은 " << c << "로 표현된다." << "\n"; 
	
	return 0;
}
