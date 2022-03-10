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

int dp[2003][2003];//r,l
int l[2003];
int r[2003];
int n;

void back(int R, int L) {
	
	if (l[L] > r[R]) {
		if (dp[R+1][L] == -1) {
			back(R+1,L);
		}
		dp[R][L] = max(dp[R+1][L]+r[R],dp[R][L]);
	}

	if (dp[R][L+1] == -1) {
		back(R, L+1);
	}
	dp[R][L] = max(dp[R][L+1], dp[R][L]);

	if (dp[R + 1][L + 1] == -1) {
		back(R + 1, L + 1);
	}
	dp[R][L] = max(dp[R + 1][L + 1], dp[R][L]);
		
	
}
int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		scanf("%d",&l[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &r[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = -1;
		}
	}
	back(1,1);
	printf("%d",dp[1][1]);
}