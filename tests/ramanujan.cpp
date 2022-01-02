#include <iostream>
#include <cmath>
using namespace std;

const long long num = 1000000;

int main(){
	for (long long i = 1; i<num; i++){
		int cnt = 0;
		int a, b, c, d;
		for (long long j = 1; j<100; j++){
			for (long long k = 1; k<=j; k++){
				if (i == j*j*j + k*k*k) 
					cnt++;
				if (i < j*j*j) {
					k = 100;
					j = 100;
				}
			}
		}
		if (cnt == 2) cout << i << "\n";
	}
	
	return 0;
}
