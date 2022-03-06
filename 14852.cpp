#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#define MOD 1000000007
#define MODUL(x,y) (((y)%MOD) + ((x)%MOD))%MOD

#define MODULF(x,y) (((y)%MOD) * ((x)%MOD))%MOD

using namespace std;

long long dp[1000008];
int n;
long long sum = 0;
int main() {
	scanf("%d",&n);
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			dp[1] = 2;
		}
		else if (i == 2) {
			dp[2] += dp[1]*2;
			dp[2] += 3;
		}
		else {
			dp[i] = MODUL(dp[i],MODULF(dp[i-1],2));
			dp[i] = MODUL(dp[i],MODULF(dp[i-2],3));
			sum = MODUL(MODULF(dp[i - 3],2), sum);
			dp[i] = MODUL(dp[i], sum);
		}
	}
	printf("%lld",dp[n]%MOD);
}
