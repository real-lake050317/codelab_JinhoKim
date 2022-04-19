#include <iostream>
using namespace std;

int asc[] = {1, 2, 3, 4, 5, 6, 7, 8};
int des[] = {8, 7, 6, 5, 4, 3, 2, 1};
int arr[10];
bool flg = true;

int main(){
	for (int i = 0; i<8; i++) cin >> arr[i];
	if (arr[0] == 1) {
		for (int i = 0; i<8; i++) if (arr[i] != asc[i]) break;
		cout << "ascending" << endl;
		return 0;
	}
	else if (arr[0] == 8) {
		for (int i = 0; i<8; i++) if (arr[i] != des[i]) break;
		cout << "descending" << endl;
		return 0;
	}
	cout << "mixed" << endl;
}
