#include <iostream>
#include <algorithm>

int T;
double arr[10010];//float -> 32bit, double -> 64bit, float ���� �߻����ɼ� ���� 
double ans = 0; //������ �Ǽ����� double��! 

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
	
	printf("%0.3f", ans); //���� ���ǻ� �Ҽ��� 3°�ڸ� ������ ��� cout���� ����! 
	
	return 0;
}
