#include <iostream>
#include <random>
using namespace std;

int main(){
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 2);
	/*
	bool flag = false;
	while(1){
		int cmd;
		int rand = dis(gen);
		cout << "������ �����? ��: 1 / ��: 2 / ��: 3";
		cin >> cmd;
		if (cmd == 1){
			if 
		}
		else if (cmd == 2){
			if 
		}
	}*/
	cout << dis(gen);
}
