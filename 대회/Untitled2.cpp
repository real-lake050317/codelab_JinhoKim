#include <iostream>
#include <cstring>
using namespace std;

int main(){
	char a[10];
	int length[5] = {1, 1, 2, 3, 5};
	int hour = 0;
	int min = 0;
	int sec = 0;
	cin >> a;
	for (int j = 0; j<5; j++){
		if (a[j] == 'R') hour += 1*length[j];
		else if (a[j] == 'G') min += 5*length[j];
		else if (a[j] == 'B') sec += 5*length[j];
		else if (a[j] == 'Y'){
			hour += 1*length[j];
			min += 5*length[j];
		}
		else if (a[j] == 'M'){
			hour += 1*length[j];
			sec += 5*length[j];
		}
		else if (a[j] == 'C'){
			min += 5*length[j];
			sec += 5*length[j];
		}
	}
	if (sec >= 60) {
		sec -= 60;
		min += 1;
	}
	if (min >= 60){
		min -= 60;
		hour += 1;
	}
	if (hour > 12){
		hour -= 12;
	}
	if (hour < 10){
		cout << "0" << hour << ":";
	}
	else {
		cout << hour << ":";
	}
	if (min < 10){
		cout << "0" << min << ":";
	}
	else {
		cout << min << ":";
	}
	if (sec < 10){
		cout << "0" << sec << "\n";
	}
	else {
		cout << sec << "\n";
	}
}
