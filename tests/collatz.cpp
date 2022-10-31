#include <iostream>
using namespace std;

int collatz(int n) {
	int count = 0;
	if (n == 1) {
		cout << n << endl;
		cout << "True" << endl;
		return 0;
	} else if (n % 2 == 0) {
		cout << n << " ";
		return collatz(n / 2);
	} else {
		cout << n << " ";
		return collatz(3 * n + 1);
	}
}

int main() {
	int n;
	cout << "Enter a number: ";
	cin >> n;
	collatz(n);
}