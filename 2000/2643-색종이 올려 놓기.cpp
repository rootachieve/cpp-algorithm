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

vector<pair<int,int>> v;
int dp[102];
int n;
int Max;
void back(int now) {
	if (now == n) {
		return;
	}else{
		dp[now] = 1;
		for (int i = now + 1; i < n; i++) {
			if (dp[i] == -1) {
				back(i);
			}

			if (v[now].first >= v[i].first && v[now].second >= v[i].second) {
				dp[now] = max(dp[now], dp[i] + 1);
			}
			else if(v[now].second >= v[i].first && v[now].first >= v[i].second){
				dp[now] = max(dp[now], dp[i]+1);
			}
		}
		Max = max(dp[now],Max);
	}
}
bool com(pair<int, int> a, pair<int, int> b) {
	return a.first*a.second > b.first*b.second;
}
int main() {
	scanf("%d",&n);
	int a,b;
	for (int i = 1; i <= n; i++) {
		dp[i-1] = -1;
		scanf("%d%d",&a,&b);
		v.push_back({a,b});
	}
	sort(v.begin(),v.end(),com);
	back(0);
	printf("%d",Max);
}
