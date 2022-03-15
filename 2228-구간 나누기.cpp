#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <deque>
#define MAX 1000000001;
#define MOD 10007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;
int dp[102][52];

int m,n;
int sum[102];

int main() {
	scanf("%d%d",&n,&m);
	int a;
	for (int i = 1; i <= n; i++) {
		scanf("%d",&a);
		sum[i] = sum[i-1]+a;
	}
	
	for (int j = 1; j <= m; j++) {
		dp[0][j] = -32768001;
	}
	
	for(int i = 1;i<=n;i++){
		for (int j = 1; j <= m; j++) {
			dp[i][j] = dp[i - 1][j];
			for (int k = 1; k <= i; k++) {
				if (k >= 2)
					dp[i][j] = max(dp[i][j], dp[k - 2][j - 1] + sum[i] - sum[k - 1]);
				else if (k == 1 && j == 1)
					dp[i][j] = max(dp[i][j], sum[i]);
			}
		}
	}

	printf("%d",dp[n][m]);
}