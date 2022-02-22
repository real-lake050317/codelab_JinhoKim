#include <iostream>
using namespace std;

int main(){
	int* ptr = (int*) 0x00000000;
	*ptr = 1;
	cout << *ptr;
}
