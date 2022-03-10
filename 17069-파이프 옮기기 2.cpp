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

int map[35][35];
int n;
long long DP[4][35][35];

int main() {
	scanf("%d", &n);
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= n + 1; j++) {
			if (j == 0 || j == n + 1 || i == n + 1 || i == 0) {
				map[i][j] = 1;
			}
			else {
				scanf("%d", &map[i][j]);
			}
		}
	}

	DP[1][1][2] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == 1 && j <= 2) continue;
			if (map[i][j] != 1) {//r
				DP[1][i][j] += DP[1][i][j - 1];
				DP[1][i][j] += DP[3][i][j - 1];
			}

			if ((map[i][j] != 1 && map[i - 1][j] != 1) && map[i][j - 1] != 1) {
				DP[3][i][j] += DP[1][i - 1][j - 1];
				DP[3][i][j] += DP[2][i - 1][j - 1];
				DP[3][i][j] += DP[3][i - 1][j - 1];
			}

			if (map[i][j] != 1) {
				DP[2][i][j] += DP[2][i - 1][j];
				DP[2][i][j] += DP[3][i - 1][j];
			}
		}
	}

	printf("%lld", DP[1][n][n] + DP[2][n][n] + DP[3][n][n]);
}