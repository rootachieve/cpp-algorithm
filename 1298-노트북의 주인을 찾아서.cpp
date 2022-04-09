#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <set>
#include<map>
#include <stack>
#define DIV 1000000007
#define MOD(x,y) (((x)%DIV)+((y)%DIV))%DIV
#define MODF(x,y) (((x)%DIV)*((y)%DIV))%DIV
#define MAX 500002
using namespace std;

vector<int> v[101];
int d[101];
bool c[101];
int n,m;
bool dfs(int node) {
	for (int i = 0; i < v[node].size(); i++) {
		if (c[v[node][i]]) {
			continue;
		}
		c[v[node][i]] = true;

		if (d[v[node][i]] == 0 || dfs(d[v[node][i]])) {
			d[v[node][i]] = node;
			return true;
		}
	}
	return false;
}
int main() {
	scanf("%d%d",&n,&m);
	int a,b;
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) {
		fill(c,c+100,false);
		if (dfs(i)) {
			ans++;
		}
	}
	printf("%d",ans);
}