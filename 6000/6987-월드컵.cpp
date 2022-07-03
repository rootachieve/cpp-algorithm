#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <deque>
#define MAX 1002147473647
#define MOD 10007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;

int score[7][4];

int target[7][4];
bool check;
void back(int a,int b) {
	if (a==5&&b==7 ) {
		bool err = false;
		for (int i = 1; i <= 6; i++) {
			for (int j = 1; j <= 3; j++) {
				if (target[i][j] != score[i][j]) {
					err= true;
				}
			}
		}
		if (!err) {
			check = true;
		}
	}
	else {
		if (check) {
			return;
		}
		if (b == 7) {
			a++;
			b=a+1;
		}
		score[a][1]++;
		score[b][3]++;
		back(a,b+1);
		score[a][1]--;
		score[b][3]--;

		score[a][2]++;
		score[b][2]++;
		back(a, b + 1);
		score[a][2]--;
		score[b][2]--;

		score[a][3]++;
		score[b][1]++;
		back(a, b + 1);
		score[a][3]--;
		score[b][1]--;


	}
}

int main() {
	for (int h = 1; h <= 4; h++) {
		for (int i = 1; i <= 6; i++) {
			for (int j = 1; j <= 3; j++) {
				score[i][j] = 0;
				scanf("%d",&target[i][j]);
			}
		}
		back(1,2);
		if (check) {
			printf("1 ");
			check = false;
		}
		else {
			printf("0 ");
		}
	}
}