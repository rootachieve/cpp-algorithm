#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <string>
#include <set>
#define MAX 1000000001;
#define MOD 10007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;

vector<int> v[10002];
int n;
int value[10002];
bool visit[10002];
int dp[2][10002];

void back(int node) {
	visit[node] = true;
	dp[1][node] = value[node];
	for(int i = 0;i<v[node].size();i++){
		if (!visit[v[node][i]]) {
			back(v[node][i]);
			dp[0][node]+=max(dp[0][v[node][i]],dp[1][v[node][i]]);
			dp[1][node]+=dp[0][v[node][i]];
		}
	}
}

int main() {
	int a,b;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		scanf("%d",&value[i]);
	}

	for (int i = 1; i <= n - 1; i++) {
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}

	back(1);
	printf("%d",max(dp[1][1],dp[0][1]));
}