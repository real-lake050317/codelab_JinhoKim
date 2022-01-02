#pragma warning(disable:4996)
#include <bits/stdc++.h>

 

struct student {
    char name[10];
    int id;
    char result;

};

int main(){
	struct student st[5];
	char find[10];
	for (int i = 0; i<5; i++){
		scanf("%s %d %c", &st[i].name, &st[i].id, &st[i].result);
	}
	scanf("%s", find);
	int score;
	int ans[10];
	int index = 0;
	for (int i = 0; i<5; i++){
		if (strcmp(find, st[i].name) == 0){
			ans[index] = st[i].result;
		}
	}
	for (int i = 0; i<index; i++){
		printf("%s", st[index].name);
	}
}
