#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <string>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <algorithm>
#include <map>
#define ll long long
#define MAX 1000001
#define MOD 1000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;

ll dp[2][42];

int main() {
	dp[0][0] = 1;
	dp[1][1] = 1;
	for (int i = 2; i <= 40; i++) {
		dp[0][i] = dp[0][i-1] + dp[0][i-2];
		dp[1][i] = dp[1][i-1] + dp[1][i-2];
	}
	int t;
	cin>>t;
	while (t--) {
		int n;
		cin>>n;
		printf("%lld %lld\n",dp[0][n],dp[1][n]);
	}
}