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
		cout << "¹«¾ùÀ» ³¾±î¿ä? ¹¬: 1 / Âî: 2 / ºü: 3";
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
