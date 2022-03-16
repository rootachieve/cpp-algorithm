#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <string>
#include <set>
#define MAX 1000000001;
#define MOD 10007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;

int dp[4][50002];
int base[50002];
int n;
int k;
int main() {
	scanf("%d",&n);
	int a;
	for (int i = 1; i <= n; i++) {
		scanf("%d",&a);
		base[i] = base[i-1] + a;
	}
	scanf("%d",&k);

	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == 1) {
				if (j <= k) {
					dp[i][j] = base[j];
				}
				else {
					dp[i][j] = max(dp[i][j-1],base[j] - base[j-k]);
				}
			}
			else {
				if (j <= k) {
					dp[i][j] = base[j];
				}
				else {
					dp[i][j] = max(dp[i][j - 1], (base[j] - base[j - k])+dp[i-1][j-k]);
				}
			}
		}
	}

	printf("%d",dp[3][n]);
}