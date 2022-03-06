#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>
using namespace std;

long long dp[108];
int n;
int main() {
	
	scanf("%d",&n);
	for (long long i = 1; i <= 6; i++) {
		dp[i] = i;
	}
	for (int i = 7; i <= n; i++) {
		dp[i] = dp[i-1] + 1;
		for(int j = 3 ;i-j>=0;j++){
			dp[i] = max(dp[i],dp[i-j]*(j-1));
		}
	}
	printf("%lld",dp[n]);
}