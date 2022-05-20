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
ll dp[1000001];
int main() {
	int n;
	scanf("%d",&n);

	dp[1] = 1;
	for(int i = 2;i<=abs(n);i++){
		dp[i] = MODULAR(dp[i-1],dp[i-2]);
	}

	if (n == 0) {
		printf("0\n0");
	}
	else if (n > 0) {
		printf("1\n%lld", (dp[n] % MOD));
	}
	else {

		n = abs(n);
		if (n % 2 == 0) {
			printf("-1\n%lld",dp[n]%MOD);
		}
		else {
			printf("1\n%lld", dp[n]%MOD);
		}
	}
}
	