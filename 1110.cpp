#include <iostream>

int N;
int cnt = 0;

int main(){
	std::cin >> N;
	int num = N;
	while (true){
		cnt++;
		num = (num%10)*10 + (num%10+num/10)%10;
		if (num == N){
			std::cout << cnt;
			return 0;
		}
	}
}
