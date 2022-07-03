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

int map[12][12];
int check[12];
int sum;
int t;
int Max;
void back(int now) {
	if (now == 12) {
		Max = max(sum,Max);
	}
	else {
		for (int i = 1; i <= 11; i++) {
			if (check[i] == 0 && map[i][now] > 0) {
				check[i] = 1;
				sum+=map[i][now];
				back(now+1);
				sum-=map[i][now];
				check[i] = 0;
			}
		}
	}
}
int main() {
	scanf("%d",&t);
	while (t--) {
		for (int i = 1; i <= 11; i++) {
			for (int j = 1; j <= 11; j++) {
				scanf("%d",&map[i][j]);
			}
		}
		Max = 0;
		back(1);
		printf("%d\n",Max);
	}
}