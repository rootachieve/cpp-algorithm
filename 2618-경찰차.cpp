#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <deque>
#include <set>
#include <unordered_set>
#include <unordered_map>
#define MAX 1002147473647
#define MOD 100003
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
#define ll long long
using namespace std;
int n,Size;
ll dp[1004][1004];
pair<int,int> in[1003];
void back(int fir, int sec, int num) {
	if (num == n + 2) {
		dp[fir][sec] = 0;
		return;
	}
	ll F = 0;
	ll S = 0;
	if (dp[num][sec] == -1) {
		back(num,sec,num+1);
	}
	F =dp[num][sec];

	if (dp[fir][num] == -1) {
		 back(fir, num, num + 1);
	}
	S = dp[fir][num];

	F += abs(in[fir].first-in[num].first) + abs(in[fir].second-in[num].second);
	S += abs(in[sec].first - in[num].first) + abs(in[sec].second - in[num].second);
	

	if (F < S) {
		dp[fir][sec] = F;
	}
	else {
		dp[fir][sec]=  S;
	}
}


int main() {
	scanf("%d",&Size);
	scanf("%d",&n);
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= n + 1; j++) {
			dp[i][j] =-1;
		}
	}
	int a,b;
	in[0] = {1,1};
	in[1] = {Size,Size};
	for (int i = 2; i <= n + 1; i++) {
		scanf("%d%d",&a,&b);
		in[i] = {a,b};
	}
	back(0,1,2);
	printf("%lld\n",dp[0][1]);

	int L = 0;
	int R = 1;
	int trace = 2;

	while (trace != n + 2) {
		ll F = 0;
		ll S = 0;
		F = abs(in[L].first - in[trace].first) + abs(in[L].second - in[trace].second);
		S = abs(in[R].first - in[trace].first) + abs(in[R].second - in[trace].second);

		if (F + dp[trace][R] < S + dp[L][trace]) {
			printf("1\n");
			L = trace;
		}
		else {
			printf("2\n");
			R = trace;
		}

		trace ++;
	}
}