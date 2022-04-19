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
bool c[1001];
int d[1001];
int n,m;
vector<int> v[1001];
bool dfs(int node) {
	for (int i = 0; i < v[node].size(); i++) {
		int t = v[node][i];

		if (c[t]) {
			continue;
		}
		c[t] = true;
		if (d[t] == 0 || dfs(d[t])) {
			d[t] = node;
			return true;
		}
	}
	return false;
}
int main() {
	scanf("%d%d",&n,&m);
	int a,b;
	for (int i = 1; i <= n; i++) {
		scanf("%d",&a);
		for (int j = 1; j <= a; j++) {
			scanf("%d",&b);
			v[i].push_back(b);
		}
	}
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		fill(c,c+1001,false);
		if(dfs(i)) answer++;
	}
	printf("%d",answer);
}