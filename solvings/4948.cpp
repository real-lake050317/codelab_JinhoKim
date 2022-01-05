#include <iostream>
#include <cmath>

bool checkPrimeNumber(int a){
	for (int i = 2; i<sqrt(a); i++)
		if (a%i == 0) return true;
	
	return false;
}

int main(void){
	int a = 1;
	while (a){
		int cnt = 0;
		std::cin >> a;
		for (int j = a; j <= 2*a; j++){
			if(!checkPrimeNumber(j)) cnt++;
		}
		
		std::cout << cnt << std::endl;
	}
}
