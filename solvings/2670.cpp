#include <iostream>
#include <algorithm>

int T;
double arr[10010];//float -> 32bit, double -> 64bit, float 오류 발생가능성 높음 
double ans = 0; //무조건 실수형은 double로! 

int main(){
	std::cin >> T;
	for (int i = 0; i<T; i++){
		std::cin >> arr[i];
	}
	
	ans = arr[0];
	
	for (int i = 1; i<T; i++){
		if (arr[i] * arr[i-1] >= arr[i]){
			arr[i] = arr[i]*arr[i-1];
		}
		ans = std::max(ans, arr[i]);
	}
	
	printf("%0.3f", ans); //문제 조건상 소수점 3째자리 까지만 출력 cout쓰지 말고! 
	
	return 0;
}
