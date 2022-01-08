#include <iostream>
using namespace std;

int n, m;
int cnt = 0;

int main(){
	cin >> n >> m;
	int arr[n+1];
	
	for (int i = 0; i<n; i++){
		cin >> arr[i];
	}
	
	int start = 0;
	int end = 0;
	int result = arr[0];
	
	while (start <= end && end<n){
		if (result < m){
			result += arr[++end];
		}
		else if (result == m){
			cnt++;
			result += arr[++end];
		}
		else{
			result -= arr[start++];
			if (start > end){
				end = start;
				result = arr[start];
			}
		}
	}
	
	cout << cnt;
}
