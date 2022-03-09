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

int dp[101][10002];
pair<int,int> base[102];
int n;
int k;
int a,b;
bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first<b.first;
}
int main() {
	scanf("%d",&k);
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d",&a,&b);
		base[i] = {a,b};
	}
	sort(base+1,base+n+1,compare);
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if(dp[i-1][j]>0){
				for (int g = 1; g <= base[i].second; g++) {
					if (j + base[i].first * g <= k) {
						dp[i][j+base[i].first*g] += dp[i-1][j];
					}
				}
				dp[i][j] +=dp[i-1][j];
			}
		}
	}
	printf("%d",dp[n][k]);
}