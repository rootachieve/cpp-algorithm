#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <map>
#include<cmath>
#include <stack>
#define DIV 1000000007
#define ll long long
#define MOD(x,y) (((x)%DIV)+((y)%DIV))%DIV
#define MODF(x,y) (((x)%DIV)*((y)%DIV))%DIV
#define MAX 5000002
using namespace std;
typedef struct item {
	ll w;
	ll v;

	item(){
		w = 0;
		v = 0;
	}
	item(ll a,ll b) : w(a), v(b) {}
};
ll dp[10001][1401];
item list[1401];
ll n,m;
int main() {
	ll a,b,c;
	ll Ic = 0;
	scanf("%lld%lld",&n,&m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld%lld%lld",&a,&b,&c);
		ll Count = 1;
		ll temp =0;
		while (c > 0) {
			temp = min(Count,c);
			list[++Ic] = item(a*temp,b*temp);
			c-=temp;
			Count*=2;

		}
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= Ic; j++) {
			if (i - list[j].w >= 0) {
				dp[i][j] = max(dp[i][j - 1], dp[i - list[j].w][j - 1] + list[j].v);
			}
			else {
				dp[i][j] = dp[i][j-1];
			}
		}
	}
	printf("%lld",dp[m][Ic]);
}