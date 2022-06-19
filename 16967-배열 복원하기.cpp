#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <algorithm>
#define ll long long
#define MAX 1000001
#define MOD 1000000000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;


int map[601][601];
int ans[301][301];
int main() {
int n,m,x,y;
	cin>>n>>m>>y>>x;

	for (int i = 1; i <= n + y; i++) {
		for (int j = 1; j <= m + x; j++) {
			cin>>map[i][j];
		}
	}


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i >= y + 1 && j >= x + 1) {
				ans[i][j] = map[i][j] - ans[i - y][j - x];
			}
			else {
				ans[i][j] = map[i][j];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			printf("%d ",ans[i][j]);
		}
		printf("\n");
	}
}