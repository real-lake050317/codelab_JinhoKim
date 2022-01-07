#include <iostream>
using namespace std;

int main(){
	char hello[] = "hello";
	char *p = hello;
	while (*p) {
		*p += 1;
		p += 1;
	}
	cout << hello;
	
	return 0;
}
