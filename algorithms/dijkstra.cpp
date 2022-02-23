#include <iostream>
using namespace std;

int num = 6;
const int INF = 1e7;

int graph[6][6] = {
	{0, 2, 5, 1, INF, INF},
	{2, 0, 3, 2, INF, INF},
	{5, 3, 0, 3, 1, 5},
	{1, 2, 3, 0, 1, INF},
	{INF, INF, 1, 1, 0, 2},
	{INF, INF, 5, INF, 2, 0},
};

bool v[6];
int d[6];

int getSmallIndex(){
	int min = INF;
	int index = 0;
	for (int i = 0; i < num; i++){
		if (d[i] < min && !v[i]){
			min = d[i];
			index = i;
		}
	}
	return index;
}

void dijkstra(int start){
	for (int i = 0; i < num; i++){
		d[i] = graph[start][i];
	}
	v[start] = true;
	for (int i = 0; i < num - 2; i++){
		int current = getSmallIndex();
		v[current] = true;
		for (int j = 0; j < 6; j++){
			if (!v[j]) {
				if (d[current] + graph[current][j] < d[j]){
					d[j] = d[current] + graph[current][j];
				}
			}
		}
	}
}

int main(){
	dijkstra(0);
	for (int i = 0; i < num; i++){
		cout << d[i] << " ";
	}
}
