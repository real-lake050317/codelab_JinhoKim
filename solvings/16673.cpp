#include <iostream>
using namespace std;

int C, K, P;
int sum = 0;

int main(){
	cin >> C >> K >> P;
	for (int i = 1; i<=C; i++){
		sum += K*i + P*i*i;
	}
	cout << sum;
	return 0;
}
