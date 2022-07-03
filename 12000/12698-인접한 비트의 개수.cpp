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

int t;
int n,k;
long long dp[2][102][102];//last , length, k
int main() {
	dp[0][1][0] = 1;
	dp[1][1][0] = 1;
	for (int i = 2; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			dp[0][i][j] += dp[1][i-1][j] + dp[0][i-1][j];
			dp[1][i][j] += dp[0][i-1][j];
			if(j>0){
				dp[1][i][j] += dp[1][i-1][j-1];
			}
		}
	}
	int a,b;
	scanf("%d",&t);
	while (t--) {
		scanf("%d%d",&a,&b);
		printf("%lld\n",dp[1][a][b]+dp[0][a][b]);
	}
}