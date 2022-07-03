#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <unordered_set>
#include <cstring>
#include <math.h>

#define MAX 2147483647
#define MOD 1000000000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
#define ll long long
using namespace std;
int n,k;
int check[2][500001];
queue<pair<int,int>> q;
int main() {
	scanf("%d%d",&n,&k);

	q.push({0,n});
	int t,l;
	int ty = 0;
	for (int i = 0; i <= 500000; i++) {
		check[0][i] = 10000000;
		check[1][i] = 10000000;
	}

	check[0][n] = 0;
	while (!q.empty()) {
		t = q.front().first;
		l = q.front().second;
		q.pop();

		if ((t & 1) == 1) {
			ty = 0;
		}
		else {
			ty = 1;
		}
		
		if (l-1>=0&&check[ty][l - 1] > t + 1) {
			check[ty][l - 1] = t + 1;
			q.push({t+1,l-1});
		}

		if (l + 1 <= 500000 && check[ty][l + 1] > t + 1) {
			check[ty][l + 1] = t + 1;
			q.push({ t + 1,l + 1 });
		}

		if (l*2 <= 500000 && check[ty][l*2] > t + 1) {
			check[ty][l*2] = t + 1;
			q.push({ t + 1,l*2 });
		}
	}
	int Min = 10000000;
	for (int i = 0; k <= 500000;i++, k += i) {
		if ((i & 1) == 1) {
			if (check[1][k] <= i) {
				Min = min(Min,i);
			}
		}
		else {
			if (check[0][k] <= i) {
				Min = min(Min, i);
			}
		}
	}

	if (Min == 10000000) {
		printf("-1");
	}
	else {
		printf("%d",Min);
	}
	
} 